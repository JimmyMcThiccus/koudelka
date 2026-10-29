"""C emission for one analyzed function (see docs/RECOMP.md for the model)."""
from .analyze import LOCAL_LABEL_RE
from .mips import REG_NAMES, uses_defs, ZERO, SP, V0, V1, A0, A1, A2, A3


def reg(r):
    return "0" if r == ZERO else REG_NAMES[r]


def hexc(v):
    return f"0x{v:X}" if v >= 0 else f"-0x{-v:X}"


class Protos:
    """Prototype table: how a call to a symbol is typed. Defaults come from the program analysis;
    entries in an override table (JSON, e.g. generated from include/shared/exe.h) win."""

    def __init__(self, prog, overrides=None):
        self.prog = prog
        self.over = overrides or {}

    def get(self, target, name):
        o = self.over.get(name)
        fi = self.prog.lookup(target, name)
        stack = fi.stack_args if fi is not None else 0
        pair = fi.ret_pair if fi is not None else False
        varargs = False
        if o:
            stack = o.get("stack_args", stack)
            pair = o.get("ret", "pair" if pair else "u32") == "pair"
            varargs = o.get("varargs", False)
        return stack, pair, varargs

    def decl(self, target, name, def_name=None):
        stack, pair, varargs = self.get(target, name)
        params = ["u32"] * (4 + stack)
        if varargs:
            params.append("...")
        return f"{'u64' if pair else 'u32'} {def_name or name}({', '.join(params)})"


