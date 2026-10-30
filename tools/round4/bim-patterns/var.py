import sys, subprocess
# usage: var.py template.cpp func module < variants
# template has @SIG@, @TOP@, @TAIL@; variants separated by '---' lines:
# first line = sig, rest = body; body may be "top|||tail"
tpl = open(sys.argv[1]).read(); func = sys.argv[2]; mod = sys.argv[3]
show = len(sys.argv) > 4
for i, v in enumerate(sys.stdin.read().split('\n---\n')):
    lines = v.strip('\n').split('\n'); sig = lines[0]; body = '\n'.join(lines[1:])
    pre, body = body.split('@@@') if '@@@' in body else ('', body)
    top, tail = body.split('|||') if '|||' in body else ('', body)
    src = tpl.replace('@SIG@', sig).replace('@TAIL@', tail).replace('@TOP@', top).replace('@PRE@', pre)
    open('scratch_c/v%d.cpp' % i, 'w').write(src)
    r = subprocess.run([sys.executable, 'tools/try_compile.py', 'scratch_c/v%d.cpp' % i, func, '--unit',
                        f'src/bim/{mod}/{mod}.cpp'], capture_output=True, text=True)
    out = (r.stdout + r.stderr).strip()
    if show: print(out)
    print(i, out.splitlines()[-1] if out else '?')
