import re,subprocess,sys
draft,h,unit=sys.argv[1:4]
src=open(draft).read()
rets=[m for m in re.finditer(r'return ([^;]+);',src)]
out_path=f'src/bim/shared/bimf_{h}.cpp'
for k,m in enumerate(rets):
    val=m.group(1)
    new=src[:m.start()]+'{ if (p || flags) return %s; else return %s; }'%(val,val)+src[m.end():]
    open(out_path,'w').write(new)
    out=subprocess.run([sys.executable,'tools/try_compile.py',out_path,f'bimf_{h}','--unit',unit],capture_output=True,text=True).stdout.strip().split('\n')[-1]
    print(k,val,out)
