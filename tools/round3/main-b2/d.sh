#!/bin/bash
# usage: d.sh file func  -> side by side diff
C:/Users/jamie/Documents/Koudelka/.venv/Scripts/python.exe scratch_c/mb.py "$1" -v "$2" 2>&1 | grep -E "^(!!|   [0-9a-f]{4}|[A-Za-z_0-9]+: retail)"
