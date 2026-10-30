"""Fetch the PC port's third-party dependencies into bin/ (git-ignored), pinned by version and SHA-256.

    .venv/Scripts/python.exe tools/port/fetch_deps.py [--force]

  bin/port/psycross  PsyCross at commit e56e4cd (github.com/OpenDriver2/PsyCross)
  bin/port/sdl2      SDL2 2.30.12 VC development package (libsdl-org/SDL release)
  bin/port/openal    OpenAL Soft 1.23.1 Windows binaries (kcat/openal-soft release)

Each archive is downloaded to bin/port/dl/, checked against the hash below, and unpacked into its own
directory (with the archive's single top-level folder stripped). Already-present directories are kept
unless --force. Nothing here runs code from the archives.
"""
import argparse
import hashlib
import shutil
import sys
import urllib.request
import zipfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
DEST = ROOT / "bin" / "port"

PSYCROSS_SHA = "e56e4cde1c2b8a15e0d4e38b26cdd9202e0d17e6"
DEPS = [
    ("psycross", f"https://github.com/OpenDriver2/PsyCross/archive/{PSYCROSS_SHA}.zip",
     "PsyCross-e56e4cd.zip"),
    ("sdl2", "https://github.com/libsdl-org/SDL/releases/download/release-2.30.12/SDL2-devel-2.30.12-VC.zip",
     "SDL2-devel-2.30.12-VC.zip"),
    ("openal", "https://github.com/kcat/openal-soft/releases/download/1.23.1/openal-soft-1.23.1-bin.zip",
     "openal-soft-1.23.1-bin.zip"),
]
# SHA-256 of each archive, recorded at the first fetch. A mismatch stops the script.
SHA256 = {
    "PsyCross-e56e4cd.zip": "d49e4f90d0622951f094d0a3017a17ed81d7a5331470cd2e4d42ab5184470b82",
    "SDL2-devel-2.30.12-VC.zip": "1ca980f9964fb44cf94be235c9818fa1dc8e3f76b08096d751b2d689e5e37d02",
    "openal-soft-1.23.1-bin.zip": "ea8bc36fd7fa05f64e13400d20886de753a227202a4ea3781913489a26b36fc6",
}


def fetch(url, path):
    print(f"  get {url}")
    with urllib.request.urlopen(url) as r, open(path, "wb") as f:
        shutil.copyfileobj(r, f)


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def unpack(zpath, out):
    tmp = out.with_name(out.name + ".tmp")
    if tmp.exists():
        shutil.rmtree(tmp)
    with zipfile.ZipFile(zpath) as z:
        for m in z.namelist():  # refuse absolute paths and ..
            p = Path(m)
            if p.is_absolute() or ".." in p.parts:
                sys.exit(f"fetch_deps: unsafe path {m!r} in {zpath.name}")
        z.extractall(tmp)
    tops = list(tmp.iterdir())
    src = tops[0] if len(tops) == 1 and tops[0].is_dir() else tmp
    if out.exists():
        shutil.rmtree(out)
    shutil.move(str(src), str(out))
    if tmp.exists():
        shutil.rmtree(tmp)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--force", action="store_true", help="download and unpack again")
    a = ap.parse_args()
    (DEST / "dl").mkdir(parents=True, exist_ok=True)
    bad = False
    for name, url, fname in DEPS:
        out = DEST / name
        if out.exists() and not a.force:
            print(f"{name}: present")
            continue
        z = DEST / "dl" / fname
        if not z.exists() or a.force:
            fetch(url, z)
        h = sha256(z)
        want = SHA256.get(fname)
        if want is None:
            print(f"  {fname}: sha256 {h} (not pinned yet; add it to SHA256)")
        elif h != want:
            print(f"  {fname}: sha256 {h} != pinned {want}")
            bad = True
            continue
        unpack(z, out)
        print(f"{name}: unpacked to {out.relative_to(ROOT)}")
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
