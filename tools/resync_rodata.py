"""Re-place a source file's INCLUDE_RODATA lines to match splat's current layout.

When rodata migration changes (a force_not_migration symbol, a new split), splat would order
the unmigrated rodata differently, but it never rewrites an existing source file. This
generates the layout splat wants today and moves each INCLUDE_RODATA line in the real file to
follow the same function it follows there. Lines for rodata that is now migrated into a
function's .s are removed, and new unmigrated ones are added.

  python tools/resync_rodata.py <target> <segment> [--dry-run]     (then run configure.py)
"""
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

import yaml

ROOT = Path(__file__).resolve().parent.parent
ENTRY = re.compile(r'^INCLUDE_(ASM|RODATA)\("([^"]+)", (\w+)\);')
DEF = re.compile(r'^(?:EXTERN_C\s+|extern\s+"C"\s+|static\s+|inline\s+)*[\w\s\*&:<>,]*?\b(\w+)\s*\(')


def entries(lines):
    """Yield (kind, name, first_line, last_line) for INCLUDE_* lines and function definitions."""
    i = 0
    while i < len(lines):
        line = lines[i]
        m = ENTRY.match(line)
        if m:
            yield m.group(1), m.group(3), i, i
            i += 1
            continue
        d = None
        if not line.startswith((" ", "\t", "#", "/", "}")) and not line.rstrip().endswith(";"):
            d = DEF.match(line)
        if not d:
            i += 1
            continue
        depth, seen, end, decl = 0, False, i, False
        for end in range(i, len(lines)):
            depth += lines[end].count("{") - lines[end].count("}")
            seen = seen or "{" in lines[end]
            if not seen and lines[end].rstrip().endswith(";"):
                decl = True  # a declaration spread over several lines
                break
            if seen and depth <= 0:
                break
        if not decl:
            yield "FUNC", d.group(1), i, end
        i = end + 1


def block(prefix, names):
    out = []
    for n in names:
        out += [f'INCLUDE_RODATA("{prefix}", {n});', ""]
    return out


def main():
    target, segment = sys.argv[1], sys.argv[2]
    dry = "--dry-run" in sys.argv
    cfg = yaml.safe_load((ROOT / "config" / f"{target}.yaml").read_text())
    opt = cfg["options"]
    sub = next(s for seg in cfg["segments"] if isinstance(seg, dict) and seg.get("type") == "code"
               for s in seg["subsegments"] if isinstance(s, list) and len(s) >= 3 and s[2] == segment
               and s[1] in ("c", "cpp"))
    src = ROOT / opt["src_path"] / f"{segment}.{sub[1]}"

    # Fresh layout: split with this one source file moved away, then put it back.
    with tempfile.TemporaryDirectory() as tmp:
        keep = Path(tmp) / src.name
        shutil.copy2(src, keep)
        src.unlink()
        try:
            subprocess.run([sys.executable, "-m", "splat", "split", f"config/{target}.yaml"], cwd=ROOT,
                           check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
            fresh = src.read_text().split("\n")
        finally:
            shutil.copy2(keep, src)

    anchor = {}  # rodata name -> the function before it in the fresh layout (None: file start)
    prev = None
    for kind, name, _, _ in entries(fresh):
        if kind == "RODATA":
            anchor[name] = prev
        else:
            prev = name
    after = {}
    for name, a in anchor.items():
        after.setdefault(a, []).append(name)

    lines = src.read_text().split("\n")
    found = list(entries(lines))
    prefix = next(m.group(2) for line in lines if (m := ENTRY.match(line)))
    rodata_now = [(name, start) for kind, name, start, _ in found if kind == "RODATA"]
    end_to_name = {end: name for kind, name, _, end in found if kind != "RODATA"}
    missing = [a for a in after if a is not None and a not in end_to_name.values()]
    if missing:
        sys.exit(f"anchor functions missing from {src.name}: {missing[:5]}")

    drop = set()
    for _, start in rodata_now:
        drop.add(start)
        if start + 1 < len(lines) and lines[start + 1] == "":
            drop.add(start + 1)
    first = next(s for k, _, s, _ in found if k != "RODATA")
    out = []
    for i, line in enumerate(lines):
        if i == first:
            out += block(prefix, after.get(None, []))
        if i in drop:
            continue
        out.append(line)
        if i in end_to_name and end_to_name[i] in after:
            out += [""] + block(prefix, after[end_to_name[i]])[:-1]

    have = {n for n, _ in rodata_now}
    moved = sum(1 for n, s in rodata_now if n in anchor)
    print(f"{src.name}: {len(anchor)} INCLUDE_RODATA placed ({moved} kept, {len(have - set(anchor))} now migrated "
          f"and removed, {len(set(anchor) - have)} new); {len(lines)} -> {len(out)} lines")
    if not dry:
        src.write_text("\n".join(out))


if __name__ == "__main__":
    main()
