"""Replace INCLUDE_ASM lines in src/main/game.cpp with code from a JSON {func_name: code}.
usage: apply.py funcs.json [only_names...]"""
import json, re, sys

src = 'src/main/game.cpp'
code = json.load(open(sys.argv[1]))
only = set(sys.argv[2:])
text = open(src).read()
n = 0
for name, body in code.items():
    if only and name not in only:
        continue
    a = int(name[5:], 16)
    assert 0x800186B0 <= a < 0x80054A2C, name
    line = f'INCLUDE_ASM("asm/main/nonmatchings/game", {name});'
    if line not in text:
        print('missing', name)
        continue
    text = text.replace(line, body)
    n += 1
open(src, 'w', newline='\n').write(text)
print(f'applied {n}')
