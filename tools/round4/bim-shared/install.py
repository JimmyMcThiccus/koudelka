import sys,re
mod,fn,path=sys.argv[1:4]
f=f'src/bim/{mod}/{mod}.cpp'
t=open(f).read()
body=open(path).read()
body=body.split('#include "bim/shared.h"\n',1)[1].strip('\n')
pat=re.compile(r'INCLUDE_ASM\("[^"]+", %s\);'%fn)
assert pat.search(t),(mod,fn)
t=pat.sub(lambda m: body,t,1)
if '"bim/shared.h"' not in t: t=t.replace('#include "common.h"\n','#include "common.h"\n#include "bim/shared.h"\n',1)
open(f,'w').write(t)
