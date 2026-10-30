/* The game's CD interface (libcd's command/interrupt level) over the disc 1 image.

   PsyCross's libcd only streams (CdlReadS through a spooler thread); the EXE drives the drive itself:
   CdControl(Setloc/ReadN/Pause/Setmode/...), a ready callback per sector that pulls data with CdGetSector
   (header first: the game reads in CdlModeSize1), and a sync callback per completed command. This module
   implements those calls over the raw .bin (2352-byte Mode 2 sectors) and raises the callbacks as
   interrupts on the game thread (port/intr.cpp calls port_cd_poll): one CdlComplete per command, and
   CdlDataReady at the drive's rate (75 sectors/s, 150 at double speed) while reading. PsyCross's versions
   are renamed psyx_* at compile time (port/configure_port.py).

   The unnamed PsyQ functions are by the feasibility study's identification: func_8009C9C0 CdStatus,
   func_8009C9D0 CdLastCom, func_8009C9E0 CdMode, func_8009D030 CdReadCallback. */
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "port_rt.h"

extern "C" unsigned port_stat_cd_commands, port_stat_cd_sectors;

typedef void (*CdCB)(unsigned char intr, unsigned char *result);

enum { CdlNoIntr = 0, CdlDataReady = 1, CdlComplete = 2, CdlDiskError = 5 };
enum { CdlNop = 1, CdlSetloc = 2, CdlPlay = 3, CdlReadN = 6, CdlStop = 8, CdlPause = 9, CdlInit = 0x0A,
       CdlSetmode = 0x0E, CdlGetlocL = 0x10, CdlGetlocP = 0x11, CdlGetTN = 0x13, CdlGetTD = 0x14,
       CdlSeekL = 0x15, CdlReadS = 0x1B };
enum { StatStandby = 0x02, StatRead = 0x20, StatSeek = 0x40 };
enum { ModeSpeed = 0x80, ModeSize1 = 0x20, ModeSize0 = 0x10 };

#define RAW 2352

static FILE *g_image;
static CdCB g_ready_cb, g_sync_cb;
static void *g_data_cb, *g_read_cb;
static int g_loc, g_next, g_mode, g_last_com, g_reading, g_sync_pending;
static unsigned char g_result[8];
static unsigned char g_sector[RAW];
static int g_cursor;          /* CdGetSector's position in g_sector */
static long long g_read_t0;   /* QPC at the start of the current read */
static int g_read_sectors;    /* sectors delivered since then */

static int bcd(int v) { return (v / 10) << 4 | (v % 10); }
static int unbcd(int v) { return (v >> 4) * 10 + (v & 15); }
static int loc_to_lba(const unsigned char *p) { return (unbcd(p[0]) * 60 + unbcd(p[1])) * 75 + unbcd(p[2]) - 150; }

static int status(void)
{
    return StatStandby | (g_reading ? StatRead : 0);
}

extern "C" void port_cd_open(const char *path)
{
    g_image = fopen(path, "rb");
    if (!g_image)
        port_log("cd: cannot open %s\n", path);
}

static void command(unsigned char com, const unsigned char *param, unsigned char *result)
{
    g_last_com = com;
    port_stat_cd_commands++;
    switch (com) {
    case CdlSetloc:
        if (param)
            g_loc = loc_to_lba(param);
        break;
    case CdlReadN:
    case CdlReadS:
        if (param)
            g_loc = loc_to_lba(param);
        g_next = g_loc;
        g_reading = 1;
        g_read_sectors = 0;
        {
            LARGE_INTEGER t;
            QueryPerformanceCounter(&t);
            g_read_t0 = t.QuadPart;
        }
        break;
    case CdlPause:
    case CdlStop:
        g_reading = 0;
        break;
    case CdlInit:
        g_reading = 0;
        g_mode = 0;
        break;
    case CdlSetmode:
        if (param)
            g_mode = param[0];
        break;
    case CdlSeekL:
    case CdlNop:
        break;
    case CdlGetTN:
        g_result[1] = 1, g_result[2] = 1;  /* one track */
        break;
    default:
        port_log("cd: command 0x%02X ignored\n", com);
        break;
    }
    g_result[0] = (unsigned char)status();
    if (result)
        memcpy(result, g_result, com == CdlGetTN ? 3 : 1);
    g_sync_pending = 1;
}

