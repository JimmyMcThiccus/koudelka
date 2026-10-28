#!/bin/sh
cd "$(dirname "$0")/.."
cat scratch_c/hdr.h scratch_c/func_800B7190.cpp > scratch_c/_build_func_800B7190.cpp
.venv/Scripts/python.exe tools/try_compile.py scratch_c/_build_func_800B7190.cpp func_800B7190 --asm-dir asm/gameend --target extracted/disc1/BIN/GAMEEND.BIN > scratch_c/_out.txt 2>&1
python - <<'P'
import re
t=open('scratch_c/_out.txt').read()
print(re.search(r'vars=\s*\d+',t).group(0), 'pt:',re.findall(r'sh\s+\$2,(\d+)\(\$sp\)',t)[:1], 'f2:',re.findall(r'addu\s+\$16,\$sp,(\d+)',t)[:1])
print(t.strip().splitlines()[-1])
P
