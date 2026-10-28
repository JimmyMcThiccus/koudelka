#!/bin/bash
# Snapshot src/include/drafts into a commit, build it in the verify worktree, and if both modes
# pass, move this branch to it (working tree untouched).
cd "$(dirname "$0")/.."
V=../r2-main-a1-verify
[ -z "$(git status --porcelain -- src include drafts config/symbols/main_a.txt 2>/dev/null)" ] && { echo "nothing to commit"; exit 0; }
tmp=$(mktemp); export GIT_INDEX_FILE=$tmp
git read-tree HEAD && git add -A src include drafts config/symbols/main_a.txt 2>/dev/null
tree=$(git write-tree); unset GIT_INDEX_FILE; rm -f $tmp
old=$(git rev-parse HEAD)
n=$(git diff -U0 $old $tree -- src | grep -c '^-INCLUDE_ASM')
c=$(git commit-tree $tree -p $old -m "main_a1: decompile $n functions")
(cd $V && git checkout -q --detach $c 2>/dev/null && bash scratch_c/build.sh) > /tmp/snap_out.txt 2>&1
out=$(cat /tmp/snap_out.txt)
echo "$(date +%T) $out"
if echo "$out" | grep -q "matching: 7/7 OK   functional: 1"; then
  git update-ref refs/heads/$(git branch --show-current) $c $old && git reset -q && git log --oneline -1
else
  echo BUILD FAILED for snapshot $c; exit 1
fi
