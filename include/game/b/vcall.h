#ifndef GAME_B_VCALL_H
#define GAME_B_VCALL_H

/* Placeholder polymorphic classes for GCC 2.x virtual calls, until the real
   classes are known. A vtable entry is {short delta; short index; pfn}, so
   slot k sits at 8*(k+1). VObj<N> has its vtable pointer at +N and slots
   v00..v63 that take any arguments. The slots are only declared, never
   defined, so no vtables are emitted. */
#define VCALL_SLOTS_10(a) \
    virtual int v##a##0(...); virtual int v##a##1(...); virtual int v##a##2(...); virtual int v##a##3(...); \
    virtual int v##a##4(...); virtual int v##a##5(...); virtual int v##a##6(...); virtual int v##a##7(...); \
    virtual int v##a##8(...); virtual int v##a##9(...);

/* v00..v63, in declaration (= slot) order */
#define VCALL_SLOTS \
    VCALL_SLOTS_10(0) VCALL_SLOTS_10(1) VCALL_SLOTS_10(2) \
    VCALL_SLOTS_10(3) VCALL_SLOTS_10(4) VCALL_SLOTS_10(5) \
    virtual int v60(...); virtual int v61(...); virtual int v62(...); virtual int v63(...);

template <int N> struct VPad {
    char pad[N];
};

template <int N> struct VObj : VPad<N> {
    VCALL_SLOTS
};

/* Vtable pointer at +0. */
struct VObj0 {
    VCALL_SLOTS
};

#endif /* GAME_B_VCALL_H */
