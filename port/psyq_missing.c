/* PsyQ functions the EXE calls that PsyCross e56e4cd does not define (docs/PORT_FEASIBILITY.md section 1,
   confirmed by the probe link: build/port/stubs/stubs.txt). Each logs "psyq: <name> ..." on its first call.
   - "skipped": returns 0 / does nothing. Safe to skip for booting; the real behaviour is feasibility item 7-9.
   - "port": a small real implementation (fixed-point math, PS1-layout primitive setters).
   - stops: what cannot be skipped (stack switch, pure virtual call).
   Unnamed functions are named by address, with the identification from the feasibility study. */
#include <math.h>
#include "port_rt.h"

typedef struct { long vx, vy, vz, pad; } VECTOR;
typedef struct { short vx, vy, vz, pad; } SVECTOR;
typedef struct { short m[3][3]; long t[3]; } MATRIX;

/* PsyCross */
unsigned int CFC2(int reg);
void SetGeomScreen(int h);
void *CdReadCallback(void *func);

#define SKIP(name) port_log_once("psyq", name " (skipped)")
#define PORT(name) port_log_once("psyq", name " (port implementation)")

/* ---- kernel / libapi ---- */
/* EnterCriticalSection / ExitCriticalSection: port/intr.cpp */
/* SetSp: func_8001E360 moves the main task onto its own stack before running the scheduler. The host keeps
   running the main task on the host stack; the task stacks belong to the context switch (func_80018F0C etc.,
   feasibility item 6: Win32 fibers). */
void func_800949B0(void *sp) { port_log_once("psyq", "SetSp (func_800949B0) (skipped: the main task stays on the host stack)"); }

/* ---- libcd (the rest: port/cd.cpp) ---- */
void func_8009DDC0(int x) { SKIP("func_8009DDC0 (unidentified)"); }

/* ---- libspu / libsnd ---- */
unsigned long SpuSetNoiseClock(long n_clock) { SKIP("SpuSetNoiseClock"); return 0; }
unsigned long SpuSetNoiseVoice(long on_off, unsigned long voice_bit) { SKIP("SpuSetNoiseVoice"); return 0; }
unsigned long SpuSetPitchLFOVoice(long on_off, unsigned long voice_bit) { SKIP("SpuSetPitchLFOVoice"); return 0; }
void SpuSetReverbModeDelayTime(long delay) { SKIP("SpuSetReverbModeDelayTime"); }
void SpuSetReverbModeFeedback(long feedback) { SKIP("SpuSetReverbModeFeedback"); }
void SpuSetVoiceARAttr(int v, unsigned short ar, long arm) { SKIP("SpuSetVoiceARAttr"); }
void SpuSetVoiceSRAttr(int v, unsigned short sr, long srm) { SKIP("SpuSetVoiceSRAttr"); }
void SpuSetVoiceRRAttr(int v, unsigned short rr, long rrm) { SKIP("SpuSetVoiceRRAttr"); }
void SpuSetVoiceLoopStartAddr(int v, unsigned long addr) { SKIP("SpuSetVoiceLoopStartAddr"); }
void SsUtReverbOff(void) { SKIP("SsUtReverbOff"); }
void func_800A0A10(long *type) { SKIP("SpuGetReverbModeType (func_800A0A10)"); if (type) *type = 0; }
int func_800A1B9C(void) { SKIP("func_800A1B9C (unidentified)"); return 0; }

/* ---- libgpu: PS1 packet layout (tag word, then code word), as the game's own primitives use ---- */
void SetDrawOffset(unsigned int *p, unsigned short *ofs)
{
    PORT("SetDrawOffset");
    p[0] = (p[0] & 0x00FFFFFF) | (2u << 24);
    p[1] = 0xE5000000u | ((ofs[1] & 0x7FFu) << 11) | (ofs[0] & 0x7FFu);
    p[2] = 0;
}

void SetLineF2(unsigned char *p)
{
    PORT("SetLineF2");
    p[3] = 3;
    p[7] = 0x40;
}

/* ---- libgte ---- */
void func_80099C80(int h) { PORT("SetGeomScreen (func_80099C80)"); SetGeomScreen(h); }

long SquareRoot12(long a)
{
    PORT("SquareRoot12");
    return a <= 0 ? 0 : (long)sqrt((double)a * 4096.0);
}

void OuterProduct0(VECTOR *v0, VECTOR *v1, VECTOR *v2)
{
    PORT("OuterProduct0");
    long x = v0->vy * v1->vz - v0->vz * v1->vy;
    long y = v0->vz * v1->vx - v0->vx * v1->vz;
    long z = v0->vx * v1->vy - v0->vy * v1->vx;
    v2->vx = x, v2->vy = y, v2->vz = z;
}

long VectorNormalS(VECTOR *v0, SVECTOR *v1)
{
    PORT("VectorNormalS");
    double x = v0->vx, y = v0->vy, z = v0->vz, s = x * x + y * y + z * z;
    double l = sqrt(s);
    if (l == 0) l = 1;
    v1->vx = (short)(x * 4096.0 / l);
    v1->vy = (short)(y * 4096.0 / l);
    v1->vz = (short)(z * 4096.0 / l);
    return (long)s;
}

/* GTE control registers 8-12: the light matrix, two shorts per word */
MATRIX *ReadLightMatrix(MATRIX *m)
{
    short *d = &m->m[0][0];
    PORT("ReadLightMatrix");
    for (int i = 0; i < 4; i++) {
        unsigned int w = CFC2(8 + i);
        d[2 * i] = (short)w;
        d[2 * i + 1] = (short)(w >> 16);
    }
    d[8] = (short)CFC2(12);
    return m;
}

/* v1 = R * v0 >> 12 + TR, with 32-bit input (GTE control registers 0-4 rotation, 5-7 translation) */
void TransRot_32(VECTOR *v0, VECTOR *v1, long *flag)
{
    short r[9];
    PORT("TransRot_32");
    for (int i = 0; i < 4; i++) {
        unsigned int w = CFC2(i);
        r[2 * i] = (short)w;
        r[2 * i + 1] = (short)(w >> 16);
    }
    r[8] = (short)CFC2(4);
    long long in[3] = {v0->vx, v0->vy, v0->vz};
    long *out = &v1->vx;
    for (int i = 0; i < 3; i++)
        out[i] = (long)((r[3 * i] * in[0] + r[3 * i + 1] * in[1] + r[3 * i + 2] * in[2]) >> 12) + (long)CFC2(5 + i);
    if (flag)
        *flag = 0;
}

/* ---- libc / libgcc ---- */
long long __divdi3(long long a, long long b)
{
    return b == 0 ? 0 : a / b;
}

/* memcmp-like byte compare without a NUL check (unnamed; its only caller is func_80077854) */
int func_80094E50(const unsigned char *a, const unsigned char *b, int n)
{
    for (;;) {
        if (*a != *b)
            return *a - *b;
        a++, b++;
        if (--n <= 0)
            return 0;
    }
}

/* `break 0` in libgcc: the pure-virtual slot of the game's GCC 2.x vtables */
void func_800A0BA0(void) { port_stop("psyq", "pure virtual function called (func_800A0BA0, break 0)"); }
