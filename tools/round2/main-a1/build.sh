#!/bin/bash
# Both build modes; prints a one-line verdict.
cd "$(dirname "$0")/.."
m=$(.venv/Scripts/python.exe configure.py --mode matching 2>&1)
n=$(echo "$m" | grep -c "check: OK")
f=$(.venv/Scripts/python.exe configure.py 2>&1)
fc=$(echo "$f" | grep -c "functional check: OK")
echo "matching: $n/7 OK   functional: $fc"
if [ "$n" != 7 ] || [ "$fc" != 1 ]; then echo "$m" | grep -iE "error|undefined|FAIL|differ" | head -20; echo "$f" | grep -iE "error|undefined|FAIL|fit" | head -20; fi
