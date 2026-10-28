#!/bin/sh
cd /c/Users/jamie/Documents/Koudelka/.claude/worktrees/r3-battle-af64ed
for f in 800CF0B0 800C8BA4; do
  timeout 1200 C:/Users/jamie/Documents/Koudelka/.venv/Scripts/python.exe tools/permute.py run permuter/func_$f -j 8 --stop-on-zero --best-only > scratch_c/perm_$f.log 2>&1
done
