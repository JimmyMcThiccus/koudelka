#!/bin/sh
cd /c/Users/jamie/Documents/Koudelka/.claude/worktrees/r2-sound-eeea8c
f=$1; shift
for fn in "$@"; do
.venv/Scripts/python.exe tools/try_compile.py $f $fn --unit src/main/sound.cpp 2>&1 | tail -${TAIL:-40}
done
