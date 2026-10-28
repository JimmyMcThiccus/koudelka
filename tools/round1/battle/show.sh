#!/bin/sh
# show.sh ADDR... : print stripped asm of battle functions
cd /c/Users/jamie/Documents/Koudelka-wt/battle
for f in "$@"; do echo "== $f"; sed -n '/^glabel/,/^endlabel/p' asm/battle/nonmatchings/battle/func_800$f.s | grep -vE '^(glabel|endlabel)' | sed -E 's|/\* [0-9A-F]+ ([0-9A-F]+) [0-9A-F]+ \*/|\1|'; done
