/* Seeing what a run does without a debugger: a heartbeat line in the log every 5 s (vblanks, task
   switches, CD commands and sectors), and with KOUDELKA_SHOT=<seconds>[,<seconds>...], at those times, the
   window (shot-<s>.bmp) and PsyCross's VRAM (vram-<s>.bmp, 1024x512) written next to the exe. Called from
   port_interrupts on the game thread. */
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "port_rt.h"

extern unsigned short vram[1024 * 512];  /* PsyCross, PsyX_render.cpp */

extern "C" {
unsigned port_stat_vblanks, port_stat_switches, port_stat_cd_commands, port_stat_cd_sectors, port_stat_frames,
    port_stat_flips;
}

static void write_bmp(const char *name, int w, int h, const unsigned *rgb)
{
    char path[MAX_PATH];
    GetModuleFileNameA(NULL, path, MAX_PATH);
    char *s = strrchr(path, '\\');
    snprintf(s ? s + 1 : path, MAX_PATH - (s ? (int)(s + 1 - path) : 0), "%s", name);
    FILE *f = fopen(path, "wb");
    if (!f)
        return;
    BITMAPFILEHEADER fh = {};
    BITMAPINFOHEADER ih = {};
    fh.bfType = 0x4D42;
    fh.bfOffBits = sizeof fh + sizeof ih;
    fh.bfSize = fh.bfOffBits + w * h * 4;
    ih.biSize = sizeof ih, ih.biWidth = w, ih.biHeight = -h, ih.biPlanes = 1, ih.biBitCount = 32;
    fwrite(&fh, sizeof fh, 1, f);
    fwrite(&ih, sizeof ih, 1, f);
    fwrite(rgb, 4, (size_t)w * h, f);
    fclose(f);
    port_log("observe: wrote %s\n", path);
}

static BOOL CALLBACK find_window(HWND w, LPARAM out)
{
    DWORD pid;
    GetWindowThreadProcessId(w, &pid);
    if (pid == GetCurrentProcessId() && IsWindowVisible(w)) {
        *(HWND *)out = w;
        return FALSE;
    }
    return TRUE;
}

static void shots(unsigned sec)
{
    char name[32];
    static unsigned px[1024 * 512];
    for (int i = 0; i < 1024 * 512; i++) {  /* PS1 15-bit BGR */
        unsigned v = vram[i];
        unsigned r = (v & 31) << 3, g = ((v >> 5) & 31) << 3, b = ((v >> 10) & 31) << 3;
        px[i] = r << 16 | g << 8 | b;
    }
    snprintf(name, sizeof name, "vram-%u.bmp", sec);
    write_bmp(name, 1024, 512, px);
    HWND w = 0;
    EnumWindows(find_window, (LPARAM)&w);
    if (!w)
        return;
    RECT rc;
    GetClientRect(w, &rc);
    int cw = rc.right, ch = rc.bottom;
    HDC wdc = GetDC(w), mdc = CreateCompatibleDC(wdc);
    HBITMAP bm = CreateCompatibleBitmap(wdc, cw, ch);
    SelectObject(mdc, bm);
    PrintWindow(w, mdc, 2 /* PW_RENDERFULLCONTENT */);
    unsigned *buf = (unsigned *)malloc((size_t)cw * ch * 4);
    BITMAPINFO bi = {};
    bi.bmiHeader.biSize = sizeof bi.bmiHeader, bi.bmiHeader.biWidth = cw, bi.bmiHeader.biHeight = -ch;
    bi.bmiHeader.biPlanes = 1, bi.bmiHeader.biBitCount = 32;
    GetDIBits(mdc, bm, 0, ch, buf, &bi, DIB_RGB_COLORS);
    snprintf(name, sizeof name, "shot-%u.bmp", sec);
    write_bmp(name, cw, ch, buf);
    free(buf);
    DeleteObject(bm);
    DeleteDC(mdc);
    ReleaseDC(w, wdc);
}

/* At a fault (port/main.cpp): the main loop's per-frame handler lists (func_8001D3A8 runs D_800A4544 and
   D_800A4544+8; a node is {vtable, next, target, priority, owns}) with each target's vtable. */
extern "C" void port_dump_state(void)
{
    extern unsigned char D_800A4544[];
    for (int l = 0; l < 2; l++) {
        unsigned char *n = *(unsigned char **)(D_800A4544 + 8 * l + 4);
        port_log("per-frame list %d:", l);
        for (int k = 0; n && k < 64; k++, n = *(unsigned char **)(n + 4)) {
            unsigned char *t = *(unsigned char **)(n + 8);
            port_log(" [node %p target %p vt %p]", n, t, t ? *(void **)t : 0);
        }
        port_log("\n");
    }
}

extern "C" void port_observe(void)
{
    static ULONGLONG t0, next = 5000;
    static const char *shot_list;  /* the next of KOUDELKA_SHOT's times */
    if (!t0) {
        t0 = GetTickCount64();
        shot_list = getenv("KOUDELKA_SHOT");
    }
    ULONGLONG t = GetTickCount64() - t0;
    if (t >= next) {
        port_log("heartbeat %llus: vblanks %u, task switches %u, ordering tables %u, flips %u, cd commands %u, "
                 "cd sectors %u\n", t / 1000, port_stat_vblanks, port_stat_switches, port_stat_frames, port_stat_flips,
                 port_stat_cd_commands, port_stat_cd_sectors);
        next += 5000;
    }
    if (shot_list && *shot_list && t >= (ULONGLONG)atoi(shot_list) * 1000) {
        shots((unsigned)atoi(shot_list));
        shot_list = strchr(shot_list, ',');
        shot_list = shot_list ? shot_list + 1 : 0;
    }
}
