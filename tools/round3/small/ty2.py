import itertools, subprocess, sys, re
src = open('scratch_c/d5b.cpp').read()
res=[]
for tm, tw in itertools.product(['unsigned int','int','unsigned short','short','unsigned char'], ['unsigned int','int','unsigned short']):
    t = src.replace("    unsigned int m;\n    unsigned int w;", f"    {tm} m;\n    {tw} w;")
    open('scratch_c/_ty.cpp','w').write(t)
    r = subprocess.run([sys.executable,'tools/try_compile.py','scratch_c/_ty.cpp','func_8008D5E8','--unit','src/main/sound.cpp','-I','drafts/sound','--quiet'],capture_output=True,text=True)
    l=(r.stdout.strip().splitlines() or ['err'])[-1]
    m=re.search(r'built (\d+) bytes, (\d+) diff', l)
    if m: res.append((int(m.group(2)),tm,tw))
res.sort(); print(res[:5])
