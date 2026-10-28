#!/bin/sh
# usage: landok.sh batch.cpp  -> runs mb.py, lands OK functions (+prelude), keeps the rest in batch.cpp.rest
PY=.venv/Scripts/python.exe
ok=$($PY scratch_c/mb.py "$1" | tee /dev/stderr | tail -1 | sed 's/^[0-9]* ok: *//')
[ -z "$ok" ] && exit 0
$PY scratch_c/land.py "$1" $ok
.venv/Scripts/python.exe scratch_c/chkdecl.py
