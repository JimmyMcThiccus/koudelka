"""Whole-program view of the game's asm and per-function analysis.

Program loads every function (the 666 still in asm, the original asm of the
decompiled ones under matchings/, and psyq.s) so call sites can be typed:
  - stack_args: how many incoming stack words (sp_entry + 0x10 ...) a function reads
  - ret_pair:   whether some caller reads $v1 after calling it (then it returns v0/v1 as a u64)
"""
import re
from dataclasses import dataclass, field
from pathlib import Path

from . import asmfile
from .mips import decode, uses_defs, LOADS, STORES, ZERO, V0, V1, A0, A1, A2, A3, GP, SP, RA, K0, K1, \
    CALLER_SAVED

ROOT = Path(__file__).resolve().parents[2]
TARGETS = ["main", "field", "battle", "movie", "capture", "gameend", "effect"]
ALLOCA_RESERVE = 0x4000
NORETURN = {"exit", "abort", "_exit"}
LOCAL_LABEL_RE = re.compile(r"^\.L([0-9A-Fa-f]{8})$")
ARG_REGS = {A0, A1, A2, A3}
# Hand-written routines that are not ordinary code (docs/PORT_FEASIBILITY.md §3/§4): they swap stacks or
# play $gp/$k0/$k1 games. They get an aborting stub. Detection below also catches them by register use.
FORCED_STUBS = {
    "func_80018F0C": "context switch (saves/restores the full register file incl. $sp/$gp/$k0/$k1)",
    "func_80018FA8": "context switch (saves/restores the full register file incl. $sp/$gp/$k0/$k1)",
    "func_800190A0": "context switch (saves/restores the full register file incl. $sp/$gp/$k0/$k1)",
    "SetSp": "swaps the stack pointer",
    "func_800949B0": "SetSp: swaps the stack pointer",
}


@dataclass
class Ins:
    idx: int
    vaddr: int
    op: object
    item: object
    reloc: tuple = None       # (kind, sym, addend)
    target: int = None        # local branch/jump target address
    tsym: str = None          # external call/jump target symbol


@dataclass
class FuncInfo:
    target: str
    name: str
    func: object                      # asmfile.Function
    nonmatching: bool = False
    insns: list = field(default_factory=list)
    problems: list = field(default_factory=list)   # reasons it can't be translated
    notes: list = field(default_factory=list)      # translated, but worth a look
    stack_args: int = 0
    ret_pair: bool = False
    varargs: bool = False
    frame_lo: int = 0       # bytes below sp_entry
    frame_hi: int = 0x10    # bytes at/above sp_entry the frame array must cover
    sp_at: dict = field(default_factory=dict)       # insn idx -> sp offset (after the insn), when known
    v1_live_after_call: dict = field(default_factory=dict)  # delay-slot idx -> bool
    jtables: dict = field(default_factory=dict)     # jr idx -> list of target addresses
    jtbl_syms: dict = field(default_factory=dict)   # jtbl name -> list of target addresses
    succ: list = None
    kind: dict = field(default_factory=dict)        # branch idx -> cond/goto/call/icall/ret/tail/itail/switch/condtail
    dynamic_sp: bool = False
    analyzed: bool = False


