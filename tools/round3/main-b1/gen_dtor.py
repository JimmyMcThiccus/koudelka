import sys
HDR='''struct VEntB { short d; short i; void *f; };
struct VTabB50 { VEntB e[10]; };
struct S_VBB { VEntB *vt; };
struct S_DtorB { S_VBB *vb; char pad4[0x28]; void **vt2C; };
'''
def gen(name,vt2c,tab,off,callee):
    return f'''//// {name}
EXTERN_C void {name}(S_DtorB *p, int flags)
{{
    p->vt2C = {vt2c};
    p->vb->vt = (VEntB *){tab}.e;
    if (!flags) {{
        VTabB50 tmp = {tab};
        p->vb->vt = tmp.e;
        char *q = (char *)p->vb - {off};
        int adj = (char *)p - q;
        tmp.e[1].d = {tab}.e[1].d + adj;
        tmp.e[5].d = {tab}.e[5].d + adj;
        tmp.e[7].d = {tab}.e[7].d + adj;
        tmp.e[9].d = {tab}.e[9].d + adj;
    }}
    {callee}(p, 0);
    if (flags & 2)
        func_8001A610(p->vb, 0);
    if (flags & 1)
        operator delete(p);
}}
'''
items=[('func_8005CF78','D_80014858','D_80014808','0x38','func_8005BDA4'),
('func_8005DC44','D_80014A08','D_800149B8','0x38','func_8005BDA4'),
('func_800593A0','D_80014180','D_80014130','0x44','func_8005BDA4'),
('func_80064188','D_800150BC','D_8001506C','0x3C','func_8005BDA4')]
out=''
decl=set()
for n,v,t,o,c in items:
    out+=gen(n,v,t,o,c)+'\n'
    decl.add(f'EXTERN_C const VTabB50 {t};'); decl.add(f'EXTERN_C void *{v}[];')
pre=HDR+'\n'.join(sorted(decl))+'\n'
open('scratch_c/b34.cpp','w').write(pre+out)
