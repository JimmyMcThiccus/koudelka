#!/bin/sh
# usage: tv.sh ADDR TEMPLATE BODY...  substitutes @BODY@ in TEMPLATE; stops at first exact match (left in place)
a=$1; t=$2; shift 2
for body in "$@"; do
  .venv/Scripts/python.exe -c "import sys; t=open(sys.argv[1]).read(); open(sys.argv[2],'w').write(t.replace('@BODY@', sys.argv[3]))" "$t" scratch_c/b/$a.cpp "$body"
  r=$(sh scratch_c/run.sh $a); echo "$r  <= ${body:0:70}"
  case "$r" in *" 0 differing"*) exit 0;; esac
done
exit 1
