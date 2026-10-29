"""Parse splat/spimdisasm .s files into functions and data blocks.

Each `glabel` in a text section becomes a Function holding its instructions;
each `dlabel` in a data section becomes a DataBlock holding its directives.
Labels (`.L800C1CDC:`) attach to the address of the next item.
"""
import re
from dataclasses import dataclass, field
from pathlib import Path

# /* 9580 80018D80 07008424 */  addiu  $a0, $a0, 0x7     (instruction or 4-byte data)
ITEM_RE = re.compile(r"^\s*/\*\s*([0-9A-F]+)\s+([0-9A-F]{8})(?:\s+([0-9A-F]+))?\s*\*/\s+(\S+)\s*(.*?)\s*$")
LABEL_RE = re.compile(r"^\s*(\.L[0-9A-Za-z_]+):\s*$")
RAWBYTES_RE = re.compile(r"^\s*/\*\s*([0-9A-F]+)\s*\*/\s*$")
TRAIL_COMMENT_RE = re.compile(r"\s*/\*.*?\*/\s*$")
RELOC_RE = re.compile(r"%(hi|lo|gp_rel)\(\s*([A-Za-z_.$][\w.$]*)\s*(?:\+\s*(0x[0-9A-Fa-f]+|\d+))?\s*\)")


@dataclass
class Item:
    vaddr: int
    word: int          # raw little-endian word (instructions / .word); 0 for other data
    mnem: str          # text mnemonic or data directive
    ops: str           # operand text with trailing comment removed
    comment: str = ""  # trailing /* ... */ comment, if any
    raw_hex: str = ""  # the hex bytes as printed


@dataclass
class Function:
    name: str
    path: Path
    items: list = field(default_factory=list)
    labels: dict = field(default_factory=dict)   # vaddr -> [label names]
    handwritten: bool = False
    size: int = 0


@dataclass
class DataBlock:
    name: str
    path: Path
    section: str
    items: list = field(default_factory=list)
    labels: dict = field(default_factory=dict)


@dataclass
class AsmFile:
    path: Path
    functions: list = field(default_factory=list)
    data: list = field(default_factory=list)


def parse_reloc(ops):
    """Return (kind, symbol, addend) for the first %hi/%lo/%gp_rel in ops, or None."""
    m = RELOC_RE.search(ops)
    if not m:
        return None
    add = m.group(3)
    return m.group(1), m.group(2), (int(add, 0) if add else 0)


def parse_file(path):
    path = Path(path)
    af = AsmFile(path)
    section = ".text"
    cur = None
    pending_labels = []
    handwritten_next = False
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        s = line.strip()
        if not s:
            continue
        if s.startswith(".section"):
            section = s.split()[1].rstrip(",")
            continue
        if s == "/* Handwritten function */":
            handwritten_next = True
            continue
        if s.startswith("glabel ") or s.startswith("dlabel ") or s.startswith("jlabel ") or s.startswith("alabel "):
            kw, name = s.split()[:2]
            if kw == "glabel" and section == ".text":
                cur = Function(name, path, handwritten=handwritten_next)
                handwritten_next = False
                af.functions.append(cur)
            elif kw in ("glabel", "dlabel"):
                cur = DataBlock(name, path, section)
                af.data.append(cur)
            else:
                # jlabel/alabel: a label inside the current object
                pending_labels.append(name)
            continue
        if s.startswith("endlabel") or s.startswith("enddlabel"):
            cur = None
            continue
        if s.startswith("nonmatching") or s.startswith(".align") or s.startswith(".include") or s.startswith(".set") \
                or s.startswith("/* Generated") or s.startswith(".size"):
            continue
        m = LABEL_RE.match(line)
        if m:
            pending_labels.append(m.group(1))
            continue
        m = RAWBYTES_RE.match(line)
        if m:
            # the bytes of the preceding .asciz/.ascii, padding included
            if cur is not None and cur.items and cur.items[-1].mnem in (".asciz", ".ascii") and not cur.items[-1].raw_hex:
                cur.items[-1].raw_hex = m.group(1)
            continue
        m = ITEM_RE.match(line)
        if m:
            rest = m.group(5)
            comment = ""
            cm = TRAIL_COMMENT_RE.search(rest)
            if cm:
                comment = cm.group(0).strip()
                rest = rest[:cm.start()]
            raw = m.group(3) or ""
            word = int.from_bytes(bytes.fromhex(raw), "little") if len(raw) == 8 else 0
            it = Item(int(m.group(2), 16), word, m.group(4), rest.strip(), comment, raw)
            if cur is None:
                # stray item outside a label (shouldn't happen in splat output)
                continue
            if pending_labels:
                cur.labels.setdefault(it.vaddr, []).extend(pending_labels)
                pending_labels = []
            cur.items.append(it)
            continue
        # anything else (macros, odd directives) is ignored
    for f in af.functions:
        if f.items:
            f.size = f.items[-1].vaddr + 4 - f.items[0].vaddr
    return af
