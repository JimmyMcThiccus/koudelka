#!/bin/sh
# usage: run.sh [-v] ADDR...   compiles scratch_c/b/ADDR.cpp (prefixed with prelude) against retail
V=--quiet; if [ "$1" = -v ]; then V=; shift; fi
for f in "$@"; do
  .venv/Scripts/python.exe scratch_c/mkprelude.py; cat scratch_c/prelude.cpp scratch_c/b/$f.cpp > scratch_c/t_$f.cpp
  out=$(.venv/Scripts/python.exe tools/try_compile.py scratch_c/t_$f.cpp func_$f --asm-dir asm/movie --target extracted/disc1/BIN/MOVIE.BIN --cflags "-O2 -G8" --as-G 0 $V 2>&1)
  if [ -n "$V" ]; then echo "$out" | tail -1; else echo "$out"; fi
  rm -f scratch_c/t_$f.cpp
done
