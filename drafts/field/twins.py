import re, sys, difflib
from pathlib import Path
def norm(p):
    out=[]
    for l in p.read_text().splitlines():
        m=re.match(r"\s*/\* \w+ \w+ \w+ \*/\s+(.*)",l)
        if not m: continue
        s=m.group(1).strip()
        if s=="nop": continue
        s=re.sub(r"\.L\w+","L",s); s=re.sub(r"(jal\s+)\w+",r"\1F",s)
        s=re.sub(r"%(hi|lo)\(\w+\)",r"%\1(S)",s)
        s=re.sub(r"\s+"," ",s)
        out.append(s)
    return out
base=Path("asm/field")
rem={p.stem:norm(p) for d in ("field","field_b") for p in (base/"nonmatchings"/d).glob("func_*.s")}
done={p.stem:norm(p) for d in ("field","field_b") for p in (base/"matchings"/d).glob("func_*.s")}
res=[]
for r,a in rem.items():
    if len(a)<10: continue
    best=(0,None)
    for d,b in done.items():
        if abs(len(a)-len(b))>len(a)*0.2: continue
        q=difflib.SequenceMatcher(None,a,b,autojunk=False).ratio()
        if q>best[0]: best=(q,d)
    if best[0]>=0.6: res.append((best[0],r,best[1],len(a)))
for q,r,d,n in sorted(res,reverse=True): print(f"{q:.3f} {r} <- {d} ({n})")
