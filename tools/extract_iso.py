"""Extract the ISO9660 filesystem from a PS1 MODE2/2352 .bin image.

Form 1 files are written as 2048-byte user data. Files flagged as CD-XA
interleaved / Form 2 (STR movies, XA audio) are written as raw 2336-byte
sectors (subheader + data) so no audio/video data is lost.

Usage: python extract_iso.py <image.bin> <out_dir> [--list]
"""
import os
import struct
import sys

RAW = 2352
HDR = 24  # 12 sync + 4 header + 8 subheader (subheader copy x2)


class Image:
    def __init__(self, path):
        self.f = open(path, "rb")
        self.f.seek(0, 2)
        self.sectors = self.f.tell() // RAW

    def raw(self, lba):
        # Some entries point past the end of the image (dummy files); pad with zeros.
        self.f.seek(lba * RAW)
        return self.f.read(RAW).ljust(RAW, b"\0")

    def user(self, lba):
        return self.raw(lba)[HDR:HDR + 2048]

    def mode2(self, lba):
        return self.raw(lba)[16:RAW]  # subheader + 2328 data/edc


def parse_dir(img, lba, size, path, out):
    data = b"".join(img.user(lba + i) for i in range((size + 2047) // 2048))
    pos = 0
    while pos < len(data):
        rlen = data[pos]
        if rlen == 0:
            pos = (pos // 2048 + 1) * 2048
            continue
        rec = data[pos:pos + rlen]
        ext = struct.unpack_from("<I", rec, 2)[0]
        flen = struct.unpack_from("<I", rec, 10)[0]
        flags = rec[25]
        nlen = rec[32]
        name = rec[33:33 + nlen]
        pos += rlen
        if name in (b"\x00", b"\x01"):
            continue
        name = name.decode("ascii", "replace").split(";")[0]
        su = rec[33 + nlen + (1 - nlen % 2):]
        xa_attr = 0
        if len(su) >= 14 and su[6:8] == b"XA":
            xa_attr = struct.unpack_from(">H", su, 4)[0]
        full = f"{path}/{name}" if path else name
        if flags & 2:
            out.append((full, ext, flen, "dir", xa_attr))
            parse_dir(img, ext, flen, full, out)
        else:
            # 0x1000 = Form2, 0x2000 = interleaved
            kind = "xa" if xa_attr & 0x3000 else "file"
            out.append((full, ext, flen, kind, xa_attr))


def main():
    img_path, out_dir = sys.argv[1], sys.argv[2]
    list_only = "--list" in sys.argv
    img = Image(img_path)
    pvd = img.user(16)
    assert pvd[1:6] == b"CD001", "no ISO9660 PVD at sector 16"
    root = pvd[156:156 + 34]
    rlba = struct.unpack_from("<I", root, 2)[0]
    rsize = struct.unpack_from("<I", root, 10)[0]
    entries = []
    parse_dir(img, rlba, rsize, "", entries)
    entries.sort(key=lambda e: e[1])
    for full, ext, flen, kind, attr in entries:
        print(f"{ext:8d} {flen:10d} {kind:4s} {attr:04x} {full}")
        if list_only or kind == "dir":
            continue
        dst = os.path.join(out_dir, full)
        os.makedirs(os.path.dirname(dst) or out_dir, exist_ok=True)
        n = (flen + 2047) // 2048
        # Some STR files lack the XA dir attribute; check sector submodes.
        if kind == "file" and any(img.raw(ext + i)[18] & 0x20 for i in range(min(n, 64))):
            kind = "xa"
        with open(dst, "wb") as o:
            if kind == "xa":
                for i in range(n):
                    o.write(img.mode2(ext + i)[:2336])
            else:
                for i in range(n):
                    o.write(img.user(ext + i))
                o.truncate(flen)
    print(f"# image sectors: {img.sectors}")


if __name__ == "__main__":
    main()
