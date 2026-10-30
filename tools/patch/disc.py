"""Write the Shadow Hearts patch into a copy of the user's Koudelka disc 1 image (docs/SH_PATCH_DESIGN.md, phase 4 step 6).

Copies the BIN/CUE (MODE2/2352), replaces SLUS_010.51 and BIN/BATTLE.BIN with tools/patch/build.py's outputs, and
recomputes each written sector's EDC and ECC (Mode 2 Form 1). The files stay at their LBAs: the game loads both by
LBA (the EXE through SYSTEM.CNF, BATTLE.BIN through the overlay table D_800AE5F8), and the patched BATTLE.BIN still
ends before EFFECT.BIN. The ISO 9660 directory records get the new sizes so the filesystem stays consistent.

The output image is the user's game data: it stays under build/ and is never committed.

  python tools/patch/disc.py --cue "Koudelka_Game_Data/Koudelka (USA) (Disc 1).cue" [--out build/shpatch/disc]
  python tools/patch/disc.py --selftest --cue ...     check the EDC/ECC code against the original image's sectors
"""
import argparse
import shutil
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
SECTOR, DATA = 2352, 2048

# ---- EDC / ECC (ECMA-130; the same tables every CD tool uses) ----
EDC = []
for i in range(256):
    e = i
    for _ in range(8):
        e = (e >> 1) ^ (0xD8018001 if e & 1 else 0)
    EDC.append(e)
F_LUT, B_LUT = [0] * 256, [0] * 256
for i in range(256):
    j = (i << 1) ^ (0x11D if i & 0x80 else 0)
    F_LUT[i] = j
    B_LUT[i ^ j] = i


def edc(data):
    e = 0
    for b in data:
        e = (e >> 8) ^ EDC[(e ^ b) & 0xFF]
    return e


def ecc_block(src, major_count, minor_count, major_mult, minor_inc):
    size = major_count * minor_count
    out = bytearray(2 * major_count)
    for major in range(major_count):
        index = (major >> 1) * major_mult + (major & 1)
        a = b = 0
        for _ in range(minor_count):
            t = src[index]
            index += minor_inc
            if index >= size:
                index -= size
            a ^= t
            b ^= t
            a = F_LUT[a]
        a = B_LUT[F_LUT[a] ^ b]
        out[major] = a
        out[major + major_count] = a ^ b
    return out


def fix_form1(sec):
    """Recompute EDC (over subheader + data) and P/Q ECC (header treated as zero, as Mode 2 requires)."""
    sec[0x818:0x81C] = struct.pack("<I", edc(sec[0x10:0x818]))
    header = bytes(sec[0xC:0x10])
    sec[0xC:0x10] = b"\0\0\0\0"
    sec[0x81C:0x8C8] = ecc_block(sec[0xC:0x81C], 86, 24, 2, 86)
    sec[0x8C8:0x930] = ecc_block(sec[0xC:0x8C8], 52, 43, 86, 88)
    sec[0xC:0x10] = header


# ---- ISO 9660 ----
def read_sector(f, lba):
    f.seek(lba * SECTOR)
    return f.read(SECTOR)


def dir_records(f, lba, size):
    for s in range((size + DATA - 1) // DATA):
        data = read_sector(f, lba + s)[24:24 + DATA]
        o = 0
        while o < DATA and data[o]:
            n = data[o]
            name = data[o + 33:o + 33 + data[o + 32]].decode("ascii", "replace")
            yield name, lba + s, o, struct.unpack_from("<I", data, o + 2)[0], struct.unpack_from("<I", data, o + 10)[0], data[o + 25]
            o += n


def find(f, path):
    pvd = read_sector(f, 16)[24:24 + DATA]
    root = pvd[156:156 + 34]
    lba, size = struct.unpack_from("<I", root, 2)[0], struct.unpack_from("<I", root, 10)[0]
    rec = None
    for part in path.split("/"):
        for name, rl, ro, el, sz, flags in dir_records(f, lba, size):
            if name.split(";")[0].upper() == part.upper():
                rec = (rl, ro, el, sz)
                lba, size = el, sz
                break
        else:
            sys.exit(f"disc.py: {path} not found")
    return rec  # (directory sector LBA, record offset, extent LBA, size)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--cue", required=True)
    ap.add_argument("--out", default=str(ROOT / "build" / "shpatch" / "disc"))
    ap.add_argument("--selftest", action="store_true")
    a = ap.parse_args()
    cue = Path(a.cue)
    bin_name = next(l.split('"')[1] for l in cue.read_text().splitlines() if l.startswith("FILE"))
    src = cue.parent / bin_name

    if a.selftest:
        with open(src, "rb") as f:
            for lba in (16, 100, 1400, 1461, 5000):
                s = bytearray(read_sector(f, lba))
                if s[0x12] & 0x20:
                    print(f"LBA {lba}: form 2, skipped")
                    continue
                t = bytearray(s)
                fix_form1(t)
                print(f"LBA {lba}: EDC/ECC {'match' if t == s else 'DIFFER'}")
        return

    files = {"SLUS_010.51": ROOT / "build" / "shpatch" / "SLUS_010.51",
             "BIN/BATTLE.BIN": ROOT / "build" / "shpatch" / "BATTLE.BIN"}
    out = Path(a.out)
    out.mkdir(parents=True, exist_ok=True)
    dst = out / "Koudelka (USA) (Disc 1) [SH patch].bin"
    print(f"copying {src.name} ...")
    shutil.copyfile(src, dst)
    with open(dst, "r+b") as f:
        effect = find(f, "BIN/EFFECT.BIN")[2]
        for path, new in files.items():
            dl, do, lba, old_size = find(f, path)
            data = new.read_bytes()
            n_old, n_new = (old_size + DATA - 1) // DATA, (len(data) + DATA - 1) // DATA
            if path.endswith("BATTLE.BIN") and lba + n_new > effect:
                sys.exit("disc.py: BATTLE.BIN would overrun EFFECT.BIN")
            for i in range(max(n_old, n_new)):
                s = bytearray(read_sector(f, lba + i))
                chunk = data[i * DATA:(i + 1) * DATA]
                s[24:24 + DATA] = chunk + bytes(DATA - len(chunk))
                sub = 0x89 if i == n_new - 1 else 0x08 if i < n_new else 0x00  # data; EOR|EOF on the last sector
                s[16:24] = bytes((0, 0, sub, 0, 0, 0, sub, 0))
                fix_form1(s)
                f.seek((lba + i) * SECTOR)
                f.write(s)
            # directory record: size (both endian)
            s = bytearray(read_sector(f, dl))
            r = 24 + do
            s[r + 10:r + 18] = struct.pack("<I", len(data)) + struct.pack(">I", len(data))
            fix_form1(s)
            f.seek(dl * SECTOR)
            f.write(s)
            print(f"{path}: LBA {lba}, {old_size:#x} -> {len(data):#x} bytes ({n_old} -> {n_new} sectors)")
    (out / "Koudelka (USA) (Disc 1) [SH patch].cue").write_text(
        f'FILE "{dst.name}" BINARY\n  TRACK 01 MODE2/2352\n    INDEX 01 00:00:00\n')
    print(f"wrote {dst}")


if __name__ == "__main__":
    main()
