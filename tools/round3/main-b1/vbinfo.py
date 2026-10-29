import re,sys
from pathlib import Path
for u,n in [x.split('/') for x in sys.argv[1:]]:
    t=Path(f'asm/main/nonmatchings/{u}/{n}.s').read_text()
    hi=re.findall(r'%hi\((D_\w+)\)',t)
    sub=re.findall(r'addiu\s+\$a0, \$a0, (-0x[0-9A-F]+)',t)
    jal=re.findall(r'jal\s+(\w+)',t)
    sh=re.findall(r'sh\s+\$\w+, (0x[0-9A-F]+)\(\$sp\)',t)
    fr=re.search(r'addiu\s+\$sp, \$sp, (-0x[0-9A-F]+)',t).group(1)
    print(u,n,'frame',fr,'syms',hi,'sub',sub,'jal',jal,'sh',sh)
