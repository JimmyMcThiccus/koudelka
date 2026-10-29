import sys
sys.argv=['x']
exec(open('drafts/field/twins.py').read().split("res=[]")[0])
names=sorted(rem)
res=[]
for i,a in enumerate(names):
    for b in names[i+1:]:
        x,y=rem[a],rem[b]
        if len(x)<12 or abs(len(x)-len(y))>len(x)*0.15: continue
        q=difflib.SequenceMatcher(None,x,y,autojunk=False).ratio()
        if q>=0.8: res.append((q,a,b,len(x)))
for q,a,b,n in sorted(res,reverse=True): print(f"{q:.3f} {a} {b} ({n})")
