/* Pads. Port 1 holds a digital pad, as on a PS1 with a controller plugged in. PsyCross maps the keyboard to
   pad 1 (and an SDL game controller when one is present), but reports the port disconnected
   (PadGetState) and leaves the buffer's status byte alone unless a game controller is attached; the game's
   poller (func_80023450) then ignores the pad. PsyCross's versions are renamed psyx_* at compile time.

   For unattended runs, KOUDELKA_PRESS=<vblank>:<button>[,...] holds a button for 4 vblanks from that vblank,
   e.g. KOUDELKA_PRESS=1300:start,1400:cross. Buttons: select start up right down left l2 r2 l1 r1 triangle
   circle cross square. */
#include <stdlib.h>
#include <string.h>
#include "port_rt.h"

extern "C" {
void psyx_PadInitDirect(unsigned char *pad1, unsigned char *pad2);
int psyx_PadGetState(int port);
unsigned char *port_pad1;  /* pad 1's buffer: status, id, buttons (active low) */
}

enum { PadStateStable = 6, HOLD = 4 };

extern "C" void PadInitDirect(unsigned char *pad1, unsigned char *pad2)
{
    port_pad1 = pad1;
    psyx_PadInitDirect(pad1, pad2);
    if (pad1)
        pad1[0] = 0;  /* status: OK */
}

extern "C" int PadGetState(int port)
{
    if ((port & 0xF3) == 0x00)  /* port 1, no multitap */
        return PadStateStable;
    return psyx_PadGetState(port);
}

/* PadChkVsync (func_800A1B9C, libpad): whether the pads were read since the last call. The game's poller
   (func_80023450) takes a frame's buttons only after a read; PsyCross updates the buffer at every vblank. */
static bool g_read;

extern "C" int func_800A1B9C(void)
{
    bool r = g_read;
    g_read = false;
    return r;
}

static const char *const g_names[16] = {"select", "l3", "r3", "start", "up", "right", "down", "left",
                                        "l2", "r2", "l1", "r1", "triangle", "circle", "cross", "square"};
static struct { unsigned at, mask; } g_script[64];
static int g_count = -1, g_next;
static bool g_holding;

static void parse(void)
{
    g_count = 0;
    const char *e = getenv("KOUDELKA_PRESS");
    while (e && *e && g_count < 64) {
        char *end;
        unsigned at = strtoul(e, &end, 10);
        if (*end != ':')
            break;
        const char *b = end + 1;
        size_t n = strcspn(b, ",");
        for (int i = 0; i < 16; i++)
            if (strlen(g_names[i]) == n && !strncmp(b, g_names[i], n))
                g_script[g_count].at = at, g_script[g_count++].mask = 1u << i;
        e = b[n] ? b + n + 1 : b + n;
    }
}

/* each vblank, before the game's VSync callback polls the pad (port/intr.cpp) */
extern "C" void port_pad_vblank(unsigned n)
{
    if (g_count < 0)
        parse();
    if (!port_pad1)
        return;
    g_read = true;
    while (g_next < g_count && g_script[g_next].at + HOLD <= n)
        g_next++, g_holding = false;
    unsigned short buttons = 0xFFFF;
    if (g_next < g_count && g_script[g_next].at <= n) {
        buttons = (unsigned short)~g_script[g_next].mask;
        if (!g_holding)
            port_log("pad: %s at vblank %u\n", g_names[__builtin_ctz(g_script[g_next].mask)], n);
        g_holding = true;
    } else if (!g_holding && g_next == 0) {
        return;  /* nothing scripted yet: leave the keyboard's state */
    }
    port_pad1[2] = (unsigned char)buttons;
    port_pad1[3] = (unsigned char)(buttons >> 8);
}
