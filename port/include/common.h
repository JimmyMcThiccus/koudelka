/* Host replacement for include/common.h (PC port). It comes first on the include path, so the game's
   headers and sources are compiled unchanged (through tools/port/hostify.py's host view).
   - INCLUDE_ASM / INCLUDE_RODATA expand to nothing: asm functions come from tools/recomp, asm data from
     tools/port/gen_data.py.
   - EXTERN_C and NULL as in the original.
   - port_args.h: the permissive parameter types the host view of shared/exe.h uses. */
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

#include "port_args.h"
#include "port_gte.h"

#endif /* COMMON_H */
