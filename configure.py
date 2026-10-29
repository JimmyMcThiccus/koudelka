"""Configure the Koudelka build.

Splits every target with splat (unless --no-split), writes build.ninja and runs
ninja. Each target (the EXE and six overlays) is assembled, linked and
extracted to a flat binary.

Two modes:
  functional (default)  the goal is a build that behaves like retail, not one
      that matches it byte for byte. Overlays take the EXE's symbols (and
      EFFECT takes BATTLE's) from the linked ELF, so code may move. The gate is
      tools/functional_check.py: every image fits its retail footprint and the
      pinned entry points in config/pins.txt stay put. SHA-1 is reported only.
  matching  every image must equal retail (tools/check.py, per target).

Usage: .venv/Scripts/python.exe configure.py [--mode functional|matching] [--no-split] [--no-build]
"""
import argparse
import os
import re
import subprocess
import sys
from pathlib import Path

import ninja_syntax
import yaml

ROOT = Path(__file__).resolve().parent
PY = sys.executable
# Native path: CreateProcess (ninja on Windows) can't launch "bin/..." relative paths.
BINUTILS = str(ROOT / "bin" / "binutils" / "mips-ps2-decompals-")
TARGETS = ["slus_010.51", "field", "battle", "movie", "capture", "gameend", "effect", "bim_base"]
# The BIM.AR monster modules: one generated config per distinct module (tools/gen_bim_targets.py).
BIM_MODULES = sorted("bim/" + p.stem for p in ROOT.glob("config/bim/*.yaml"))
TARGETS += BIM_MODULES
# Images whose symbols an overlay links against in functional mode.
DEPENDS = {t: ["slus_010.51"] for t in TARGETS[1:]}
DEPENDS["effect"] = ["slus_010.51", "battle"]  # EFFECT loads directly after BATTLE
DEPENDS["bim_base"] = ["slus_010.51", "battle"]  # BIM.AR modules load in EFFECT's place
for _m in BIM_MODULES:
    DEPENDS[_m] = ["slus_010.51", "bim_base"]  # each module calls only the EXE and the shared base

AS_FLAGS = "-EL -march=r3000 -mtune=r3000 -mabi=32 -no-pad-sections -G0 -Iinclude"
LD_FLAGS = "-EL --no-check-sections -nostdlib"

sys.path.insert(0, str(ROOT / "tools"))
import toolchain  # noqa: E402  (per-file compiler settings from config/toolchain.toml)


def cc_args(src):
    return " ".join(f'"{a}"' if " " in a else a for a in toolchain.cc_args(src))


def load(target):
    with open(ROOT / "config" / f"{target}.yaml") as f:
        return yaml.safe_load(f)


def extract_bim():
    """The BIM.AR shared base is cut from MONSTER/BIM.AR, not a file on the disc (docs/BIM_AR.md)."""
    if (ROOT / "extracted" / "bim" / "bim_base.bin").exists():
        return
    if not (ROOT / "extracted" / "disc1" / "MONSTER" / "BIM.AR").exists():
        sys.exit("configure: extracted/bim/bim_base.bin is missing and so is extracted/disc1/MONSTER/BIM.AR")
    subprocess.run([PY, "tools/bim_ar.py", "--disc", "extracted/disc1", "--out", "extracted/bim", "--extract"],
                   cwd=ROOT, check=True, stdout=subprocess.DEVNULL)


def split(target):
    cfg = load(target)
    asm = ROOT / cfg["options"]["asm_path"]
    if asm.exists():
        import shutil
        shutil.rmtree(asm)
    # Overlays list the EXE's symbols too; splat warns that they fall outside the
    # overlay's segments, which is expected. Keep the log for real errors.
    log = ROOT / "build" / f"split.{target}.log"
    log.parent.mkdir(parents=True, exist_ok=True)
    with open(log, "w") as f:
        subprocess.run([PY, "-m", "splat", "split", f"config/{target}.yaml"], cwd=ROOT, check=True,
                       stdout=f, stderr=subprocess.STDOUT)
    if target == "slus_010.51":
        # splat writes the PS-X EXE header's initial PC as a number. Make it the entry symbol, so a
        # functional build whose code has moved still boots at `start`.
        header = asm / "header.s"
        text = header.read_text()
        fixed = re.sub(r"\.word 0x800A0A20(\s*/\* Initial PC \*/)", r".word start\1", text)
        if fixed == text:
            sys.exit("configure: EXE header initial PC not found in " + str(header))
        header.write_text(fixed)


