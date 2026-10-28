#!/bin/sh
# show.sh ADDR... : stripped asm of battle functions
cd /c/Users/jamie/Documents/Koudelka/.claude/worktrees/r3-battle-af64ed
for f in "$@"; do echo "== func_$f"; p=$(ls asm/battle/nonmatchings/*/func_$f.s | head -1); sed -n '/^glabel/,/^endlabel/p' $p | grep -vE '^(glabel|endlabel)' | sed -E 's|/\* [0-9A-F]+ ([0-9A-F]+) [0-9A-F]+ \*/ *|\1 |' | sed -E 's/^([0-9A-F]{8}) +/\1 /'; done
