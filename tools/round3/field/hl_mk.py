import sys
# usage: hl_mk.py file base@n newn "old" "new" [...]
f,base,newn=sys.argv[1:4]
s=open(f).read()
secs=s.split("### ")
cur=[x for x in secs if x.startswith(base+"\n")][0]
for i in range(4,len(sys.argv),2):
    assert sys.argv[i] in cur, sys.argv[i]
    cur=cur.replace(sys.argv[i],sys.argv[i+1])
name=base.split('@')[0]
cur=name+"@"+newn+cur[len(base):]
open(f,'a').write("\n### "+cur)
