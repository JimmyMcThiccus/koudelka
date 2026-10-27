#ifndef SHARED_VBASE_H
#define SHARED_VBASE_H

/* Used by both main_a (func_800186E8) and main_b for virtual-base conversions.
   GCC 2.x vtable entries are {short delta; short index; pfn}; run() is the first slot. */
struct Item {
    virtual void run();
};

struct List {
    int pad;
    int count;
};

struct Holder : virtual List {
};

// Converting to the virtual base each time keeps the null checks retail has.
inline int count_of(List *l) { return l->count; }

#endif /* SHARED_VBASE_H */
