#!/bin/sh
# both build modes; prints OK counts
cd "$(dirname "$0")/.."
m=$(.venv/Scripts/python.exe configure.py --mode matching 2>&1)
echo "$m" | grep -E "rror|undefined|FAIL|differ" | head -20
echo "matching OK: $(echo "$m" | grep -c 'check: OK')"
f=$(.venv/Scripts/python.exe configure.py 2>&1)
echo "$f" | grep -E "rror|undefined|FAIL" | head -20
echo "$f" | grep "functional check:"
n=$(echo "$m" | grep -c 'check: OK'); echo "$f" | grep -q "functional check: OK" && [ "$n" = 7 ]
