/* Differential test runner: calls a decompiled function (the game's C++ built
   natively) and its recompiled twin (tools/recomp output) on the same random
   arguments and memory, and compares the return value and every byte either
   one could have written.

   usage: difftest.exe <case index | first:end | -1 for all> <trials> <seed> [-v]
   prints one line per case:
   RESULT <name> trials=<n> ok=<n> both_fault=<n> decomp_only_fault=<n> recomp_only_read_fault=<n>
          skipped=<n> mismatch=<n>

   Memory model: a 64 KB arena of random words (mostly arena pointers and small
   integers) plus the whole globals area (every global either build references,
   laid out at its PS1 address offset by the generated globals.s). Both are
   refilled before each trial, restored between the two calls and compared
   afterwards. Arguments are drawn per parameter type. Faults are caught with
   SEH; a watchdog thread turns a hang into an exception. Non-leaf functions
   call the same native callees from both builds. */
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "difftest.h"

extern u8 recomp_globals_start[], recomp_globals_end[];
#define GLOBALS_SIZE ((u32)(recomp_globals_end - recomp_globals_start))

#define ARENA_SIZE 0x10000
#define ARENA_GUARD 0x2000000
#define MAXARGS 26
#define EXC_HANG 0xE0000002u
#define EXC_BREAK 0xE0000007u
#define EXC_TRAP 0xE0000009u

static u8 *arena;
static u32 rng_state;

static u32 rnd(void) {
    u32 x = rng_state;
    x ^= x << 13; x ^= x >> 17; x ^= x << 5;
    return rng_state = x;
}

/* ---- runtime the recompiled code links against --------------------------- */

void recomp_unsupported(const char *f, const char *why) {
    (void)f; (void)why;
    RaiseException(EXC_TRAP, 0, 0, NULL);
    for (;;) {}
}
void recomp_break(const char *f, u32 code, u32 va) {
    (void)f; (void)code; (void)va;
    RaiseException(EXC_BREAK, 0, 0, NULL);
}
void recomp_bad_jump(const char *f, u32 va, u32 x) {
    (void)f; (void)va; (void)x;
    RaiseException(EXC_TRAP, 0, 0, NULL);
    for (;;) {}
}
void recomp_stack_overflow(const char *f) {
    (void)f;
    RaiseException(EXC_TRAP, 0, 0, NULL);
    for (;;) {}
}
u32 recomp_hw_address(const char *f, u32 a) {
    (void)f;
    RaiseException(EXC_TRAP, 0, 0, NULL);
    return a;
}

/* ---- hang watchdog --------------------------------------------------------- */
static HANDLE main_thread;
static volatile LONG armed;
static volatile DWORD deadline;

static __declspec(noinline) void hang_raise(void) {
    RaiseException(EXC_HANG, 0, 0, NULL);
}

static DWORD WINAPI watchdog(LPVOID unused) {
    (void)unused;
    for (;;) {
        Sleep(20);
        if (!armed || (LONG)(GetTickCount() - deadline) < 0)
            continue;
        SuspendThread(main_thread);
        if (armed) {
            CONTEXT ctx;
            ctx.ContextFlags = CONTEXT_CONTROL;
            GetThreadContext(main_thread, &ctx);
            ctx.Esp -= 4;
            *(u32 *)ctx.Esp = 0;
            ctx.Eip = (DWORD)(size_t)hang_raise;
            SetThreadContext(main_thread, &ctx);
            armed = 0;
        }
        ResumeThread(main_thread);
    }
}

typedef u64 (*fn_t)(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, u32,
                    u32, u32, u32, u32, u32, u32, u32, u32);

static int filter(EXCEPTION_POINTERS *ep, DWORD *out, int *write) {
    *out = ep->ExceptionRecord->ExceptionCode;
    *write = *out == EXCEPTION_ACCESS_VIOLATION && ep->ExceptionRecord->NumberParameters > 0 &&
             ep->ExceptionRecord->ExceptionInformation[0] != 0;
    return EXCEPTION_EXECUTE_HANDLER;
}

/* 0 = returned, else the exception code; *write is set for an access violation on a store */
static DWORD call_guarded(void *fn, const u32 *a, u64 *ret, int *write, u32 seed) {
    DWORD code = 0;
    *write = 0;
    srand(seed); /* native callees may use the CRT's rand() */
    __try {
        deadline = GetTickCount() + 150;
        armed = 1;
        *ret = ((fn_t)fn)(a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10], a[11], a[12], a[13],
                          a[14], a[15], a[16], a[17], a[18], a[19], a[20], a[21], a[22], a[23], a[24], a[25]);
        armed = 0;
    } __except (filter(GetExceptionInformation(), &code, write)) {
        armed = 0;
    }
    return code;
}

