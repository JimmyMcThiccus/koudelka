// func_800C8228: 4 differing (scheduling of the vtable-delta patch stores). Virtual-base destructor: g++ copies
// the vbase vtable to the stack and patches 4 deltas; func_800B9A0C, func_800C5278, func_800C800C, func_800C8114 share the pattern.
struct VTE { u16 delta; s16 index; void* pfn; };
struct VT { VTE e[10]; };
struct VB { VT* vptr; };
struct A { VB* x0; char pad[0x2C - 4]; void* x2C; };
extern "C" VT D_800B85C4;
extern "C" char D_800B84CC[];
extern "C" void func_800C95EC();
extern "C" void func_8005BDA4(void*, s32);
extern "C" void func_800C8228(A* p, s32 f) { p->x2C = D_800B84CC; p->x0->vptr = &D_800B85C4; if (f == 0) { VT t = D_800B85C4; p->x0->vptr = &t; char* b = (char*)p->x0 - 0x38; s32 d = (char*)p - b; t.e[1].delta = D_800B85C4.e[1].delta + d; t.e[5].delta = D_800B85C4.e[5].delta + d; t.e[7].delta = D_800B85C4.e[7].delta + d; t.e[9].delta = D_800B85C4.e[9].delta + d; } func_800C95EC(); func_8005BDA4(p, 0); if (f & 2) func_8001A610(p->x0, 0); if (f & 1) operator delete(p); }