class Emitter:
    def __init__(self, prog, protos, fi, prefix="", rodata_static=False):
        self.prog = prog
        self.protos = protos
        self.fi = fi
        self.prefix = prefix
        self.rodata_static = rodata_static
        self.ext_funcs = set()
        self.ext_data = set()
        self.local_data = {}   # name -> C definition
        self.lines = []
        self.uses_bc = False
        self.uses_jt = False
        self.raw_addrs = []
        self.hw_addrs = []

    # ------------------------------------------------------------ symbols
    def sym_addr(self, sym, addend=0):
        """C expression for the host address of sym+addend."""
        if sym in self.fi.jtbl_syms or sym in self.local_data or sym in self.local_names:
            pass
        elif self.prog.is_function(self.fi.target, sym):
            if sym != self.fi.name:
                self.ext_funcs.add(sym)
        else:
            self.ext_data.add(sym)
        name = sym
        if sym == self.fi.name and self.prefix:
            name = self.prefix + sym
        e = f"(u32)&{name}"
        if addend:
            e = f"({e} + {hexc(addend)})"
        return e

    # ------------------------------------------------------------ helpers
    def addr(self, ins):
        o = ins.op
        if ins.reloc:
            kind, sym, add = ins.reloc
            if kind == "gp_rel":
                return self.sym_addr(sym, add), False
            if kind == "lo":
                return f"{reg(o.rs)} + RECOMP_LO({self.sym_addr(sym, add)})", False
            raise ValueError(f"unexpected {kind} reloc on memory access")
        base = reg(o.rs)
        stack = o.rs == SP
        if o.simm == 0:
            return base, stack
        return f"{base} + {hexc(o.simm)}", stack

    def mem(self, kind, ins):
        a, stack = self.addr(ins)
        if not stack and self.scratch_io(ins):
            a = f"RECOMP_HW(FN, {a})"
        return f"{'STK' if stack else 'MEM'}_{kind}({a})"

    def scratch_io(self, ins, offset=None):
        """True when `offset` (default: the instruction's immediate) is >= 0x400 from a register last set by
        `lui 0x1F80` in the same block: that is the PS1 I/O area (0x1F801000...), not the 1 KB scratchpad."""
        o = ins.op
        off = o.simm if offset is None else offset
        if ins.reloc or off < 0x400:
            return False
        for j in range(ins.idx - 1, max(-1, ins.idx - 16), -1):
            p = self.fi.insns[j]
            u, d = uses_defs(p.op)
            if o.rs in d:
                return p.op.name == "lui" and p.op.imm == 0x1F80 and not p.reloc
            if p.op.has_delay:
                return False
        return False

    # ------------------------------------------------------------ one instruction
    def insn(self, ins):
        o = ins.op
        n = o.name
        rs, rt, rd = reg(o.rs), reg(o.rt), reg(o.rd)
        if o.word == 0:
            return ""
        if n in ("sll", "srl", "sra", "sllv", "srlv", "srav", "add", "addu", "sub", "subu", "and", "or", "xor",
                 "nor", "slt", "sltu", "mfhi", "mflo") and o.rd == ZERO:
            return ""
        if n in ("addi", "addiu", "slti", "sltiu", "andi", "ori", "xori", "lui", "mfc2", "cfc2") and o.rt == ZERO:
            return ""
        if n == "sll":
            return f"{rd} = {rt} << {o.sa};"
        if n == "srl":
            return f"{rd} = {rt} >> {o.sa};"
        if n == "sra":
            return f"{rd} = (u32)((s32){rt} >> {o.sa});"
        if n == "sllv":
            return f"{rd} = {rt} << ({rs} & 31);"
        if n == "srlv":
            return f"{rd} = {rt} >> ({rs} & 31);"
        if n == "srav":
            return f"{rd} = (u32)((s32){rt} >> ({rs} & 31));"
        if n == "mfhi":
            return f"{rd} = hi;"
        if n == "mflo":
            return f"{rd} = lo;"
        if n == "mthi":
            return f"hi = {rs};"
        if n == "mtlo":
            return f"lo = {rs};"
        if n == "mult":
            return f"RECOMP_MULT(hi, lo, {rs}, {rt});"
        if n == "multu":
            return f"RECOMP_MULTU(hi, lo, {rs}, {rt});"
        if n == "div":
            return f"RECOMP_DIV(hi, lo, {rs}, {rt});"
        if n == "divu":
            return f"RECOMP_DIVU(hi, lo, {rs}, {rt});"
        if n in ("add", "addu"):
            if o.rt == ZERO:
                return f"{rd} = {rs};"
            if o.rs == ZERO:
                return f"{rd} = {rt};"
            return f"{rd} = {rs} + {rt};"
        if n in ("sub", "subu"):
            if o.rs == ZERO:
                return f"{rd} = -{rt};"
            return f"{rd} = {rs} - {rt};"
        if n == "and":
            return f"{rd} = {rs} & {rt};"
        if n == "or":
            if o.rt == ZERO:
                return f"{rd} = {rs};"
            return f"{rd} = {rs} | {rt};"
        if n == "xor":
            return f"{rd} = {rs} ^ {rt};"
        if n == "nor":
            return f"{rd} = ~({rs} | {rt});"
        if n == "slt":
            return f"{rd} = (s32){rs} < (s32){rt};"
        if n == "sltu":
            return f"{rd} = {rs} < {rt};"
        if n in ("addi", "addiu"):
            if ins.reloc:
                kind, sym, add = ins.reloc
                if kind == "lo":
                    return f"{rt} = {rs} + RECOMP_LO({self.sym_addr(sym, add)});"
                if kind == "gp_rel":
                    return f"{rt} = {self.sym_addr(sym, add)};"
                raise ValueError(f"%{kind} on addiu")
            if o.rs == ZERO:
                return f"{rt} = {hexc(o.simm)};" if o.simm >= 0 else f"{rt} = (u32){o.simm};"
            if o.simm == 0:
                return f"{rt} = {rs};"
            if self.scratch_io(ins):
                self.hw_addrs.append(ins.vaddr)
                return f"{rt} = RECOMP_HW(FN, 0x{0x1F800000 + o.simm:08X}u);"
            return f"{rt} = {rs} + {hexc(o.simm)};" if o.simm > 0 else f"{rt} = {rs} - {hexc(-o.simm)};"
        if n == "slti":
            return f"{rt} = (s32){rs} < {o.simm};"
        if n == "sltiu":
            return f"{rt} = {rs} < 0x{o.simm & 0xFFFFFFFF:X}u;"
        if n in ("andi", "ori", "xori"):
            if ins.reloc:
                raise ValueError(f"%{ins.reloc[0]} on {n}")
            sym = {"andi": "&", "ori": "|", "xori": "^"}[n]
            if o.rs == ZERO:
                return f"{rt} = {'0' if n == 'andi' else hexc(o.imm)};"
            if n == "ori" and self.scratch_io(ins, o.imm):
                self.hw_addrs.append(ins.vaddr)
                return f"{rt} = RECOMP_HW(FN, 0x{0x1F800000 | o.imm:08X}u);"
            return f"{rt} = {rs} {sym} {hexc(o.imm)};"
        if n == "lui":
            if ins.reloc:
                kind, sym, add = ins.reloc
                if kind != "hi":
                    raise ValueError(f"%{kind} on lui")
                return f"{rt} = RECOMP_HI({self.sym_addr(sym, add)});"
            v = o.imm << 16
            if o.imm == 0x1F80:
                return f"{rt} = RECOMP_SCRATCHPAD_BASE; /* 0x1F800000 */"
            if 0x8001 <= o.imm <= 0x801F or 0xA000 <= o.imm <= 0xA01F:
                # inside PS1 RAM (0x80000000 itself is almost always the sign-bit constant)
                self.raw_addrs.append(ins.vaddr)
                return f"{rt} = 0x{v:08X}u; /* raw PS1 address? */"
            return f"{rt} = 0x{v:X};"
        if n == "lb":
            return f"{rt} = (u32)(s32){self.mem('S8', ins)};" if o.rt else ""
        if n == "lbu":
            return f"{rt} = {self.mem('U8', ins)};" if o.rt else ""
        if n == "lh":
            return f"{rt} = (u32)(s32){self.mem('S16', ins)};" if o.rt else ""
        if n == "lhu":
            return f"{rt} = {self.mem('U16', ins)};" if o.rt else ""
        if n == "lw":
            return f"{rt} = {self.mem('U32', ins)};" if o.rt else ""
        if n == "sb":
            return f"{self.mem('U8', ins)} = (u8){rt};"
        if n == "sh":
            return f"{self.mem('U16', ins)} = (u16){rt};"
        if n == "sw":
            return f"{self.mem('U32', ins)} = {rt};"
        if n in ("lwl", "lwr"):
            a, _ = self.addr(ins)
            return f"{rt} = recomp_{n}({rt}, {a});" if o.rt else ""
        if n in ("swl", "swr"):
            a, _ = self.addr(ins)
            return f"recomp_{n}({a}, {rt});"
        if n == "lwc2":
            a, _ = self.addr(ins)
            return f"GTE_LWC2({o.rt}, {a});"
        if n == "swc2":
            a, _ = self.addr(ins)
            return f"GTE_SWC2({o.rt}, {a});"
        if n == "mfc2":
            return f"{rt} = GTE_MFC2({o.rd});"
        if n == "cfc2":
            return f"{rt} = GTE_CFC2({o.rd});"
        if n == "mtc2":
            return f"GTE_MTC2({rt}, {o.rd});"
        if n == "ctc2":
            return f"GTE_CTC2({rt}, {o.rd});"
        if n == "cop2":
            return f"GTE_COP2(0x{o.word & 0x1FFFFFF:07X});"
        if n == "break":
            return f"RECOMP_BREAK(FN, {(o.word >> 16) & 0x3FF}, 0x{ins.vaddr:08X});"
        raise ValueError(f"cannot translate {n} at 0x{ins.vaddr:08X}")

    # ------------------------------------------------------------ control flow
    def cond(self, b):
        o = b.op
        rs, rt = reg(o.rs), reg(o.rt)
        n = o.name
        if n == "beq":
            return f"{rs} == {rt}"
        if n == "bne":
            return f"{rs} != {rt}"
        if n == "blez":
            return f"(s32){rs} <= 0"
        if n == "bgtz":
            return f"(s32){rs} > 0"
        if n == "bltz":
            return f"(s32){rs} < 0"
        if n == "bgez":
            return f"(s32){rs} >= 0"
        raise ValueError(n)

    def call_args(self, nstack):
        args = ["a0", "a1", "a2", "a3"]
        for k in range(nstack):
            args.append(f"STK_U32(sp + 0x{0x10 + 4 * k:X})")
        if nstack:
            self.needs_sp = True
        return ", ".join(args)

    def call(self, b, kind):
        if kind in ("icall", "itail"):
            nstack = self.prog.indirect_stack_args
            d = b.idx + 1
            pair = self.fi.v1_live_after_call.get(d, False) or (kind == "itail" and self.fi.ret_pair)
            args = self.call_args(nstack)
            if pair:
                self.writes_v1 = True
                return f"{{ u64 r_ = RECOMP_ICALL2(jt)({args}); v0 = (u32)r_; v1 = (u32)(r_ >> 32); }}"
            return f"v0 = RECOMP_ICALL(jt)({args});"
        name = b.tsym
        stack, pair, varargs = self.protos.get(self.fi.target, name)
        if name != self.fi.name:
            self.ext_funcs.add(name)
        cname = self.prefix + name if name == self.fi.name else name
        args = self.call_args(stack)
        if pair:
            self.writes_v1 = True
            return f"{{ u64 r_ = {cname}({args}); v0 = (u32)r_; v1 = (u32)(r_ >> 32); }}"
        return f"v0 = {cname}({args});"

    def ret(self):
        return "return RECOMP_PAIR(v0, v1);" if self.fi.ret_pair else "return v0;"

    def control(self, b, delay_c):
        k = self.fi.kind[b.idx]
        out = []
        if k == "cond":
            self.uses_bc = True
            out.append(f"bc = {self.cond(b)};")
            out += delay_c
            out.append(f"if (bc) goto L_{b.target:08X};")
        elif k == "goto":
            out += delay_c
            out.append(f"goto L_{b.target:08X};")
        elif k == "call":
            out += delay_c
            out.append(self.call(b, k))
        elif k == "icall":
            self.uses_jt = True
            out.append(f"jt = {reg(b.op.rs)};")
            out += delay_c
            out.append(self.call(b, k))
        elif k == "ret":
            out += delay_c
            out.append(self.ret())
        elif k == "tail":
            out += delay_c
            out.append(self.call(b, k))
            out.append(self.ret())
        elif k == "condtail":
            self.uses_bc = True
            out.append(f"bc = {self.cond(b)};")
            out += delay_c
            out.append(f"if (bc) {{ {self.call(b, k)} {self.ret()} }}")
        elif k == "itail":
            self.uses_jt = True
            out.append(f"jt = {reg(b.op.rs)};")
            out += delay_c
            out.append(self.call(b, k))
            out.append(self.ret())
        elif k == "switch":
            self.uses_jt = True
            out.append(f"jt = {reg(b.op.rs)};")
            out += delay_c
            cases = " ".join(f"case {self.jt_id[a]}: goto L_{a:08X};" for a in sorted(set(self.fi.jtables[b.idx])))
            out.append(f"switch (jt) {{ {cases} default: RECOMP_BAD_JUMP(FN, 0x{b.vaddr:08X}, jt); }}")
        else:
            raise ValueError(k)
        return out

    # ------------------------------------------------------------ rodata in the function's .s
    def collect_local_data(self):
        """Data blocks defined in the function's own .s (jump tables, strings, constants)."""
        from . import asmfile
        af = asmfile.parse_file(self.fi.func.path)
        self.local_names = set()
        for d in af.data:
            self.local_names.add(d.name)
        self.local_blocks = [d for d in af.data if d.name not in self.fi.jtbl_syms]

    def emit_local_data(self):
        out = []
        storage = "static " if self.rodata_static else "RECOMP_RODATA "
        for d in self.local_blocks:
            words = []
            all_words = all(it.mnem == ".word" for it in d.items)
            has_sym = any(it.mnem == ".word" and not it.ops.startswith("0x") for it in d.items)
            if has_sym and not all_words:
                raise ValueError(f"rodata {d.name} mixes symbol words with other data")
            if all_words:
                for it in d.items:
                    v = it.ops.strip()
                    if v.startswith("0x") or v.lstrip("-").isdigit():
                        words.append(f"0x{int(v, 0) & 0xFFFFFFFF:08X}")
                    else:
                        if LOCAL_LABEL_RE.match(v):
                            raise ValueError(f"rodata {d.name} holds a code label {v}")
                        sym, _, add = v.partition("+")
                        words.append(self.sym_addr(sym.strip(), int(add, 0) if add.strip() else 0))
                out.append(f"{storage}RECOMP_ALIGN(8) const u32 {d.name}[{len(words)}] = {{ {', '.join(words)} }};")
            else:
                bs = data_bytes(d)
                body = ", ".join(f"0x{b:02X}" for b in bs)
                out.append(f"{storage}RECOMP_ALIGN(8) const u8 {d.name}[{len(bs)}] = {{ {body} }};")
        return out

    # ------------------------------------------------------------ whole function
    def emit(self):
        fi = self.fi
        self.collect_local_data()
        self.needs_sp = False
        self.writes_v1 = False
        # jump table ids
        all_t = sorted({a for addrs in fi.jtbl_syms.values() for a in addrs})
        self.jt_id = {a: k for k, a in enumerate(all_t)}
        labels = set()
        for ins in fi.insns:
            if ins.target is not None:
                labels.add(ins.target)
        labels |= set(all_t)
        body = []
        n = len(fi.insns)
        i = 0
        while i < n:
            ins = fi.insns[i]
            if ins.vaddr in labels:
                body.append(f"L_{ins.vaddr:08X}:;")
            if ins.op.has_delay:
                d = fi.insns[i + 1]
                dc = self.insn(d)
                stmts = self.control(ins, [dc] if dc else [])
                body.append("    " + " ".join(stmts) + f"  /* {ins.vaddr:08X} {fmt_asm(ins)} ; {fmt_asm(d)} */")
                i += 2
                continue
            c = self.insn(ins)
            if c and fi.dynamic_sp and SP in uses_defs(ins.op)[1]:
                c += " if (sp < (u32)frame) recomp_stack_overflow(FN);"
            if c:
                body.append(f"    {c}  /* {fmt_asm(ins)} */")
            i += 1
        # registers
        used = set()
        for ins in fi.insns:
            u, d = uses_defs(ins.op)
            used |= u | d
        if any(fi.kind.get(i) in ("call", "icall", "tail", "itail", "condtail") for i in fi.kind):
            used |= {V0, A0, A1, A2, A3}
        if fi.ret_pair or self.writes_v1:
            used |= {V1}
        used.add(V0)
        uses_sp = SP in used or self.needs_sp
        regs = [r for r in range(1, 32) if r in used and r not in (A0, A1, A2, A3, SP)]
        decls = [f"u32 {', '.join(REG_NAMES[r] + ' = 0' for r in regs)};"] if regs else []
        if "hi" in used or "lo" in used:
            decls.append("u32 hi = 0, lo = 0;")
        if self.uses_bc:
            decls.append("u32 bc;")
        if self.uses_jt:
            decls.append("u32 jt;")
        stack_params = [f"u32 stk_{0x10 + 4 * k:X}" for k in range(fi.stack_args)]
        params = ["u32 a0", "u32 a1", "u32 a2", "u32 a3"] + stack_params
        prologue = []
        if uses_sp:
            size = fi.frame_lo + fi.frame_hi
            size = (size + 7) & ~7
            decls.append(f"RECOMP_ALIGN(8) u8 frame[0x{size:X}] = {{ 0 }};")
            decls.append(f"u32 sp = (u32)frame + 0x{fi.frame_lo:X};")
            if fi.varargs:
                for k, r in enumerate(("a0", "a1", "a2", "a3")):
                    prologue.append(f"STK_U32(sp + 0x{4 * k:X}) = {r};")
            for k in range(fi.stack_args):
                prologue.append(f"STK_U32(sp + 0x{0x10 + 4 * k:X}) = stk_{0x10 + 4 * k:X};")
        ret_t = "u64" if fi.ret_pair else "u32"
        out = []
        out.append(f"/* {fi.name} ({fi.target}), recompiled from {rel(fi.func.path)} */")
        out.append('#include "recomp.h"')
        out.append(f'#define FN "{fi.name}"')
        out.append("")
        local_defs = self.emit_local_data()
        # jump tables: values are switch ids, not addresses
        jt_defs = []
        for name, addrs in fi.jtbl_syms.items():
            ids = ", ".join(str(self.jt_id[a]) for a in addrs)
            jt_defs.append(f"static RECOMP_ALIGN(8) const u32 {name}[{len(addrs)}] = {{ {ids} }};")
        ext = []
        for s in sorted(self.ext_funcs):
            ext.append(f"RECOMP_EXTERN_C {self.protos.decl(fi.target, s)};")
        for s in sorted(self.ext_data - self.local_names):
            ext.append(f"RECOMP_EXTERN_DATA u8 {s}[];")
        out += ext
        out += jt_defs
        out += local_defs
        out.append("")
        out.append(f"RECOMP_FUNC {ret_t} {self.prefix}{fi.name}({', '.join(params)}) {{")
        for d in decls:
            out.append("    " + d)
        for p in prologue:
            out.append("    " + p)
        out += body
        out.append("    " + self.ret())
        out.append("}")
        if self.raw_addrs:
            fi.notes.append("raw PS1 address constants at " + ", ".join(f"0x{a:08X}" for a in self.raw_addrs))
        if self.hw_addrs:
            fi.notes.append("PS1 I/O addresses (0x1F801000+; trap at run time) at " +
                            ", ".join(f"0x{a:08X}" for a in self.hw_addrs))
        return "\n".join(out) + "\n"


