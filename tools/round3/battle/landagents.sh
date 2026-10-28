#!/bin/sh
# landagents.sh FILE...: for each agent file: verify 0 diff against current header, then land
PY=C:/Users/jamie/Documents/Koudelka/.venv/Scripts/python.exe
cd /c/Users/jamie/Documents/Koudelka/.claude/worktrees/r3-battle-af64ed
for f in "$@"; do
  n=$(basename $f .cpp | sed 's/_near//')
  out=$($PY scratch_c/battle-batch.py $f 2>&1 | tail -3)
  if echo "$out" | grep -q "^OK: func_"; then
    lab=$(echo "$out" | sed -n 's/^OK: //p' | awk '{print $1" "$2}')
    $PY scratch_c/battle-land.py $f "$lab" && echo "LANDED $f ($lab)"
  else
    echo "SKIP $f: $(echo "$out" | head -1 | cut -c1-150)"
  fi
done
