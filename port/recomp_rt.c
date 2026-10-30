/* Traps and hooks for the recompiled EXE functions (tools/recomp/runtime/recomp.h). */
#include "port_rt.h"

typedef unsigned int u32;

__declspec(noreturn) void recomp_unsupported(const char *func, const char *why)
{
    port_stop("unimplemented", "%s (recompiler stub: %s)", func, why);
}

void recomp_break(const char *func, u32 code, u32 vaddr)
{
    /* break 6/7: the compiler's divide-by-zero / overflow checks. The PS1 has no handler installed for
       them in this game, so execution goes on with the R3000 result. */
    if (code == 6 || code == 7) {
        port_log_once("divide check", func);
        return;
    }
    port_stop("break", "%s: break %u at %08X", func, code, vaddr);
}

__declspec(noreturn) void recomp_bad_jump(const char *func, u32 vaddr, u32 value)
{
    port_stop("bad-jump", "%s: jump table at %08X: value %u has no case", func, vaddr, value);
}

__declspec(noreturn) void recomp_stack_overflow(const char *func)
{
    port_stop("stack", "%s: alloca beyond the frame's reserve", func);
}

u32 recomp_hw_address(const char *func, u32 addr)
{
    port_stop("hardware", "%s: PS1 I/O address %08X", func, addr);
}

/* RECOMP_ICALL_TARGET: indirect calls from recompiled code. */
u32 port_icall_target(u32 x)
{
    char sym[128];
    if (x == 0)
        port_stop("null-call", "indirect call through a null pointer");
    if (x >= 0x80000000u)
        port_stop("ps1-address", "indirect call to PS1 address %08X %s", x, port_ps1_symbol(x, sym, sizeof sym));
    if (x >= (u32)port_hiram && x < (u32)port_ram + PORT_RAM_SIZE) {
        u32 a = port_host_to_ps1((const void *)x);
        port_stop("overlay", "call into the overlay/heap area at PS1 %08X %s", a, port_ps1_symbol(a, sym, sizeof sym));
    }
    return x;
}
