"""Convert Shadow Hearts' Judgment Ring art into the patch's VRAM blob (docs/SH_PATCH_DESIGN.md 2.3).

Reads the assets tools/patch/sh_assets.py extracted from the user's Shadow Hearts disc (TEXTURE/BT/BTLDATA.BIN) and
writes build/shpatch/shring.bin: every image at half resolution (Koudelka's ring is half the size of SH's), as 4 bpp
PS1 textures with 15-bit CLUTs, plus a table of VRAM rectangles. tools/patch/build.py appends it to BATTLE.BIN; at
battle start the patch LoadImage()s it from the EFFECT/BIM slot, before the BIM block overwrites it.

Layout (texels in two 4 bpp texture pages at y 256; CLUTs on row 511), mirrored in include/shpatch/ring_tex.h:
  page x 640: ring3 144x144 @ (0,0), ring1 112x112 @ (144,0), ring0 72x72 @ (144,112), shadow 80x80 @ (0,144)
  page x 704: ring2 128x128 @ (0,0), light 72x72 @ (128,0), labels 60x12 @ (128, 72 + 12 i)
  CLUTs: ring (additive, x0.75) x 640, shadow (subtractive, x7/8) x 656, light (additive) x 672, labels x 688

The output is game data: it stays under build/ and is never committed.

  python tools/patch/sh_ring_tex.py [--assets build/shpatch/sh_assets] [--out build/shpatch/shring.bin]
"""
import argparse
import json
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
PAGE_A, PAGE_B, TEX_Y, CLUT_Y = 640, 704, 256, 511
LAYERS = [  # (asset, page x, texel x, texel y, clut x)
    ("00_ring0", PAGE_A, 144, 112), ("01_ring1", PAGE_A, 144, 0), ("02_ring2", PAGE_B, 0, 0),
    ("03_ring3", PAGE_A, 0, 0), ("04_shadow", PAGE_A, 0, 144), ("05_light", PAGE_B, 128, 0)]
LABELS = [0x21, 0x20, 0x1C, 0x1E, 0x1D, 0x1F, 0x23]  # Miss!! Good!! Great!! Nice!! Cool!! Perfect!! Hit!!
LABEL_X, LABEL_Y, LABEL_W, LABEL_H = 128, 72, 60, 12


def half(px, w, h, levels):
    """2x2 box filter of intensity indices, requantised to `levels` steps (index 0 = transparent)."""
    out = []
    for y in range(0, h, 2):
        for x in range(0, w, 2):
            s = px[y * w + x] + px[y * w + x + 1] + px[(y + 1) * w + x] + px[(y + 1) * w + x + 1]
            out.append(min(15, round(s / 4 * 15 / (levels - 1))))
    return out


def pack4(px, w, h, pad_w):
    """4 bpp rows (low nibble first), each padded to pad_w texels, as VRAM halfwords."""
    b = bytearray()
    for y in range(h):
        row = px[y * w:(y + 1) * w] + [0] * (pad_w - w)
        for i in range(0, pad_w, 2):
            b.append(row[i] | row[i + 1] << 4)
    return bytes(b)


def c15(r, g, b, stp):
    return (r >> 3) | (g >> 3) << 5 | (b >> 3) << 10 | stp << 15


def clut16(cols):
    return b"".join(struct.pack("<H", c) for c in cols)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--assets", default=str(ROOT / "build" / "shpatch" / "sh_assets"))
    ap.add_argument("--out", default=str(ROOT / "build" / "shpatch" / "shring.bin"))
    a = ap.parse_args()
    d = Path(a.assets)
    m = json.loads((d / "manifest.json").read_text())
    rects = []  # (x, y, w, h halfwords, data)

    ramp = (d / "00_ring0.clut.bin").read_bytes()
    grey = [ramp[i * 4] for i in range(16)]
    rects.append((640, CLUT_Y, 16, 1, clut16([0] + [c15(g * 3 // 4, g * 3 // 4, g * 3 // 4, 1) for g in grey[1:]])))
    rects.append((656, CLUT_Y, 16, 1, clut16([0] + [c15(g * 7 // 8, g * 7 // 8, g * 7 // 8, 1) for g in grey[1:]])))
    rects.append((672, CLUT_Y, 16, 1, clut16([0] + [c15(j * 17, j * 17, j * 17, 1) for j in range(1, 16)])))

    for name, page, tx, ty in LAYERS:
        e = next(e for e in m["entries"] if e.get("name") == name)
        w, h = e["width"], e["height"]
        px = list((d / e["pixels"]).read_bytes())
        hp = half(px, w, h, 256 if e["bpp"] == 8 else 16)
        hw, hh = w // 2, h // 2
        rects.append((page + tx // 4, TEX_Y + ty, hw // 4, hh, pack4(hp, hw, hh, hw)))

    # labels: 2x2 average in RGB, then the nearest of the cel's own 16 colours
    lab = m["entries"][7]
    lclut = (d / lab["clut"]).read_bytes()
    pal = [tuple(lclut[i * 4:i * 4 + 4]) for i in range(16)]
    rects.append((688, CLUT_Y, 16, 1, clut16([0] + [c15(r, g, b, 1) for r, g, b, _ in pal[1:]])))
    for i, cel in enumerate(LABELS):
        c = lab["cels"][cel]
        w, h = c["width"], c["height"]
        px = list((d / c["pixels"]).read_bytes())
        out = []
        for y in range(0, min(h, 2 * LABEL_H), 2):
            for x in range(0, min(w, 2 * LABEL_W), 2):
                q = [px[(y + dy) * w + x + dx] if x + dx < w and y + dy < h else 0 for dy in (0, 1) for dx in (0, 1)]
                solid = [pal[k] for k in q if k]
                if len(solid) < 2:
                    out.append(0)
                    continue
                avg = [sum(col[j] for col in solid) / len(solid) for j in range(3)]
                out.append(min(range(1, 16), key=lambda k: sum((pal[k][j] - avg[j]) ** 2 for j in range(3))))
        ow, oh = min(w, 2 * LABEL_W) // 2, min(h, 2 * LABEL_H) // 2
        grid = [0] * (LABEL_W * LABEL_H)
        ox, oy = (LABEL_W - ow) // 2, (LABEL_H - oh) // 2
        for y in range(oh):
            for x in range(ow):
                grid[(y + oy) * LABEL_W + x + ox] = out[y * ow + x]
        rects.append((PAGE_B + LABEL_X // 4, TEX_Y + LABEL_Y + LABEL_H * i, LABEL_W // 4, LABEL_H,
                      pack4(grid, LABEL_W, LABEL_H, LABEL_W)))

    head = b"SHRG" + struct.pack("<HH", len(rects), 0)
    off = len(head) + 12 * len(rects)
    table, data = b"", b""
    for x, y, w, h, blob in rects:
        assert len(blob) == w * h * 2, (x, y, w, h, len(blob))
        table += struct.pack("<hhhhI", x, y, w, h, off + len(data))
        data += blob + bytes(-len(blob) % 4)
    Path(a.out).write_bytes(head + table + data)
    print(f"{a.out}: {len(rects)} rectangles, {len(head + table + data)} bytes")


if __name__ == "__main__":
    main()