def emit_stub(fi, protos, prefix=""):
    why = "; ".join(fi.problems).replace("\\", "\\\\").replace('"', '\\"')
    ret_t = "u64" if fi.ret_pair else "u32"
    return (f"/* {fi.name} ({fi.target}): not translated: {why} */\n"
            f'#include "recomp.h"\n\n'
            f"RECOMP_FUNC {ret_t} {prefix}{fi.name}(u32 a0, u32 a1, u32 a2, u32 a3) {{\n"
            f'    RECOMP_UNSUPPORTED("{fi.name}", "{why}");\n'
            f"}}\n")


def fmt_asm(ins):
    t = f"{ins.item.mnem} {ins.item.ops}".strip()
    return t.replace("*/", "* /")


def rel(p):
    from .analyze import ROOT
    try:
        return p.resolve().relative_to(ROOT).as_posix()
    except ValueError:
        return p.as_posix()


def data_bytes(d):
    out = bytearray()
    for it in d.items:
        m = it.mnem
        if m == ".word":
            out += (int(it.ops, 0) & 0xFFFFFFFF).to_bytes(4, "little")
        elif m == ".short":
            out += (int(it.ops, 0) & 0xFFFF).to_bytes(2, "little")
        elif m == ".byte":
            out += bytes([int(it.ops, 0) & 0xFF])
        elif m == ".space":
            out += bytes(int(it.ops, 0))
        elif m in (".asciz", ".ascii"):
            if it.raw_hex:
                out += bytes.fromhex(it.raw_hex)
            else:
                s = it.ops.strip()
                assert s.startswith('"') and s.endswith('"'), s
                b = s[1:-1].encode("latin-1").decode("unicode_escape").encode("latin-1")
                out += b + (b"\0" if m == ".asciz" else b"")
        else:
            raise ValueError(f"data directive {m}")
    return bytes(out)
