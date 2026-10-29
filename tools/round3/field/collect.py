# collect.py out.txt file:section[=newname] ...   copy sections from scratch files into out.txt
import re, sys
out=[]
for spec in sys.argv[2:]:
    f,s=spec.split(':')
    t=open(f).read()
    pre,*parts=re.split(r"^### (\S+)\s*$",t,flags=re.M)
    d=dict(zip(parts[0::2],parts[1::2]))
    out.append("### "+s.split('@')[0]+"\n"+d[s])
open(sys.argv[1],'a').write("\n".join(out)+"\n")
