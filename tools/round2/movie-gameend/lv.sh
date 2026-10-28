#!/bin/sh
# lv.sh func 'code'   -- verify and land a one-function snippet (header part before //@func)
printf '#include "movie/movie.h"\n%s\n' "$2" > scratch_c/_land.cpp
r=$(.venv/Scripts/python.exe tools/try_compile.py scratch_c/_land.cpp $1 --unit ${3:-src/movie/movie.cpp} 2>&1 | tail -1)
echo "$r"
case "$r" in *" 0 differing"*) .venv/Scripts/python.exe scratch_c/land.py $1 scratch_c/_land.cpp ${3:-src/movie/movie.cpp} ${4:-include/movie/movie.h};; esac
