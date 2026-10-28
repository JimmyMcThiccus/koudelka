#!/bin/sh
sh scratch_c/dump.sh $1 -dL && grep -E "real insns|savings" scratch_c/dump/out.i.loop | head -${2:-12}
.venv/Scripts/python.exe tools/try_compile.py $1 ${3:-func_800B7190} --unit ${4:-src/gameend/gameend.cpp} 2>&1 | tail -1
