import itertools, subprocess, sys, re
src = open('drafts/sound/func_8008D97C.cpp').read()
types = ['int', 'short', 'unsigned char', 'unsigned short', 'unsigned int', 'char']
res = []
for ta, tb, tr in itertools.product(types, repeat=3):
    t = src.replace("    int a;\n    int b;\n    int r;", f"    {ta} a;\n    {tb} b;\n    {tr} r;")
    open('scratch_c/_ty.cpp', 'w').write(t)
    r = subprocess.run([sys.executable, 'tools/try_compile.py', 'scratch_c/_ty.cpp', 'func_8008D97C', '--unit', 'src/main/sound.cpp', '-I', 'drafts/sound', '--quiet'], capture_output=True, text=True)
    l = (r.stdout.strip().splitlines() or ['err'])[-1]
    m = re.search(r'built (\d+) bytes, (\d+) diff', l)
    if m: res.append((int(m.group(2)), ta, tb, tr, m.group(1)))
res.sort(); print([x for x in res if x[1] in ("int","unsigned int") and x[2] in ("short","unsigned short","int","unsigned int") and x[3] in ("int","unsigned int")][:8])
