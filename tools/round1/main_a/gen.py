"""Generate C++ for trivial accessor-style functions in main_a.
usage: gen.py MAXSIZE [--apply]  -> writes scratch_c/gen_header.h and scratch_c/gen_funcs.json
"""
import re, os, sys, json

D = 'asm/main/nonmatchings/game'
LO, HI = 0x800186B0, 0x80054A2C
LTYPE = {'lw': 'int', 'lh': 'short', 'lhu': 'unsigned short', 'lb': 'signed char', 'lbu': 'unsigned char'}
STYPE = {'sw': 'int', 'sh': 'short', 'sb': 'char'}
SIZE = {'int': 4, 'short': 2, 'unsigned short': 2, 'signed char': 1, 'unsigned char': 1, 'char': 1}


def funcs(maxsize):
    for f in sorted(os.listdir(D)):
        m = re.match(r'func_([0-9A-F]{8})\.s', f)
        if not m:
            continue
        a = int(m.group(1), 16)
        if not (LO <= a < HI):
            continue
        t = open(os.path.join(D, f)).read()
        mm = re.search(r'nonmatching \S+, (0x[0-9A-F]+)', t)
        if not mm:
            continue
        size = int(mm.group(1), 16)
        if size > maxsize:
            continue
        ins = []
        bad = False
        for line in t.splitlines():
            x = re.match(r'\s*/\* \S+ \S+ \S+ \*/\s+(.*)', line)
            if x:
                ins.append(re.sub(r'\s+', ' ', x.group(1)).strip())
            elif line.strip().startswith('.L') or '.word' in line:
                bad = True
        if not bad:
            yield a, ins


def num(s):
    return int(s, 16) if s.lower().startswith(('0x', '-0x')) else int(s)


def hx(n):
    return f'0x{n:X}' if n >= 0 else f'-0x{-n:X}'


