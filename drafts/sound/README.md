# sound drafts (round 2)

Near misses for `src/main/sound.cpp` (PsyQ 4.1 / GCC 2.7.2). Each file is a scratch file: `#include "pre.h"` (copied
here) on line 1, the diff summary on line 2. To retry one, copy it to `scratch_c/` and run
`tools/try_compile.py scratch_c/<f>.cpp <f> --unit src/main/sound.cpp`.

| Function | Diffs | What differs |
|---|---|---|
| func_80090724 | 1 | operand order of `addu` in `note + (signed char)v->9` (0x278) |
| func_80091B38 | 6 | registers of p[0]/p[1] swapped (a1/v1) |
| func_8008D97C | 9 | final size sum: `prod + (a + (b + 0xE0))` gives the right shape; retail has the loaded byte in $v1, the product in $v0 and the sum in $v1 (here swapped) |
| func_8008BE08, func_8008C6B0 | 15 | list unlink: retail copies the head into its own register |
| func_8008D5E8 | 17 | temp register reuse in the last bit-field extract; store order |
| func_8008BECC (memcpy) | ~25 | dst/src register choice and copies after the byte-loop guard |
| func_8008BF78 (memset) | ~29 | which pointer gets strength-reduced (+1 insn) |
| func_80090CF4 (sequencer tick) | ~254 | logic complete; s1/s2 and a0/a1 swaps, `lb` vs `lbu` for t->5F, 1 extra insn |

Round 3: func_8008DEE4 landed. The trick: step the pointer (`p += 8`, then `p[6]`, `p[10]`, `p[11]`) instead of indexing `p[j * 8 + 6]`; the loop optimiser then reduces the pointer itself and gives the retail `p+0xB` offsets (-5/-1/0). Try it on other loops whose retail strength reduction differs.
