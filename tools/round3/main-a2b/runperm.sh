#!/bin/sh
PY=C:/Users/jamie/Documents/Koudelka/.venv/Scripts/python.exe
cd C:/Users/jamie/Documents/Koudelka/.claude/worktrees/r3-main-a2b-4ef520
for f in 80044990:u_8003F7E8 8004AA44:u_80045850; do
  n=${f%%:*}; u=${f##*:}
  $PY tools/permute.py setup drafts/main_a2b/func_$n.cpp func_$n --unit src/main/$u.cpp > scratch_c/perm_$n.log 2>&1
  timeout 700 $PY tools/permute.py run permuter/func_$n -j 8 --stop-on-zero --best-only >> scratch_c/perm_$n.log 2>&1
done