def classify(ins):
    """Return (kind, info) or None. kind decides template; info includes field accesses on a0."""
    body = [i for i in ins if i not in ('jr $ra', 'nop')]
    p = lambda pat, s: re.fullmatch(pat, s)
    if not body:
        return ('void', {})
    if len(body) == 1:
        b = body[0]
        if b == 'addu $v0, $zero, $zero':
            return ('ret_const', {'k': 0})
        if m := p(r'addiu \$v0, \$zero, (-?0x[0-9A-F]+)', b):
            return ('ret_const', {'k': num(m[1])})
        if b == 'addu $v0, $a0, $zero':
            return ('ret_a0', {})
        if b == 'addu $v0, $a1, $zero':
            return ('ret_a1', {})
        if m := p(r'addiu \$v0, \$a0, (0x[0-9A-F]+)', b):
            return ('addr', {'off': num(m[1]), 'fields': [(num(m[1]), None)]})
        if m := p(r'(s[whb]) \$(a1|zero), (0x[0-9A-F]+)\(\$a0\)', b):
            return ('set' if m[2] == 'a1' else 'clear', {'off': num(m[3]), 'fields': [(num(m[3]), STYPE[m[1]])]})
        if m := p(r'(l[whb]u?) \$v0, (0x[0-9A-F]+)\(\$a0\)', b):
            return ('get', {'off': num(m[2]), 'fields': [(num(m[2]), LTYPE[m[1]])]})
        if m := p(r'lw \$v0, %gp_rel\((D_[0-9A-F]+)\)\(\$gp\)', b):
            return ('gget', {'sym': m[1], 'gt': 'int'})
        if m := p(r'sw \$a0, %gp_rel\((D_[0-9A-F]+)\)\(\$gp\)', b):
            return ('gset', {'sym': m[1], 'gt': 'int'})
        if m := p(r'sh \$zero, %gp_rel\((D_[0-9A-F]+)\)\(\$gp\)', b):
            return ('gclear', {'sym': m[1], 'gt': 'short'})
        return None
    if len(body) == 2:
        a, b = body
        if (m := p(r'(l[whb]u?) \$v0, (0x[0-9A-F]+)\(\$a0\)', a)):
            off, t = num(m[2]), LTYPE[m[1]]
            f = [(off, t)]
            if (n := p(r'andi \$v0, \$v0, (0x[0-9A-F]+)', b)):
                return ('get_expr', {'off': off, 'fields': f, 'expr': f' & {hx(num(n[1]))}'})
            if b == 'sltiu $v0, $v0, 0x1':
                return ('get_expr', {'off': off, 'fields': f, 'expr': ' == 0'})
            if b == 'sltu $v0, $zero, $v0':
                return ('get_expr', {'off': off, 'fields': f, 'expr': ' != 0'})
            if b == 'slti $v0, $v0, 0x1':
                return ('get_expr', {'off': off, 'fields': f, 'expr': ' < 1'})
            if (n := p(r'(s[wh]) \$a1, (0x[0-9A-F]+)\(\$a0\)', b)) and num(n[2]) == off and SIZE[STYPE[n[1]]] == SIZE[t]:
                return ('swap', {'off': off, 'fields': f})
            return None
        if (m := p(r'addiu \$v0, \$zero, (0x[0-9A-F]+)', a)) and (n := p(r'(s[wh]) \$v0, (0x[0-9A-F]+)\(\$a0\)', b)):
            return ('set_const', {'off': num(n[2]), 'k': num(m[1]), 'fields': [(num(n[2]), STYPE[n[1]])]})
        if a == 'addu $v0, $a0, $zero' and (n := p(r'(s[wh]) \$(a1|zero), (0x[0-9A-F]+)\(\$v0\)', b)):
            return ('set_ret' if n[2] == 'a1' else 'clear_ret', {'off': num(n[3]), 'fields': [(num(n[3]), STYPE[n[1]])]})
        if a == 'addu $v0, $a1, $zero' and (n := p(r'(s[wh]) \$v0, (0x[0-9A-F]+)\(\$a0\)', b)):
            return ('set_ret_v', {'off': num(n[2]), 'fields': [(num(n[2]), STYPE[n[1]])]})
        if (m := p(r'(s[wh]) \$a1, (0x[0-9A-F]+)\(\$a0\)', a)) and (n := p(r'(s[wh]) \$a2, (0x[0-9A-F]+)\(\$a0\)', b)):
            return ('set2', {'off': num(m[2]), 'off2': num(n[2]),
                             'fields': [(num(m[2]), STYPE[m[1]]), (num(n[2]), STYPE[n[1]])]})
        return None
    return None


def compatible(t1, t2):
    if t1 is None or t2 is None:
        return True
    if SIZE[t1] != SIZE[t2]:
        return False
    return True


def merge(t1, t2):
    if t1 is None:
        return t2
    if t2 is None:
        return t1
    # prefer load types (they carry signedness)
    if t1 in ('short', 'char'):
        return t2
    return t1