/* ---- random state ----------------------------------------------------------- */
static u32 arena_ptr(void) {
    u32 off = rnd() % (ARENA_SIZE / 2);
    if ((rnd() & 7) != 0)
        off &= ~3u;
    return (u32)(size_t)arena + off;
}

static u32 rand_word(void) {
    u32 r = rnd() % 100;
    if (r < 35) return arena_ptr();
    if (r < 60) return rnd() % 16;
    if (r < 72) return 0;
    if (r < 85) return rnd() & 0xFFFF;
    if (r < 92) return (u32)-(int)(rnd() % 16 + 1);
    return rnd() | 0x80000000u; /* above 2 GB: never mapped in this (not large-address-aware) process */
}

static void fill(u8 *p, u32 n) {
    u32 i;
    for (i = 0; i + 4 <= n; i += 4) {
        u32 w = rand_word();
        memcpy(p + i, &w, 4);
    }
}

static u32 rand_int(void) {
    u32 r = rnd() % 100;
    if (r < 40) return rnd() % 16;
    if (r < 60) return rnd() % 256;
    if (r < 75) return rnd() & 0xFFFF;
    if (r < 85) return (u32)-(int)(rnd() % 16 + 1);
    if (r < 90) return 0;
    return rnd() | 0x80000000u;
}

/* pointer arguments get separate 12 KB slices of the arena so that two of them
   rarely overlap (overlapping copies are undefined in C and differ by compiler) */
static u32 arg_ptr(int slot) {
    u32 off = (u32)(slot & 3) * 0x3000 + rnd() % 0x2000;
    if ((rnd() & 7) != 0)
        off &= ~3u;
    return (u32)(size_t)arena + off;
}

static u32 gen_arg(char k, int slot) {
    switch (k) {
    case 'p': return (rnd() % 16) ? arg_ptr(slot) : 0;
    case 'c': return (u32)(int)(signed char)rand_int();
    case 'C': return rand_int() & 0xFF;
    case 's': return (u32)(int)(short)rand_int();
    case 'S': return rand_int() & 0xFFFF;
    case 'b': return rnd() & 1;
    default: return rand_int();
    }
}

/* snapshot buffers: arena followed by the globals area */
static u8 *snap_init, *snap_a, *snap_now;

static u32 state_size(void) {
    return ARENA_SIZE + GLOBALS_SIZE;
}

/* Snapshots are read-only while the functions run, so a wild store (a random index far past the arena)
   faults in both builds instead of corrupting the state the second run starts from. */
