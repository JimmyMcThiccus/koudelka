"""Build the Shadow Hearts battle patch (docs/SH_PATCH_DESIGN.md 1.2).

Layered on the matching build: the retail EXE and BATTLE.BIN stay byte for byte, except for
  - code     every object from src/shpatch/**/*.cpp, packed into runs of dead EXE code (REGIONS: functions that no
             jal, j, pointer word or %hi/%lo pair in any image references, and no source names). The EXE is always
             resident, so nothing the patch needs can be overwritten by a CD load; the memory after the EFFECT/BIM slot
             is not free (effect actions load data there; found in phase 4)
  - detours  src/shpatch/detours.txt: `j replacement; nop` over each hooked function's first 8 bytes, plus
             trampolines (the two displaced instructions, then `j function+8`) where the patch calls the original

Everything links against the matching ELFs' symbols, so run a matching build first (configure.py --mode matching).
BATTLE.BIN keeps its size; only its detours change.

  python tools/patch/build.py              writes build/shpatch/SLUS_010.51 and build/shpatch/BATTLE.BIN
  python tools/patch/build.py --inject     also writes the patch into a running DuckStation (pause it in a battle
                                           first: BATTLE.BIN must already be loaded, and no CD read in flight)
"""
import argparse
import re
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(ROOT / "tools"))
BIN = ROOT / "bin" / "binutils"
NM, LD, OBJCOPY, OBJDUMP = (str(BIN / f"mips-ps2-decompals-{t}.exe") for t in ("nm", "ld", "objcopy", "objdump"))
OUT = ROOT / "build" / "shpatch"
CC = ["--psyq", "bin/psyq4.4", "--aspsx", "2.81", "--cflags", "-O2 -G0", "--as-G", "0", "--expand-div"]

EXE_VRAM, EXE_HEADER = 0x80010000, 0x800
BATTLE_VRAM = 0x800B6DF0
# Runs of dead EXE functions, largest first (docs/SH_PATCH_DESIGN.md 1.1). Checked twice: no reference in any image
# (EXE, the overlays, EFFECT, bim_base, the 85 module images) and none in src/, include/, config/ or asm/.
REGIONS = [(0x80033F9C, 0x80034710), (0x80032334, 0x80032A10), (0x80040C10, 0x800410F4), (0x80081034, 0x800814E8),
           (0x80025874, 0x80025CE0), (0x80022518, 0x800228A0), (0x8003A318, 0x8003A654), (0x8002AD0C, 0x8002AFEC),
           (0x80082174, 0x80082450), (0x80086288, 0x8008655C), (0x8004EB28, 0x8004EDCC)]
# (0x8002DED8..0x8002E600, 1,832 B, is also unreferenced but shares a file with the OT submit the patch hooks: left alone)
OLD_POCKET = (0x800E5850, 0x800EA8A0)  # where earlier builds put BATTLE code; --inject still cleans up after them
SYMBOL = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")
PACKED = (".text", ".rodata", ".data", ".sdata", ".sbss", ".bss")


def run(cmd):
    res = subprocess.run([str(c) for c in cmd], capture_output=True, text=True)
    if res.returncode:
        sys.exit(f"build.py: failed: {' '.join(map(str, cmd))}\n{res.stdout}{res.stderr}")
    return res.stdout


def symbols(elf, defined_only=True):
    out = {}
    for line in run([NM, elf]).splitlines():
        p = line.split()
        if len(p) == 3 and SYMBOL.match(p[2]) and (not defined_only or p[1] in "TtDdRrBbSsGgVv"):
            out.setdefault(p[2], int(p[0], 16) & 0xFFFFFFFF)
    return out


def function_end(syms, addr):
    later = [a for a in syms.values() if a > addr]
    return min(later) if later else addr + 8


def is_control(w):
    op = w >> 26
    if op in (1, 2, 3, 4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17):  # REGIMM, j, jal, beq..bgtz, likely branches
        return True
    if op == 0 and (w & 0x3F) in (8, 9):  # jr, jalr
        return True
    if op in (0x10, 0x11, 0x12) and ((w >> 21) & 0x1F) == 8:  # bc0/bc1/bc2
        return True
    return False


def branch_targets(words, base):
    for i, w in enumerate(words):
        op = w >> 26
        if op in (1, 4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17):
            off = w & 0xFFFF
            off -= 0x10000 if off & 0x8000 else 0
            yield base + 4 * (i + 1 + off)


