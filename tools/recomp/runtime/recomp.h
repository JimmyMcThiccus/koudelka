/* Runtime for statically recompiled MIPS functions (tools/recomp).

   The recompiled code works on real 32-bit host addresses: a MIPS register is a
   u32 C local, `lw $t0, 0x1B8($a0)` is MEM_U32(a0 + 0x1B8), and globals are the
   host symbols. Everything a port may want to change goes through a macro that
   can be predefined before this header:

     RECOMP_ADDR(a)            host address for a computed address (default: identity;
                               RECOMP_CHECK_ADDR routes it through recomp_check_addr)
     RECOMP_ICALL_TARGET(x)    host function for an indirect call target
     RECOMP_SCRATCHPAD_BASE    host address of the 1 KB scratchpad (0x1F800000)
     GTE_MTC2/MFC2/CTC2/CFC2/COP2   software GTE (default: PsyCross's MTC2/MFC2/CTC2/CFC2/doCOP2)
*/
#ifndef RECOMP_H
#define RECOMP_H

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;

#ifdef __cplusplus
#define RECOMP_EXTERN_C extern "C"
#else
#define RECOMP_EXTERN_C
#endif
/* declaration (never a tentative definition) of a global the code references */
#ifdef __cplusplus
#define RECOMP_EXTERN_DATA extern "C"
#else
#define RECOMP_EXTERN_DATA extern
#endif

#ifndef RECOMP_FUNC
#define RECOMP_FUNC RECOMP_EXTERN_C
#endif
/* storage class for rodata a function's .s defined (strings, constant tables) */
#ifndef RECOMP_RODATA
#define RECOMP_RODATA
#endif

#if defined(_MSC_VER) && !defined(__clang__)
#define RECOMP_ALIGN(n) __declspec(align(n))
#define RECOMP_NORETURN __declspec(noreturn)
#else
#define RECOMP_ALIGN(n) __attribute__((aligned(n)))
#define RECOMP_NORETURN __attribute__((noreturn))
#endif

/* ---- traps ---------------------------------------------------------------- */
RECOMP_EXTERN_C RECOMP_NORETURN void recomp_unsupported(const char *func, const char *why);
RECOMP_EXTERN_C void recomp_break(const char *func, u32 code, u32 vaddr);
RECOMP_EXTERN_C RECOMP_NORETURN void recomp_bad_jump(const char *func, u32 vaddr, u32 value);
RECOMP_EXTERN_C RECOMP_NORETURN void recomp_stack_overflow(const char *func);
RECOMP_EXTERN_C u32 recomp_hw_address(const char *func, u32 addr);

#define RECOMP_UNSUPPORTED(f, why) recomp_unsupported(f, why)
#define RECOMP_BREAK(f, code, va) recomp_break(f, code, va)
#define RECOMP_BAD_JUMP(f, va, x) recomp_bad_jump(f, va, x)
/* a constant in the PS1 I/O area (0x1F801000 and up): reported, then used as is */
#define RECOMP_HW(f, a) recomp_hw_address(f, a)

/* ---- address translation -------------------------------------------------- */
#ifndef RECOMP_SCRATCHPAD_BASE
/* 0x1F800000-0x1F8003FF. Aligned to 4 KB so `ori` on the base still works. */
RECOMP_EXTERN_DATA u8 recomp_scratchpad[0x400];
#define RECOMP_SCRATCHPAD_BASE ((u32)recomp_scratchpad)
#endif

#ifndef RECOMP_ADDR
#ifdef RECOMP_CHECK_ADDR
RECOMP_EXTERN_C u32 recomp_check_addr(u32 a);
#define RECOMP_ADDR(a) recomp_check_addr(a)
#else
#define RECOMP_ADDR(a) (a)
#endif
#endif

/* Memory is accessed through may_alias types: the same bytes are read as u8,
   u16 and u32, as on the PS1. (Build with -fno-strict-aliasing as well.) */
typedef u8 __attribute__((may_alias)) recomp_u8a;
typedef s8 __attribute__((may_alias)) recomp_s8a;
typedef u16 __attribute__((may_alias)) recomp_u16a;
typedef s16 __attribute__((may_alias)) recomp_s16a;
typedef u32 __attribute__((may_alias)) recomp_u32a;
#define MEM_U8(a)  (*(recomp_u8a *)(RECOMP_ADDR(a)))
#define MEM_S8(a)  (*(recomp_s8a *)(RECOMP_ADDR(a)))
#define MEM_U16(a) (*(recomp_u16a *)(RECOMP_ADDR(a)))
#define MEM_S16(a) (*(recomp_s16a *)(RECOMP_ADDR(a)))
#define MEM_U32(a) (*(recomp_u32a *)(RECOMP_ADDR(a)))
/* sp-relative accesses never need translation */
#define STK_U8(a)  (*(recomp_u8a *)(a))
#define STK_S8(a)  (*(recomp_s8a *)(a))
#define STK_U16(a) (*(recomp_u16a *)(a))
#define STK_S16(a) (*(recomp_s16a *)(a))
#define STK_U32(a) (*(recomp_u32a *)(a))

