"""Run maspsx (bin/maspsx) so that the right small .extern symbols use $gp.

ASPSX reached a small global (size <= -G) through $gp only in the source file that
defines it; everywhere else it used lui (main_b's round-2 scan: for each of 30
symbols reached both ways, the $gp uses form one contiguous range of code). Our
units declare those globals extern, because their storage stays in the asm .sdata,
so maspsx alone would never use $gp for them.

KOUDELKA_GP_SYMS (set by tools/cc.py) lists the symbols the unit's own retail asm
reaches through $gp; those `.extern sym, size` symbols are registered as sdata.
Without it, every small .extern is registered (the round-1 behaviour).

Takes maspsx's arguments; reads stdin, writes stdout.
"""
import os
import re
import runpy
import sys
from pathlib import Path

MASPSX_DIR = Path(__file__).resolve().parent.parent / "bin" / "maspsx"
sys.path.insert(0, str(MASPSX_DIR))

import maspsx  # noqa: E402  (the package in bin/maspsx/maspsx/)

_preprocess = maspsx.MaspsxProcessor.preprocess_lines
_listed = os.environ.get("KOUDELKA_GP_SYMS")
GP_SYMS = None if _listed is None else set(filter(None, _listed.split(",")))


def preprocess_lines(self):
    _preprocess(self)
    if not self.sdata_limit or not self.gp_allow:
        return
    for line in self.lines:
        m = re.match(r"\.extern\s+([^,\s]+)\s*,\s*(\d+)", line)
        if m and 0 < int(m.group(2)) <= self.sdata_limit and (GP_SYMS is None or m.group(1) in GP_SYMS):
            self.sdata_entries.setdefault(m.group(1), int(m.group(2)))


maspsx.MaspsxProcessor.preprocess_lines = preprocess_lines
sys.argv[0] = str(MASPSX_DIR / "maspsx.py")
runpy.run_path(str(MASPSX_DIR / "maspsx.py"), run_name="__main__")
