/* PC port entry point: replaces the PS1 `start` routine and the BIOS init (docs/PORT_PHASE2.md section 6),
   plus the port's log, its single stop path and the crash handler.

   koudelka.exe [--cd <disc 1 .bin>] [--no-window]
   The disc image can also come from KOUDELKA_CD; the default is baked in by port/configure_port.py. */
#include <windows.h>
#include <dbghelp.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_rt.h"
#include "port_config.h" /* PORT_DEFAULT_CD, written by port/configure_port.py */

extern "C" {
void PsyX_Initialise(char *windowName, int screenWidth, int screenHeight, int fullscreen);
void PsyX_CDFS_Init(const char *imageFileName, int track, int sectorSize);

/* game side (tools/port/gen_data.py, src/main) */
extern unsigned int D_800B4C08;          /* RAM-size word the heap init reads (0x180000 on the PS1) */
extern unsigned char D_800EA8A0[];       /* heap start, inside port_ram */
extern void (*D_80010000[])(void);       /* .ctors: one _GLOBAL_$I$ per C++ unit */
void func_80018B88(void);                /* heap init, called by `start` */
}
int game_main();                         /* src/main/u_8001949C.cpp `main`, renamed by -Dmain=game_main */

#ifndef PORT_DEFAULT_CD
#define PORT_DEFAULT_CD ""
#endif

static FILE *g_log;
static int g_stopping;

static void log_v(const char *fmt, va_list ap)
{
    va_list ap2;
    va_copy(ap2, ap);
    vfprintf(stderr, fmt, ap);
    if (g_log) {
        vfprintf(g_log, fmt, ap2);
        fflush(g_log);
    }
    va_end(ap2);
}

extern "C" void port_log(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    log_v(fmt, ap);
    va_end(ap);
}

extern "C" void port_log_once(const char *kind, const char *name)
{
    static const char *seen[1024];
    static int nseen;
    for (int i = 0; i < nseen; i++)
        if (seen[i] == name || !strcmp(seen[i], name))
            return;
    if (nseen < 1024)
        seen[nseen++] = name;
    port_log("%s: %s\n", kind, name);
}

extern "C" unsigned int port_host_to_ps1(const void *p)
{
    unsigned int a = (unsigned int)p, b = (unsigned int)port_ram;
    return a >= b && a < b + PORT_RAM_SIZE ? PORT_RAM_PS1 + (a - b) : 0;
}

/* ---- symbols ---------------------------------------------------------------------------------------- */
struct Ps1Sym { unsigned int addr; char name[60]; };
static Ps1Sym *g_ps1syms;
static int g_nps1syms = -1;

static void exe_dir_file(char *out, int n, const char *name)
{
    GetModuleFileNameA(NULL, out, n);
    char *s = strrchr(out, '\\');
    snprintf(s ? s + 1 : out, n - (s ? (int)(s + 1 - out) : 0), "%s", name);
}

extern "C" const char *port_ps1_symbol(unsigned int addr, char *buf, int n)
{
    buf[0] = 0;
    if (g_nps1syms < 0) {
        char path[MAX_PATH];
        exe_dir_file(path, MAX_PATH, "ps1_syms.txt");
        FILE *f = fopen(path, "r");
        g_nps1syms = 0;
        if (f) {
            int cap = 1 << 14;
            g_ps1syms = (Ps1Sym *)malloc(cap * sizeof(Ps1Sym));
            Ps1Sym s;
            while (g_nps1syms < cap && fscanf(f, "%x %59s", &s.addr, s.name) == 2)
                g_ps1syms[g_nps1syms++] = s;
            fclose(f);
        }
    }
    const Ps1Sym *best = NULL;
    for (int i = 0; i < g_nps1syms; i++)  /* the file lists overlays' symbols too, so several may match */
        if (g_ps1syms[i].addr <= addr && (!best || g_ps1syms[i].addr > best->addr))
            best = &g_ps1syms[i];
    if (best) {
        int k = 0;
        for (int i = 0; i < g_nps1syms && k < n - 64; i++)
            if (g_ps1syms[i].addr == best->addr)
                k += snprintf(buf + k, n - k, "%s%s", k ? "/" : "(", g_ps1syms[i].name);
        snprintf(buf + k, n - k, "+0x%X)", addr - best->addr);
    }
    return buf;
}

