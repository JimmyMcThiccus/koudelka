"""Adapt a landed twin's C to a remaining function.

gen(target_path, twin_path) -> (name, [candidates]).  Callees are remapped by call position, differing
immediates by aligned-instruction diff; every callee is called through an asm("name") alias so module
definitions can't clash.
"""
import difflib, os, re

DECL = re.compile(r'^EXTERN_C [^\n;{]*;\n', re.M)


def jals(t):
    return re.findall(r'jal\s+(\w+)', t)


def ins(t):
    return [re.sub(r'\s+', ' ', re.sub(r'^\s*/\*.*?\*/\s*', '', l).strip()) for l in t.splitlines() if '/*' in l]


def find_source(mod, name):
    """C text of `name` as compiled in module `mod` (follows the shared #include)."""
    src = open(f'src/bim/{mod}/{mod}.cpp').read()
    base = re.sub(r'_\d+$', '', name)
    for text in (src, open(f'src/bim/shared/{base}.cpp').read() if os.path.exists(f'src/bim/shared/{base}.cpp') else ''):
        for nm in (name, base):
            m = re.search(r'^EXTERN_C [^\n]*\b%s\(' % nm, text, re.M)
            if m:
                i = text.index('{', m.end())
                d = 0
                for j in range(i, len(text)):
                    d += text[j] == '{'
                    d -= text[j] == '}'
                    if d == 0:
                        break
                body = text[m.start():j + 1]
                if nm != name:
                    body = body.replace(nm + '(', name + '(', 1)
                return body
    raise KeyError(name)


def imm_map(a, b):
    out = {}
    sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == 'replace' and i2 - i1 == j2 - j1:
            for x, y in zip(a[i1:i2], b[j1:j2]):
                if x.split(' ')[0] != y.split(' ')[0]:
                    continue
                nx = re.findall(r'-?0x[0-9A-F]+', x)
                ny = re.findall(r'-?0x[0-9A-F]+', y)
                if len(nx) == len(ny):
                    for u, v in zip(nx, ny):
                        if u != v:
                            out[int(u, 16)] = int(v, 16)
    return out


def gen(target, twin):
    tt, wt = open(target).read(), open(twin).read()
    name = re.search(r'glabel (\w+)', tt).group(1)
    tname = re.search(r'glabel (\w+)', wt).group(1)
    tmod = twin.replace('\\', '/').split('/')[2]
    body = find_source(tmod, tname)
    body = re.sub(r'\b%s\(' % tname, name + '(', body, count=1)
    ja, jb = jals(wt), jals(tt)
    if len(ja) != len(jb):
        raise ValueError('call count %d vs %d' % (len(ja), len(jb)))
    cmap = {}
    for x, y in zip(ja, jb):
        if cmap.get(x, y) != y:
            raise ValueError('ambiguous callee ' + x)
        cmap[x] = y
    # rename callee identifiers (also _c / _a style aliases of them)
    used = set()

    def ren(m):
        ident, suffix = m.group(1), m.group(2) or ''
        if ident in cmap:
            used.add((ident, suffix))
            return cmap[ident] + '_t' + suffix
        return m.group(0)
    body = re.sub(r'\b((?:func|bimf)_[0-9A-Fa-f]{8}(?:_\d+)?)(_[a-z])?\b(?=\s*\()', ren, body)
    # immediates
    im = imm_map(ins(wt), ins(tt))
    cands = []
    variants = [body]
    if im:
        b2 = body
        for u, v in im.items():
            for fmt in ('0x%X', '%d'):
                b2 = re.sub(r'(?<![\w.])%s(?![\w.])' % re.escape(fmt % u), (fmt % v) if v >= 0 or fmt == '%d' else '%d' % v, b2)
        variants = [b2, body]
    # declarations: alias every renamed callee with the twin's declared prototype
    twsrc = open(f'src/bim/{tmod}/{tmod}.cpp').read()
    base = re.sub(r'_\d+$', '', tname)
    if os.path.exists(f'src/bim/shared/{base}.cpp'):
        twsrc += open(f'src/bim/shared/{base}.cpp').read()
    twsrc += open('include/bim/shared.h').read() + open('include/bim/bim.h').read() + open('include/shared/exe.h', errors='ignore').read()
    decls = []
    for ident, suffix in sorted(used):
        m = re.search(r'^EXTERN_C ([^\n(]*?)\b%s%s\(([^\n]*?)\)\s*(?:asm\("[^"]*"\))?;' % (re.escape(ident), re.escape(suffix)), twsrc, re.M) or \
            re.search(r'^EXTERN_C ([^\n(]*?)\b%s\(([^\n]*?)\)' % re.escape(ident), twsrc, re.M)
        if not m:
            raise ValueError('no prototype for ' + ident + suffix)
        decls.append(f'EXTERN_C {m.group(1)}{cmap[ident]}_t{suffix}({m.group(2)}) asm("{cmap[ident]}");')
    for v in variants:
        cands.append('\n'.join(decls) + '\n\n' + v)
    return name, cands
