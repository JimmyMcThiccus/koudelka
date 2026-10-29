import itertools, subprocess, sys, re
from pathlib import Path
# brute-force store order for func_8008533C message object
st = {
 'v178': "    FIELD_AT(p, void *, 0x0) = D_80010178;\n",
 'f4':   "    FIELD_AT(p, int, 0x4) = 0;\n",
 'v300': "    FIELD_AT(p, void *, 0x0) = D_80010300;\n",
 'f8':   "    FIELD_AT(p, short, 0x8) = 2;\n",
 'fA':   "    FIELD_AT(p, short, 0xA) = 8;\n",
 'v2D0': "    FIELD_AT(p, void *, 0x0) = D_800102D0;\n",
 'fC':   "    FIELD_AT(p, int, 0xC) = 0;\n",
 'f10':  "    FIELD_AT(p, int, 0x10) = a + 0xF;\n",
}
pre = '''extern "C" int func_80043700(void *self, int a, void *b, int c);
'''
out = pre
n = 0
seen = set()
for perm in itertools.permutations(st.keys()):
    pos = {k: i for i, k in enumerate(perm)}
    if not (pos['v178'] < pos['v300'] < pos['v2D0']): continue
    if not (pos['f4'] > pos['v178'] and pos['f8'] > pos['v300'] and pos['fA'] > pos['v300'] and pos['fC'] > pos['v2D0'] - 10): continue
    if not (pos['f8'] < pos['fA']): continue
    n += 1
    body = ''.join(st[k] for k in perm)
    out += f'''//// func_8008533C {' '.join(perm)}
extern "C" void func_8008533C(void *self, int a, int b)
{{
    if (func_80043700(self, (short)a, self, b == 0)) {{
        char *p = (char *)func_8001CA10(0x14);
{body}        func_8001EFE4(self, p);
    }}
}}
'''
Path('scratch_c/perm.cpp').write_text(out)
print(n)
