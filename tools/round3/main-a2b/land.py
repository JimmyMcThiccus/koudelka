"""usage: land.py file.cpp [labels...]  -- prelude + leading decl lines of each section go to include/game/a2b/a2b.h"""
import re, sys
from pathlib import Path
path = Path(sys.argv[1]); only=set(sys.argv[2:])
parts = re.split(r'^//// (func_[0-9A-F]{8}(?: \w+)?)[^\n]*\n', path.read_text(), flags=re.M)
fix = lambda s: s.replace('extern "C" ', 'EXTERN_C ').strip('\n')
header = Path('include/game/a2b/a2b.h'); h = header.read_text()
def add(lines):
    global h
    new=[l for l in lines if l.strip() and l not in h]
    if new:
        i=h.rindex('#endif'); h=h[:i]+'\n'.join(new)+'\n'+h[i:]
pre=fix(parts[0])
if pre.strip() and pre not in h:
    j=h.rindex('#endif'); h=h[:j]+pre+chr(10)+h[j:]
UNITS=[(0x8003C510,'u_8003C510'),(0x8003F7E8,'u_8003F7E8'),(0x80044BE4,'u_80044BE4'),(0x80045850,'u_80045850')]
def unit(n):
    a=int(n[5:13],16); u=None
    for st,nm in UNITS:
        if a>=st: u=nm
    return u
texts={}; n=0
for label, body in zip(parts[1::2], parts[2::2]):
    name=label.split()[0]
    if only and label not in only and name not in only: continue
    u=unit(name); t=texts.get(u) or Path(f'src/main/{u}.cpp').read_text()
    line=f'INCLUDE_ASM("asm/main/nonmatchings/{u}", {name});'
    assert line in t, name
    lines=fix(body).split('\n'); k=0
    while k<len(lines) and ((lines[k].startswith('EXTERN_C') and lines[k].rstrip().endswith(';')) or (lines[k].startswith('struct ') and lines[k].rstrip().endswith('};')) or lines[k].startswith('#define')):
        k+=1
    add(lines[:k])
    t=t.replace(line,chr(10).join(lines[k:])); texts[u]=t; n+=1
for u,t in texts.items(): Path(f'src/main/{u}.cpp').write_text(t,newline=chr(10))
header.write_text(h,newline=chr(10)); print('landed',n)