class Program:
    def __init__(self, root=ROOT, targets=TARGETS):
        self.root = Path(root)
        self.targets = targets
        self.funcs = {t: {} for t in targets}     # target -> name -> FuncInfo
        self.data = {t: {} for t in targets}      # target -> name -> DataBlock
        self.by_addr = {t: {} for t in targets}   # target -> vaddr -> name
        self.nonmatching = {t: [] for t in targets}
        self.indirect_stack_args = 4
        self.indirect_pair_sites = 0

    # ---------------------------------------------------------------- loading
    def load(self):
        for t in self.targets:
            base = self.root / "asm" / t
            for p in sorted(base.rglob("*.s")):
                af = asmfile.parse_file(p)
                nonm = "nonmatchings" in p.parts
                for f in af.functions:
                    old = self.funcs[t].get(f.name)
                    if old is not None and not (nonm and not old.nonmatching):
                        continue
                    self.funcs[t][f.name] = FuncInfo(t, f.name, f)
                    if f.items:
                        self.by_addr[t][f.items[0].vaddr] = f.name
                for d in af.data:
                    self.data[t].setdefault(d.name, d)
        # the functions that are still INCLUDE_ASM in src/
        inc_re = re.compile(r'INCLUDE_ASM\(\s*"([^"]+)"\s*,\s*([A-Za-z0-9_]+)\s*\)')
        for src in sorted((self.root / "src").rglob("*.c*")):
            for m in inc_re.finditer(src.read_text(encoding="utf-8", errors="replace")):
                folder, name = m.group(1), m.group(2)
                t = folder.split("/")[1]
                if t not in self.funcs:  # e.g. the BIM.AR modules (asm/bim), not a recompiler target
                    continue
                path = self.root / folder / (name + ".s")
                af = asmfile.parse_file(path)
                fn = next(f for f in af.functions if f.name == name)
                fi = FuncInfo(t, name, fn, nonmatching=True)
                self.funcs[t][name] = fi
                for d in af.data:
                    self.data[t].setdefault(d.name, d)
                self.nonmatching[t].append(name)

    def lookup(self, target, name):
        """FuncInfo for a callee as seen from `target` (own overlay first, then the EXE, then any overlay)."""
        fi = self.funcs.get(target, {}).get(name)
        if fi is None and target != "main":
            fi = self.funcs["main"].get(name)
        if fi is None:
            for t in self.targets:
                fi = self.funcs[t].get(name)
                if fi is not None:
                    break
        return fi

    def lookup_data(self, target, name):
        d = self.data.get(target, {}).get(name)
        if d is None:
            d = self.data["main"].get(name)
        return d

    def is_function(self, target, name):
        return self.lookup(target, name) is not None

    # ---------------------------------------------------------------- analysis
    def analyze_all(self):
        for t in self.targets:
            for fi in self.funcs[t].values():
                analyze_function(self, fi)
        # stack args for indirect calls: enough for every function reachable through a pointer
        mx = 0
        for t in self.targets:
            for fi in self.funcs[t].values():
                mx = max(mx, fi.stack_args)
        self.indirect_stack_args = min(max(mx, 4), 12)
        # ret_pair: iterate until stable (a function returning a callee's v1 makes that callee a pair)
        changed = True
        rounds = 0
        while changed and rounds < 20:
            changed = False
            rounds += 1
            for t in self.targets:
                for fi in self.funcs[t].values():
                    if fi.problems or not fi.insns:
                        continue
                    if rounds > 1 and not fi.ret_pair:
                        continue
                    liveness(self, fi)
                    need = [d - 1 for d, live in fi.v1_live_after_call.items() if live]
                    if fi.ret_pair:
                        # a tail call returns the callee's v0/v1 as this function's
                        need += [i for i, k in fi.kind.items() if k in ("tail", "condtail")]
                    for b in need:
                        call = fi.insns[b]
                        if call.tsym:
                            ce = self.lookup(t, call.tsym)
                            if ce is not None and not ce.ret_pair:
                                ce.ret_pair = True
                                changed = True
        # frames: make room for the outgoing stack words read at each call
        for t in self.targets:
            for fi in self.funcs[t].values():
                if fi.problems or not fi.insns:
                    continue
                size_frame_for_calls(self, fi)


def local_label_addr(name):
    m = LOCAL_LABEL_RE.match(name)
    return int(m.group(1), 16) if m else None


