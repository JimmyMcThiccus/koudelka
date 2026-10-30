/* Interrupts and critical sections.

   On the PS1 the VSync interrupt stops the CPU, runs the game's callback to completion and returns, and
   EnterCriticalSection/ExitCriticalSection mask it. PsyCross instead calls the callback from its own thread,
   in parallel with the game, so the game could see a list half way through an update the PS1 would show
   only whole. Here PsyCross's thread only counts vblanks, and the game's callback runs on the game thread
   at the points where a PS1 interrupt could be taken: when interrupts are unmasked again
   (ExitCriticalSection), after VSync, and at task switches (port/fibers.cpp). PsyCross's VSyncCallback and
   VSync are renamed psyx_* when it is compiled (port/configure_port.py), so these take the game's calls.
   Like the kernel calls, Enter/Exit do not nest; the game counts nesting itself (D_800B4BFC). */
#include "port_rt.h"

/* no <windows.h>: it declares EnterCriticalSection(CRITICAL_SECTION *) */
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(void);

extern "C" {
int psyx_VSyncCallback(void (*f)(void));
int psyx_VSync(int mode);
}

static void (*g_vsync)(void);       /* the game's callback */
static volatile long g_pending;     /* vblanks not delivered yet */
static bool g_masked, g_in_irq;
static unsigned long g_game_thread;

static void tick(void)  /* PsyCross's interrupt thread */
{
    __atomic_add_fetch(&g_pending, 1, __ATOMIC_SEQ_CST);
}

extern "C" void port_interrupts(void)
{
    if (g_masked || g_in_irq || GetCurrentThreadId() != g_game_thread)
        return;
    while (__atomic_load_n(&g_pending, __ATOMIC_SEQ_CST) > 0) {
        __atomic_sub_fetch(&g_pending, 1, __ATOMIC_SEQ_CST);
        if (!g_vsync)
            continue;
        g_in_irq = true;
        g_vsync();
        g_in_irq = false;
    }
}

extern "C" void port_interrupts_init(void)
{
    g_game_thread = GetCurrentThreadId();
}

extern "C" int VSyncCallback(void (*f)(void))
{
    void (*old)(void) = g_vsync;
    g_vsync = f;
    __atomic_store_n(&g_pending, 0, __ATOMIC_SEQ_CST);
    psyx_VSyncCallback(f ? tick : 0);
    return (int)(size_t)old;
}

extern "C" int VSync(int mode)
{
    int r = psyx_VSync(mode);
    port_interrupts();
    return r;
}

extern "C" void EnterCriticalSection(void)
{
    if (!g_in_irq)
        g_masked = true;
}

extern "C" void ExitCriticalSection(void)
{
    if (g_in_irq)
        return;  /* a callback leaves the mask as it found it */
    g_masked = false;
    port_interrupts();
}