static u8 *snap_alloc(u32 n) {
    return (u8 *)VirtualAlloc(NULL, n, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
}

static void protect(u8 *p, u32 n, int ro) {
    DWORD old;
    VirtualProtect(p, n, ro ? PAGE_READONLY : PAGE_READWRITE, &old);
}

static void save(u8 *dst) {
    memcpy(dst, arena, ARENA_SIZE);
    memcpy(dst + ARENA_SIZE, recomp_globals_start, GLOBALS_SIZE);
}

static void restore(const u8 *src) {
    memcpy(arena, src, ARENA_SIZE);
    memcpy(recomp_globals_start, src + ARENA_SIZE, GLOBALS_SIZE);
}

static u64 ret_mask(int bits) {
    return bits >= 64 ? ~0ull : bits == 0 ? 0 : ((1ull << bits) - 1);
}

static int verbose;

static void run_case(int ci, int trials, u32 seed) {
    const Case *c = &cases[ci];
    u32 ssize = state_size();
    int t, ok = 0, both = 0, skipped = 0, bad = 0, dfault = 0, rfault = 0;
    snap_init = snap_alloc(ssize);
    snap_a = snap_alloc(ssize);
    snap_now = snap_alloc(ssize);
    for (t = 0; t < trials; t++) {
        u32 a[MAXARGS];
        u64 rd = 0, rr = 0;
        DWORD ed, er;
        int wd, wr;
        u32 crt_seed;
        int i;
        rng_state = seed * 2654435761u ^ (u32)ci * 40503u ^ (u32)t * 69069u ^ 0x9E3779B9u;
        if (!rng_state) rng_state = 1;
        for (i = 0; i < 8; i++) rnd();
        fill(arena, ARENA_SIZE);
        fill(recomp_globals_start, GLOBALS_SIZE);
        for (i = 0; i < MAXARGS; i++) a[i] = i < c->nargs ? gen_arg(c->argkinds[i], i) : 0;
        crt_seed = rnd();
        /* all three snapshots are read-only during both calls, so the two runs see the same address space */
        save(snap_init);
        protect(snap_init, ssize, 1);
        protect(snap_a, ssize, 1);
        protect(snap_now, ssize, 1);
        ed = call_guarded(c->decomp, a, &rd, &wd, crt_seed);
        protect(snap_a, ssize, 0);
        save(snap_a);
        protect(snap_a, ssize, 1);
        restore(snap_init);
        er = call_guarded(c->recomp, a, &rr, &wr, crt_seed);
        protect(snap_init, ssize, 0);
        protect(snap_a, ssize, 0);
        protect(snap_now, ssize, 0);
        if (ed == EXC_HANG) { skipped++; continue; }
        if (ed || er) {
            /* both faulted (memory is not compared: the fault point differs) */
            if (ed && er) { both++; continue; }
            /* Only one build faulted, on a load or a divide. Either compiler may drop a load whose
               value is dead (clang on the recompiled C, or on the decompiled C after inlining a
               callee), and the R3000 does not trap on x/0. On a PS1 such a load reads RAM, so
               this is not a behaviour difference; it is reported apart. A one-sided fault on a
               store, or any other exception, is a mismatch. */
            if (ed && !er && ((ed == EXCEPTION_ACCESS_VIOLATION && !wd) || ed == EXCEPTION_INT_DIVIDE_BY_ZERO ||
                              ed == EXCEPTION_INT_OVERFLOW)) {
                dfault++;
                continue;
            }
            if (er && !ed && er == EXCEPTION_ACCESS_VIOLATION && !wr) {
                rfault++;
                continue;
            }
            bad++;
            if (verbose || bad <= 3)
                printf("  MISMATCH %s trial %d: fault decomp=%08lX recomp=%08lX args=%08X %08X %08X %08X\n",
                       c->name, t, ed, er, a[0], a[1], a[2], a[3]);
            continue;
        }
        {
            u64 m = ret_mask(c->ret_bits);
            int rbad = (rd & m) != (rr & m);
            u32 o = 0;
            u8 *now = snap_now;
            int mbad;
            save(now);
            mbad = memcmp(now, snap_a, ssize) != 0;
            if (mbad)
                for (o = 0; o < ssize && now[o] == snap_a[o]; o++) {}
            if (rbad || mbad) {
                bad++;
                if (verbose || bad <= 3) {
                    printf("  MISMATCH %s trial %d: ret decomp=%llX recomp=%llX", c->name, t, rd & m, rr & m);
                    if (mbad)
                        printf(" mem@%s+0x%X decomp=%02X recomp=%02X", o < ARENA_SIZE ? "arena" : "globals",
                               o < ARENA_SIZE ? o : o - ARENA_SIZE, snap_a[o], now[o]);
                    printf(" args=%08X %08X %08X %08X\n", a[0], a[1], a[2], a[3]);
                }
            } else {
                ok++;
            }
        }
    }
    printf("RESULT %s trials=%d ok=%d both_fault=%d decomp_only_fault=%d recomp_only_read_fault=%d skipped=%d "
           "mismatch=%d\n", c->name, trials, ok, both, dfault, rfault, skipped, bad);
    fflush(stdout);
    VirtualFree(snap_init, 0, MEM_RELEASE);
    VirtualFree(snap_a, 0, MEM_RELEASE);
    VirtualFree(snap_now, 0, MEM_RELEASE);
}

int main(int argc, char **argv) {
    /* "<i>", "<first>:<end>" or -1 for all */
    const char *sel = argc > 1 ? argv[1] : "-1";
    int first = atoi(sel), end = first + 1;
    int trials = argc > 2 ? atoi(argv[2]) : 1000;
    u32 seed = argc > 3 ? (u32)strtoul(argv[3], NULL, 0) : 1;
    int i;
    verbose = argc > 4 && !strcmp(argv[4], "-v");
    if (strchr(sel, ':'))
        end = atoi(strchr(sel, ':') + 1);
    setvbuf(stdout, NULL, _IONBF, 0);
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);
    /* the arena sits in the middle of 64 MB of reserved, uncommitted address space: stores up to 32 MB past
       either end fault rather than land in the harness's memory */
    {
        u8 *res = (u8 *)VirtualAlloc(NULL, ARENA_GUARD * 2, MEM_RESERVE, PAGE_NOACCESS);
        arena = (u8 *)VirtualAlloc(res + ARENA_GUARD, ARENA_SIZE, MEM_COMMIT, PAGE_READWRITE);
    }
    DuplicateHandle(GetCurrentProcess(), GetCurrentThread(), GetCurrentProcess(), &main_thread, 0, FALSE,
                    DUPLICATE_SAME_ACCESS);
    CreateThread(NULL, 0, watchdog, NULL, 0, NULL);
    printf("CASES %d\n", ncases);
    for (i = 0; i < ncases; i++)
        if (first < 0 || (i >= first && i < end))
            run_case(i, trials, seed);
    return 0;
}
