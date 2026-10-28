#!/bin/sh
# dump compact asm of functions
for f in "$@"; do echo "== $f"; sed -E 's/^\s*\/\* [0-9A-F]+ ([0-9A-F]+) [0-9A-F]+ \*\/\s*/\1 /' asm/movie/nonmatchings/movie/func_$f.s | grep -vE '^(nonmatching|glabel|endlabel|$)'; done
