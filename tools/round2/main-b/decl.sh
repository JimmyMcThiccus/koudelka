#!/bin/sh
# usage: decl.sh sym... -> declarations in my headers, and definitions in my units
for s in "$@"; do
  r=$(grep -h "\b$s\b" include/game/b/*.h include/shared/vbase.h | grep -v "^ *//\|^ *\*" | head -2)
  d=$(grep -h "^EXTERN_C.*\b$s(" src/main/main_b.cpp src/main/u_80056E0C.cpp src/main/u_8005F238.cpp src/main/u_80062610.cpp src/main/u_800658E0.cpp src/main/u_80071A74.cpp src/main/u_80082174.cpp | head -1)
  echo "$s: ${r:-NONE}${d:+   DEF: $d}"
done
