"""Run maspsx (bin/maspsx) with one addition: small .extern symbols use $gp.

GCC tells the assembler a symbol's size with `.extern sym, size`. ASPSX reached
small externs (size <= -G) through $gp: retail reaches some $gp variables from
functions in different source files (either side of a .ctors boundary). maspsx
only treats symbols defined in the file's own .sdata/.sbss that way, so this
also registers small .extern symbols as sdata.

Takes maspsx's arguments; reads stdin, writes stdout.
"""
import re
import runpy
import sys
from pathlib import Path

MASPSX_DIR = Path(__file__).resolve().parent.parent / "bin" / "maspsx"
sys.path.insert(0, str(MASPSX_DIR))

import maspsx  # noqa: E402  (the package in bin/maspsx/maspsx/)

_preprocess = maspsx.MaspsxProcessor.preprocess_lines


def preprocess_lines(self):
    _preprocess(self)
    if not self.sdata_limit or not self.gp_allow:
        return
    for line in self.lines:
        m = re.match(r"\.extern\s+([^,\s]+)\s*,\s*(\d+)", line)
        if m and 0 < int(m.group(2)) <= self.sdata_limit:
            self.sdata_entries.setdefault(m.group(1), int(m.group(2)))


maspsx.MaspsxProcessor.preprocess_lines = preprocess_lines
sys.argv[0] = str(MASPSX_DIR / "maspsx.py")
runpy.run_path(str(MASPSX_DIR / "maspsx.py"), run_name="__main__")