def object_size(o):
    """Bytes the object needs in a region: its packed sections, each aligned as the linker will align it."""
    size = 0
    for line in run([OBJDUMP, "-h", o]).splitlines():
        p = line.split()
        if len(p) >= 7 and p[0].isdigit() and p[1].startswith(PACKED):
            align = 2 ** int(p[6].split("**")[1])
            size = (size + align - 1) & ~(align - 1)
            size += int(p[2], 16)
    common = sum(int(l.split()[1], 16) for l in run([NM, "-S", o]).splitlines()
                 if len(l.split()) == 4 and l.split()[2] == "C")
    return (size + 7 & ~7) + (common + 7 & ~7)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--inject", action="store_true", help="write the patch into a running DuckStation")
    a = ap.parse_args()

    exe_elf, battle_elf = ROOT / "build" / "slus_010.51.elf", ROOT / "build" / "battle.elf"
    retail = {"exe": (ROOT / "extracted" / "disc1" / "SLUS_010.51").read_bytes(),
              "battle": (ROOT / "extracted" / "disc1" / "BIN" / "BATTLE.BIN").read_bytes()}
    for img, built in (("exe", "slus_010.51.bin"), ("battle", "battle.bin")):
        b = ROOT / "build" / built
        built_bytes = b.read_bytes() if b.exists() else b""  # the built EXE omits retail's trailing padding
        if not built_bytes or retail[img][:len(built_bytes)] != built_bytes:
            sys.exit(f"build.py: build/{built} is missing or not retail: run configure.py --mode matching first")
    (OUT / "obj").mkdir(parents=True, exist_ok=True)
    detours = [l.split() for l in (ROOT / "src" / "shpatch" / "detours.txt").read_text().splitlines()
               if l.strip() and not l.startswith("#")]
    retail_syms = {"exe": symbols(exe_elf), "battle": symbols(battle_elf)}
    file_base = {"exe": EXE_VRAM - EXE_HEADER, "battle": BATTLE_VRAM}

    # Addresses outside both images (EFFECT, the BIM base, hardware) come from splat's undefined_*_auto files.
    import yaml
    pool = {}
    for target in ("slus_010.51", "battle"):
        opt = yaml.safe_load((ROOT / "config" / f"{target}.yaml").read_text())["options"]
        for key in ("undefined_syms_auto_path", "undefined_funcs_auto_path"):
            for m in re.finditer(r"^\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)", (ROOT / opt[key]).read_text(), re.M):
                pool.setdefault(m.group(1), int(m.group(2), 16))
    pool.update(retail_syms["battle"])
    pool.update(retail_syms["exe"])

    objs = []
    for src in sorted((ROOT / "src" / "shpatch").rglob("*.cpp")):
        rel = src.relative_to(ROOT).as_posix()
        o = OUT / "obj" / f"{src.parent.name}_{src.name}.o"
        run([sys.executable, ROOT / "tools" / "cc.py", *CC, "-Iinclude", "-o", o, rel])
        objs.append(o)

    # trampolines and @count shims
    tramp = []
    for img, func, repl, *tr in detours:
        if not tr:
            continue
        addr = retail_syms[img][func]
        data, off = retail[img], addr - file_base[img]
        w = struct.unpack_from("<2I", data, off)
        body = struct.unpack_from(f"<{(function_end(retail_syms[img], addr) - addr) // 4}I", data, off)
        if any(is_control(x) for x in w):
            sys.exit(f"build.py: {func}: a displaced instruction is a branch or jump; no trampoline")
        if addr + 4 in set(branch_targets(body, addr)):
            sys.exit(f"build.py: {func}: something branches to {func}+4; no trampoline")
        if repl == "@count":  # diagnostics: count calls in g_shCount[n], then run the original
            n = int(tr[0])
            tramp.append(f".globl {func}_count\n{func}_count:\n  lui $t8, %hi(g_shCount+{4 * n})\n"
                         f"  lw $t9, %lo(g_shCount+{4 * n})($t8)\n  nop\n  addiu $t9, $t9, 1\n"
                         f"  sw $t9, %lo(g_shCount+{4 * n})($t8)\n")
        else:
            tramp.append(f".globl {tr[0]}\n{tr[0]}:\n")
        tramp.append(f"  .word {w[0]:#010x}\n  .word {w[1]:#010x}\n  j {addr + 8:#010x}\n  nop\n")
    if tramp:
        s = OUT / "tramp.s"
        s.write_text(".set noreorder\n.set noat\n.section .text\n" + "".join(tramp))
        o = OUT / "obj" / "tramp.s.o"
        run([BIN / "mips-ps2-decompals-as.exe", "-EL", "-march=r3000", "-mabi=32", "-G0", "-o", o, s])
        objs.append(o)

    # pack objects into the regions: an exact search, largest object first (a dozen objects, a dozen regions)
    sizes = {o: object_size(o) for o in objs}
    free = [[lo, hi - lo, []] for lo, hi in REGIONS]
    order = sorted(objs, key=lambda o: -sizes[o])

    def place(i):
        if i == len(order):
            return True
        tried = set()
        for r in sorted(free, key=lambda r: r[1]):
            if r[1] < sizes[order[i]] or r[1] in tried:
                continue
            tried.add(r[1])
            r[1] -= sizes[order[i]]
            r[2].append(order[i])
            if place(i + 1):
                return True
            r[1] += sizes[order[i]]
            r[2].pop()
        return False

    if not place(0):
        sys.exit(f"build.py: the objects ({sum(sizes.values())} bytes) do not fit the regions; split one or add a region")

    own = set()
    for o in objs:
        for line in run([NM, o]).splitlines():
            p = line.split()
            if len(p) == 3 and p[1] in "TtDdRrBbSsGgVvC":
                own.add(p[2])
    sym_ld = OUT / "syms.ld"
    sym_ld.write_text("".join(f"{k} = {v:#010x};\n" for k, v in sorted(pool.items()) if k not in own))
    sec = []
    for i, (lo, hi) in enumerate(REGIONS):
        files = free[i][2]
        if not files:
            continue
        body = " ".join(f"*{o.name}({kind})" for o in files
                        for kind in (".text*", ".rodata*", ".data*", ".sdata*", ".sbss*", ".bss*", "COMMON"))
        sec.append(f"  .sh{i} {lo:#010x} : {{ {body} }}\n")
    ld = OUT / "patch.ld"
    ld.write_text("SECTIONS {\n" + "".join(sec) + "  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) *(.pdr) "
                  "*(.comment) *(.gnu.attributes) *(.mdebug*) }\n}\n")
    elf = OUT / "patch.elf"
    run([LD, "-EL", "--no-check-sections", "-nostdlib", "-T", ld, "-T", sym_ld, "-Map", OUT / "patch.map",
         "-o", elf, *objs])
    linked = symbols(elf)
    writes = {"exe": [], "battle": []}
    for i, (lo, hi) in enumerate(REGIONS):
        if not free[i][2]:
            continue
        b = OUT / f"sh{i}.bin"
        run([OBJCOPY, "-O", "binary", "-j", f".sh{i}", elf, b])
        code = b.read_bytes()
        if len(code) > hi - lo:
            sys.exit(f"build.py: .sh{i} is {len(code)} bytes, room for {hi - lo}")
        writes["exe"].append((lo, code))
        print(f".sh{i} {lo:#010x}: {len(code):5d} of {hi - lo} bytes  " + " ".join(o.name for o in free[i][2]))

    for img, func, repl, *tr in detours:
        target = linked.get(f"{func}_count" if repl == "@count" else repl)
        if target is None:
            sys.exit(f"build.py: {repl} is not defined by the patch")
        writes[img].append((retail_syms[img][func], struct.pack("<2I", 0x08000000 | ((target >> 2) & 0x3FFFFFF), 0)))

    images = {"exe": bytearray(retail["exe"]), "battle": bytearray(retail["battle"])}
    for img in images:
        for addr, data in writes[img]:
            o = addr - file_base[img]
            images[img][o:o + len(data)] = data
    (OUT / "SLUS_010.51").write_bytes(images["exe"])
    (OUT / "BATTLE.BIN").write_bytes(images["battle"])
    print(f"build/shpatch/SLUS_010.51, build/shpatch/BATTLE.BIN (sizes unchanged); {len(detours)} detours")

    if a.inject:
        import duckstation as d
        if d.call("get_status").get("state") != "paused":
            sys.exit("build.py --inject: pause DuckStation first (in a battle, with no CD read in flight)")
        if bytes.fromhex(d.call("read_memory", address=hex(BATTLE_VRAM), size=4)["data"]) != retail["battle"][:4]:
            sys.exit("build.py --inject: BATTLE.BIN is not loaded")
        # An earlier injection may have detoured functions this one does not: put their retail bytes back first, or
        # they would jump into the middle of the new code.
        spans = REGIONS + [OLD_POCKET]
        order = []
        for img in ("battle", "exe"):
            data = retail[img][EXE_HEADER:] if img == "exe" else retail[img]
            start = EXE_VRAM if img == "exe" else BATTLE_VRAM
            dump = OUT / f"live_{img}.bin"  # large inline reads stall the server; a file read takes 0.4 s
            d.call("read_memory", address=hex(start), size=len(data), path=str(dump))
            live = dump.read_bytes()
            for name, addr in retail_syms[img].items():
                o = addr - start
                if not 0 <= o < len(live) - 8 or any(lo <= addr < hi for lo, hi in REGIONS):
                    continue
                w = struct.unpack_from("<I", live, o)[0]
                t = ((w & 0x3FFFFFF) << 2) | 0x80000000
                if w >> 26 == 2 and any(lo <= t < hi for lo, hi in spans) and live[o:o + 8] != data[o:o + 8]:
                    order.append((addr, data[o:o + 8]))
        # code next, detours last, so no detour can reach code that is not there yet
        order += [w for w in writes["exe"] if any(w[0] == lo for lo, _ in REGIONS)]
        order += [w for w in writes["battle"] + writes["exe"] if not any(w[0] == lo for lo, _ in REGIONS)]
        for addr, data in order:
            d.call("write_memory", address=hex(addr), data=data.hex())
        print(f"injected {len(order)} writes into DuckStation")


if __name__ == "__main__":
    main()
