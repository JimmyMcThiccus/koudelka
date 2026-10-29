import re,glob,os,sys
ref=None
n=0
for f in sorted(glob.glob('src/bim/w*/*.cpp')):
    m=os.path.basename(f)[:-4]
    text=open(f).read()
    def repl(mt):
        global n
        fn=mt.group(1)
        sp=f'asm/bim/{m}/nonmatchings/{m}/{fn}.s'
        if not os.path.exists(sp): return mt.group(0)
        s=open(sp).read()
        if 'nonmatching %s, 0x7C'%fn not in s or '__builtin_new' not in s: return mt.group(0)
        ins=[re.sub(r'^\s*/\*.*?\*/\s*','',l).strip() for l in s.splitlines() if '/*' in l]
        sz=re.search(r'jal\s+__builtin_new\n\s*/\*.*?\*/\s*addiu\s+\$a0, \$zero, (0x[0-9A-F]+)',s)
        callee=re.search(r'jal\s+(func_[0-9A-F]+)',s)
        if not sz or not callee: return mt.group(0)
        # signature check: replace variable parts
        sig=[re.sub(r'func_[0-9A-F]+|0x[0-9A-F]+','X',i) for i in ins]
        global ref
        if ref is None: ref=sig
        if sig!=ref: return mt.group(0)
        n+=1
        c=callee.group(1)
        return (f'EXTERN_C void *{c}(void *self, int in_chrg, int a, int b, int c, int d, int e);\n\n'
                f'EXTERN_C void *{fn}(int a, short b, int c, int d, int e)\n{{\n'
                f'    return {c}(operator new({sz.group(1)}), 1, a, b, c, d, e);\n}}')
    new=re.sub(r'INCLUDE_ASM\("[^"]+", (func_[0-9A-F]+)\);',repl,text)
    if new!=text: open(f,'w').write(new)
print(n,'factories')
