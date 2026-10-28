/* Absolute symbols for the EXE link (splat declares them, but doesn't define them). */

/* The shared overlay slot: every overlay but EFFECT is linked here, and the EXE
   reads the loaded overlay's header (id word, entry table) from it. The entry
   point also clears BSS up to it and starts the heap there, so the EXE's BSS
   must end at or before it (tools/functional_check.py). */
ovl_header = 0x800B6DF0;

/* GCC 2.8's operator new[] calls __builtin_vec_new; the EXE's copy is the library function at
   0x800A0D2C, which the game's C calls as func_800A0D2C. An alias rather than a rename keeps those
   callers working. (__builtin_delete is named in main.txt.) */
__builtin_vec_new = func_800A0D2C;
