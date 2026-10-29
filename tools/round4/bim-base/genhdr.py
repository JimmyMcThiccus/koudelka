# regenerate BimMon in include/bim/bim.h from a field list
import re
F = [
 (0x3E,"unsigned char","b3E"),(0x7D,"unsigned char","b7D"),(0x7E,"unsigned char","b7E"),(0x80,"unsigned short","s80"),
 (0x410,"short","s410"),(0x4BC,"signed char","b4BC"),(0x4CA,"short","s4CA"),
 (0x4E4,"char","b4E4"),(0x4E5,"char","b4E5"),(0x4E6,"char","b4E6"),(0x4E8,"int","f4E8"),(0x4EC,"int","f4EC"),
 (0x9A4,"int","f9A4"),(0x9C8,"int","f9C8"),(0x9CC,"int","f9CC"),(0x9D0,"int","f9D0"),(0x9D4,"int","f9D4"),(0x9D8,"int","f9D8"),
 (0x9DC,"int","f9DC"),(0x9E0,"int","f9E0"),(0x9E4,"int","f9E4"),(0x9E8,"int","f9E8"),(0x9EC,"int","f9EC"),(0x9F0,"int","f9F0"),(0x9F4,"unsigned int","f9F4"),
]
extra = open("scratch_c/fields_extra.txt").read().split("\n") if __import__("os").path.exists("scratch_c/fields_extra.txt") else []
for l in extra:
    l=l.strip()
    if l:
        o,t,n=l.split(None,2); F.append((int(o,16),t,n))
F.sort()
sz={"BimRec5":20,"BimSlot":0x400,"void*":4,"char":1,"signed char":1,"unsigned char":1,"short":2,"unsigned short":2,"int":4,"unsigned int":4}
out=["struct BimMon {"]
pos=0
for o,t,n in F:
    if o>pos: out.append("    char pad%X[0x%X];"%(pos,o-pos))
    out.append("    %s %s;"%(t,n)); pos=o+sz[t] if t in sz else o+int(re.search(r'\[(0x[0-9A-F]+|\d+)\]',n).group(1),0) if False else o+sz[t]
out.append("};")
p="include/bim/bim.h"; s=open(p).read()
a=s.index("struct BimMon {"); b=s.index("};",a)+2
s=s[:a]+"\n".join(out)+s[b:]
open(p,"w").write(s)