def analyze_function(prog, fi):
    if fi.analyzed:
        return
    fi.analyzed = True
    f = fi.func
    if fi.name in FORCED_STUBS:
        fi.problems.append(FORCED_STUBS[fi.name])
    if not f.items:
        fi.problems.append("empty function")
        return
    start = f.items[0].vaddr
    end = f.items[-1].vaddr + 4
    for i, it in enumerate(f.items):
        if it.mnem.startswith("."):
            fi.problems.append(f"not code: data directive {it.mnem} in text at 0x{it.vaddr:08X}")
            return
        op = decode(it.word)
        ins = Ins(i, it.vaddr, op, it, asmfile.parse_reloc(it.ops))
        if op.name == "?":
            fi.problems.append(f"unknown instruction word 0x{it.word:08X} at 0x{it.vaddr:08X}")
        if op.name in ("cop0", "syscall"):
            fi.problems.append(f"{op.name} at 0x{it.vaddr:08X}")
        if op.name in ("bltzal", "bgezal"):
            fi.problems.append(f"{op.name} (branch-and-link) at 0x{it.vaddr:08X}")
        if op.is_branch or op.name in ("j", "jal"):
            if op.is_branch:
                tgt = (it.vaddr + 4 + op.simm * 4) & 0xFFFFFFFF
            else:
                tgt = (it.vaddr & 0xF0000000) | (op.target << 2)
            txt = it.ops.split(",")[-1].strip()
            if op.name != "jal" and start <= tgt < end:
                ins.target = tgt
            else:
                if txt.startswith(".L") or txt.startswith("0x") or not txt:
                    name = prog.by_addr[fi.target].get(tgt) or prog.by_addr["main"].get(tgt)
                    if name is None:
                        for t in prog.targets:
                            name = prog.by_addr[t].get(tgt)
                            if name:
                                break
                    if name is None:
                        fi.problems.append(f"{op.name} to 0x{tgt:08X} outside the function and not a known function")
                    ins.tsym = name
                else:
                    ins.tsym = txt.split("+")[0].strip()
        fi.insns.append(ins)
    if fi.problems:
        return
    n = len(fi.insns)
    # register-use checks for the hand-written oddities
    for ins in fi.insns:
        u, d = uses_defs(ins.op)
        regs = (u | d) - {"hi", "lo"}
        if regs & {K0, K1}:
            fi.problems.append(f"uses $k0/$k1 at 0x{ins.vaddr:08X}")
            break
        gp_rel = ins.reloc is not None and ins.reloc[0] == "gp_rel"
        if GP in d or (GP in u and not gp_rel):
            fi.problems.append(f"reads or writes $gp outside %gp_rel at 0x{ins.vaddr:08X}")
            break
        if (RA in u and ins.op.name not in ("jr", "sw")) or (ins.op.name == "sw" and ins.op.rs == RA):
            fi.problems.append(f"uses $ra as data at 0x{ins.vaddr:08X}")
            break
    if fi.problems:
        return
    for i, ins in enumerate(fi.insns):
        if ins.op.has_delay:
            if i + 1 >= n:
                fi.problems.append(f"branch at 0x{ins.vaddr:08X} has no delay slot")
                return
            if fi.insns[i + 1].op.has_delay:
                fi.problems.append(f"branch in delay slot at 0x{fi.insns[i + 1].vaddr:08X}")
                return
    find_jump_tables(prog, fi)
    if fi.problems:
        return
    build_succ(fi)
    if fi.problems:
        return
    sp_dataflow(prog, fi)


def find_jump_tables(prog, fi):
    tables = {}
    for ins in fi.insns:
        if ins.reloc and ins.reloc[1].startswith("jtbl_"):
            name = ins.reloc[1]
            if name in tables:
                continue
            d = prog.lookup_data(fi.target, name)
            if d is None:
                fi.problems.append(f"jump table {name} not found")
                return
            addrs = []
            for it in d.items:
                a = local_label_addr(it.ops.strip()) if it.mnem == ".word" else None
                if a is None:
                    break
                addrs.append(a)
            if not addrs:
                fi.problems.append(f"jump table {name} has no label entries")
                return
            tables[name] = addrs
    fi.jtbl_syms = tables
    start = fi.insns[0].vaddr
    end = fi.insns[-1].vaddr + 4
    for name, addrs in tables.items():
        for a in addrs:
            if not (start <= a < end):
                fi.problems.append(f"jump table {name} entry 0x{a:08X} outside the function")
                return
    for i, ins in enumerate(fi.insns):
        if ins.op.name != "jr" or ins.op.rs == RA:
            continue
        # which table feeds this jr? look back for a %lo(jtbl_*) within the block
        found = None
        for j in range(i - 1, max(-1, i - 12), -1):
            p = fi.insns[j]
            if p.reloc and p.reloc[1] in tables:
                found = p.reloc[1]
                break
            if p.op.has_delay:
                break
        if found:
            fi.jtables[i] = list(tables[found])
        elif tables and len(tables) == 1:
            fi.jtables[i] = list(next(iter(tables.values())))
            fi.notes.append(f"jr at 0x{ins.vaddr:08X} assumed to use {next(iter(tables))}")
        # else: indirect tail call


