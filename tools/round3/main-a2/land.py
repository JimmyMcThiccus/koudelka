"""Land a sectioned scratch file (see multi.py) into my units.
Prelude, then each section's leading declarations, are appended to include/game/a2/a2.h.
usage: land.py file.cpp [labels...]"""
import re, sys
from pathlib import Path
UNITS=[(0x80032264,'u_80032264'),(0x80033ECC,'u_80033ECC'),(0x800372C0,'u_800372C0'),(0x80037398,'u_80037398'),(0x8003852C,'u_8003852C')]
def unit(name):
    a=int(name[5:13],16); u=None
    for s,n in UNITS:
        if a>=s: u=n
    return u
path = Path(sys.argv[1]); only=set(sys.argv[2:])
parts = re.split(r'^//// (func_[0-9A-F]{8}(?: \w+)?)[^\n]*\n', path.read_text(), flags=re.M)
fix = lambda s: s.replace('extern "C"', 'EXTERN_C').strip('\n')
header = Path('include/game/a2/a2.h')
h = header.read_text()
def add(lines):
    global h
    new=[l for l in lines if l.strip() and l not in h]
    if new:
        i=h.rindex('#endif'); h=h[:i]+'\n'.join(new)+'\n'+h[i:]
add(fix(parts[0]).split('\n'))
n=0; texts={}
for label, body in zip(parts[1::2], parts[2::2]):
    name=label.split()[0]
    if (only and label not in only) or (not only and label!=name): continue
    u=unit(name)
    t=texts.get(u) or Path(f'src/main/{u}.cpp').read_text()
    line=f'INCLUDE_ASM("asm/main/nonmatchings/{u}", {name});'
    assert line in t, name
    lines=fix(body).split('\n')
    k=0
    while k<len(lines) and ((lines[k].startswith('EXTERN_C') and lines[k].rstrip().endswith(';')) or (lines[k].startswith('struct ') and lines[k].rstrip().endswith('};')) or lines[k].startswith('#define')):
        k+=1
    add(lines[:k])
    t=t.replace(line,'\n'.join(lines[k:]))
    texts[u]=t; n+=1
for u,t in texts.items(): Path(f'src/main/{u}.cpp').write_text(t,newline='\n')
header.write_text(h,newline='\n')
print('landed',n)
