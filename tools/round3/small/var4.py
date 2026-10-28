import subprocess, sys, itertools
pre = open('scratch_c/b4.cpp').read().split('//// func_80028A24')[0]
tmpl = pre + "//// func_80028A24 src/main/u_80028428.cpp\n" + """EXTERN_C void func_80028184(void *p);
EXTERN_C void func_80028A24(S_Spr2 *q)
{
    register S_Sp2 *p asm("$9") = (S_Sp2 *)q;
    if (p->unk8) {
%s
    }
    func_80028184(p);
}
"""
bodies = {
'a': """        int i = D_800B4CF0;
        DM2 *s = &p->dm[i];
        DM2 *d = &p->dm[i ^ 1];
        SP2 *s2 = &p->sp[i];
        SP2 *d2 = &p->sp[i ^ 1];
        d->c = s->c;
        d2->c = s2->c;""",
'b': """        int i = D_800B4CF0;
        int j = i ^ 1;
        DM2 *s = &p->dm[i];
        DM2 *d = &p->dm[j];
        d->c = s->c;
        SP2 *s2 = &p->sp[i];
        SP2 *d2 = &p->sp[j];
        d2->c = s2->c;""",
'c': """        int i = D_800B4CF0;
        DM2 *d = &p->dm[i ^ 1];
        DM2 *s = &p->dm[i];
        d->c = s->c;
        SP2 *d2 = &p->sp[i ^ 1];
        SP2 *s2 = &p->sp[i];
        d2->c = s2->c;""",
'd': """        int i = D_800B4CF0;
        p->dm[i ^ 1].c = p->dm[i].c;
        p->sp[i ^ 1].c = p->sp[i].c;""",
'e': """        int i = D_800B4CF0;
        int j = i ^ 1;
        DM2 *d = &p->dm[j];
        DM2 *s = &p->dm[i];
        SP2 *d2 = &p->sp[j];
        SP2 *s2 = &p->sp[i];
        d->c = s->c;
        d2->c = s2->c;""",
}
for k,b in bodies.items():
    open('scratch_c/v4.cpp','w').write(tmpl % b)
    r = subprocess.run([sys.executable,'scratch_c/multi.py','scratch_c/v4.cpp'],capture_output=True,text=True)
    print(k, r.stdout.strip().splitlines()[0])
