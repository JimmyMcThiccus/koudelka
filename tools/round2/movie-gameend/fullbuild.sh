#!/bin/sh
.venv/Scripts/python.exe configure.py --mode matching >/dev/null 2>&1
.venv/Scripts/python.exe tools/resync_rodata.py movie movie 2>&1 | tail -1
sh scratch_c/build.sh
