"""Build the Shadow Hearts battle patch (docs/SH_PATCH_DESIGN.md 1.2).

Layered on the matching build: the retail EXE and BATTLE.BIN stay byte for byte, except for
  - .shexe   src/shpatch/exe/*.cpp, linked into the dead func_80040C10 (1,252 bytes) of the EXE
  - .shpatch src/shpatch/battle/*.cpp, linked at 0x800E5850 (the pocket after the EFFECT/BIM slot); BATTLE.BIN
             grows to cover it, and the EXE's two BATTLE size words (D_800137A8[2], D_800AE5F8[5]) follow
  - detours  src/shpatch/detours.txt: `j replacement; nop` over each hooked function's first 8 bytes, plus
             trampolines (the two displaced instructions, then `j function+8`) where the patch calls the original

Both sections link against the matching ELFs' symbols, so run a matching build first (configure.py --mode matching).

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
NM, LD, OBJCOPY = (str(BIN / f"mips-ps2-decompals-{t}.exe") for t in ("nm", "ld", "objcopy"))
OUT = ROOT / "build" / "shpatch"
CC = ["--psyq", "bin/psyq4.4", "--aspsx", "2.81", "--cflags", "-O2 -G0", "--as-G", "0", "--expand-div"]

EXE_VRAM, EXE_HEADER = 0x80010000, 0x800
BATTLE_VRAM, BATTLE_SIZE, BATTLE_SECTORS_MAX = 0x800B6DF0, 0x1EFBC, 200  # LBA 1400; EFFECT.BIN is at LBA 1600
# image: (section, load address, bytes available, retail symbol the region replaces or None)
REGIONS = {
    "exe": (".shexe", 0x80040C10, 1252, "func_80040C10"),
    "battle": (".shpatch", 0x800E5850, 0x800EA8A0 - 0x800E5850, None),
}
SIZE_WORDS = [(0x800137A8 + 2 * 4, BATTLE_SIZE, lambda n: n),                         # bytes read
              (0x800AE5F8 + 5 * 4, 0x1F000, lambda n: (n + 0x7FF) & ~0x7FF)]          # overlay table size
SYMBOL = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


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


def compile_image(image):
    objs = []
    for src in sorted((ROOT / "src" / "shpatch" / image).glob("*.cpp")):
        rel = src.relative_to(ROOT).as_posix()
        o = OUT / "obj" / (src.name + ".o")
        o.parent.mkdir(parents=True, exist_ok=True)
        run([sys.executable, ROOT / "tools" / "cc.py", *CC, "-Iinclude", "-o", o, rel])
        objs.append(o)
    return objs


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
    OUT.mkdir(parents=True, exist_ok=True)
    detours = [l.split() for l in (ROOT / "src" / "shpatch" / "detours.txt").read_text().splitlines()
               if l.strip() and not l.startswith("#")]

    retail_syms = {"exe": symbols(exe_elf), "battle": symbols(battle_elf)}
    # Addresses outside an image (EFFECT, the BIM base, hardware) come from splat's undefined_*_auto files.
    import yaml
    extern = {}
    for target in ("slus_010.51", "battle"):
        opt = yaml.safe_load((ROOT / "config" / f"{target}.yaml").read_text())["options"]
        for key in ("undefined_syms_auto_path", "undefined_funcs_auto_path"):
            for m in re.finditer(r"^\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)", (ROOT / opt[key]).read_text(), re.M):
                extern.setdefault(m.group(1), int(m.group(2), 16))
    image_of = lambda addr: "exe" if addr < BATTLE_VRAM else "battle"
    words_at = {}  # image -> {addr: (bytes)} writes beyond the sections
    sections = {}
    linked_syms = dict(retail_syms["exe"])
    for image in ("exe", "battle"):
        name, base, room, replaces = REGIONS[image]
        objs = compile_image(image)
        # trampolines for this image's detours
        tramp = []
        for img, func, repl, *tr in detours:
            if img != image or not tr:
                continue
            addr = retail_syms[img][func]
            data = retail[img]
            off = addr - (EXE_VRAM - EXE_HEADER if img == "exe" else BATTLE_VRAM)
            w = struct.unpack_from("<2I", data, off)
            end = function_end(retail_syms[img], addr)
            body = struct.unpack_from(f"<{(end - addr) // 4}I", data, off)
            if any(is_control(x) for x in w):
                sys.exit(f"build.py: {func}: a displaced instruction is a branch or jump; no trampoline")
            if addr + 4 in set(branch_targets(body, addr)):
                sys.exit(f"build.py: {func}: something branches to {func}+4; no trampoline")
            if repl == "@count":  # diagnostics: count calls in g_shCount[n], then run the original
                n = int(tr[0])
                tramp.append(f".globl {func}_count\n{func}_count:\n  lui $t8, %hi(g_shCount+{4 * n})\n"
                             f"  lw $t9, %lo(g_shCount+{4 * n})($t8)\n  nop\n  addiu $t9, $t9, 1\n"
                             f"  sw $t9, %lo(g_shCount+{4 * n})($t8)\n")
                tr = [None]
            else:
                tramp.append(f".globl {tr[0]}\n{tr[0]}:\n")
            tramp.append(f"  .word {w[0]:#010x}\n  .word {w[1]:#010x}\n  j {addr + 8:#010x}\n  nop\n")
        if tramp:
            s = OUT / f"{image}_tramp.s"
            s.write_text(".set noreorder\n.set noat\n.section .text\n" + "".join(tramp))
            o = OUT / "obj" / f"{image}_tramp.s.o"
            run([BIN / "mips-ps2-decompals-as.exe", "-EL", "-march=r3000", "-mabi=32", "-G0", "-o", o, s])
            objs.append(o)
        # what the patch objects define themselves must not also come from the symbol script
        own = set()
        for o in objs:
            for line in run([NM, o]).splitlines():
                p = line.split()
                if len(p) == 3 and p[1] in "TtDdRrBbSsGgVvC":
                    own.add(p[2])
        pool = dict(extern)
        pool.update(linked_syms)
        if image == "battle":
            pool.update(retail_syms["battle"])
        sym_ld = OUT / f"{image}_syms.ld"
        sym_ld.write_text("".join(f"{k} = {v:#010x};\n" for k, v in sorted(pool.items()) if k not in own))
        sec_ld = OUT / f"{image}.ld"
        sec_ld.write_text(
            f"SECTIONS {{\n  {name} {base:#010x} : {{ *(.text*) *(.rodata*) *(.data*) *(.sdata*) *(.sbss*) "
            f"*(.bss*) *(COMMON) }}\n  /DISCARD/ : {{ *(.reginfo) *(.MIPS.abiflags) *(.pdr) *(.comment) "
            f"*(.gnu.attributes) *(.mdebug*) }}\n}}\n")
        elf = OUT / f"{image}.elf"
        run([LD, "-EL", "--no-check-sections", "-nostdlib", "-T", sec_ld, "-T", sym_ld,
             "-Map", OUT / f"{image}.map", "-o", elf, *objs])
        bin_ = OUT / f"{image}.bin"
        run([OBJCOPY, "-O", "binary", "-j", name, elf, bin_])
        code = bin_.read_bytes()
        if len(code) > room:
            sys.exit(f"build.py: {name} is {len(code)} bytes, room for {room}")
        sections[image] = (base, code)
        new = symbols(elf)
        linked_syms.update({k: v for k, v in new.items() if base <= v < base + room})
        print(f"{name}: {len(code)} of {room} bytes at {base:#010x}")

    # detours
    writes = {"exe": [], "battle": []}
    for img, func, repl, *tr in detours:
        addr = retail_syms[img][func]
        target = linked_syms.get(f"{func}_count" if repl == "@count" else repl)
        if target is None:
            sys.exit(f"build.py: {repl} is not defined by the patch")
        writes[img].append((addr, struct.pack("<2I", 0x08000000 | ((target >> 2) & 0x3FFFFFF), 0)))

    # images
    exe = bytearray(retail["exe"])
    battle = bytearray(retail["battle"])
    base, code = sections["battle"]
    battle += bytes(base - BATTLE_VRAM - len(battle)) + code
    battle += bytes(-len(battle) % 4)
    if (len(battle) + 0x7FF) // 0x800 > BATTLE_SECTORS_MAX:
        sys.exit("build.py: BATTLE.BIN would overrun EFFECT.BIN on the disc")
    base_e, code_e = sections["exe"]
    writes["exe"].append((base_e, code_e))
    for addr, old, f in SIZE_WORDS:
        cur = struct.unpack_from("<I", exe, addr - EXE_VRAM + EXE_HEADER)[0]
        if cur != old:
            sys.exit(f"build.py: EXE word {addr:#x} is {cur:#x}, expected {old:#x}")
        writes["exe"].append((addr, struct.pack("<I", f(len(battle)))))
    for addr, data in writes["exe"]:
        o = addr - EXE_VRAM + EXE_HEADER
        exe[o:o + len(data)] = data
    for addr, data in writes["battle"]:
        o = addr - BATTLE_VRAM
        battle[o:o + len(data)] = data
    (OUT / "SLUS_010.51").write_bytes(exe)
    (OUT / "BATTLE.BIN").write_bytes(battle)
    print(f"build/shpatch/SLUS_010.51 ({len(exe)} bytes), build/shpatch/BATTLE.BIN ({len(battle)} bytes, "
          f"{(len(battle) + 0x7FF) // 0x800} sectors); {len(detours)} detours")

    if a.inject:
        import duckstation as d
        status = d.call("get_status")
        if status.get("state") != "paused":
            sys.exit("build.py --inject: pause DuckStation first (in a battle, with no CD read in flight)")
        if bytes.fromhex(d.call("read_memory", address=hex(BATTLE_VRAM), size=4)["data"]) != battle[:4]:
            sys.exit("build.py --inject: BATTLE.BIN is not loaded")
        # An earlier injection may have detoured functions this one does not: put their retail bytes back first, or
        # they would jump into the middle of the new sections.
        order = []
        for img, start, data, base_img in (("battle", BATTLE_VRAM, retail["battle"], BATTLE_VRAM),
                                           ("exe", EXE_VRAM, retail["exe"][EXE_HEADER:], EXE_VRAM)):
            dump = OUT / f"live_{img}.bin"  # large inline reads stall the server; a file read takes 0.4 s
            d.call("read_memory", address=hex(start), size=len(data), path=str(dump))
            live = dump.read_bytes()
            lo, hi = REGIONS["battle"][1], REGIONS["battle"][1] + REGIONS["battle"][2]
            lo_e, hi_e = REGIONS["exe"][1], REGIONS["exe"][1] + REGIONS["exe"][2]
            for name, addr in retail_syms[img].items():
                o = addr - base_img
                if not 0 <= o < len(live) - 8 or (lo_e <= addr < hi_e):
                    continue
                w = struct.unpack_from("<I", live, o)[0]
                t = ((w & 0x3FFFFFF) << 2) | 0x80000000
                if w >> 26 == 2 and (lo <= t < hi or lo_e <= t < hi_e) and live[o:o + 8] != data[o:o + 8]:
                    order.append((addr, data[o:o + 8]))
        # sections next, detours last, so no detour can reach code that is not there yet
        order += [(sections["battle"][0], sections["battle"][1]), (base_e, code_e)]
        order += [(a_, d_) for a_, d_ in writes["battle"] + writes["exe"] if a_ not in (base_e,)]
        for addr, data in order:
            d.call("write_memory", address=hex(addr), data=data.hex())
        print(f"injected {len(order)} writes into DuckStation")


if __name__ == "__main__":
    main()