static void log_address(const char *prefix, DWORD64 addr)
{
    HANDLE proc = GetCurrentProcess();
    char buf[sizeof(SYMBOL_INFO) + 256];
    SYMBOL_INFO *si = (SYMBOL_INFO *)buf;
    si->SizeOfStruct = sizeof(SYMBOL_INFO);
    si->MaxNameLen = 255;
    DWORD64 disp = 0;
    IMAGEHLP_LINE64 line = {sizeof(line)};
    DWORD ldisp = 0;
    if (SymFromAddr(proc, addr, &disp, si)) {
        if (SymGetLineFromAddr64(proc, addr, &ldisp, &line))
            port_log("%s%08X %s+0x%X (%s:%u)\n", prefix, (unsigned)addr, si->Name, (unsigned)disp, line.FileName,
                     (unsigned)line.LineNumber);
        else
            port_log("%s%08X %s+0x%X\n", prefix, (unsigned)addr, si->Name, (unsigned)disp);
    } else {
        port_log("%s%08X\n", prefix, (unsigned)addr);
    }
}

static void log_stack(CONTEXT *ctx)
{
    HANDLE proc = GetCurrentProcess(), thread = GetCurrentThread();
    STACKFRAME64 sf = {};
    sf.AddrPC.Offset = ctx->Eip;
    sf.AddrFrame.Offset = ctx->Ebp;
    sf.AddrStack.Offset = ctx->Esp;
    sf.AddrPC.Mode = sf.AddrFrame.Mode = sf.AddrStack.Mode = AddrModeFlat;
    port_log("stack:\n");
    for (int i = 0; i < 48; i++) {
        if (!StackWalk64(IMAGE_FILE_MACHINE_I386, proc, thread, &sf, ctx, NULL, SymFunctionTableAccess64,
                         SymGetModuleBase64, NULL) || !sf.AddrPC.Offset)
            break;
        log_address("  ", sf.AddrPC.Offset);
    }
}

extern "C" __declspec(noreturn) void port_stop(const char *kind, const char *fmt, ...)
{
    va_list ap;
    if (g_stopping++)
        ExitProcess(3);
    port_log("STOP %s: ", kind);
    va_start(ap, fmt);
    log_v(fmt, ap);
    va_end(ap);
    port_log("\n");
    CONTEXT ctx;
    RtlCaptureContext(&ctx);
    log_stack(&ctx);
    if (g_log)
        fclose(g_log);
    ExitProcess(2);
}

/* the generated stubs (build/port/stubs/stubs.s) land here */
extern "C" __declspec(noreturn) void port_stub_hit(const char *kind, const char *name, unsigned int caller)
{
    char cbuf[512];
    HANDLE proc = GetCurrentProcess();
    char buf[sizeof(SYMBOL_INFO) + 256];
    SYMBOL_INFO *si = (SYMBOL_INFO *)buf;
    si->SizeOfStruct = sizeof(SYMBOL_INFO);
    si->MaxNameLen = 255;
    DWORD64 disp = 0;
    if (SymFromAddr(proc, caller, &disp, si))
        snprintf(cbuf, sizeof cbuf, "%s+0x%X", si->Name, (unsigned)disp);
    else
        snprintf(cbuf, sizeof cbuf, "%08X", caller);
    port_stop(kind, "%s (called from %s)", name, cbuf);
}

static LONG WINAPI on_crash(EXCEPTION_POINTERS *ep)
{
    EXCEPTION_RECORD *er = ep->ExceptionRecord;
    char sym[256];
    if (g_stopping++)
        ExitProcess(3);
    unsigned int pc = (unsigned int)(size_t)er->ExceptionAddress;
    if (er->ExceptionCode == EXCEPTION_ACCESS_VIOLATION && er->NumberParameters >= 2) {
        unsigned int op = (unsigned int)er->ExceptionInformation[0], a = (unsigned int)er->ExceptionInformation[1];
        const char *what = op == 0 ? "read" : op == 1 ? "write" : "execute";
        unsigned int ps1 = port_host_to_ps1((void *)(size_t)a);
        if (op == 8 && ps1 >= PORT_HIRAM_PS1)
            port_log("STOP overlay: executed the overlay/heap area at PS1 %08X %s\n", ps1,
                     port_ps1_symbol(ps1, sym, sizeof sym));
        else if (a >= 0x80000000u)
            port_log("STOP fault: %s of PS1 address %08X %s at %08X\n", what, a, port_ps1_symbol(a, sym, sizeof sym), pc);
        else if (a >= 0x1F800000u && a < 0x1FC00000u)
            port_log("STOP hardware: %s of PS1 I/O/scratchpad address %08X at %08X\n", what, a, pc);
        else
            port_log("STOP fault: %s of %08X at %08X\n", what, a, pc);
    } else {
        port_log("STOP fault: exception %08X at %08X\n", (unsigned)er->ExceptionCode, pc);
    }
    log_address("at ", pc);
    CONTEXT ctx = *ep->ContextRecord;
    log_stack(&ctx);
    if (g_log)
        fclose(g_log);
    ExitProcess(2);
}

