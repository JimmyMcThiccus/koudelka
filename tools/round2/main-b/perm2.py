import itertools
from pathlib import Path
st = {
 'v178': "        FIELD_AT(p, void *, 0x0) = D_80010178;\n",
 'f4':   "        FIELD_AT(p, int, 0x4) = 0;\n",
 'v300': "        FIELD_AT(p, void *, 0x0) = D_80010300;\n",
 'f8':   "        FIELD_AT(p, short, 0x8) = 2;\n",
 'fA':   "        FIELD_AT(p, short, 0xA) = 8;\n",
 'v2D0': "        FIELD_AT(p, void *, 0x0) = D_800102D0;\n",
 'fC':   "        FIELD_AT(p, int, 0xC) = 0;\n",
 'f10':  "        FIELD_AT(p, int, 0x10) = d;\n",
}
out = 'extern "C" int func_80043700(void *self, int a, void *b, int c);\n'
orders = [
 'v178 f4 v300 f8 fA v2D0 fC f10', 'v178 fC f4 v300 f8 fA v2D0 f10', 'v178 f4 v300 f8 fA v2D0 f10 fC',
 'v178 f4 v300 f8 fA fC f10 v2D0', 'v178 v300 f8 fA f4 f10 fC v2D0', 'v178 f4 v300 f8 fA f10 fC v2D0',
]
for o in orders:
    body = ''.join(st[k] for k in o.split())
    out += f'''//// func_8008533C {o}
extern "C" void func_8008533C(void *self, int a, int b)
{{
    if (func_80043700(self, (short)a, self, b == 0)) {{
        int d = a + 0xF;
        char *p = (char *)func_8001CA10(0x14);
{body}        func_8001EFE4(self, p);
    }}
}}
'''
Path('scratch_c/perm2.cpp').write_text(out)
