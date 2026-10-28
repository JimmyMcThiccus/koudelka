import re, sys, glob
for fn in sys.argv[1:]:
    hits = glob.glob(f'asm/**/{fn}.s', recursive=True)
    if not hits: print(fn, 'NOT FOUND'); continue
    ins=[]
    for line in open(hits[0]).read().splitlines():
        x = re.match(r'\s*/\* \S+ (\S+) \S+ \*/\s+(.*)', line)
        if x: ins.append(re.sub(r'\s+', ' ', x.group(2)))
        elif line.strip().startswith('.L') or line.strip().startswith('glabel'): ins.append(line.strip())
    print(fn + ' [' + hits[0] + ']:\n  ' + '\n  '.join(ins))
