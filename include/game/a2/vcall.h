#ifndef GAME_A2_VCALL_H
#define GAME_A2_VCALL_H

/* Placeholder polymorphic classes for GCC 2.x virtual calls (same scheme as
   include/game/b/vcall.h). A vtable entry is {short delta; short index; pfn},
   so slot k sits at 8*(k+1). A2VObj<N> has its vtable pointer at +N. The
   slots are only declared, never defined, so no vtables are emitted. */
#define A2_SLOTS_10(a) \
    virtual int v##a##0(...); virtual int v##a##1(...); virtual int v##a##2(...); virtual int v##a##3(...); \
    virtual int v##a##4(...); virtual int v##a##5(...); virtual int v##a##6(...); virtual int v##a##7(...); \
    virtual int v##a##8(...); virtual int v##a##9(...);

#define A2_SLOTS \
    A2_SLOTS_10(0) A2_SLOTS_10(1) A2_SLOTS_10(2) \
    A2_SLOTS_10(3) A2_SLOTS_10(4) A2_SLOTS_10(5) \
    virtual int v60(...); virtual int v61(...); virtual int v62(...); virtual int v63(...);

template <int N> struct A2VPad {
    char pad[N];
};

template <int N> struct A2VObj : A2VPad<N> {
    A2_SLOTS
};

struct A2VObj0 {
    A2_SLOTS
};

#endif /* GAME_A2_VCALL_H */
