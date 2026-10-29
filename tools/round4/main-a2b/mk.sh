#!/bin/sh
# usage: mk.sh body.cpp func unit(u_8003C510 etc)
b=$1; f=$2; u=$3
{ echo '#include "common.h"'; echo "#define EXE_H_IN_$u"; sed -n '/#include "shared\/exe.h"/,/#include "game\/a2b\/a2b.h"/p' src/main/$u.cpp; cat $b; } > scratch_c/_full_$f.cpp
.venv/Scripts/python.exe tools/try_compile.py scratch_c/_full_$f.cpp $f --unit src/main/$u.cpp "${@:4}"
