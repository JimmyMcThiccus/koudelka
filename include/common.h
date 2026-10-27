#ifndef COMMON_H
#define COMMON_H

/* With -G8, CC1PSX/CC1PLPSX 2.8.1 output every function after all top-level
   __asm__ statements, which would move decompiled functions away from their
   INCLUDE_ASM neighbours. Wrapping each include in a dummy function keeps source
   order; maspsx keeps only the "# maspsx-keep" lines of
   __maspsx_include_asm_hack* functions. These come before include_asm.h (splat
   generates that file and only defines the macros if they're missing). */
#define INCLUDE_ASM(FOLDER, NAME) \
    void __maspsx_include_asm_hack_##NAME() { \
        __asm__( \
            ".text # maspsx-keep\n" \
            "\t.align\t2 # maspsx-keep\n" \
            "\t.set noreorder # maspsx-keep\n" \
            "\t.set noat # maspsx-keep\n" \
            ".include \"" FOLDER "/" #NAME ".s\" # maspsx-keep\n" \
            "\t.set reorder # maspsx-keep\n" \
            "\t.set at # maspsx-keep\n" \
        ); \
    }
#define INCLUDE_RODATA(FOLDER, NAME) \
    void __maspsx_include_asm_hack_rodata_##NAME() { \
        __asm__( \
            ".section .rodata # maspsx-keep\n" \
            ".include \"" FOLDER "/" #NAME ".s\" # maspsx-keep\n" \
            ".text # maspsx-keep\n" \
        ); \
    }

#include "include_asm.h"

#ifndef NULL
#define NULL 0
#endif

/* Names stay unmangled so assembly that references func_XXXXXXXX links against
   decompiled code. Wrap declarations of asm functions and decompiled free
   functions in EXTERN_C. Decompiled member functions need their mangled name
   added to config/symbols/ instead. */
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif

#endif /* COMMON_H */
