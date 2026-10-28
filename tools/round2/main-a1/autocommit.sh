#!/bin/bash
# Every ~10 min: if src/include/drafts changed, build both modes; commit only if the tree didn't change during the build.
cd "$(dirname "$0")/.."
snap() { { git diff -- src include drafts; git ls-files -o --exclude-standard src include drafts | xargs -r cat; } | md5sum; }
while [ ! -f scratch_c/STOP ]; do
  sleep 600
  [ -z "$(git status --porcelain -- src include drafts)" ] && continue
  for try in 1 2 3; do
    a=$(snap)
    out=$(bash scratch_c/build.sh)
    b=$(snap)
    [ "$a" == "$b" ] && break
  done
  echo "$(date +%T) $out" | head -1
  if [ "$a" != "$b" ]; then echo "tree kept changing, skip"; continue; fi
  if echo "$out" | grep -q "matching: 7/7 OK   functional: 1"; then
    n=$(git diff -U0 -- src | grep -c '^-INCLUDE_ASM')
    git add -A src include drafts
    git commit -qm "main_a1: decompile $n functions" && git log --oneline -1
  else
    echo "$out"; echo BUILD FAILED; exit 1
  fi
done
