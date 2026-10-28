"""Find original-file boundaries from jump-table alignment.

GCC 2.8 puts `.align 3` before every jump table, which aligns it to 8 *relative to the start
of its object's rodata*. So all jump tables of one original file share the same address mod 8,
and wherever that remainder changes between consecutive tables, a new file starts. A unit's
rodata start must have the same remainder as its tables, or compiled tables land 4 bytes off.

  python tools/jtbl_classes.py [target ...]     (default: every target)

Prints, per target, each run of tables with the same remainder: their range, the functions that
own them, and the source unit those functions are in now.
"""
import bisect
import glob
import re
import sys
from pathlib import Path

import yaml

ROOT = Path(__file__).resolve().parent.parent
TARGETS = ["slus_010.51", "field", "battle", "movie", "capture", "gameend", "effect"]


def main():
    targets = sys.argv[1:] or TARGETS
    for t in targets:
        cfg = yaml.safe_load((ROOT / "config" / f"{t}.yaml").read_text())
        opt = cfg["options"]
        seg = [s for s in cfg["segments"] if isinstance(s, dict) and s.get("type") == "code"][0]
        vram, rom0 = seg["vram"], seg["start"]
        units = sorted((s[0] - rom0 + vram, s[2]) for s in seg["subsegments"]
                       if isinstance(s, list) and len(s) >= 3 and s[1] in ("c", "cpp", "asm"))
        asm = ROOT / opt["asm_path"]
        funcs = sorted({int(m, 16) for f in asm.rglob("func_*.s") for m in re.findall(r"func_([0-9A-F]{8})\.s", f.name)})
        tables = {}
        for f in list(asm.rglob("*.s")):
            text = f.read_text()
            for m in re.finditer(r"dlabel (jtbl_([0-9A-F]{8}))\n(.*?)enddlabel", text, re.S):
                targets_ = [int(x, 16) for x in re.findall(r"\.word \.L([0-9A-F]{8})", m.group(3))]
                if targets_:
                    fn = funcs[bisect.bisect_right(funcs, min(targets_)) - 1]
                    tables[int(m.group(2), 16)] = fn
        if not tables:
            print(f"== {t}: no jump tables")
            continue
        unit_of = lambda a: units[bisect.bisect_right([u for u, _ in units], a) - 1][1]
        runs = []
        for addr in sorted(tables):
            cls = addr % 8
            if runs and runs[-1]["cls"] == cls:
                runs[-1]["tables"].append(addr)
            else:
                runs.append({"cls": cls, "tables": [addr]})
        print(f"== {t}: {len(tables)} jump tables in {len(runs)} runs")
        for r in runs:
            fs = sorted(tables[a] for a in r["tables"])
            us = sorted({unit_of(f) for f in fs})
            print(f"  mod8={r['cls']}  tables {r['tables'][0]:08X}..{r['tables'][-1]:08X} ({len(r['tables'])})"
                  f"  funcs {fs[0]:08X}..{fs[-1]:08X}  unit(s) {', '.join(us)}")


if __name__ == "__main__":
    main()
