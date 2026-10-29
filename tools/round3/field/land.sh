#!/bin/sh
# land.sh batch1.txt [batch2.txt ...]: apply OK sections, build both modes
cd "$(dirname "$0")/.."
PY=.venv/Scripts/python.exe
for b in "$@"; do $PY scratch_c/apply.py "$b" || exit 1; done
for attempt in 1 2; do
  m=$($PY configure.py --mode matching 2>&1)
  und=$(echo "$m" | grep -o "undefined reference to \`D_[0-9A-F]*'" | sed "s/.*\`\(D_[0-9A-F]*\)'/\1/" | sort -u)
  [ -z "$und" ] && break
  for d in $und; do echo "$d = 0x${d#D_}; // force_not_migration:True" >> config/symbols/field.txt; echo "kept rodata $d"; done
  $PY tools/resync_rodata.py field field | tail -1
  $PY tools/resync_rodata.py field field_b | tail -1
  sed -i 's|nonmatchings/field", |nonmatchings/field_b", |' src/field/field_b.cpp
done
echo "$m" | grep -E "warning|error" | grep -v "LF will" | sort -u | head -20
n=$(echo "$m" | grep -c "check: OK")
echo "matching: $n/7"
[ "$n" = 7 ] || { echo "$m" | grep -A5 "FAILED\|FAIL" | head -30; exit 1; }
f=$($PY configure.py 2>&1 | grep "functional check")
echo "$f"
echo "$f" | grep -q "functional check: OK" || exit 1
