"""MIPS I (R3000 + GTE) decoding from the raw instruction word.

The text mnemonic splat prints is only used for relocations and labels; the
operation itself comes from the word, so pseudo-ops (beqz, negu, b, move, ...)
need no special cases.
"""
from dataclasses import dataclass

REG_NAMES = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3",
             "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
             "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7",
             "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]
ZERO, AT, V0, V1, A0, A1, A2, A3 = range(8)
GP, SP, FP, RA = 28, 29, 30, 31
K0, K1 = 26, 27
CALLER_SAVED = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 24, 25}

SPECIAL = {0: "sll", 2: "srl", 3: "sra", 4: "sllv", 6: "srlv", 7: "srav", 8: "jr", 9: "jalr",
           12: "syscall", 13: "break", 16: "mfhi", 17: "mthi", 18: "mflo", 19: "mtlo",
           24: "mult", 25: "multu", 26: "div", 27: "divu", 32: "add", 33: "addu", 34: "sub",
           35: "subu", 36: "and", 37: "or", 38: "xor", 39: "nor", 42: "slt", 43: "sltu"}
REGIMM = {0: "bltz", 1: "bgez", 16: "bltzal", 17: "bgezal"}
PRIMARY = {2: "j", 3: "jal", 4: "beq", 5: "bne", 6: "blez", 7: "bgtz", 8: "addi", 9: "addiu",
           10: "slti", 11: "sltiu", 12: "andi", 13: "ori", 14: "xori", 15: "lui",
           32: "lb", 33: "lh", 34: "lwl", 35: "lw", 36: "lbu", 37: "lhu", 38: "lwr",
           40: "sb", 41: "sh", 42: "swl", 43: "sw", 46: "swr", 50: "lwc2", 58: "swc2"}
COP2_MOVE = {0: "mfc2", 2: "cfc2", 4: "mtc2", 6: "ctc2"}

LOADS = {"lb": 1, "lbu": 1, "lh": 2, "lhu": 2, "lw": 4, "lwl": 4, "lwr": 4}
STORES = {"sb": 1, "sh": 2, "sw": 4, "swl": 4, "swr": 4}
BRANCHES = {"beq", "bne", "blez", "bgtz", "bltz", "bgez", "bltzal", "bgezal"}
JUMPS = {"j", "jal", "jr", "jalr"}


@dataclass
class Op:
    name: str
    rs: int
    rt: int
    rd: int
    sa: int
    imm: int     # zero-extended 16-bit
    simm: int    # sign-extended 16-bit
    target: int  # j/jal 26-bit index
    word: int

    @property
    def is_branch(self):
        return self.name in BRANCHES

    @property
    def is_jump(self):
        return self.name in JUMPS

    @property
    def has_delay(self):
        return self.name in BRANCHES or self.name in JUMPS

    @property
    def is_call(self):
        return self.name in ("jal", "jalr", "bltzal", "bgezal")

    @property
    def is_load(self):
        return self.name in LOADS or self.name == "lwc2"

    @property
    def is_store(self):
        return self.name in STORES or self.name == "swc2"


def decode(word):
    op = word >> 26
    rs = (word >> 21) & 31
    rt = (word >> 16) & 31
    rd = (word >> 11) & 31
    sa = (word >> 6) & 31
    imm = word & 0xFFFF
    simm = imm - 0x10000 if imm & 0x8000 else imm
    target = word & 0x3FFFFFF
    if op == 0:
        name = SPECIAL.get(word & 63, "?")
    elif op == 1:
        name = REGIMM.get(rt, "?")
    elif op == 16:
        name = "cop0"
    elif op == 18:
        if word & (1 << 25):
            name = "cop2"
        else:
            name = COP2_MOVE.get(rs, "?")
    else:
        name = PRIMARY.get(op, "?")
    return Op(name, rs, rt, rd, sa, imm, simm, target, word)


def uses_defs(o):
    """GPRs read and written by one instruction (not counting call effects), plus hi/lo as 'hi'/'lo'."""
    n = o.name
    u, d = set(), set()
    if n in ("sll", "srl", "sra"):
        u, d = {o.rt}, {o.rd}
    elif n in ("sllv", "srlv", "srav", "add", "addu", "sub", "subu", "and", "or", "xor", "nor", "slt", "sltu"):
        u, d = {o.rs, o.rt}, {o.rd}
    elif n == "jr":
        u = {o.rs}
    elif n == "jalr":
        u, d = {o.rs}, {o.rd}
    elif n in ("mfhi", "mflo"):
        u, d = {n[2:]}, {o.rd}
    elif n in ("mthi", "mtlo"):
        u, d = {o.rs}, {n[2:]}
    elif n in ("mult", "multu", "div", "divu"):
        u, d = {o.rs, o.rt}, {"hi", "lo"}
    elif n in ("beq", "bne"):
        u = {o.rs, o.rt}
    elif n in ("blez", "bgtz", "bltz", "bgez"):
        u = {o.rs}
    elif n in ("bltzal", "bgezal"):
        u, d = {o.rs}, {RA}
    elif n == "jal":
        d = {RA}
    elif n in ("addi", "addiu", "slti", "sltiu", "andi", "ori", "xori"):
        u, d = {o.rs}, {o.rt}
    elif n == "lui":
        d = {o.rt}
    elif n in ("lwl", "lwr"):
        u, d = {o.rs, o.rt}, {o.rt}
    elif n in LOADS:
        u, d = {o.rs}, {o.rt}
    elif n in STORES:
        u = {o.rs, o.rt}
    elif n == "lwc2":
        u = {o.rs}
    elif n == "swc2":
        u = {o.rs}
    elif n in ("mfc2", "cfc2"):
        d = {o.rt}
    elif n in ("mtc2", "ctc2"):
        u = {o.rt}
    u.discard(ZERO)
    d.discard(ZERO)
    return u, d
