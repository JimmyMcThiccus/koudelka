out=[]
i=0
for mt in ['int','unsigned char']:
  for vt in ['int','unsigned char']:
    for nt in ['int','unsigned char']:
      for loop in range(4):
          if loop==0: body='''for (i = 0; i < 3; ) {
        c = &D_800B4D10[i];
        v = D_800B4D10[++i];
        m &= v;
        *c = v;
    }'''
          elif loop==1: body='''i = 0;
    do {
        c = &D_800B4D10[i];
        v = D_800B4D10[++i];
        m &= v;
        *c = v;
    } while (i < 3);'''
          elif loop==2: body='''for (i = 0; i < 3; ) {
        c = &D_800B4D10[i];
        i++;
        v = D_800B4D10[i];
        *c = v;
        m &= v;
    }'''
          else: body='''i = 0;
    do {
        c = &D_800B4D10[i];
        i++;
        v = D_800B4D10[i];
        *c = v;
        m &= v;
    } while (i < 3);'''
          out.append(f'''//// func_80035C30 v{i}
EXTERN_C int func_80035C30(int a)
{{
    {nt} na = (a ^ 2) & 0x12;
    {mt} m = na;
    int i; {vt} v; unsigned char *c;
    {body}
    D_800B4D10[3] = na;
    if (m) func_8003831C(&D_800AC86C, m);
    return m;
}}
''')
          i+=1
open('scratch_c/w5.cpp','w').write(''.join(out))
