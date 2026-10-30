/* GPU glue. PsyCross draws each DrawOTag into the window's back buffer but presents it only in
   PsyX_EndScene, which its own libgpu never calls in a frame (games call it themselves). Koudelka flips
   with PutDispEnv + PutDrawEnv once a frame (func_8002D1E0, after VSync), so the frame drawn before the
   flip is ended and shown there. PsyCross's DrawOTag and PutDispEnv are renamed psyx_* (port/configure_port.py). */
#include "port_rt.h"

extern "C" {
struct DISPENV;
DISPENV *psyx_PutDispEnv(DISPENV *env);
void psyx_DrawOTag(unsigned long *p);
void PsyX_EndScene(void);
extern unsigned port_stat_frames, port_stat_flips;
}

extern "C" void DrawOTag(unsigned long *p)
{
    port_stat_frames++;
    psyx_DrawOTag(p);
}

extern "C" DISPENV *PutDispEnv(DISPENV *env)
{
    DISPENV *r = psyx_PutDispEnv(env);
    port_stat_flips++;
    PsyX_EndScene();
    return r;
}
