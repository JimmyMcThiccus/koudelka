/* Host (clang, i686-pc-windows-msvc) replacement for include/common.h, used by the
   differential tests to compile the decompiled sources natively. It is found first
   on the include path, so the game headers are used unchanged.
   - INCLUDE_ASM / INCLUDE_RODATA expand to nothing: the asm functions become
     undefined symbols (the tests link with /force:unresolved and never call them).
   - EXTERN_C and NULL as in the original. */
#ifndef COMMON_H
#define COMMON_H

#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)

#ifndef NULL
#define NULL 0
#endif

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif

#endif /* COMMON_H */
