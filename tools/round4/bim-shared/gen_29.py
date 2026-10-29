import re,glob,os
HDR='''EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
'''
n=0
def norm(t):
    return [re.sub(r'\.L[0-9A-F]+','.L',re.sub(r'(jal|j)\s+\S+$',lambda m:m.group(1),re.sub(r'%(hi|lo)\([^)]*\)','%X',re.sub(r'^\s*/\*.*?\*/\s*','',l).strip()))) for l in t.splitlines() if '/*' in l]
def sigkey(ins):
    out=[]
    for i in ins:
        if re.match(r'(addiu +\$a1, \$zero, 0x[0-9A-F]+|addiu +\$a2, \$zero, 0x[0-9A-F]+|addu +\$a[123], \$\w+, \$\w+)$',i) and len(out)<14: out.append('ARG')
        else: out.append(i)
    return out
ref_mod,ref_fn='w0_07230563b8','bimf_29503d9b'
for f in sorted(glob.glob('src/bim/w*/*.cpp')):
    m=os.path.basename(f)[:-4]
    text=open(f).read()
    def repl(mt):
        global n
        fn=mt.group(1)
        base=re.match(r'(bimf_[0-9a-f]{8})',fn).group(1)
        sp=f'asm/bim/{m}/nonmatchings/{m}/{fn}.s'
        t=open(sp).read()
        if base not in('bimf_29503d9b','bimf_1d1122f5','bimf_cb8fde67','bimf_c744c68b'): return mt.group(0)
        names=re.findall(r'jal\s+(\w+)',t)
        assert len(names)==11,(m,fn,names)
        lines=[re.sub(r'^\s*/\*.*?\*/\s*','',l).strip() for l in t.splitlines() if '/*' in l]
        # args: evaluate a1,a2,a3 before the first jal
        reg={'$zero':0}
        for i in lines:
            if i.startswith('jal'): break
            mm=re.match(r'addiu\s+(\$\w+), (\$\w+), (-?0x[0-9A-Fa-f]+|-?\d+)',i)
            if mm: reg[mm.group(1)]=reg.get(mm.group(2),0)+int(mm.group(3),0)
            mm=re.match(r'addu\s+(\$\w+), (\$\w+), (\$\w+)',i)
            if mm and mm.group(1) in('$a1','$a2','$a3'): reg[mm.group(1)]=reg.get(mm.group(2),0)+reg.get(mm.group(3),0)
        a1,a2,a3=reg['$a1'],reg['$a2'],reg['$a3']
        # delay-slot style of the 0x10 store: retail style 'sw; j; addiu' => dummy needed
        j=[k for k,i in enumerate(lines) if i.startswith('sw') and '0x9F0' in i and lines[k+1].startswith('j')]
        dummy = bool(j)
        lastjal=max(k for k,i in enumerate(lines) if i.startswith('jal'))
        retone = lines[lastjal+2].startswith('addiu') and lines[lastjal+2].endswith('0x1')
        n+=1
        # names order: 7818,8CC0,8C0C,06b4,84C8,8350,131b,a1b3,b496,dd77,e310
        N=[x for x in names]
        decl=''
        for c in dict.fromkeys(N[3:5]+N[6:]):
            pass
        aliases=''
        for k in (3,6,7,8,9,10):
            aliases+='EXTERN_C int %s_c(void *p, unsigned *flags) asm("%s");'%(N[k],N[k])+chr(10)
        ret9='''    if (%s_c(p, flags)) {
        if (p || flags)
            return 1;
        else
            return 1;
    }'''%N[9] if dummy else '''    if (%s_c(p, flags))
        return 1;'''%N[9]
        tailret = ('    %s_c(p, flags);'%N[10]+chr(10)+'    return 1;') if retone else ('    return %s_c(p, flags);'%N[10])
        body=f'''{HDR}{aliases}
EXTERN_C int {fn}(BimMon *p, unsigned *flags)
{{
    func_800D7818(p, {a1}, {a2}, {a3}, 0, 0, 0, 0, 0);
    if (!(p->f9C8 > 0) && (*flags & 1) && func_800D8CC0(p, flags))
        return 1;
    func_800D8C0C(p);
    if (((BimV *)p)->v21((int)flags))
        return 1;
    if ({N[3]}_c(p, flags))
        return 1;
    if (func_800D84C8(p)) {{
        if (func_800D8350(p, 3)) {{
            if ((*flags & 2) && {N[6]}_c(p, flags) && !p->f9F0) {{
                p->f9F0 = 0x10;
                return 1;
            }}
            if ((*flags & 1) && {N[7]}_c(p, flags))
                return 1;
        }}
    }}
    if ({N[8]}_c(p, flags))
        return 1;
{ret9}
{tailret}
}}'''
        return body
    new=re.sub(r'INCLUDE_ASM\("[^"]+", (bimf_(?:29503d9b|1d1122f5|cb8fde67|c744c68b)(?:_\d+)?)\);',repl,text)
    if new!=text:
        if '"bim/shared.h"' not in new: new=new.replace('#include "common.h"\n','#include "common.h"\n#include "bim/shared.h"\n',1)
        open(f,'w').write(new)
print(n)
