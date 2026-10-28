"""Fingerprint each unit's compiler by its function epilogues.

GCC 2.8.1 (PsyQ 4.4, the game code) fills the `jr $ra` delay slot with the stack restore:
    jr $ra / addiu $sp, $sp, N
GCC 2.7.2 (PsyQ 4.1) leaves the slot to the assembler, which cannot move the restore:
    addiu $sp, $sp, N / jr $ra / nop
So the 2.7.2 form marks code that needs a PsyQ 4.1 override. Run after a split:

  python tools/epilogue_scan.py [--list unit]
"""
import collections
import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def main():
    show = sys.argv[sys.argv.index("--list") + 1] if "--list" in sys.argv else None
    res = collections.defaultdict(lambda: {"2.7.2": [], "2.8": []})
    for f in glob.glob(os.path.join(ROOT, "asm", "*", "*matchings", "*", "func_*.s")):
        unit = os.path.basename(os.path.dirname(f))
        ins = re.findall(r"\*/[ \t]+(\w+)[ \t]*([^\n]*)", open(f).read())
        addr = int(re.search(r"func_([0-9A-F]{8})", f).group(1), 16)
        for k in range(1, len(ins) - 1):
            if ins[k][0] != "jr" or ins[k][1].strip() != "$ra":
                continue
            prev, slot = ins[k - 1], ins[k + 1]
            if slot[0] == "addiu" and slot[1].startswith("$sp, $sp"):
                res[unit]["2.8"].append(addr)
            elif slot[0] == "nop" and prev[0] == "addiu" and prev[1].startswith("$sp, $sp"):
                res[unit]["2.7.2"].append(addr)
    print("%-14s %8s %8s  %s" % ("unit", "2.7.2", "2.8", "2.7.2-style range"))
    for unit in sorted(res):
        old, new = res[unit]["2.7.2"], res[unit]["2.8"]
        rng = "%08x..%08x" % (min(old), max(old)) if old else ""
        print("%-14s %8d %8d  %s" % (unit, len(old), len(new), rng))
    if show:
        for kind in ("2.7.2", "2.8"):
            print(f"{show} {kind}:", " ".join("%08x" % a for a in sorted(set(res[show][kind]))))


if __name__ == "__main__":
    main()
