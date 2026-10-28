#!/bin/sh
cd /c/Users/jamie/Documents/Koudelka/.claude/worktrees/r3-battle-af64ed
for f in 800D407C 800C56A8; do
  timeout 900 C:/Users/jamie/Documents/Koudelka/.venv/Scripts/python.exe tools/permute.py run permuter/func_$f -j 8 --stop-on-zero --best-only > scratch_c/perm_$f.log 2>&1
done
