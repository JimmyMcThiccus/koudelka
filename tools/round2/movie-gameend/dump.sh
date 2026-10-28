#!/bin/sh
# usage: dump.sh file.cpp flags...
src=$1; shift
d=scratch_c/dump
TMPDIR=$(cygpath -w $d) bin/psyq4.4/CPPPSX.EXE -undef -D__GNUC__=2 -D__OPTIMIZE__ -D_MIPSEL -D__mips -D__mips__ -Dmips -D__psx -D__psx__ -Dpsx -lang-c++ -D__cplusplus -D_LANGUAGE_C_PLUS_PLUS -Iinclude $src $d/out.i
TMPDIR=$(cygpath -w $d) bin/psyq4.4/CC1PLPSX.EXE -quiet -O2 -G8 "$@" $d/out.i -o $d/out.s
