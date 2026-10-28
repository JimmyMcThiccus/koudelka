"""Land a sectioned scratch file (see multi.py) into src/main/game.cpp.
The prelude (types, externs) is appended to the header given; each section replaces its
function's INCLUDE_ASM line. `extern "C"` becomes EXTERN_C.
usage: land.py file.cpp include/game/a/xxx.h [names...]   (names: only land these)"""
import re, sys
from pathlib import Path

path, header = Path(sys.argv[1]), Path(sys.argv[2])
only = set(sys.argv[3:])
parts = re.split(r'^//// (func_[0-9A-F]{8})[^\n]*\n', path.read_text(), flags=re.M)
fix = lambda s: s.replace('extern "C"', 'EXTERN_C').strip('\n')
src = Path('src/main/game.cpp')
text = src.read_text()
n = 0
for name, body in zip(parts[1::2], parts[2::2]):
    if only and name not in only:
        continue
    a = int(name[5:], 16)
    assert 0x800186B0 <= a < 0x80054A2C, name
    line = f'INCLUDE_ASM("asm/main/nonmatchings/game", {name});'
    assert line in text, name
    text = text.replace(line, fix(body))
    n += 1
src.write_text(text, newline='\n')
pre = fix(parts[0])
if pre:
    h = header.read_text()
    guard = '#endif'
    i = h.rindex(guard)
    header.write_text(h[:i] + pre + '\n\n' + h[i:], newline='\n')
print(f'landed {n}')
