"""Extract Shadow Hearts' (PS2, SLUS_203.47) Judgment Ring textures from the user's own disc files.

Reads TEXTURE/BT/BTLDATA.BIN out of TEXTURE.PKB through PKFINFO.TBL, splits its offset table and decodes every
entry: GRA rasters (DPX-compressed or not) and GRS cel sheets. Formats, as read from SLUS_203.47:

  PKFINFO.TBL (FileIOLib::InitPkb/SearchFile/searchInfo/enCode/deCode)
             16-byte header: u16 ?, u16 record size (0x10), u16 record bytes (count = bytes / size), rest 0.
             Records (little endian): 8 bytes packed name, u32 loc, u32 size. The name is not a hash: 12 characters
             of ".0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_" (digit d+1, 0 = none, lower case folds to upper), in
             three groups of four base-40 digits g = c0 + c1*40 + c2*1600 + c3*64000 (< 2^22). Bytes 0..1 (big
             endian) = hi0 + hi1*40 + hi2*1600 with hi = g >> 16; bytes 2..3, 4..5, 6..7 = g & 0xFFFF (big endian).
             Bit 31 of size marks a directory; then (size & 0x7FFFFFFF) / 0x10 is where its children start,
             relative to the index the parent's search started from (0 for the top level). Top-level directories
             are the *.PKB archives (loc 0 in the file: the game fills in the ISO LSN at boot); a top-level file
             (DISK.DAT) is a plain ISO file. A path's byte offset inside its PKB is 16 * the sum of the locs of
             every component below the PKB; files start on 2048-byte sectors. Files are stored as is: no
             compression at this level (individual files may be DPX).
  DPX        (DPX_check, DPX_expand, expand_main, Get_Data) 16-byte header: u16 0xA183, u16 keep-header flag,
             u8 ?, u8 type (0 = 1, else 2; both expand alike), u16 0, u32 stored size (header included), u32
             expanded size. If the keep-header flag is set the expanded data starts with the header (type byte
             cleared). The stream after the header is LZ77 with a bit reader that fetches a byte when 8 bits are
             used, MSB first:
               0              literal byte
               1 0 a b o      copy 2*a+b+2 bytes from distance o (1 byte)
               1 1 lo hi      v = lo | hi<<8: distance (v >> 3) + 1, count (v & 7) + 2;
                              if v & 7 == 0 a third byte n: n == 0 ends the stream, else count n + 9
  GRA        (CCircle::CreateFromGRA) u16 width, u16 height, u16 width, u16 height, u16 bpp (1 = 8 bpp, 2 = 4 bpp),
             u16 1 (always), u16 CLUT colours, u16 0; CLUT (RGBA8888) at +0x10, then the pixels (4 bpp: low nibble
             first). The first width/height pair is what CreateFromGRA uses.
  GRS        (_GRSHDR::GetCelTbl/GetCelBits, CSurface::CreateFromGRS, CCircle::MakeSprite) u8 2, u8 4, u8 bpp (8),
             u8 0, u8 flags (bit 0: cels are 4 bpp, drawn through a 4 bpp CLUT), 3 x u8 0, u16 CLUT colours, u16 cel
             count, u16 cel table offset, u16 cel bits offset; CLUT at +0x10. Cel table: 8 bytes per cel, u16 width,
             u16 height, u16 bits offset in 16-byte units, u16 palette. Pixels are rows of width pixels, packed.
             The palette field picks a 16-colour row of the GRS's CLUT as field & 7: the labels use 0, the status
             icons (entry 8) 8..15, whose rows in the stored CLUT are black, while rows 0..7 draw them correctly
             (empirical: how the GS gets there was not traced).
CLUTs are written exactly as stored. GsxClut::LoadClut applies the CSM1 swizzle (entries 8..15 and 16..23 of each
32 trade places) itself when it uploads an 8 bpp CLUT, so a CLUT the game loads is in logical order (index i =
colour i) and nothing here unswizzles. The ring art does not care: rings 0..3, the shadow and the comet are 4 bpp and
CCircle draws all of them with raster 0's 16-colour CLUT (a grey ramp, index 0 transparent). The light (raster 5) is
8 bpp and RenderLight draws it with system CLUT 2, which CreateRaster fills with LoadGlayedSysClut(2, 8): colour i =
white with alpha (i + 1) >> 1. Its own stored CLUT is never loaded (it is a grey ramp in CSM1 order); the light
preview uses the system CLUT, written as 05_light.sysclut2.clut.bin. PS2 alpha 0x80 = opaque; the previews scale
alpha by 2 (clamped to 255).

  python tools/patch/sh_assets.py --sh "<SH disc folder>" --out build/shpatch/sh_assets

Writes, under --out, BTLDATA.BIN and for each image <name>.png (RGBA preview), <name>.bin (indices, one byte per
pixel even at 4 bpp) and <name>.clut.bin, plus manifest.json. The outputs are game data: keep them under build/.
"""
import argparse
import json
import struct
import sys
import zlib
from pathlib import Path