def write_ninja(mode):
    out = open(ROOT / "build.ninja", "w")
    n = ninja_syntax.Writer(out, width=120)
    n.comment(f"mode: {mode} (configure.py --mode)")
    n.variable("python", PY.replace("\\", "/"))
    n.variable("nm", f"{BINUTILS}nm.exe")
    n.rule("as", f"{BINUTILS}as.exe {AS_FLAGS} -o $out $in", description="as $in")
    n.rule("cc", "$python tools/cc.py $ccargs -Iinclude -o $out $in",
           description="cc $in", depfile="$out.d", deps="gcc")
    n.rule("ld", f"{BINUTILS}ld.exe {LD_FLAGS} -T $ldscript $externs -Map $map -o $out",
           description="ld $out")
    n.rule("objcopy", f"{BINUTILS}objcopy.exe -O binary $in $out", description="objcopy $out")
    n.rule("extern", "$python tools/extern_syms.py $nm $out $undefs --defined $in", description="extern $out")
    n.rule("check", "$python tools/check.py $in $size $sha1 $out", description="check $in")
    n.rule("functional", "$python tools/functional_check.py $nm $out", description="functional check")

    checks = []
    outputs = []
    for t in TARGETS:
        cfg = load(t)
        opt = cfg["options"]
        objs = []
        for s in sorted((ROOT / opt["asm_path"]).rglob("*.s")):
            rel = s.relative_to(ROOT).as_posix()
            if "/nonmatchings/" in rel or "/matchings/" in rel:  # INCLUDE_ASM targets / reference only
                continue
            o = f"build/{rel}.o"
            n.build(o, "as", rel, implicit=["include/macro.inc"])
            objs.append(o)
        src_dir = ROOT / opt["src_path"]
        for s in sorted(p for p in src_dir.rglob("*") if p.suffix in (".c", ".cpp")) if src_dir.exists() else []:
            rel = s.relative_to(ROOT).as_posix()
            o = f"build/{rel}.o"
            n.build(o, "cc", rel, implicit=["tools/cc.py", "config/toolchain.toml"],
                    variables={"ccargs": cc_args(rel)})
            objs.append(o)
        elf = opt["elf_path"]
        undefs = [opt["undefined_syms_auto_path"], opt["undefined_funcs_auto_path"]]
        if mode == "functional" and t in DEPENDS:
            # External symbols at their dependencies' current linked addresses.
            externs = [f"build/linkers/{t}.extern.ld"]
            n.build(externs[0], "extern", [f"build/{d}.elf" for d in DEPENDS[t]], implicit=undefs,
                    variables={"undefs": " ".join(undefs)})
        else:
            externs = undefs
        if t == "slus_010.51":
            externs = externs + ["config/symbols/main_absolute.ld"]
        n.build(elf, "ld", objs, implicit=[opt["ld_script_path"]] + externs,
                variables={"ldscript": opt["ld_script_path"], "map": elf.replace(".elf", ".map"),
                           "externs": " ".join(f"-T {e}" for e in externs)})
        binf = elf.replace(".elf", ".bin")
        n.build(binf, "objcopy", elf)
        outputs += [elf, binf]
        if mode == "matching":
            size = os.path.getsize(ROOT / opt["target_path"])
            ok = f"build/{t}.ok"
            n.build(ok, "check", binf, variables={"size": str(size), "sha1": cfg["sha1"]})
            checks.append(ok)
    if mode == "functional":
        n.build("build/functional.ok", "functional", outputs, implicit=["config/pins.txt"])
        checks.append("build/functional.ok")
    n.build("check", "phony", checks)
    n.default("check")
    out.close()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--mode", choices=["functional", "matching"], default="functional")
    ap.add_argument("--no-split", action="store_true")
    ap.add_argument("--no-build", action="store_true")
    args = ap.parse_args()
    os.chdir(ROOT)
    extract_bim()
    if not args.no_split:
        # splat runs are independent processes with separate outputs, so split in parallel.
        from concurrent.futures import ThreadPoolExecutor
        with ThreadPoolExecutor(max_workers=os.cpu_count() or 4) as pool:
            for t in pool.map(lambda t: (split(t), t)[1], TARGETS):
                print(f"split {t}")
    write_ninja(args.mode)
    if not args.no_build:
        ninja = Path(PY).parent / "ninja.exe"
        sys.exit(subprocess.run([str(ninja), "-k", "0"]).returncode)


if __name__ == "__main__":
    main()
