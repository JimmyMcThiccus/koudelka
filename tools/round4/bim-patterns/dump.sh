#!/bin/sh
# dump.sh src.cpp outdir  -> RTL dumps + .s in outdir
R=$(pwd); mkdir -p "$2"; rm -f "$2"/*
P=bin/psyq4.4
export TMPDIR=$(cygpath -w "$R/$2")
$P/CPPPSX.EXE -undef -D__GNUC__=2 -D__OPTIMIZE__ -D_MIPSEL -D__mips -D__mips__ -Dmips -D__psx -D__psx__ -Dpsx -lang-c++ -D__cplusplus -D_LANGUAGE_C_PLUS_PLUS -Iinclude "$1" "$2/out.i"
cd "$2" && "$R/$P/CC1PLPSX.EXE" -quiet -O2 -G8 -da out.i -o out.s
