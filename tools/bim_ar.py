"""Measure MONSTER/BIM.AR, the monsters' code-overlay archive.

BIM.AR has no header or entry table. It is 332 back-to-back "blocks", each one overlay image (id word
0x0000000a, loaded at 0x800D5DAC like EFFECT.BIN) followed by that monster's data. A block starts at a
sector whose first 20 bytes are the fixed signature below. BIN/SECT.DAT maps monster id -> (absolute
LBA, bytes) for 95 of the blocks. See docs/BIM_AR.md.

  python tools/bim_ar.py --disc <extracted/disc1> [--out build/bim_ar] [--extract]

--out gets blocks.csv, funcs.csv and summary.txt; --extract also writes the distinct module images
(code part only) as mod_<hash>.bin. Everything under --out is derived from game data: keep it git-ignored.
"""
import argparse
import collections
import csv
import hashlib
import json
import os
import re
import struct

BASE = 0x800D5DAC  # overlay slot shared with EFFECT.BIN
BIM_LBA = 2203  # MONSTER/BIM.AR on the disc (extracted/disc1.files.txt)
SECTOR = 2048
SIG = struct.pack("<5I", 0xA, 0, 0, 0, 0x800D6B98)
# BATTLE.BIN's calls to 0x800D5DAC and above that are not EFFECT functions (found while fixing Ghidra refs)
BATTLE_TARGETS = [0x800D6328, 0x800D68EC, 0x800D7048, 0x800D8F98, 0x800D8FF8, 0x800D94F4, 0x800DA400]


