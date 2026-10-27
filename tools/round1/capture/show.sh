#!/bin/sh
# show.sh func... : compact asm
for f in "$@"; do
  s=asm/capture/nonmatchings/capture/$f.s
  [ -f $s ] || s=asm/capture/matchings/capture/$f.s
  echo "== $f"; grep -E '^\s*/\*|^\s*\.L|jlabel|^\.L' $s | sed -E 's/^\s*\/\* \S+ (\S+) \S+ \*\/\s*/\1 /'
done
