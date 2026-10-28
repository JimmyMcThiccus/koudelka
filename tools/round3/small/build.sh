#!/bin/bash
PY=C:/Users/jamie/Documents/Koudelka/.venv/Scripts/python.exe
$PY configure.py --mode matching 2>&1 | grep -E "check:|error|Error|undefined|FAILED" | head -30
$PY configure.py 2>&1 | grep -E "functional check|error|Error|undefined|FAILED" | head -30
