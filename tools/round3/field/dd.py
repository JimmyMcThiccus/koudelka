import re,sys,difflib
from pathlib import Path
def get(n):
    for d in ("nonmatchings","matchings"):
        for u in ("field","field_b"):
            p=Path(f"asm/field/{d}/{u}/{n}.s")
            if p.exists(): break
        else: continue
        break
    out=[]
    for l in p.read_text().splitlines():
        m=re.match(r"\s*/\* \w+ \w+ \w+ \*/\s+(.*)",l)
        if not m: continue
        s=re.sub(r"\s+"," ",m.group(1).strip())
        if s=="nop": continue
        out.append(re.sub(r"\.L\w+","L",s))
    return out
a,b=get(sys.argv[1]),get(sys.argv[2])
for l in difflib.unified_diff(b,a,sys.argv[2],sys.argv[1],lineterm="",n=0):
    if not l.startswith("@@"): print(l)
