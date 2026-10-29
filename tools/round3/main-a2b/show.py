import re, sys
lines=open('scratch_c/sizes.txt').read().split('\n')
lo,hi=int(sys.argv[1]),int(sys.argv[2])
names=set(sys.argv[3:])
for l in lines:
    if not l: continue
    s,f,u=l.split()
    s=int(s)
    if names and f not in names: continue
    if not names and not (lo<=s<=hi): continue
    t=open(f'asm/main/nonmatchings/{u}/{f}.s').read()
    out=[]
    for line in t.splitlines():
        x=re.match(r'\s*/\* \S+ \S+ \S+ \*/\s+(.*)',line)
        if x: out.append(re.sub(r'\s+',' ',x.group(1)))
        elif re.match(r'\s*\.L\w+:',line): out.append(line.strip())
        elif 'dlabel' in line and 'end' not in line: out.append('['+line.strip()+']')
    print(f'{f} ({s}): '+' | '.join(out))
