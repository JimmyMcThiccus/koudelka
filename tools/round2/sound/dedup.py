# remove repeated identical struct definitions in sound.cpp (keep the first); report differing ones
import re
from pathlib import Path
p = Path("src/main/sound.cpp"); t = p.read_text()
seen = {}
out = []
pos = 0
for m in re.finditer(r"^struct (\w+) \{\n.*?^\};\n", t, re.S | re.M):
    name, body = m.group(1), m.group(0)
    if name in seen:
        if seen[name] == body:
            out.append(t[pos:m.start()]); pos = m.end()
        else:
            print("DIFFERENT", name)
    else:
        seen[name] = body
out.append(t[pos:])
p.write_text("".join(out))