/* %hi/%lo of a host address, so any hi/lo pairing behaves as the linker made it */
#define RECOMP_HI(x) ((((u32)(x)) + 0x8000u) & 0xFFFF0000u)
#define RECOMP_LO(x) ((u32)(s32)(s16)(u16)((u32)(x) & 0xFFFFu))

/* ---- unaligned word access (little-endian MIPS = little-endian x86) -------- */
static inline u32 recomp_lwl(u32 rt, u32 addr) {
    u32 sh = (addr & 3) * 8;
    u32 w = MEM_U32(addr & ~3u);
    return (rt & (0x00FFFFFFu >> sh)) | (w << (24 - sh));
}
static inline u32 recomp_lwr(u32 rt, u32 addr) {
    u32 sh = (addr & 3) * 8;
    u32 w = MEM_U32(addr & ~3u);
    return (rt & ~(0xFFFFFFFFu >> sh)) | (w >> sh);
}
static inline void recomp_swl(u32 addr, u32 rt) {
    u32 sh = (addr & 3) * 8;
    u32 a = addr & ~3u;
    MEM_U32(a) = (MEM_U32(a) & ~(0xFFFFFFFFu >> (24 - sh))) | (rt >> (24 - sh));
}
static inline void recomp_swr(u32 addr, u32 rt) {
    u32 sh = (addr & 3) * 8;
    u32 a = addr & ~3u;
    MEM_U32(a) = (MEM_U32(a) & ~(0xFFFFFFFFu << sh)) | (rt << sh);
}

/* ---- multiply / divide ------------------------------------------------------ */
#define RECOMP_MULT(hi, lo, a, b) do { s64 p_ = (s64)(s32)(a) * (s64)(s32)(b); \
    (lo) = (u32)p_; (hi) = (u32)((u64)p_ >> 32); } while (0)
#define RECOMP_MULTU(hi, lo, a, b) do { u64 p_ = (u64)(u32)(a) * (u64)(u32)(b); \
    (lo) = (u32)p_; (hi) = (u32)(p_ >> 32); } while (0)
/* R3000 results for x/0 and INT_MIN/-1 instead of a host trap */
#define RECOMP_DIV(hi, lo, a, b) do { s32 n_ = (s32)(a), d_ = (s32)(b); \
    if (d_ == 0) { (lo) = n_ >= 0 ? 0xFFFFFFFFu : 1u; (hi) = (u32)n_; } \
    else if (d_ == -1 && n_ == (s32)0x80000000) { (lo) = 0x80000000u; (hi) = 0; } \
    else { (lo) = (u32)(n_ / d_); (hi) = (u32)(n_ % d_); } } while (0)
#define RECOMP_DIVU(hi, lo, a, b) do { u32 n_ = (a), d_ = (b); \
    if (d_ == 0) { (lo) = 0xFFFFFFFFu; (hi) = n_; } \
    else { (lo) = n_ / d_; (hi) = n_ % d_; } } while (0)

/* ---- GTE (cop2) --------------------------------------------------------------
   Default: PsyCross's software GTE (include/psx/inline_c.h). lwc2/swc2 are
   mtc2/mfc2 with a memory operand, as in PsyCross. */
#ifndef GTE_MTC2
RECOMP_EXTERN_C void MTC2(unsigned int value, int reg);
RECOMP_EXTERN_C unsigned int MFC2(int reg);
RECOMP_EXTERN_C void CTC2(unsigned int value, int reg);
RECOMP_EXTERN_C unsigned int CFC2(int reg);
RECOMP_EXTERN_C int doCOP2(int op);
#define GTE_MTC2(v, r) MTC2((v), (r))
#define GTE_MFC2(r) ((u32)MFC2(r))
#define GTE_CTC2(v, r) CTC2((v), (r))
#define GTE_CFC2(r) ((u32)CFC2(r))
#define GTE_COP2(op) doCOP2(op)
#endif
#define GTE_LWC2(r, a) GTE_MTC2(MEM_U32(a), (r))
#define GTE_SWC2(r, a) (MEM_U32(a) = GTE_MFC2(r))

/* ---- calls ---------------------------------------------------------------- */
typedef u32 (*recomp_icall_t)(u32, u32, u32, u32, ...);
typedef u64 (*recomp_icall2_t)(u32, u32, u32, u32, ...);
#ifndef RECOMP_ICALL_TARGET
#define RECOMP_ICALL_TARGET(x) (x)
#endif
#define RECOMP_ICALL(x) ((recomp_icall_t)(RECOMP_ICALL_TARGET(x)))
#define RECOMP_ICALL2(x) ((recomp_icall2_t)(RECOMP_ICALL_TARGET(x)))
#define RECOMP_PAIR(v0, v1) (((u64)(u32)(v1) << 32) | (u32)(v0))

#endif /* RECOMP_H */
