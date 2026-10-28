#!/bin/sh
# print cleaned asm for functions
D=/c/Users/jamie/Documents/Koudelka/.claude/worktrees/r2-sound-eeea8c/asm/main
for f in "$@"; do
  p=$(ls $D/nonmatchings/sound/$f.s $D/matchings/sound/$f.s 2>/dev/null | head -1)
  sed -e 's/^ *\/\* [0-9A-F]* \([0-9A-F]*\) [0-9A-F]* \*\/ */\1 /' "$p" | grep -v '^\s*$' | grep -v 'nonmatching\|endlabel'
done