def build_succ(fi):
    """Instruction-level successors. A branch's successor is its delay slot; the delay slot carries the
    branch's control transfer."""
    n = len(fi.insns)
    addr_idx = {ins.vaddr: ins.idx for ins in fi.insns}
    succ = [[] for _ in range(n)]
    fi.kind = {}
    for i, ins in enumerate(fi.insns):
        o = ins.op
        if i > 0 and fi.insns[i - 1].op.has_delay:
            b = fi.insns[i - 1]
            k = branch_kind(fi, b)
            fi.kind[i - 1] = k
            if k == "cond":
                succ[i] = [i + 1, addr_idx[b.target]] if i + 1 < n else [addr_idx[b.target]]
            elif k == "goto":
                succ[i] = [addr_idx[b.target]]
            elif k == "call" and b.tsym in NORETURN:
                succ[i] = []
            elif k in ("call", "icall"):
                succ[i] = [i + 1] if i + 1 < n else []
            elif k == "switch":
                succ[i] = sorted({addr_idx[a] for a in fi.jtables[i - 1]})
            elif k == "condtail":
                succ[i] = [i + 1] if i + 1 < n else []
            else:  # ret, tail, itail
                succ[i] = []
            continue
        if o.has_delay:
            succ[i] = [i + 1]
        else:
            succ[i] = [i + 1] if i + 1 < n else []
    for i, ins in enumerate(fi.insns):
        for s in succ[i]:
            if s >= n:
                fi.problems.append("falls off the end of the function")
                return
        if ins.target is not None and ins.target not in addr_idx:
            fi.problems.append(f"branch target 0x{ins.target:08X} is not an instruction")
            return
        if ins.target is not None and addr_idx[ins.target] > 0 and fi.insns[addr_idx[ins.target] - 1].op.has_delay:
            fi.problems.append(f"branch into a delay slot at 0x{ins.target:08X}")
            return
    fi.succ = succ


def branch_kind(fi, b):
    o = b.op
    if o.name in ("jal",):
        return "call"
    if o.name == "jalr":
        return "icall"
    if o.name == "jr":
        if o.rs == RA:
            return "ret"
        if b.idx in fi.jtables:
            return "switch"
        return "itail"
    if o.name == "j":
        return "goto" if b.target is not None else "tail"
    # conditional branches (beq $zero,$zero is an unconditional `b`)
    uncond = (o.name == "beq" and o.rs == 0 and o.rt == 0) or (o.name == "bgez" and o.rs == 0)
    if b.target is None:
        return "condtail" if not uncond else "tail"
    return "goto" if uncond else "cond"


def mem_size(op):
    if op.name in LOADS:
        return LOADS[op.name]
    if op.name in STORES:
        return STORES[op.name]
    return 4