def main():
    maxsize = int(sys.argv[1])
    items = []
    for a, ins in funcs(maxsize):
        c = classify(ins)
        if c is None:
            print(f'skip {a:08X}: {" | ".join(ins)}', file=sys.stderr)
            continue
        items.append((a, c))

    # cluster functions that touch a0 fields
    clusters = []
    cur = None
    last = 0
    for a, (kind, info) in items:
        fl = info.get('fields')
        if not fl:
            continue
        ok = cur is not None and a - last <= 0x100
        if ok:
            for off, t in fl:
                for off2, t2 in cur['fields'].items():
                    s1 = SIZE[t] if t else 1
                    s2 = SIZE[t2] if t2 else 1
                    if off == off2:
                        if not compatible(t, t2):
                            ok = False
                    elif off < off2 + s2 and off2 < off + s1:
                        ok = False
        if not ok:
            cur = {'name': f'S_{a:08X}', 'fields': {}, 'funcs': []}
            clusters.append(cur)
        for off, t in fl:
            cur['fields'][off] = merge(cur['fields'].get(off), t)
        cur['funcs'].append(a)
        info['struct'] = cur['name']
        last = a

    hdr = []
    for c in clusters:
        hdr.append(f'typedef struct {c["name"]} {{')
        pos = 0
        for off in sorted(c['fields']):
            t = c['fields'][off] or 'int'
            if t == 'char':
                t = 'unsigned char'
            if off % SIZE[t]:
                t = 'unsigned char'
            if off > pos:
                hdr.append(f'    char pad{pos:X}[0x{off - pos:X}];')
            hdr.append(f'    {t} unk{off:X};')
            pos = off + SIZE[t]
            c['fields'][off] = t
        hdr.append(f'}} {c["name"]};')
        hdr.append('')

    globs = {}
    code = {}
    for a, (kind, info) in items:
        n = f'func_{a:08X}'
        S = info.get('struct')
        off = info.get('off')
        fld = f'unk{off:X}' if off is not None else None
        if kind == 'void':
            s = f'EXTERN_C void {n}()\n{{\n}}'
        elif kind == 'ret_const':
            s = f'EXTERN_C int {n}()\n{{\n    return {hx(info["k"]) if abs(info["k"]) > 9 else info["k"]};\n}}'
        elif kind == 'ret_a0':
            s = f'EXTERN_C void *{n}(void *p)\n{{\n    return p;\n}}'
        elif kind == 'ret_a1':
            s = f'EXTERN_C void *{n}(void *p, void *q)\n{{\n    return q;\n}}'
        elif kind == 'addr':
            s = f'EXTERN_C void *{n}({S} *p)\n{{\n    return &p->{fld};\n}}'
        elif kind == 'set':
            s = f'EXTERN_C void {n}({S} *p, int v)\n{{\n    p->{fld} = v;\n}}'
        elif kind == 'clear':
            s = f'EXTERN_C void {n}({S} *p)\n{{\n    p->{fld} = 0;\n}}'
        elif kind == 'set_const':
            s = f'EXTERN_C void {n}({S} *p)\n{{\n    p->{fld} = {info["k"]};\n}}'
        elif kind == 'get':
            s = f'EXTERN_C int {n}({S} *p)\n{{\n    return p->{fld};\n}}'
        elif kind == 'get_expr':
            s = f'EXTERN_C int {n}({S} *p)\n{{\n    return p->{fld}{info["expr"]};\n}}'
        elif kind == 'swap':
            s = f'EXTERN_C int {n}({S} *p, int v)\n{{\n    int old = p->{fld};\n    p->{fld} = v;\n    return old;\n}}'
        elif kind == 'set_ret':
            s = f'EXTERN_C {S} *{n}({S} *p, int v)\n{{\n    p->{fld} = v;\n    return p;\n}}'
        elif kind == 'clear_ret':
            s = f'EXTERN_C {S} *{n}({S} *p)\n{{\n    p->{fld} = 0;\n    return p;\n}}'
        elif kind == 'set_ret_v':
            s = f'EXTERN_C int {n}({S} *p, int v)\n{{\n    p->{fld} = v;\n    return v;\n}}'
        elif kind == 'set2':
            s = (f'EXTERN_C void {n}({S} *p, int a, int b)\n{{\n    p->{fld} = a;\n'
                 f'    p->unk{info["off2"]:X} = b;\n}}')
        elif kind in ('gget', 'gset', 'gclear'):
            globs[info['sym']] = info['gt']
            g = info['sym']
            if kind == 'gget':
                s = f'EXTERN_C int {n}()\n{{\n    return {g};\n}}'
            elif kind == 'gset':
                s = f'EXTERN_C void {n}(int v)\n{{\n    {g} = v;\n}}'
            else:
                s = f'EXTERN_C void {n}()\n{{\n    {g} = 0;\n}}'
        code[n] = s
    for g, t in sorted(globs.items()):
        hdr.append(f'EXTERN_C {t} {g};')
    open('scratch_c/gen_header.h', 'w').write('\n'.join(hdr) + '\n')
    json.dump(code, open('scratch_c/gen_funcs.json', 'w'), indent=1)
    print(f'{len(code)} functions, {len(clusters)} structs')


main()
