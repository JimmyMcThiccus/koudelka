#!/bin/sh
# both build modes; prints summary
PY=C:/Users/jamie/Documents/Koudelka/.venv/Scripts/python.exe
$PY configure.py --mode matching > scratch_c/build_m.log 2>&1
echo "matching OK: $(grep -c 'check: OK' scratch_c/build_m.log)"
grep -iE "error|undefined|FAIL|mismatch" scratch_c/build_m.log | head -15
$PY configure.py > scratch_c/build_f.log 2>&1
grep -E "functional check" scratch_c/build_f.log | tail -1
grep -iE "error|undefined|FAIL" scratch_c/build_f.log | head -10
