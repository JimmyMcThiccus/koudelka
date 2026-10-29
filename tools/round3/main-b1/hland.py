# usage: hland.py file.cpp... : for each file, land the first matching variant of each still-asm function
import re, subprocess, sys
from pathlib import Path
sys.path.insert(0, 'scratch_c')
from mb import unit_of
H = Path('include/game/b/decls_b.h')
def add_prelude(pre):
    h = H.read_text()
    chunks = [c.strip('\n') for c in re.split(r'\n\s*\n', pre.replace('extern "C"', 'EXTERN_C')) if c.strip()]
    new = [c for c in chunks if c not in h]
    if new:
        i = h.rindex('#endif')
        H.write_text(h[:i] + '\n\n'.join(new) + '\n\n' + h[i:], newline='\n')
def filt(pre):
    # drop prelude chunks whose struct / extern name the header already defines
    h = H.read_text()
    out = []
    items, cur, depth = [], [], 0
    for line in pre.splitlines():
        cur.append(line)
        depth += line.count('{') - line.count('}')
        if depth == 0 and (line.rstrip().endswith(';') or line.rstrip().endswith('}') or not line.strip()):
            items.append('\n'.join(cur)); cur = []
    if cur:
        items.append('\n'.join(cur))
    for c in items:
        if not c.strip():
            continue
        m = re.search(r'^struct (\w+)\s*(:[^{]*)?\{', c, re.M)
        if m and re.search(r'^struct ' + m.group(1) + r'\b', h, re.M):
            continue
        m = re.search(r'^extern "C" [^\n;]*?\b(\w+)\s*(\(|\[|;)', c, re.M)
        if m and not c.lstrip().startswith('struct') and re.search(r'\b' + m.group(1) + r'\b', h) and c.count('\n') == 0:
            continue
        out.append(c)
    return '\n\n'.join(out) + '\n\n'

for f in sys.argv[1:]:
    t = Path(f).read_text(errors='ignore')
    parts = re.split(r'^(//// func_[0-9A-F]{8}[^\n]*\n)', t, flags=re.M)
    pre = filt(parts[0])
    for hdr, body in zip(parts[1::2], parts[2::2]):
        name = re.search(r'func_[0-9A-F]{8}', hdr).group(0)
        u = unit_of(name)
        if not u: continue
        tmp = Path('scratch_c/_h.cpp'); tmp.write_text(pre + hdr + body)
        r = subprocess.run([sys.executable, 'scratch_c/mb.py', str(tmp)], capture_output=True, text=True)
        if not r.stdout.strip().splitlines()[-1].startswith('1 ok'):
            # prelude may already be in header -> retry without prelude
            tmp.write_text(hdr + body)
            r = subprocess.run([sys.executable, 'scratch_c/mb.py', str(tmp)], capture_output=True, text=True)
            if not r.stdout.strip().splitlines()[-1].startswith('1 ok'):
                continue
            usepre = False
        else:
            usepre = True
        if usepre: add_prelude(pre)
        src = u.read_text(); line = f'INCLUDE_ASM("asm/main/nonmatchings/{u.stem}", {name});'
        u.write_text(src.replace(line, body.replace('extern "C"', 'EXTERN_C').strip('\n')), newline='\n')
        print('landed', name, 'from', f, flush=True)
