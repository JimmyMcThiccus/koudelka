import itertools,subprocess,re
loads={'c':'int c = q[2];','a':'int a = q[0];','b':'int b = q[1];','e':'int e = q[3];'}
stores={'c':'AT(d, int, 0x24) = c;','a':'AT(d, int, 0xC) = a;','b':'AT(d, int, 0x10) = b;','e':'AT(d, int, 0x28) = e;'}
tmpl='''EXTERN_C int *func_80049420_t(int *p, int *q) asm("func_80049420");
EXTERN_C int *func_80049420_t(int *p, int *q)
{
    int n = p[0];
    p[0] = n + 1;
    int k = n / 3;
    int m = n - k * 3;
%s
    char *d = (char *)p + (m * 8 + k * 48);
%s
    return p;
}
'''
for pos in ('before','after'):
  for lo in itertools.permutations('caeb'):
    for so in itertools.permutations('caeb'):
        L='\n'.join('    '+loads[x] for x in lo); S='\n'.join('    '+stores[x] for x in so)
        src=tmpl%(L,S)
        if pos=='after':
            src=tmpl%('',S); src=src.replace('    char *d','%s\n    char *d'%L)
        open('scratch_c/g_t.cpp','w').write(src)
        r=subprocess.run(['sh','scratch_c/mk.sh','scratch_c/g_t.cpp','func_80049420','u_80045850'],capture_output=True,text=True)
        m=re.search(r'(\d+) differing',r.stdout+r.stderr)
        if m and int(m.group(1))==0:
            print('FOUND',pos,lo,so); open('scratch_c/g_found.cpp','w').write(src); raise SystemExit
print('none')
