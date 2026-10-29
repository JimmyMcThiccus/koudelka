import re
out=[]
for u in ['u_8003C510','u_8003F7E8','u_80044BE4','u_80045850']:
  src=open(f'src/main/{u}.cpp').read()
  for m in re.finditer(r'INCLUDE_ASM\("([^"]+)", (\w+)\)', src):
    d,f=m.groups()
    t=open(f'{d}/{f}.s').read()
    sz=int(re.search(r'nonmatching \S+, (0x[0-9A-F]+)',t).group(1),16)
    out.append((sz,f,u))
out.sort()
open('scratch_c/sizes.txt','w').write('\n'.join(f'{s} {f} {u}' for s,f,u in out))
print(len(out)); print(' '.join(f'{f[5:]}:{s}' for s,f,u in out))
