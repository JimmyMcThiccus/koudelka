# usage: rest.py batch.cpp -> append sections whose INCLUDE_ASM still exists to scratch_c/pending.cpp (no prelude)
import re, sys
from pathlib import Path
sys.path.insert(0, 'scratch_c')
from mb import unit_of
parts = re.split(r'^(//// func_[0-9A-F]{8}[^\n]*\n)', Path(sys.argv[1]).read_text(), flags=re.M)
out = []
for hdr, body in zip(parts[1::2], parts[2::2]):
    name = re.search(r'func_[0-9A-F]{8}', hdr).group(0)
    if unit_of(name): out.append(hdr + body)
p = Path('scratch_c/pending.cpp')
p.write_text((p.read_text() if p.exists() else '') + ''.join(out))
print('pending +', len(out))