def words(b):
    return struct.unpack("<%dI" % (len(b) // 4), b[: len(b) // 4 * 4])


def find_blocks(d):
    starts = [s for s in range(len(d) // SECTOR) if d[s * SECTOR : s * SECTOR + 20] == SIG]
    ends = starts[1:] + [len(d) // SECTOR]
    return list(zip(starts, ends))


def read_sect(path):
    t = open(path, "rb").read()
    w = words(t)
    return {i // 2: (w[i], w[i + 1]) for i in range(0, len(w), 2) if w[i] and w[i + 1]}


# One block's first 0xA000 bytes are the overlay image; the rest of the block (sector 20 on) is model/texture/motion
# data with no code in it. The image is four windows, each padded with 0x2a ('*') up to its end:
#   W0 0x0000-0x5DE0 overlay id 0x0a: header (id word + entry table), vtables, the monster's behaviour code
#   W1 0x5DE0-0x7100 a second overlay-style module (own id word + pointer table), or all '*'
#   W2 0x7100-0x8420 a third, same shape
#   W3 0x8420-0x981C data table tagged "MCTB" (stats; BATTLE copies 0x2C bytes from image+0x97F0); then 0x40 fill to 0xA000
WINDOWS = [(0x0000, 0x5DE0), (0x5DE0, 0x7100), (0x7100, 0x8420)]
DATA_WIN = (0x8420, 0x981C)
IMAGE = 0xA000
NL = chr(10)


def window(img, w):
    """The window's bytes without its trailing '*' fill."""
    return img[w[0] : w[1]].rstrip(b"*")


def func_starts(code, base):
    """Function boundaries: frame-pushing prologues, jal targets and the header's pointers, all inside the window."""
    w = words(code)
    s = set()
    for i, x in enumerate(w):
        if x >> 16 == 0x27BD and x & 0x8000 and i >= 0x40:  # addiu $sp,$sp,-N
            s.add(i * 4)
        if x >> 26 == 3:  # jal
            o = ((x & 0x3FFFFFF) << 2 | 0x80000000) - base
            if 0 <= o < len(code):
                s.add(o)
    for x in w[:0x100]:
        o = x - base
        if 0 < o < len(code) and o % 4 == 0:
            s.add(o)
    return sorted(s)


def first_code(code):
    """Offset of the first prologue: the header and vtables before it are data."""
    w = words(code)
    for i, x in enumerate(w):
        if x >> 16 == 0x27BD and x & 0x8000 and i >= 0x40:
            return i * 4
    return len(code)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--disc", required=True)
    ap.add_argument("--out", default="build/bim_ar")
    ap.add_argument("--extract", action="store_true")
    a = ap.parse_args()
    d = open(os.path.join(a.disc, "MONSTER", "BIM.AR"), "rb").read()
    sect = read_sect(os.path.join(a.disc, "BIN", "SECT.DAT"))
    by_lba = collections.defaultdict(list)
    for idx, (lba, sz) in sect.items():
        by_lba[lba - BIM_LBA].append((idx, sz))
    blocks = find_blocks(d)
    os.makedirs(a.out, exist_ok=True)

    rows = []
    wins = [dict() for _ in WINDOWS]  # per window: content hash -> (bytes, [block starts])
    datas = {}
    funcs = collections.defaultdict(set)  # (addr, body hash) -> {(window, content hash)}
    fbytes = {}
    stats = collections.Counter()
    ids = [collections.Counter() for _ in WINDOWS]
    tgt = {t: collections.Counter() for t in BATTLE_TARGETS}
    seen = set()
    for s, e in blocks:
        b = d[s * SECTOR : e * SECTOR]
        img = b[:IMAGE]
        hs = []
        for wi, w in enumerate(WINDOWS):
            c = window(img, w)
            h = hashlib.md5(c).hexdigest()[:10]
            hs.append(h)
            wins[wi].setdefault(h, (c, []))[1].append(s)
            if c:
                ids[wi][struct.unpack("<I", c[:4])[0]] += 1
            if (wi, h) in seen:
                continue
            seen.add((wi, h))
            base = BASE + w[0]
            fc = first_code(c)
            fs = [o for o in func_starts(c, base) if o >= fc]
            for o, o2 in zip(fs, fs[1:] + [len(c)]):
                fh = hashlib.md5(c[o:o2]).hexdigest()[:10]
                funcs[(base + o, fh)].add((wi, h))
                fbytes[(base + o, fh)] = o2 - o
            cw = words(c)
            for i, x in enumerate(cw):
                if i * 4 < fc:
                    continue
                if x == 0x03E00008:
                    stats["jr_ra"] += 1
                    slot = cw[i + 1] if i + 1 < len(cw) else 0
                    if slot >> 16 == 0x27BD:
                        stats["epilogue_gcc28 (jr ra; addiu sp in the slot)"] += 1
                    elif slot == 0 and cw[i - 1] >> 16 == 0x27BD:
                        stats["epilogue_gcc272 (addiu sp; jr ra; nop)"] += 1
                if x == 0x0007000D:
                    stats["break 7 (divide by zero check)"] += 1
                if x == 0x0006000D:
                    stats["break 6 (divide overflow check)"] += 1
        dat = img[DATA_WIN[0] : DATA_WIN[1]]
        datas.setdefault(hashlib.md5(dat).hexdigest()[:10], dat)
        ids_here = [i for i, _ in by_lba.get(s, [])]
        rows.append((s, e - s, ".".join(hs), hashlib.md5(b).hexdigest()[:10], ",".join(map(str, ids_here)), dat[:4].decode("latin1")))
        full = img[:0x8420]
        for t in BATTLE_TARGETS:
            o = t - BASE
            tgt[t][full[o : o + 4].hex()] += 1

    with open(os.path.join(a.out, "blocks.csv"), "w", newline="") as f:
        c = csv.writer(f)
        c.writerow(["sector", "sectors", "win_hashes_w0.w1.w2", "block_hash", "sect_ids", "w3_tag"])
        c.writerows(rows)
    with open(os.path.join(a.out, "funcs.csv"), "w", newline="") as f:
        c = csv.writer(f)
        c.writerow(["addr", "body_hash", "bytes", "windows_containing"])
        for (addr, fh), ms in sorted(funcs.items()):
            c.writerow(["%08x" % addr, fh, fbytes[(addr, fh)], len(ms)])

    out = []
    out.append("blocks %d (%d distinct by full bytes), %d sectors" % (len(blocks), len({r[3] for r in rows}), len(d) // SECTOR))
    out.append("SECT.DAT entries %d -> %d distinct blocks" % (len(sect), len(by_lba)))
    for wi, w in enumerate(WINDOWS):
        used = [h for h, (c, _) in wins[wi].items() if c]
        out.append("W%d: %d distinct contents (%d non-empty, %d blocks with it empty), %d distinct bytes" % (
            wi, len(wins[wi]), len(used), sum(len(v[1]) for h, v in wins[wi].items() if not v[0]), sum(len(wins[wi][h][0]) for h in used)))
        out.append("   id words: " + str({hex(k): v for k, v in ids[wi].most_common()}))
        out.append("   multiplicity of contents: " + str(sorted(collections.Counter(len(v[1]) for h, v in wins[wi].items() if v[0]).items())))
    out.append("W3 data: %d distinct of %d, %d bytes each" % (len(datas), len(blocks), DATA_WIN[1] - DATA_WIN[0]))
    nf = len(funcs)
    out.append("distinct (addr, body) functions %d, %d bytes" % (nf, sum(fbytes.values())))
    for wi in range(len(WINDOWS)):
        fw = [k for k, v in funcs.items() if any(x[0] == wi for x in v)]
        out.append("   W%d: %d functions, %d bytes; in every non-empty W%d content: %d" % (
            wi, len(fw), sum(fbytes[k] for k in fw), wi,
            sum(1 for k in fw if len({x for x in funcs[k] if x[0] == wi}) == len([h for h, (c, _) in wins[wi].items() if c]))))
    out.append("counts over distinct window contents: " + str(dict(stats)))
    for t in BATTLE_TARGETS:
        out.append("BATTLE target %08x first word across %d blocks: %s" % (t, len(blocks), dict(tgt[t])))
    print(NL.join(out))

    # W0 = shared base (identical in every block) + a monster-specific tail
    w0 = [c for c, _ in wins[0].values()]
    n = min(len(c) for c in w0)
    share = 0
    while share + 4 <= n and len({c[share : share + 4] for c in w0}) == 1:
        share += 4
    out.append("W0 shared base: first 0x%X bytes identical in all %d contents; tails 0x%X.. (%d..%d bytes)" % (
        share, len(w0), share, min(len(c) - share for c in w0), max(len(c) - share for c in w0)))
    open(os.path.join(a.out, "summary.txt"), "w").write(NL.join(out) + NL)
    print(out[-1])

    if a.extract:
        man = [{"name": "bim_base", "vram": BASE, "size": share, "sha1": hashlib.sha1(w0[0][:share]).hexdigest(), "blocks": len(blocks)}]
        open(os.path.join(a.out, "bim_base.bin"), "wb").write(w0[0][:share])
        for wi in range(len(WINDOWS)):
            for h, (c, ss) in sorted(wins[wi].items()):
                if not c:
                    continue
                name = "w%d_%s" % (wi, h)
                data = c[share:] if wi == 0 else c
                vram = BASE + WINDOWS[wi][0] + (share if wi == 0 else 0)
                open(os.path.join(a.out, name + ".bin"), "wb").write(data)
                ids = sorted({i for s0 in ss for i, _ in by_lba.get(s0, [])})
                man.append({"name": name, "vram": vram, "size": len(data), "sha1": hashlib.sha1(data).hexdigest(),
                            "blocks": len(ss), "sect_ids": ids})
        json.dump(man, open(os.path.join(a.out, "manifest.json"), "w"), indent=1)
        print("wrote %d modules + manifest.json to %s" % (len(man), a.out))


if __name__ == "__main__":
    main()
