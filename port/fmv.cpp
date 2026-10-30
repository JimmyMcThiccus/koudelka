/* FMV, skipped (the user's decision for now; a software MDEC comes later).

   How the game plays a movie: MOVIE opens a stream (func_800B92B8) and creates a player, which waits as a
   client of the stream until the stream has a frame (func_800B8EB8 asks StGetNext); then the player ticks
   once per frame, gets frames (func_800B9484), decodes them on the MDEC (libpress DecDCT*, slice by slice
   through the MDEC-out callback) and, once the stream reports itself stopped, ends through its own path
   and notifies its owner. The stream stops itself when a frame's number is at or past the movie's end
   frame (func_800B9484: h->x8 >= p->x28).

   The skip uses that natural end: StGetNext gives one empty frame, so the player starts, and then a frame
   numbered past any end, so the stream stops and the player ends after one or two frames. The MDEC is
   "black": DecDCTout fills its slice with zeros and raises the MDEC-out callback as an interrupt
   (port_fmv_poll, from port/intr.cpp), and libpress's Huffman decoder has nothing to decode. These replace
   the recompiled libpress functions (port/configure_port.py drops a recompiled function port/ defines,
   prefixed for an overlay: movie_DecDCTReset). */
#include <string.h>
#include "port_rt.h"

typedef void (*MdecCB)(void);

static int g_stream_open;
static unsigned g_movies, g_frames_given;
static unsigned long g_frame[0x200];  /* an empty MDEC bitstream: size 0 */
static unsigned long g_header[8];     /* StreamHdr: x8 is the frame number */
static MdecCB g_mdec_out_cb;
static int g_mdec_pending;

/* ---- libcd streaming (St*), not in PsyCross ---- */
extern "C" void StSetRing(unsigned long *ring, unsigned long size)
{
    g_stream_open = 1;
    g_frames_given = 0;
    port_log("fmv: movie %u started (ring %p, %lu sectors): skipped, ended at its first frames\n", ++g_movies,
             ring, size);
}

extern "C" void StSetStream(unsigned long mode, unsigned long start, unsigned long end, void *f1, void *f2) {}
extern "C" void StClearRing(void) {}

extern "C" void StUnSetRing(void)
{
    if (g_stream_open)
        port_log("fmv: movie %u stopped after %u frames\n", g_movies, g_frames_given);
    g_stream_open = 0;
}

extern "C" unsigned long StFreeRing(unsigned long *base) { return 0; }

extern "C" unsigned long StGetNext(unsigned long **addr, unsigned long **header)
{
    if (!g_stream_open)
        return 1;
    memset(g_frame, 0, sizeof g_frame);
    memset(g_header, 0, sizeof g_header);
    g_header[2] = g_frames_given++ ? 0x7FFF : 1;  /* the first frame starts the player, the next one ends it */
    *addr = g_frame;
    *header = g_header;
    return 0;
}

extern "C" void StCdInterrupt(void) {}
extern "C" int CdRead2(long mode) { return 1; }  /* streaming read started; StGetNext supplies the frames */

/* ---- MOVIE's libpress: a black MDEC ---- */
extern "C" void movie_DecDCTReset(int mode)
{
    g_mdec_pending = 0;
}

extern "C" void movie_DecDCTin(void *buf, int mode) {}

extern "C" void movie_DecDCTout(void *buf, int size)
{
    if (buf && size > 0)
        memset(buf, 0, (size_t)size * 4);
    g_mdec_pending = 1;
}

extern "C" int movie_DecDCTinSync(int mode)
{
    return 0;
}

extern "C" int movie_DecDCToutSync(int mode)
{
    return 0;
}

extern "C" void *movie_DecDCTinCallback(void *f)
{
    return 0;
}

extern "C" void *movie_DecDCToutCallback(void *f)
{
    void *old = (void *)g_mdec_out_cb;
    g_mdec_out_cb = (MdecCB)f;
    return old;
}

extern "C" void movie_DecDCTvlcBuild(void *table) {}

extern "C" int movie_DecDCTvlc2(void *bs, void *buf, void *table)
{
    return 0;  /* the bitstream is fully decoded */
}

/* the MDEC-out "interrupts", at interrupt points (port/intr.cpp) */
extern "C" void port_fmv_poll(void)
{
    for (int i = 0; i < 64 && g_mdec_pending && g_mdec_out_cb; i++) {
        g_mdec_pending = 0;
        g_mdec_out_cb();  /* may start the next slice (DecDCTout) */
    }
}
