/* Allocation glue. On the PS1, operator new / __builtin_new call the game's allocator (func_8001B134) and
   operator delete / __builtin_delete its free (func_8001B1C8), over the heap func_80018B88 built in port RAM.
   The host does the same. Before the game heap exists (CRT start-up) the host heap serves, and delete tells
   the two apart by address.

   One difference: new memory is zeroed. The game reads some fields it never set (MOVIE's logo fade children
   fade out from colour channels nothing wrote), and what it finds there is the remains of earlier objects,
   often halves of heap pointers. On the PS1 those are 0x801F/0xCxxx, negative as s16, and the fade ends on
   its first frame; host pointers (0x006B....) give positive halves, the fade outlives the objects and the
   per-frame list calls into a deleted one. Zero behaves like the PS1 values here. */
#include <stdlib.h>
#include <string.h>
#include "port_rt.h"

extern "C" {
void *func_8001B134(unsigned int size);
void func_8001B1C8(void *p);
}

static bool in_port_ram(void *p)
{
    return port_host_to_ps1(p) != 0;
}

static void *game_alloc(unsigned int size)
{
    void *p = func_8001B134(size);
    if (p)
        memset(p, 0, size);
    return p;
}

extern "C" void *__builtin_new(unsigned int size)
{
    return game_alloc(size ? size : 1);
}

extern "C" void __builtin_delete(void *p)
{
    if (!p)
        return;
    if (in_port_ram(p))
        func_8001B1C8(p);
    else
        free(p);
}

extern "C" void *__builtin_vec_new(unsigned int size)
{
    return __builtin_new(size);
}

extern "C" void __builtin_vec_delete(void *p)
{
    __builtin_delete(p);
}

extern "C" unsigned int D_800B4EE8;  /* the game heap's free-list head, set by func_80018B88 */

static void *alloc(size_t n)
{
    if (D_800B4EE8)
        return game_alloc((unsigned int)(n ? n : 1));
    return malloc(n ? n : 1);
}

void *operator new(size_t n) { return alloc(n); }
void *operator new[](size_t n) { return alloc(n); }
void operator delete(void *p) noexcept { __builtin_delete(p); }
void operator delete[](void *p) noexcept { __builtin_delete(p); }
void operator delete(void *p, size_t) noexcept { __builtin_delete(p); }
void operator delete[](void *p, size_t) noexcept { __builtin_delete(p); }
