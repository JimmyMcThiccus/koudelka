#!/bin/sh
# verify each named scratch file matches; print failures
cd /c/Users/jamie/Documents/Koudelka/.claude/worktrees/r2-sound-eeea8c
for f in "$@"; do r=$(.venv/Scripts/python.exe tools/try_compile.py scratch_c/$f.cpp $f --unit src/main/sound.cpp --quiet 2>&1 | tail -1); case "$r" in *" 0 differing"*) echo "ok $f";; *) echo "FAIL $f: $r";; esac; done
