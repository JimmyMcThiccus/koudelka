"""Make a git worktree of this repo buildable.

bin/, .venv/ and extracted/ are git-ignored, so a fresh worktree has none of
them. This copies what the build needs from the main checkout (about 45 MB):
binutils, the PsyQ compilers named in config/toolchain.toml, maspsx, the
virtualenv, and the seven retail target files. Copies, not links, so removing
a worktree can never delete the main checkout's files.

Run it from inside the worktree with the main checkout's Python:

    <main>/.venv/Scripts/python.exe tools/worktree_setup.py [--configure]
"""
import argparse
import shutil
import subprocess
import sys
import tomllib
from pathlib import Path

TARGET_FILES = ["extracted/disc1/SLUS_010.51"] + [
    f"extracted/disc1/BIN/{n}.BIN" for n in ["FIELD", "BATTLE", "MOVIE", "CAPTURE", "GAMEEND", "EFFECT"]]


def git(*args, cwd):
    return subprocess.run(["git", *args], cwd=cwd, capture_output=True, text=True, check=True).stdout.strip()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--configure", action="store_true", help="run configure.py (split + build) afterwards")
    a = ap.parse_args()

    here = Path(git("rev-parse", "--show-toplevel", cwd=Path.cwd()))
    main_root = Path(git("rev-parse", "--path-format=absolute", "--git-common-dir", cwd=here)).parent
    if here.resolve() == main_root.resolve():
        sys.exit("worktree_setup: this is the main checkout; run it inside a worktree")

    with open(here / "config" / "toolchain.toml", "rb") as f:
        comp = tomllib.load(f)["compiler"]
    # the default compiler plus any a per-file override names (e.g. PsyQ 4.1 for the sound driver)
    psyqs = [comp["psyq"]] + sorted({o["psyq"] for o in comp.get("overrides", {}).values()
                                     if isinstance(o, dict) and "psyq" in o} - {comp["psyq"]})
    dirs = ["bin/binutils", *psyqs, "bin/maspsx", ".venv"]

    for rel in dirs:
        src, dst = main_root / rel, here / rel
        if not src.exists():
            sys.exit(f"worktree_setup: {src} is missing in the main checkout")
        if dst.exists():
            print(f"{rel}: already present")
            continue
        shutil.copytree(src, dst, symlinks=True)
        print(f"{rel}: copied")
    for rel in TARGET_FILES:
        src, dst = main_root / rel, here / rel
        dst.parent.mkdir(parents=True, exist_ok=True)
        if not dst.exists():
            shutil.copy2(src, dst)
    print(f"{len(TARGET_FILES)} retail target files: copied")

    if a.configure:
        py = here / ".venv" / "Scripts" / "python.exe"
        sys.exit(subprocess.run([str(py), "configure.py"], cwd=here).returncode)


if __name__ == "__main__":
    main()
