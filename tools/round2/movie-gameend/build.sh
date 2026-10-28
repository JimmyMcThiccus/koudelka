#!/bin/sh
# full verification: matching (7x OK) + functional
.venv/Scripts/python.exe configure.py --mode matching > scratch_c/build_m.log 2>&1
m=$(grep -c "check: OK" scratch_c/build_m.log)
.venv/Scripts/python.exe configure.py > scratch_c/build_f.log 2>&1
f=$(grep -c "functional check: OK" scratch_c/build_f.log)
echo "matching OK=$m/7 functional=$f"
grep -E "FAIL|undefined|rror" scratch_c/build_m.log scratch_c/build_f.log | head -8
