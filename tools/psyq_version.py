"""Score each PsyQ SDK version by how many library OBJ signatures match the EXE.

Uses the signature JSONs shipped with ghidra_psx_ldr. A signature counts only
when it matches at a single location, so the version whose library code is
byte-identical to what was linked scores highest.

Usage: python psyq_version.py <exe> <psyq_sig_dir> [version ...]
"""
import json
import os
import re
import sys


def sig_regex(sig):
    parts = []
    for tok in sig.split():
        parts.append(b"." if tok == "??" else re.escape(bytes([int(tok, 16)])))
    return re.compile(b"".join(parts), re.S)


def main():
    exe, sig_dir = sys.argv[1], sys.argv[2]
    data = open(exe, "rb").read()[0x800:]
    versions = sys.argv[3:] or sorted(
        v for v in os.listdir(sig_dir) if v.isdigit())
    results = {}
    for ver in versions:
        hits = {}
        vdir = os.path.join(sig_dir, ver)
        for lib in sorted(os.listdir(vdir)):
            if not lib.endswith(".json"):
                continue
            for obj in json.load(open(os.path.join(vdir, lib))):
                sig = obj.get("sig", "")
                if sig.count("??") * 3 > len(sig) // 2 or len(sig) < 96:
                    continue  # too generic to be evidence
                m = [x.start() for x in sig_regex(sig).finditer(data)]
                if len(m) == 1:
                    hits[f"{lib[:-5]}/{obj['name']}"] = 0x80010000 + m[0]
        results[ver] = hits
        libs = {}
        for k in hits:
            libs[k.split("/")[0]] = libs.get(k.split("/")[0], 0) + 1
        print(f"{ver:>5}: {len(hits):4d} objs  " +
              " ".join(f"{l.replace('.LIB','')}={n}" for l, n in sorted(libs.items())))
    return results


if __name__ == "__main__":
    main()
