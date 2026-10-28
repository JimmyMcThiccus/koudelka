#!/bin/sh
# usage: scratch_c/t.sh func_XXXX [-v]
cd "$(dirname "$0")/.."
cat scratch_c/hdr.h scratch_c/$1.cpp > scratch_c/_build_$1.cpp
if [ "$2" = "-v" ]; then
.venv/Scripts/python.exe tools/try_compile.py scratch_c/_build_$1.cpp $1 --asm-dir asm/gameend --target extracted/disc1/BIN/GAMEEND.BIN --quiet
else
.venv/Scripts/python.exe tools/try_compile.py scratch_c/_build_$1.cpp $1 --asm-dir asm/gameend --target extracted/disc1/BIN/GAMEEND.BIN --quiet | grep -E '!!|differing'
fi
