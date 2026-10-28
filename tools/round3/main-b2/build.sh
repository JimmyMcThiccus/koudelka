#!/bin/bash
# full verdict: matching then functional
PY=C:/Users/jamie/Documents/Koudelka/.venv/Scripts/python.exe
n=$($PY configure.py --mode matching 2>&1 | grep -c "check: OK")
echo "matching: $n x check: OK"
$PY configure.py 2>&1 | grep -E "functional check|rror|undefined"
