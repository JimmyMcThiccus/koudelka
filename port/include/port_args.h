/* Permissive argument and return types for the host view of include/shared/exe.h (tools/port/hostify.py).

   GCC 2.8 accepted, in C++, a void * (or any pointer, or an integer) where a T * parameter was declared, and a
   pointer where an integer was. clang does not. hostify.py rewrites exe.h's prototypes, for callers outside the
   owning unit only, so that
     T *  parameter  -> port_parg<T>   (any pointer, any integer; a real conversion such as derived-to-base wins)
     int  parameter  -> port_iarg<int> (also any pointer)
     T *  return     -> port_pret      (converts to any pointer, and to int)
   Each is 4 bytes and trivially copyable; port_pret is an aggregate. On i686 cdecl they are passed and returned
   exactly like the pointer or integer they stand for, so the callee (built from the original prototype, or
   recompiled) sees the same stack and EAX. */
#ifndef PORT_ARGS_H
#define PORT_ARGS_H
#ifdef __cplusplus

typedef unsigned int port_uptr;

template <bool B> struct port_enable_if {};
template <> struct port_enable_if<true> { typedef int type; };

struct port_pret {
    void *p;
    template <class U> operator U *() const { return (U *)p; }
    operator int() const { return (int)(port_uptr)p; }
};
template <class T>
inline T *port_vb_conv(port_pret r, long) { return (T *)r.p; }

/* GCC 2.x virtual bases: the object holds a pointer to its virtual base subobject (tools/port/hostify.py
   rewrites `struct X : virtual B` to a `B *port_vb` member). Converting X * to B * loads it, null check
   included; any other pointer converts as is. */
template <class T, class U, typename port_enable_if<__is_same(decltype(((U *)0)->port_vb), T *)>::type = 0>
inline T *port_vb_conv(U *d, int) { return d ? d->port_vb : 0; }
template <class T, class U>
inline T *port_vb_conv(U *d, long) { return (T *)d; }
struct port_pret;
template <class T>
inline T *port_vb_conv(port_pret r, long);
template <class T, class I, typename port_enable_if<__is_integral(I)>::type = 0>
inline T *port_vb_conv(I v, long) { return (T *)(port_uptr)v; }

template <class T> struct port_parg {
    T *p;
    port_parg(T *q) : p(q) {}
    template <class U, typename port_enable_if<!__is_convertible_to(U *, T *)>::type = 0>
    port_parg(U *q) : p(port_vb_conv<T>(q, 0)) {}
    template <class I, typename port_enable_if<__is_integral(I) || __is_enum(I)>::type = 0>
    port_parg(I v) : p((T *)(port_uptr)v) {}
    port_parg(decltype(nullptr)) : p(0) {}
    port_parg(port_pret r) : p((T *)r.p) {}
    /* so an inline function whose parameter hostify made a port_parg uses it like the pointer */
    T *operator->() const { return p; }
    operator T *() const { return p; }
};

template <class T> struct port_iarg {
    T v;
    port_iarg(T x) : v(x) {}
    template <class U> port_iarg(U *q) : v((T)(port_uptr)q) {}
    port_iarg(port_pret r) : v((T)(port_uptr)r.p) {}
};

/* A GCC 2.x vtable entry (the game's vtables are asm data in this format). tools/port/hostify.py turns
   each virtual function into a dispatcher through these. */
struct port_vt_entry {
    short delta;
    short index;
    void *pfn;
};

/* The game's placeholder polymorphic classes (include/game/b/vcall.h: VObj<N>, VObj0) declare 64 varargs
   slots. hostify turns each into a variadic template calling slot k through the GCC vtable, with C's
   default argument promotions so every argument fills a 4-byte stack slot as the callee expects. */
inline int port_promote(char x) { return x; }
inline int port_promote(signed char x) { return x; }
inline int port_promote(unsigned char x) { return x; }
inline int port_promote(short x) { return x; }
inline int port_promote(unsigned short x) { return x; }
inline int port_promote(bool x) { return x; }
template <class T> inline T port_promote(T x) { return x; }

template <class... A> inline int port_vslot_call(void *vptr, void *self, int slot, A... a)
{
    port_vt_entry *e = (port_vt_entry *)vptr + slot;
    return ((int (*)(void *, A...))e->pfn)((char *)self + e->delta, a...);
}

#endif
#endif
