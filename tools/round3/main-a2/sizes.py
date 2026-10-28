import re, os, sys
units = ['u_80032264','u_80033ECC','u_800372C0','u_80037398','u_8003852C']
out=[]
for u in units:
    src=open(f'src/main/{u}.cpp').read()
    for m in re.finditer(r'INCLUDE_ASM\("([^"]+)", (\w+)\)', src):
        d,f=m.groups()
        t=open(f'{d}/{f}.s').read()
        sz=int(re.search(r'nonmatching \S+, (0x[0-9A-F]+)',t).group(1),16)
        out.append((sz,f,u))
out.sort()
for s,f,u in out: print(s,f,u)