ALPHABET = ".0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_"
DPX_MAGIC = 0xA183
BTLDATA = "TEXTURE/BT/BTLDATA.BIN"
# BTLDATA.BIN's offset table, as CBattle::AfterLoadInit and the objects it creates use it
NAMES = {0: "ring0", 1: "ring1", 2: "ring2", 3: "ring3", 4: "shadow", 5: "light", 6: "comet", 7: "labels",
         8: "sysclut"}
# CCircle::MakeSprite: SprIdxTbl (0x4B8400, read as 0x4B83FF[mark & 0x7F], so mark 1 is the first entry) maps a
# hit's mark to a label cel; when magic power < 100% the cel is 0x23 instead
SPR_IDX_TBL = [0x21, 0x20, 0x1C, 0x1E, 0x1D, 0x1F, 0x00, 0x01, 0x02, 0x03]
LOW_POWER_CEL = 0x23
# what each cel of the label sheet (entry 7) shows, read off the decoded sheet
LABEL_CELS = [str(d) for d in range(10)] + ["+", "-", "STR", "VIT", "AGL", "INT", "POW", "LUC", "HP", "MP", "SP",
                                            "Poison", "Paralysis", "Silence", "Petrify", "Confusion", "Violently",
                                            "Fine!!", "Great!!", "Cool!!", "Nice!!", "Perfect!!", "Good!!", "Miss!!",
                                            "Strike!!", "Hit!!", "Death!!"]


def encode_name(name):
    digits = []
    for ch in name.upper()[:12]:
        if ch not in ALPHABET:
            sys.exit(f"sh_assets.py: '{ch}' cannot be in a PKFINFO name ({name})")
        digits.append(ALPHABET.index(ch) + 1)
    digits += [0] * (12 - len(digits))
    groups = [sum(d * 40 ** k for k, d in enumerate(digits[g * 4:g * 4 + 4])) for g in range(3)]
    hi = [g >> 16 for g in groups]
    return struct.pack(">HHHH", hi[0] + hi[1] * 40 + hi[2] * 1600, *(g & 0xFFFF for g in groups))


