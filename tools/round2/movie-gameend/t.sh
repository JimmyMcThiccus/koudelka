#!/bin/sh
.venv/Scripts/python.exe tools/try_compile.py scratch_c/$1 $2 --unit ${3:-src/movie/movie.cpp} > scratch_c/last.txt 2>&1
grep -E "^(!!|  ) |differing|rror|failed|:[0-9]+:" scratch_c/last.txt | tail -${4:-60}
