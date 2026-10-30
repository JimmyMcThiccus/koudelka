import re, glob, os, sys
out = []
for p in sorted(glob.glob('asm/**/nonmatchings/**/*.s', recursive=True)):
    p = p.replace(chr(92), '/')
    if p.startswith('asm/bim'): continue
    L = []
    for l in open(p).read().splitlines():
        m = re.match(r'\s*(\.L\w+):', l)
        if m: L.append(('label', m.group(1))); continue
        m = re.search(r'\*/\s+(.*)$', l)
        if m and '/*' in l: L.append(('ins', re.sub(r'\s+', ' ', m.group(1).strip())))
    # epilogue label = label after which, before jr ra, only lw/addiu sp/nop
    epi = set()
    for k, (kind, x) in enumerate(L):
        if kind != 'label': continue
        ok = False
        seg = [xx for kk, xx in L[k + 1:k + 16] if kk == 'ins']
        for n2, xx in enumerate(seg):
            if xx.startswith('jr $ra'):
                ok = not (n2 + 1 < len(seg) and re.match(r'\S+ \$v0,', seg[n2 + 1])); break
            if not (xx.startswith('lw $') and '($sp)' in xx or xx == 'nop' or xx.startswith('addiu $sp')): break
        if ok: epi.add(x)
    # find branch/jump to epi
    setv0 = False; bare = []
    for k, (kind, x) in enumerate(L):
        if kind != 'ins': continue
        m = re.match(r'(beqz|bnez|beq|bne|bltz|bgez|blez|bgtz|j)\s+(?:.*, )?(\.L\w+)$', x)
        if m and m.group(2) in epi:
            d = L[k + 1][1] if k + 1 < len(L) and L[k + 1][0] == 'ins' else ''
            if re.match(r'\S+ \$v0,', d): setv0 = True
            elif m.group(1) != 'j': bare.append((x, d))
        if x.startswith('jr $ra') and k + 1 < len(L) and re.match(r'\S+ \$v0,', L[k + 1][1]):
            setv0 = True
        # fallthrough into epi label with v0 written just before
        if kind == 'ins' and k + 1 < len(L) and L[k + 1][0] == 'label' and L[k + 1][1] in epi and re.match(r'\S+ \$v0,', x):
            setv0 = True
    if setv0 and bare:
        out.append(p)
        print(p, len(bare), bare[0])
