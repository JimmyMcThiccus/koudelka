#!/bin/sh
PY=.venv/Scripts/python.exe
$PY -u configure.py --mode matching > scratch_c/m.log 2>&1; echo "matching rc=$?"; grep -c "check: OK" scratch_c/m.log; grep -i "error\|mismatch\|undefined" scratch_c/m.log | head -10
$PY -u configure.py > scratch_c/f.log 2>&1; echo "functional rc=$?"; grep "functional check" scratch_c/f.log; grep -i "error\|undefined\|overflow" scratch_c/f.log | head -10