def decode_name(b):
    u = (b[0] << 8) | b[1]
    his = [u % 40, u // 40 % 40, u // 1600 % 40]
    out = ""
    for g in range(3):
        v = his[g] << 16 | ((b[2 + g * 2] << 8) | b[3 + g * 2])
        for k in range(4):
            d = v // 40 ** k % 40
            out += ALPHABET[d - 1] if d else ""
    return out


class PkfInfo:
    def __init__(self, data):
        _, recsize, nbytes = struct.unpack_from("<HHH", data, 0)
        self.recs = [(data[o:o + 8],) + struct.unpack_from("<II", data, o + 8)
                     for o in range(0x10, 0x10 + nbytes // recsize * recsize, recsize)]

    def lookup(self, path):
        """FileIOLib::SearchFile: returns (archive file name, byte offset in it, size)."""
        parts = [p for p in path.replace("\\", "/").split("/") if p]
        start, loc_sum, archive = 0, 0, None
        for depth, part in enumerate(parts):
            key = encode_name(part)
            idx = next((i for i in range(start, len(self.recs)) if self.recs[i][0] == key), None)
            if idx is None:
                sys.exit(f"sh_assets.py: {path}: '{part}' not in PKFINFO.TBL")
            _, loc, size = self.recs[idx]
            if depth == 0:
                archive = part.upper() + (".PKB" if size & 0x80000000 else "")
            else:
                loc_sum += loc
            if size & 0x80000000:
                start += (size & 0x7FFFFFFF) // 0x10
            elif depth != len(parts) - 1:
                sys.exit(f"sh_assets.py: {path}: '{part}' is a file")
        if size & 0x80000000:
            sys.exit(f"sh_assets.py: {path} is a directory")
        return archive, loc_sum * 16, size


def dpx_expand(src):
    """DPX_expand(src, dst, -1): the 16-byte header, then expand_main."""
    magic, keep, _, _, _, stored, expanded = struct.unpack_from("<HHBBHII", src, 0)
    if magic != DPX_MAGIC:
        raise ValueError("not DPX")
    out = bytearray()
    if keep:
        out += src[:5] + b"\0" + src[6:16]
    pos, bits, nbits = 16, 0, 0

    def bit():
        nonlocal pos, bits, nbits
        if nbits == 0:
            bits, nbits = src[pos], 8
            pos += 1
        nbits -= 1
        return (bits >> nbits) & 1

    while True:
        if not bit():
            out.append(src[pos])
            pos += 1
        elif not bit():
            count = bit() * 2 + bit() + 2
            dist = src[pos]
            pos += 1
            for _ in range(count):
                out.append(out[-dist])
        else:
            v = src[pos] | src[pos + 1] << 8
            pos += 2
            dist, count = (v >> 3) + 1, (v & 7) + 2
            if v & 7 == 0:
                n = src[pos]
                pos += 1
                if n == 0:
                    break
                count = n + 9
            for _ in range(count):
                out.append(out[-dist])
    if len(out) != expanded + (16 if keep else 0):
        print(f"sh_assets.py: warning: DPX expanded to {len(out):#x} bytes, header says {expanded:#x}")
    return bytes(out), stored


def unpack_pixels(data, off, width, height, bpp):
    if bpp == 8:
        return bytes(data[off:off + width * height])
    row = (width + 1) // 2
    out = bytearray()
    for y in range(height):
        for x in range(width):
            b = data[off + y * row + x // 2]
            out.append(b >> 4 if x & 1 else b & 0xF)
    return bytes(out)


def write_png(path, width, height, rgba):
    raw = b"".join(b"\0" + rgba[y * width * 4:(y + 1) * width * 4] for y in range(height))

    def chunk(tag, body):
        return struct.pack(">I", len(body)) + tag + body + struct.pack(">I", zlib.crc32(tag + body) & 0xFFFFFFFF)

    path.write_bytes(b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", struct.pack(">IIBBBBB", width, height, 8, 6, 0, 0, 0))
                     + chunk(b"IDAT", zlib.compress(raw, 9)) + chunk(b"IEND", b""))


def to_rgba(indices, clut, base=0):
    out = bytearray()
    for i in indices:
        o = (base + i) * 4
        r, g, b, a = clut[o:o + 4] if o + 4 <= len(clut) else (255, 0, 255, 0x80)
        out += bytes((r, g, b, min(255, a * 2)))
    return bytes(out)


def glayed_sysclut():
    """LoadGlayedSysClut(n, 8): colour 0 transparent black, colour i white with alpha (i + 1) >> 1."""
    return bytes(4) + b"".join(bytes((255, 255, 255, (i + 1) >> 1)) for i in range(1, 256))


def grey_clut(bpp):
    n = 1 << bpp
    return b"".join(bytes((i * 255 // (n - 1),) * 3 + (0x80,)) for i in range(n))


def emit(out, name, width, height, bpp, indices, clut, clut_note, base=0):
    (out / f"{name}.bin").write_bytes(indices)
    write_png(out / f"{name}.png", width, height, to_rgba(indices, clut if clut else grey_clut(bpp), base))
    return {"width": width, "height": height, "bpp": bpp, "png": f"{name}.png", "pixels": f"{name}.bin",
            "clut": clut_note}


def is_grs(e):
    if len(e) < 0x10 or e[2] not in (4, 8):
        return False
    ncol, ncel, ct, cb = struct.unpack_from("<HHHH", e, 8)
    return ct == 0x10 + ncol * 4 and cb == (ct + ncel * 8 + 15) & ~15 and cb + 16 <= len(e)


def decode_gra(out, name, entry, shared_clut):
    info = {}
    data = entry
    if struct.unpack_from("<H", entry, 0)[0] == DPX_MAGIC:
        data, stored = dpx_expand(entry)
        info.update(dpx=True, dpx_stored_size=stored, expanded_size=len(data))
        (out / f"{name}.gra").write_bytes(data)
    else:
        info.update(dpx=False)
    width, height, _, _, code, _, ncol = struct.unpack_from("<HHHHHHH", data, 0)
    bpp = {1: 8, 2: 4}.get(code)
    if bpp is None:
        info.update(kind="unknown", note=f"bpp code {code} not understood; header {data[:16].hex()}")
        return info, None
    clut = bytes(data[0x10:0x10 + ncol * 4])
    pix = unpack_pixels(data, 0x10 + ncol * 4, width, height, bpp)
    if clut:
        (out / f"{name}.clut.bin").write_bytes(clut)
        note = f"{name}.clut.bin"
    if name == "05_light":
        drawn = glayed_sysclut()
        (out / f"{name}.sysclut2.clut.bin").write_bytes(drawn)
        info.update(drawn_with=f"{name}.sysclut2.clut.bin (system CLUT 2, LoadGlayedSysClut(2, 8))")
        info.update(kind="GRA", clut_colours=ncol, gra_header=data[:16].hex())
        info.update(emit(out, name, width, height, bpp, pix, drawn, note))
        # white on transparent is invisible in most viewers: also composite it over black
        rgba = to_rgba(pix, drawn)
        write_png(out / f"{name}_on_black.png", width, height,
                  b"".join(bytes((rgba[o + 3],) * 3 + (255,)) for o in range(0, len(rgba), 4)))
        return info, clut
    if not clut and shared_clut:
        note = "none stored: CCircle draws rasters 1..6 with raster 0's CLUT (preview uses it)"
    elif not clut:
        note = "none stored (grey preview)"
    info.update(kind="GRA", clut_colours=ncol, gra_header=data[:16].hex())
    info.update(emit(out, name, width, height, bpp, pix, clut or shared_clut, note))
    return info, clut


def decode_grs(out, name, entry):
    flags = entry[4]
    ncol, ncel, ct, cb = struct.unpack_from("<HHHH", entry, 8)
    bpp = 4 if flags & 1 else entry[2]
    clut = bytes(entry[0x10:0x10 + ncol * 4])
    celdir = out / name
    celdir.mkdir(exist_ok=True)
    (celdir / "clut.bin").write_bytes(clut)
    cels, sheet_w, sheet = [], 0, []
    for i in range(ncel):
        w, h, units, pal = struct.unpack_from("<HHHH", entry, ct + i * 8)
        pix = unpack_pixels(entry, cb + units * 16, w, h, bpp)
        base = (pal & 7) * 16 if bpp == 4 else 0
        cel = emit(celdir, f"cel_{i:02X}", w, h, bpp, pix, clut, f"{name}/clut.bin", base)
        cel.update(index=i, bits_offset=cb + units * 16, palette=pal)
        cel["png"], cel["pixels"] = f"{name}/{cel['png']}", f"{name}/{cel['pixels']}"
        cels.append(cel)
        sheet.append((w, h, to_rgba(pix, clut, base)))
        sheet_w = max(sheet_w, w)
    # contact sheet: cels top to bottom in index order, 2 px apart, on a dark grey ground
    gap = 2
    sheet_h = sum(h + gap for _, h, _ in sheet)
    canvas = bytearray(bytes((40, 40, 40, 255)) * (sheet_w * sheet_h))
    y = 0
    for i, (w, h, rgba) in enumerate(sheet):
        cels[i]["sheet_y"] = y
        for r in range(h):
            for x in range(w):
                s, d = (r * w + x) * 4, ((y + r) * sheet_w + x) * 4
                a = rgba[s + 3]
                for c in range(3):
                    canvas[d + c] = (rgba[s + c] * a + canvas[d + c] * (255 - a)) // 255
        y += h + gap
    write_png(out / f"{name}_sheet.png", sheet_w, sheet_h, bytes(canvas))
    return {"kind": "GRS", "bpp": bpp, "flags": flags, "clut_colours": ncol, "clut": f"{name}/clut.bin",
            "cel_count": ncel, "cel_table": ct, "cel_bits": cb, "sheet": f"{name}_sheet.png", "cels": cels}


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--sh", required=True, help="folder holding PKFINFO.TBL and the *.PKB archives")
    ap.add_argument("--out", required=True, help="output folder (keep it under build/)")
    args = ap.parse_args()
    sh, out = Path(args.sh), Path(args.out)
    out.mkdir(parents=True, exist_ok=True)

    tbl = PkfInfo((sh / "PKFINFO.TBL").read_bytes())
    archive, offset, size = tbl.lookup(BTLDATA)
    with open(sh / archive, "rb") as f:
        f.seek(offset)
        btl = f.read(size)
    if len(btl) != size:
        sys.exit(f"sh_assets.py: {archive} is too short for {BTLDATA}")
    (out / "BTLDATA.BIN").write_bytes(btl)

    count = struct.unpack_from("<I", btl, 0)[0] // 4
    offs = list(struct.unpack_from(f"<{count}I", btl, 0)) + [len(btl)]
    manifest = {"source": {"path": BTLDATA, "archive": archive, "offset": offset, "size": size},
                "spr_idx_tbl": SPR_IDX_TBL, "low_power_cel": LOW_POWER_CEL, "entries": []}
    shared = None
    for i in range(count):
        entry = btl[offs[i]:offs[i + 1]]
        name = f"{i:02d}_{NAMES.get(i, 'entry')}"
        if is_grs(entry):
            info = decode_grs(out, name, entry)
        else:
            info, clut = decode_gra(out, name, entry, shared if i <= 6 else None)
            if i == 0:
                shared = clut
        if i <= 6 and i != 5:
            info["drawn_with"] = "00_ring0.clut.bin (CCircle loads only raster 0's CLUT)"
        if i == 7:
            for cel, word in zip(info["cels"], LABEL_CELS):
                cel["shows"] = word
        info.update(index=i, name=name, offset=offs[i], size=offs[i + 1] - offs[i])
        manifest["entries"].append(info)
        dims = f"{info['width']}x{info['height']}" if "width" in info else f"{info.get('cel_count', '?')} cels"
        print(f"{name:12} {info['kind']:4} {offs[i]:#07x} {dims:>9} {info.get('bpp', '?')} bpp "
              f"{info.get('clut_colours', 0)} colours")
    (out / "manifest.json").write_text(json.dumps(manifest, indent=1))
    print(f"sh_assets.py: {count} entries from {archive}+{offset:#x} -> {out}")


if __name__ == "__main__":
    main()
