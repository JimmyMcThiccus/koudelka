"""usage: ip.py body.cpp func unit [-v] [--sym MANGLED] -- replace INCLUDE_ASM of func in unit source with body, compile the whole file,
compare only func's symbol (value/size from readelf -s) against retail."""
import re, subprocess, sys, struct, tempfile
from pathlib import Path
sys.path.insert(0, 'tools')
import toolchain, rabbitizer
ROOT = Path('.').resolve()
BIN = ROOT / 'bin' / 'binutils'
args = [a for a in sys.argv[1:] if not a.startswith('-')]
body, name, unit = Path(args[0]).read_text(), args[1], args[2]
sym = name
if '--sym' in sys.argv: sym = sys.argv[sys.argv.index('--sym') + 1]; args.remove(sym)
s = Path(unit).read_text()
m = re.search(r'^INCLUDE_ASM\([^)]*\b%s\);\n' % re.escape(name), s, flags=re.M)
assert m, 'no INCLUDE_ASM'
s = s[:m.start()] + body + '\n' + s[m.end():]
f = Path('scratch_c/_ip_%s.cpp' % name); f.write_text(s)
st = toolchain.settings(unit)
asm_dir, target = toolchain.target_of(unit)
cargs = toolchain.cc_args(unit)
gp_from = cargs[cargs.index("--gp-from") + 1] if "--gp-from" in cargs and st.get("as_G") != 0 else None
# retail bytes
rom = size = None
for sf in Path(asm_dir).rglob('*.s'):
    text = sf.read_text()
    mm = re.search(rf"nonmatching {name}, (0x[0-9A-F]+)", text)
    if not mm: continue
    r = re.search(rf"glabel {name}\n\s*/\* ([0-9A-F]+) ", text)
    rom, size = int(r.group(1), 16), int(mm.group(1), 16); break
want = open(ROOT / target, 'rb').read()[rom:rom + size]
with tempfile.TemporaryDirectory() as tmp:
    tmp = Path(tmp); obj = tmp / 'out.o'
    cc = [sys.executable, 'tools/cc.py', '--psyq', st['psyq'], '--aspsx', st['aspsx'], '--cflags', st['cflags'],
          *(['--as-G', str(st['as_G'])] if st.get('as_G') is not None else []),
          *(['--expand-div'] if st['expand_div'] else []), *(['--gp-from', gp_from] if gp_from else []),
          '-Iinclude', '-o', str(obj), str(f)]
    r = subprocess.run(cc, cwd=ROOT, capture_output=True, text=True)
    if r.returncode: print(r.stdout[-3000:] + r.stderr[-3000:]); print('compile failed'); sys.exit(1)
    subprocess.run([str(BIN / 'mips-ps2-decompals-objcopy.exe'), '-O', 'binary', '-j', '.text', str(obj), str(tmp / 't.bin')], check=True)
    full = (tmp / 't.bin').read_bytes()
    syms = subprocess.run([str(BIN / 'mips-ps2-decompals-readelf.exe'), '-sW', str(obj)], capture_output=True, text=True).stdout
    off = gsz = None
    for l in syms.splitlines():
        p = l.split()
        if len(p) >= 8 and p[7] == sym and p[6] != 'UND':
            off, gsz = int(p[1], 16), int(p[2])
    if off is None: print('symbol not found', sym); sys.exit(1)
    rel = subprocess.run([str(BIN / 'mips-ps2-decompals-readelf.exe'), '-r', str(obj)], capture_output=True, text=True).stdout
    relocs = {int(l.split()[0], 16) for l in rel.splitlines() if re.match(r'^[0-9a-f]{8} ', l) and 'R_MIPS' in l}
got = full[off:off + gsz]
n = max(len(got), len(want)) // 4; diffs = 0; lines = []
for i in range(n):
    w = struct.unpack_from('<I', want, i * 4)[0] if i * 4 < len(want) else None
    g = struct.unpack_from('<I', got, i * 4)[0] if i * 4 < len(got) else None
    mask = 0xFFFFFFFF
    if g is not None and (off + i * 4) in relocs: mask = 0xFC000000 if g >> 26 in (2, 3) else 0xFFFF0000
    same = w is not None and g is not None and (w & mask) == (g & mask)
    diffs += not same
    dis = lambda x: rabbitizer.Instruction(x).disassemble() if x is not None else '-'
    lines.append(f"{'  ' if same else '!!'} {i*4:04x}  {dis(w):40s} {dis(g)}")
if '-v' in sys.argv: print('\n'.join(lines))
print(f'{name}: retail {len(want)} bytes, built {len(got)} bytes, {diffs} differing instructions')