def sp_dataflow(prog, fi):
    """Forward dataflow of registers that hold sp_entry + constant."""
    n = len(fi.insns)
    state_in = [None] * n
    state_in[0] = {SP: 0}
    work = [0]
    out_states = [None] * n
    while work:
        i = work.pop()
        st = dict(state_in[i])
        st = sp_transfer(fi, i, st)
        out_states[i] = st
        for s in fi.succ[i]:
            old = state_in[s]
            if old is None:
                new = dict(st)
            else:
                new = {r: v for r, v in old.items() if st.get(r) == v}
            if new != old:
                state_in[s] = new
                work.append(s)
    lo = 0
    hi = 0x10
    stack_args = 0
    for i, ins in enumerate(fi.insns):
        st = state_in[i]
        if st is None:
            continue  # unreachable
        o = ins.op
        if SP not in st:
            fi.dynamic_sp = True    # alloca: $sp moved by a run-time amount
        else:
            fi.sp_at[i] = st[SP]
            lo = max(lo, -st[SP])
        if (o.is_load or o.is_store) and o.rs in st and ins.reloc is None:
            a = st[o.rs] + o.simm
            sz = mem_size(o)
            if a < -lo:
                lo = -a
            if a + sz > hi:
                hi = a + sz
            if o.is_load and a >= 0x10:
                stack_args = max(stack_args, (a + sz - 0x10 + 3) // 4)
        if o.name in ("addiu", "addi") and o.rs in st and o.rt not in (SP, ZERO):
            a = st[o.rs] + o.simm
            if a >= 0:
                fi.varargs = True
        out = out_states[i]
        if out is not None and SP not in out:
            fi.dynamic_sp = True
    if fi.dynamic_sp:
        lo += ALLOCA_RESERVE
        fi.notes.append(f"moves $sp by a run-time amount (alloca); frame has 0x{ALLOCA_RESERVE:X} spare bytes, checked at run time")
    fi.frame_lo = (lo + 7) & ~7
    fi.stack_args = stack_args
    fi.frame_hi = max(hi, 0x10 + 4 * stack_args)
    if fi.varargs:
        fi.notes.append("takes the address of its incoming argument area; a0-a3 are copied to the home slots")


def sp_transfer(fi, i, st):
    ins = fi.insns[i]
    o = ins.op
    u, d = uses_defs(o)
    new = None
    if o.name in ("addiu", "addi") and o.rs in st and ins.reloc is None:
        new = (o.rt, st[o.rs] + o.simm)
    elif o.name in ("addu", "or", "add") and (o.rs in st and o.rt == ZERO):
        new = (o.rd, st[o.rs])
    elif o.name in ("addu", "or", "add") and (o.rt in st and o.rs == ZERO):
        new = (o.rd, st[o.rt])
    for r in d:
        st.pop(r, None)
    if new is not None and new[0] != ZERO:
        st[new[0]] = new[1]
    # call made from this delay slot: caller-saved registers are dead afterwards
    if i > 0 and fi.insns[i - 1].op.has_delay and fi.kind.get(i - 1) in ("call", "icall"):
        for r in list(st):
            if r in CALLER_SAVED:
                del st[r]
    return st


def liveness(prog, fi):
    """Backward liveness; records whether $v1 is live right after each call."""
    n = len(fi.insns)
    preds = [[] for _ in range(n)]
    for i in range(n):
        for s in fi.succ[i]:
            preds[s].append(i)
    # an lwl/lwr pair loading one register overwrites all of it: the first half does not read it
    full_pair = set()
    for i in range(n - 1):
        a, b = fi.insns[i].op, fi.insns[i + 1].op
        if {a.name, b.name} == {"lwl", "lwr"} and a.rt == b.rt and a.rs == b.rs and a.rt != a.rs                 and abs(a.simm - b.simm) == 3:
            full_pair.add(i)
    live_in = [set() for _ in range(n)]
    live_after_call = {}
    work = list(range(n))
    in_work = set(work)
    while work:
        i = work.pop()
        in_work.discard(i)
        out = set()
        for s in fi.succ[i]:
            out |= live_in[s]
        ins = fi.insns[i]
        u, d = uses_defs(ins.op)
        if i in full_pair:
            u = u - {ins.op.rt}
        # control transfer carried by this delay slot
        k = None
        if i > 0 and fi.insns[i - 1].op.has_delay:
            k = fi.kind.get(i - 1)
        cur = set(out)
        if k in ("call", "icall"):
            live_after_call[i] = V1 in cur
            cur -= {V0, V1}
            cur |= {A0, A1, A2, A3, SP}
        elif k == "ret":
            cur = {V0, SP} | ({V1} if fi.ret_pair else set())
        elif k in ("tail", "itail"):
            cur = {A0, A1, A2, A3, SP}
            if k == "itail":
                cur.add(fi.insns[i - 1].op.rs)
        elif k == "condtail":
            cur |= {A0, A1, A2, A3, SP}
        new = (cur - d) | u
        if new != live_in[i]:
            live_in[i] = new
            for p in preds[i]:
                if p not in in_work:
                    work.append(p)
                    in_work.add(p)
    fi.v1_live_after_call = live_after_call


def size_frame_for_calls(prog, fi):
    for i, ins in enumerate(fi.insns):
        if not ins.op.has_delay:
            continue
        k = fi.kind.get(i)
        if k not in ("call", "icall", "tail", "itail", "condtail"):
            continue
        n = callee_stack_args(prog, fi, ins)
        if n == 0:
            continue
        sp = fi.sp_at.get(i + 1)
        if sp is None:
            continue
        need = sp + 0x10 + 4 * n
        if need > fi.frame_hi:
            fi.frame_hi = need


def callee_stack_args(prog, fi, ins):
    k = fi.kind.get(ins.idx)
    if k in ("icall", "itail"):
        return prog.indirect_stack_args
    ce = prog.lookup(fi.target, ins.tsym) if ins.tsym else None
    return ce.stack_args if ce is not None else 0
