"""Per-file compiler settings from config/toolchain.toml, shared by configure.py and try_compile.py.

[compiler] holds the defaults (psyq, aspsx, cflags, expand_div). A [compiler.overrides]
entry for a source file is either a cflags string or a table with any of: cflags, as_G
(assembler -G), psyq (compiler directory), aspsx (maspsx --aspsx-version), expand_div.
"""
import tomllib
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

with open(ROOT / "config" / "toolchain.toml", "rb") as f:
    COMPILER = tomllib.load(f)["compiler"]


def settings(src):
    """The merged settings dict for a source path like "src/main/sound.cpp"."""
    o = COMPILER.get("overrides", {}).get(src, {})
    if not o and src.startswith("src/bim/"):  # the BIM.AR monster modules: built like the overlays
        o = {"cflags": "-O2 -G8", "as_G": 0}
    if isinstance(o, str):
        o = {"cflags": o}
    s = {k: COMPILER[k] for k in ("psyq", "aspsx", "cflags") if k in COMPILER}
    s["expand_div"] = COMPILER.get("expand_div", False)
    s.update(o)
    return s


def cc_args(src):
    """tools/cc.py arguments (a list) for a source path."""
    s = settings(src)
    args = ["--psyq", s["psyq"], "--aspsx", s["aspsx"], "--cflags", s["cflags"]]
    if "as_G" in s:
        args += ["--as-G", str(s["as_G"])]
    if s["expand_div"]:
        args.append("--expand-div")
    if s.get("as_G", 8) != 0 and Path(src).parts[1] == "main":
        args += ["--gp-from", f"asm/main/*/{Path(src).stem}"]
    return args


def target_of(src):
    """(asm dir, retail binary) for the target a source path builds into."""
    area = Path(src).parts[1]
    if area == "main":
        return "asm/main", "extracted/disc1/SLUS_010.51"
    if area == "bim_base":
        return "asm/bim_base", "extracted/bim/bim_base.bin"
    if area == "bim":
        name = Path(src).parts[2]
        return f"asm/bim/{name}", f"extracted/bim/{name}.bin"
    return f"asm/{area}", f"extracted/disc1/BIN/{area.upper()}.BIN"
