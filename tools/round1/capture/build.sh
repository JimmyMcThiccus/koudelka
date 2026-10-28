#!/bin/sh
cd "$(dirname "$0")/.."
.venv/Scripts/python.exe configure.py --mode matching > scratch_c/_m.log 2>&1; m=$(grep -c 'check: OK' scratch_c/_m.log)
.venv/Scripts/python.exe configure.py > scratch_c/_f.log 2>&1; f=$(grep -c 'functional check: OK' scratch_c/_f.log)
echo "matching OK x$m, functional OK x$f"
grep -iE 'error|FAIL|mismatch' scratch_c/_m.log scratch_c/_f.log | head -20
grep capture scratch_c/_f.log | grep fit