/* ---- C runtime pieces the PS1 build got from PsyQ ---------------------------------------------------- */
#define N_CTORS 27  /* `__main` walks 0x1B entries of .ctors at D_80010000 */

extern "C" void __main(void)
{
    static int done;
    if (done)
        return;
    done = 1;
    for (int i = 0; i < N_CTORS; i++)
        if (D_80010000[i])
            D_80010000[i]();
}

/* ---- entry ------------------------------------------------------------------------------------------- */
int main(int argc, char **argv)
{
    char path[MAX_PATH];
    exe_dir_file(path, MAX_PATH, "koudelka-port.log");
    g_log = fopen(path, "w");
    SetUnhandledExceptionFilter(on_crash);
    SymSetOptions(SYMOPT_LOAD_LINES | SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
    SymInitialize(GetCurrentProcess(), NULL, TRUE);

    const char *cd = getenv("KOUDELKA_CD");
    int window = 1;
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--cd") && i + 1 < argc)
            cd = argv[++i];
        else if (!strcmp(argv[i], "--no-window"))
            window = 0;
    }
    if (!cd || !*cd)
        cd = PORT_DEFAULT_CD;
    port_log("koudelka port, phase 2 (EXE only)\n");
    port_log("port RAM %08X = PS1 %08X, overlay area %08X = PS1 %08X\n", (unsigned)port_ram, PORT_RAM_PS1,
             (unsigned)port_hiram, PORT_HIRAM_PS1);
    /* The game's ordering tables hold 24-bit addresses (P_TAG addr:24), and PsyCross is built with the PS1
       layout. That needs every primitive below 16 MB: port RAM (game heap) and this thread's stack. */
    if ((unsigned)port_ram + PORT_RAM_SIZE > 0x01000000u || (unsigned)&argc > 0x01000000u)
        port_stop("layout", "port RAM %08X or the stack %08X is above 16 MB: 24-bit OT pointers would break",
                  (unsigned)port_ram, (unsigned)&argc);

    if (window) {
        PsyX_Initialise((char *)"Koudelka", 640, 480, 0);
        SetUnhandledExceptionFilter(on_crash);  /* PsyX_Initialise installs its own (minidump) handler */
    }
    if (cd && *cd) {
        port_log("CD image: %s\n", cd);
        PsyX_CDFS_Init(cd, 0, 0);
    } else {
        port_log("no CD image (--cd or KOUDELKA_CD)\n");
    }

    /* start: the heap runs from &D_800EA8A0 to PS1 0x80200000, as on the PS1. func_80018B88 computes its
       size as (D_800B4C08 - 0x7FF80000 - (int)&D_800EA8A0) & ~7, so set the word to give that size for
       the host address. The only patch to game data. */
    unsigned int heap = (unsigned int)port_ram + PORT_RAM_SIZE - (unsigned int)D_800EA8A0;
    port_log("heap: %u bytes at %08X (D_800B4C08 %08X -> %08X)\n", heap, (unsigned)D_800EA8A0, D_800B4C08,
             heap + 0x7FF80000u + (unsigned int)D_800EA8A0);
    D_800B4C08 = heap + 0x7FF80000u + (unsigned int)D_800EA8A0;
    func_80018B88();
    /* GCC's main() starts with a call to __main (the .ctors list). */
    __main();
    port_log("game main\n");
    int r = game_main();
    port_stop("returned", "main returned %d (the PS1 start routine executes break here)", r);
}
