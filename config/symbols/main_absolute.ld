/* Absolute symbols for the EXE link (splat declares them, but doesn't define them). */

/* The shared overlay slot: every overlay but EFFECT is linked here, and the EXE
   reads the loaded overlay's header (id word, entry table) from it. The entry
   point also clears BSS up to it and starts the heap there, so the EXE's BSS
   must end at or before it (tools/functional_check.py). */
ovl_header = 0x800B6DF0;