extern "C" int CdControl(unsigned char com, unsigned char *param, unsigned char *result)
{
    command(com, param, result);
    return 1;
}

extern "C" int CdControlF(unsigned char com, unsigned char *param)
{
    command(com, param, 0);
    return 1;
}

extern "C" int CdControlB(unsigned char com, unsigned char *param, unsigned char *result)
{
    command(com, param, result);
    return 1;
}

extern "C" int CdSync(int mode, unsigned char *result)
{
    if (result)
        result[0] = (unsigned char)status();
    return CdlComplete;
}

extern "C" int CdReady(int mode, unsigned char *result)
{
    if (result)
        result[0] = (unsigned char)status();
    return g_reading ? CdlDataReady : CdlNoIntr;
}

extern "C" int CdGetSector(void *dst, int words)
{
    int n = words * 4;
    if (g_cursor + n > RAW)
        n = RAW - g_cursor;
    memcpy(dst, g_sector + g_cursor, n);
    g_cursor += n;
    return 1;
}

extern "C" void *CdReadyCallback(void *f)
{
    void *old = (void *)g_ready_cb;
    g_ready_cb = (CdCB)f;
    return old;
}

extern "C" void *CdSyncCallback(void *f)
{
    void *old = (void *)g_sync_cb;
    g_sync_cb = (CdCB)f;
    return old;
}

extern "C" void *CdDataCallback(void *f)
{
    void *old = g_data_cb;
    g_data_cb = f;
    return old;
}

extern "C" void *func_8009D030(void *f) /* CdReadCallback */
{
    void *old = g_read_cb;
    g_read_cb = f;
    return old;
}

extern "C" int CdInit(void) { g_reading = 0; g_mode = 0; return g_image != 0; }
extern "C" int CdReset(int mode) { g_reading = 0; return 1; }
extern "C" void CdFlush(void) {}
extern "C" int CdMix(void *vol) { return 1; }
extern "C" int func_8009C9C0(void) { return status(); }   /* CdStatus */
extern "C" int func_8009C9D0(void) { return g_last_com; } /* CdLastCom */
extern "C" int func_8009C9E0(void) { return g_mode; }     /* CdMode */

static void read_sector(int lba)
{
    memset(g_sector, 0, RAW);
    if (g_image && !_fseeki64(g_image, (long long)lba * RAW, SEEK_SET))
        fread(g_sector, 1, RAW, g_image);
    /* CdGetSector starts at the header with CdlModeSize1, at the subheader with Size0, else at the data */
    g_cursor = (g_mode & ModeSize1) ? 12 : (g_mode & ModeSize0) ? 24 : 24;
}

/* called by port/intr.cpp with interrupts masked, on the game thread */
extern "C" void port_cd_poll(void)
{
    if (g_sync_pending) {
        g_sync_pending = 0;
        if (g_sync_cb) {
            unsigned char r[8];
            memcpy(r, g_result, sizeof r);
            g_sync_cb(CdlComplete, r);
        }
    }
    if (!g_reading)
        return;
    LARGE_INTEGER t, f;
    QueryPerformanceCounter(&t);
    QueryPerformanceFrequency(&f);
    int rate = (g_mode & ModeSpeed) ? 150 : 75;
    int due = (int)((t.QuadPart - g_read_t0) * rate / f.QuadPart) - g_read_sectors;
    for (int i = 0; i < due && i < 8 && g_reading; i++) {
        read_sector(g_next++);
        port_stat_cd_sectors++;
        g_read_sectors++;
        unsigned char r[8] = {(unsigned char)status()};
        if (g_ready_cb)
            g_ready_cb(CdlDataReady, r);
    }
}
