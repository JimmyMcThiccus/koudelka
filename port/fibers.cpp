/* The coroutine scheduler's context switch (src/main/u_80018B88.cpp, hand-written asm on the PS1) as Win32
   fibers. These definitions replace the recompiler's stubs (port/configure_port.py leaves out a recompiled
   function that port/ defines).

   On the PS1 a task object doubles as its jmp_buf (registers at +0xC..+0x80, the task stack at +0x88, its
   size in words at +0x8):
     func_80018F0C(cur, s)  saves cur's context, allocates s's stack, and returns with $s0 = s. Its caller,
                            func_8001E848, then sees cur == s: it leaves the critical section, moves to the new
                            stack (SetSp), runs s->f2() (vtable slot 2) and ends the task (func_8001E9A8). When
                            cur is resumed later, $s0 is restored and the call returns normally.
     func_80018FA8(a, b)    saves a's context and resumes b
     func_800190A0(obj, jb) deletes obj through vtable slot 1 (flags 3) and resumes jb, for good
   Here each task has a fiber. func_80018F0C creates s's fiber, whose entry does what the cur == s branch
   does, and switches to it; its return means cur was resumed, so the caller takes the normal path. The game
   stack is still allocated (the task's destructor frees it) but unused. */
#include <windows.h>
#include "port_rt.h"
#include "port_args.h"

extern "C" {
void *__builtin_vec_new(unsigned int size);
void func_8001E9A8(void *task);     /* ends the current task: next task, then func_800190A0 */
void func_80018788(void *holder);   /* leave the critical section */
void port_interrupts(void);         /* pending VSync callbacks (port/intr.cpp) */
extern unsigned port_stat_switches;
extern unsigned char D_800A451C[];  /* the critical-section holder */
}

#define FIBER_STACK (1u << 20)

struct TaskFiber {
    void *task;
    LPVOID fiber;
};
static TaskFiber g_tasks[256];
static LPVOID g_main_fiber;
static LPVOID g_dead;  /* a finished task's fiber, deleted by the next fiber to run */
static int g_nfibers, g_maxfibers;

static int g_trace = -1;
extern "C" void *D_800B4C18, *D_800B4C1C, *D_800B4C20;  /* current task, ready list, waiting list */

/* KOUDELKA_TRACE=1: log every switch with the scheduler's lists */
static void trace(const char *what, void *a, void *b)
{
    if (g_trace < 0) {
        char v[8];
        g_trace = GetEnvironmentVariableA("KOUDELKA_TRACE", v, sizeof v) > 0 && v[0] != '0';
    }
    if (!g_trace)
        return;
    void *ev = b ? *(void **)((char *)b + 0x8C + 4) : 0;  /* b's first pending event */
    unsigned *w = ev && (unsigned)(size_t)ev > 0x10000 ? (unsigned *)ev : 0;
    if (w)
        port_log("fiber: %s %p -> %p  cur %p ready %p wait %p  b.event %p [%08X %08X %08X %08X %08X]\n", what, a, b,
                 D_800B4C18, D_800B4C1C, D_800B4C20, ev, w[0], w[1], w[2], w[3], w[4]);
    else
        port_log("fiber: %s %p -> %p  cur %p ready %p wait %p\n", what, a, b, D_800B4C18, D_800B4C1C, D_800B4C20);
}

static TaskFiber *find(void *task)
{
    for (int i = 0; i < 256; i++)
        if (g_tasks[i].task == task)
            return &g_tasks[i];
    return 0;
}

static void bind(void *task, LPVOID fiber)
{
    TaskFiber *t = find(task);
    if (!t)
        t = find(0);
    if (!t)
        port_stop("fiber", "more than 256 tasks");
    t->task = task;
    t->fiber = fiber;
}

static DWORD g_game_thread;

/* the running task's fiber is the current one */
static void running(void *task)
{
    if (GetCurrentThreadId() != g_game_thread)
        port_stop("fiber", "task switch for %p on thread %lu, not the game thread (an interrupt callback?)", task,
                  GetCurrentThreadId());
    TaskFiber *t = find(task);
    if (!t) {
        for (int i = 0; i < 256; i++)
            if (g_tasks[i].task && g_tasks[i].fiber == GetCurrentFiber())
                port_stop("fiber", "task %p runs on the fiber of task %p", task, g_tasks[i].task);
        bind(task, GetCurrentFiber());
    } else if (t->fiber != GetCurrentFiber())
        port_stop("fiber", "task %p runs on a fiber that is not its own", task);
}

static void reap()
{
    if (g_dead && g_dead != GetCurrentFiber()) {
        trace("delete-fiber", g_dead, 0);
        DeleteFiber(g_dead);
        g_dead = 0;
        g_nfibers--;
    }
}

static void resume(void *task)
{
    if (GetCurrentThreadId() != g_game_thread)
        port_stop("fiber", "resume of %p on thread %lu, not the game thread", task, GetCurrentThreadId());
    TaskFiber *t = find(task);
    if (!t)
        port_stop("fiber", "resume of task %p, which has no context", task);
    if (t->fiber != GetCurrentFiber())
        SwitchToFiber(t->fiber);
    reap();
}

static void WINAPI task_main(void *s)
{
    reap();
    func_80018788(D_800A451C);
    port_vt_entry *e = *(port_vt_entry **)s + 2;
    ((void (*)(void *))e->pfn)((char *)s + e->delta);
    func_8001E9A8(s);
    port_stop("fiber", "task %p continued after its end", s);
}

extern "C" void port_fibers_init(void)
{
    g_game_thread = GetCurrentThreadId();
    g_main_fiber = ConvertThreadToFiberEx(NULL, FIBER_FLAG_FLOAT_SWITCH);
    if (!g_main_fiber)
        port_stop("fiber", "ConvertThreadToFiber failed (%lu)", GetLastError());
}

extern "C" int func_80018F0C(void *cur, void *s)
{
    trace("start", cur, s);
    running(cur);
    unsigned int words = *(unsigned int *)((char *)s + 0x8);
    *(void **)((char *)s + 0x88) = __builtin_vec_new(words * 4);
    LPVOID f = CreateFiberEx(64 * 1024, FIBER_STACK, FIBER_FLAG_FLOAT_SWITCH, task_main, s);
    if (!f)
        port_stop("fiber", "CreateFiberEx failed (%lu)", GetLastError());
    if (++g_nfibers > g_maxfibers) {
        g_maxfibers = g_nfibers;
        port_log("fiber: task %p started (%d task fibers)\n", s, g_nfibers);
    }
    bind(s, f);
    trace("new-fiber", f, s);
    SwitchToFiber(f);
    reap();
    return 0;
}

extern "C" void func_80018FA8(void *a, void *b)
{
    trace("switch", a, b);
    port_stat_switches++;
    running(a);
    port_interrupts();
    resume(b);
}

extern "C" void func_800190A0(void *obj, void *jb)
{
    LPVOID self = GetCurrentFiber();
    trace("end", obj, jb);
    if (obj) {
        port_vt_entry *e = *(port_vt_entry **)obj + 1;
        ((void (*)(void *, int))e->pfn)((char *)obj + e->delta, 3);
    }
    for (int i = 0; i < 256; i++)  /* this fiber ends: forget every task bound to it */
        if (g_tasks[i].fiber == self && self != g_main_fiber)
            g_tasks[i].task = 0, g_tasks[i].fiber = 0;
    if (self != g_main_fiber)
        g_dead = self;
    resume(jb);
    port_stop("fiber", "a deleted task was resumed");
}
