"""Name the functions the BIM.AR modules share, so each can be written once (docs/BIM_AR.md, step 4).

The 85 module targets (config/bim/) repeat many functions at different addresses. A function can share one C
definition across modules only if its code is the same with relocated fields masked AND every reference names
the same thing everywhere: an EXE or bim_base symbol, or another shared function. References to a module's own
data differ by module, so functions that make them stay per-module. Functions with jump tables stay per-module
too (their tables live in the module header's rodata).

Each shared group gets one name, bimf_<hash>, at its address in every module that has it, written to
config/symbols/bim/<module>.txt (the generated module configs read that file). Then re-split: the modules'
INCLUDE_ASM lines use the shared names, and tools/bim_sync.py swaps in a shared definition once it exists.

  python tools/bim_shared.py            (needs asm/bim/ from a split; prints the numbers)
"""
import hashlib
import re
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
INSN = re.compile(r"/\* [0-9A-F]+ ([0-9A-F]{8}) ([0-9A-F]{8}) \*/\s+(\S+)\s*(.*)")
SYMREF = re.compile(r"%(?:hi|lo|gp_rel)\(([A-Za-z_.$][\w.$]*)")


def parse(path):
    """(address, masked code bytes, [referenced symbols], has a jump table) of one function's .s file."""
    words, refs, jtbl, addr = [], [], False, None
    for line in path.read_text().splitlines():
        m = INSN.search(line)
        if not m:
            continue
        vram, raw, mnem, ops = int(m.group(1), 16), bytearray.fromhex(m.group(2)), m.group(3), m.group(4)
        addr = vram if addr is None else addr
        syms = SYMREF.findall(ops)
        if mnem in ("jal", "j") and ops and not ops.startswith("$"):
            raw[0:3] = b"\0\0\0"  # 26-bit target: bytes are little-endian, the low 26 bits are bytes 0-2 and part of 3
            raw[3] &= 0xFC
            if not ops.startswith(".L"):
                syms.append(ops.split()[0])
        elif syms:
            raw[0:2] = b"\0\0"
        if any(s.startswith("jtbl_") for s in syms):
            jtbl = True
        refs += [s for s in syms if not s.startswith(".L")]
        words.append(bytes(raw))
    return addr, b"".join(words), refs, jtbl


def main():
    funcs = {}  # (module, name) -> (address, masked bytes, refs, jtbl)
    for mod_dir in sorted((ROOT / "asm" / "bim").iterdir()):
        mod = mod_dir.name
        for s in [p for kind in ("nonmatchings", "matchings") for p in (mod_dir / kind / mod).glob("*.s")]:
            if "glabel" in s.read_text():
                funcs[(mod, s.stem)] = parse(s)
    print(f"{len(funcs)} module functions in {len({m for m, _ in funcs})} modules")

    # Group by masked code, then refine until every member's references name the same things, with a call to
    # another module-local function written as that function's group. Iterate to a fixpoint.
    local = {(m, n) for m, n in funcs}
    group = {k: hashlib.sha1(v[1]).hexdigest() for k, v in funcs.items()}
    for _ in range(10):
        new = {}
        for (m, n), (addr, body, refs, jt) in funcs.items():
            sig = [("@" + group[(m, r)]) if (m, r) in local else r for r in refs]
            new[(m, n)] = hashlib.sha1(body + "\0".join(sig).encode()).hexdigest()
        if len(set(new.values())) == len(set(group.values())):
            group = new
            break
        group = new

    members = defaultdict(list)
    for k, g in group.items():
        members[g].append(k)
    shared = {}
    for g, ks in members.items():
        if len(ks) < 2 or any(funcs[k][3] for k in ks):
            continue  # only one copy anywhere, or has a jump table
        # A repeat inside one module needs its own symbol: bimf_<hash>_1, _2, ... by address. tools/bim_sync.py
        # compiles the same definition under that name.
        seen = defaultdict(int)
        for k in sorted(ks, key=lambda k: (k[0], funcs[k][0])):
            n = seen[k[0]]
            seen[k[0]] += 1
            shared[k] = f"bimf_{g[:8]}" + (f"_{n}" if n else "")

    out = ROOT / "config" / "symbols" / "bim"
    out.mkdir(parents=True, exist_ok=True)
    for old in out.glob("*.txt"):
        old.unlink()
    by_mod = defaultdict(list)
    for (m, n), name in shared.items():
        by_mod[m].append((funcs[(m, n)][0], name))
    for mod_dir in sorted((ROOT / "asm" / "bim").iterdir()):
        rows = sorted(by_mod.get(mod_dir.name, []))
        (out / f"{mod_dir.name}.txt").write_text(
            f"// {mod_dir.name}: functions shared with other BIM.AR modules (tools/bim_shared.py; do not edit)\n"
            + "".join(f"{name} = 0x{a:08X}; // type:func\n" for a, name in rows))
    groups = {n.split("_")[1] for n in shared.values()}
    distinct = len(set(group.values()))
    print(f"{len(groups)} shared functions cover {len(shared)} module functions; "
          f"{len(funcs) - len(shared)} stay per-module; {distinct} distinct functions in all, "
          f"so writing each once means {len(groups) + len(funcs) - len(shared)} definitions instead of {len(funcs)}")


if __name__ == "__main__":
    main()
