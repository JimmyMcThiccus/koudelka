import sys
body = open('scratch_c/bb538.body').read()
vars_ = open('scratch_c/bb538.vars').read().split('\n====\n')
out=[]
for i,v in enumerate(vars_):
    out.append(f"### func_800BB538@{i}\n{v}\n{body}")
open('scratch_c/t2.txt','w').write("\n".join(out))
