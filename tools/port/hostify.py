"""Write the host view of the EXE sources for the PC port (docs/PORT_PHASE2.md section 2).

    .venv/Scripts/python.exe tools/port/hostify.py [--out build/port] [--no-implicit]

  include/**          -> build/port/hinc/**   (second on the host include path, after port/include)
  src/main/*.cpp      -> build/port/hsrc/main/*.cpp
  aliases found       -> build/port/aliases.txt  ("A B" per line: GCC 2.8 .set aliases, for the stub step)

The PS1 sources are not changed. Rewrites, all mechanical:
  - asm("name") symbol renames get the i686 COFF decoration: asm("_name"). On a member function they also get
    __attribute__((cdecl)), so `this` is passed on the stack like the recompiled callee's a0.
  - register ... asm("$N") pins lose the asm.
  - top-level __asm__(".set A, B") aliases are removed (collected into aliases.txt).
  - #define macros whose body is MIPS inline asm (GTE) are removed; port/include/port_gte.h defines them.
  - Every one-line EXTERN_C function declaration becomes permissive: pointer and integer parameters become
    port_parg<T>/port_iarg<T>, a void * return port_pret (port/include/port_args.h). GCC 2.8 accepted the
    loose conversions these allow; the types keep their size and calling convention.
  - src: every EXTERN_C definition `T f(P) {` becomes `T port_def_f(P) asm("_f"); T port_def_f(P) {`, so it
    still defines the C symbol _f while all calls (in the unit too) go through f's permissive declaration,
    which is inserted before f's first use (GCC 2.8 also allowed calls before any declaration).
  - src: GCC named return values (`T f(P) return r { ... }`) become a local r and `return r;`.
  - src: functions called with no declaration at all (GCC 2.8 implicit declarations) get
    `EXTERN_C port_pret f(...);` after #include "common.h". They are found by a clang -fsyntax-only pass
    (skip it with --no-implicit).
"""
import argparse
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from tools.recomp import hostcc  # noqa: E402

# Flags for the game's C++ on the host (docs/RECOMP.md "Toolchain", plus GCC 2.8's &Type(args)).
GAME_FLAGS = ["-x", "c++", "-w", "-Wno-error=address-of-temporary", "-Dmain=game_main", "-fno-finite-loops",
              "-fno-exceptions", "-fno-rtti"]
# Game names that clash with the host C runtime. The game defines its own no-op printf (u_8001986C.cpp); the
# UCRT's is an inline definition in every object that uses it. The recompiled code gets -Dprintf=game_printf.
RENAMES = {"printf": "game_printf"}
PORT_INCLUDE = ROOT / "port" / "include"

LABEL_RE = re.compile(r'\b(asm|__asm__)\s*\(\s*"([A-Za-z_.][\w.$]*)"\s*\)')
PIN_RE = re.compile(r'\s*\b(asm|__asm__)\s*\(\s*"\$\w+"\s*\)')
SET_RE = re.compile(r'__asm__\s*\(((?:\s*"[^"]*")+)\s*\)\s*;', re.S)
ASM_MACRO_RE = re.compile(r'^#define\s+(\w+)\s*\([^)]*\)\s*__asm__\s+volatile\s*\(.*$', re.M)

INT_WORDS = {"int", "unsigned", "signed", "short", "long", "char", "u_char", "u_short", "u_int", "u_long",
             "uint", "ushort", "uchar", "s8", "u8", "s16", "u16", "s32", "u32"}


def renames(text):
    for a, b in RENAMES.items():
        text = re.sub(r"\b%s\b" % a, b, text)
    return text


def member_declarator(line):
    """For text ending in a member function declarator `head(params) [const]`: (head, params), else None."""
    s = re.sub(r"\s*const\s*$", "", line.rstrip())
    if not s.endswith(")") or re.match(r"\s*(EXTERN_C|extern|static)\b", line) or \
            not re.search(r"\b(struct|class)\b|^\s+", line):
        return None
    depth, i = 0, len(s) - 1
    while i >= 0:
        depth += s[i] == ")"
        depth -= s[i] == "("
        if depth == 0:
            break
        i -= 1
    head = re.split(r"[;{}]|\bpublic:|\bprivate:|\bprotected:", s[:i])[-1]
    return head.strip(), s[i + 1:-1]


def fix_labels(text, stats):
    """asm("name") -> asm("_name"); pins dropped. Members: methods get cdecl, so `this` is the first stack
    argument as in the recompiled or decompiled callee. Constructors and destructors cannot be cdecl in the
    MSVC ABI (`this` in ECX, callee pops), so they are pointed at a thunk _port_thiscall<N>_<name> that
    tools/port/gen_stubs.py generates (N: bytes of stack arguments)."""
    text, n = PIN_RE.subn("", text)
    stats["pins"] += n

    def lab(m):
        name = m.group(2)
        stats["labels"] += 1
        new = f'{m.group(1)}("_{name}")'
        line_start = text.rfind("\n", 0, m.start()) + 1
        md = member_declarator(text[line_start:m.start()])
        if md:
            head, params = md
            if re.fullmatch(r"(explicit\s+|inline\s+)*~?\w+", head):
                ps = [p for p in split_params(params) if p not in ("", "void")]
                stats["thiscall_thunks"] += 1
                return f'{m.group(1)}("_port_thiscall{4 * len(ps)}_{name}")'
            stats["cdecl_members"] += 1
            new += " __attribute__((cdecl))"
        return new
    return LABEL_RE.sub(lab, text)


def drop_sets(text, aliases, stats):
    def sub(m):
        body = "".join(re.findall(r'"([^"]*)"', m.group(1)))
        body = body.encode().decode("unicode_escape")
        if not body.lstrip().startswith(".set"):
            return m.group(0)
        for line in body.splitlines():
            mm = re.match(r"\s*\.set\s+([^,\s]+)\s*,\s*(\S+)", line)
            if mm:
                aliases.append((mm.group(1), mm.group(2)))
        stats["set_blocks"] += 1
        return "/* port: .set aliases removed (build/port/aliases.txt) */"
    return SET_RE.sub(sub, text)


def drop_asm_macros(text, stats):
    def sub(m):
        stats["asm_macros"] += 1
        return f"/* port: MIPS asm macro {m.group(1)} removed (port/include/port_gte.h) */"
    return ASM_MACRO_RE.sub(sub, text)


# ---------------------------------------------------------------- permissive prototypes
DECL_RE = re.compile(r"^EXTERN_C\s+(?P<ret>[^()]*?)\s*\b(?P<name>\w+)\s*\((?P<params>.*)\)\s*;(?P<tail>.*)$")


def split_params(s):
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch in "(<[":
            depth += 1
        elif ch in ")>]":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def permissive_param(p):
    if "&" in p and "(" not in p and not p.lstrip().startswith("const"):
        return "const " + p  # GCC 2.8 bound temporaries to non-const references; same ABI
    if p in ("", "void", "...") or "(" in p or "&" in p or "[" in p or "port_" in p or "=" in p:
        return p
    if "*" in p:
        i = p.rindex("*")
        base, name = p[:i].strip(), p[i + 1:].strip()
        if name and not re.fullmatch(r"\w+", name):
            return p
        return f"port_parg<{base}> {name}".rstrip()
    toks = p.split()
    name = ""
    if len(toks) > 1 and toks[-1] not in INT_WORDS:
        name = toks[-1]
        toks = toks[:-1]
    toks_nc = [t for t in toks if t != "const"]
    if toks_nc and all(t in INT_WORDS for t in toks_nc):
        return f"port_iarg<{' '.join(toks)}> {name}".rstrip()
    return p


def permissive_ret(ret):
    return "port_pret" if re.fullmatch(r"(const\s+)?void\s*\*", ret.strip()) else ret.strip()


def balanced(s):
    d = 0
    for ch in s:
        d += ch == "("
        d -= ch == ")"
        if d < 0:
            return False
    return d == 0


def permissive_proto(ret, name, params):
    newp = ", ".join(permissive_param(p) for p in split_params(params))
    return f"EXTERN_C {permissive_ret(ret)} {name}({newp})"


def permissive_decls(text, stats):
    """Every one-line EXTERN_C function declaration (not an asm-label alias) becomes permissive."""
    out = []
    for line in text.split("\n"):
        m = DECL_RE.match(line) if line.startswith("EXTERN_C") else None
        if m and m.group("ret").strip() and balanced(m.group("params")) and "asm" not in line:
            new = permissive_proto(m.group("ret"), m.group("name"), m.group("params")) + ";" + m.group("tail")
            if new != line:
                stats["permissive_decls"] += 1
                line = new
        out.append(line)
    return "\n".join(out)


# ---------------------------------------------------------------- definitions in src
DEF_RE = re.compile(r"^EXTERN_C\s+(?P<ret>[^;{}()]*?)\s*\b(?P<name>\w+)\s*\((?P<params>[^;{}]*?)\)\s*"
                    r"(?P<nrv>return\s+\w+\s*)?\{", re.M)


def skip_noncode(text, i):
    """If text[i] starts a comment or a string/char literal, return the index after it, else None."""
    if text.startswith("//", i):
        j = text.find("\n", i)
        return len(text) if j < 0 else j
    if text.startswith("/*", i):
        j = text.find("*/", i + 2)
        return len(text) if j < 0 else j + 2
    c = text[i]
    if c in "\"'":
        j = i + 1
        while j < len(text) and text[j] != c:
            j += 2 if text[j] == "\\" else 1
        return j + 1
    return None


def item_starts(text):
    """Line offsets where a top-level item (declaration/definition) begins."""
    starts, depth, i, n, expect = [], 0, 0, len(text), True
    while i < n:
        j = skip_noncode(text, i)
        if j is not None:
            i = j
            continue
        c = text[i]
        if c == "#" and text[text.rfind("\n", 0, i) + 1:i].strip() == "":
            j = i
            while True:  # preprocessor line, with continuations
                j = text.find("\n", j)
                if j < 0 or text[j - 1] != "\\":
                    break
                j += 1
            i = n if j < 0 else j
            continue
        if c.isspace():
            i += 1
            continue
        if depth == 0 and expect:
            starts.append(text.rfind("\n", 0, i) + 1)
            expect = False
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                expect = True
        elif c == ";" and depth == 0:
            expect = True
        i += 1
    return starts


def matching_brace(text, i):
    """Index of the } that closes the { at i."""
    depth, n = 0, len(text)
    while i < n:
        j = skip_noncode(text, i)
        if j is not None:
            i = j
            continue
        c = text[i]
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                return i
        i += 1
    raise ValueError("unbalanced braces")


ALIAS_RE = re.compile(r'^EXTERN_C\s[^;{}]*?\b(\w+)\s*\([^;{}]*\)\s*(?:asm|__asm__)\s*\(\s*"_([\w.$]+)"\s*\)\s*;', re.M)


def asm_aliases(text):
    """C name -> symbol for EXTERN_C declarations with an asm label (after fix_labels)."""
    return {m.group(1): m.group(2) for m in ALIAS_RE.finditer(text)}


def rewrite_definitions(text, stats, header_aliases):
    """A definition of an asm-label alias name defines the label's symbol and keeps the alias declaration."""
    starts = item_starts(text)
    aliases = dict(header_aliases)
    aliases.update(asm_aliases(text))
    edits = []      # (start, end, replacement)
    inserts = {}    # offset -> [lines]
    for m in DEF_RE.finditer(text):
        ret, name, params = m.group("ret").strip(), m.group("name"), m.group("params")
        if not ret or not balanced(params):
            continue
        head = f"{ret} port_def_{name}({' '.join(params.split())})"
        body_open = m.end() - 1
        rep = f'{head} asm("_{aliases.get(name, name)}");\n{head}\n{{'
        if m.group("nrv"):
            r = m.group("nrv").split()[1]
            close = matching_brace(text, body_open)
            body = re.sub(r"\breturn\s*;", f"return {r};", text[body_open + 1:close])
            rep += f" {ret} {r};" + body + f"return {r};\n}}"
            edits.append((m.start(), close + 1, rep))
            stats["named_returns"] += 1
        else:
            edits.append((m.start(), m.end(), rep))
        stats["definitions"] += 1
        if name in aliases:
            continue  # its asm-labelled declaration serves the calls
        u = re.search(r"\b%s\b" % re.escape(name), text[:m.start()])
        at = max((s for s in starts if s <= (u.start() if u else m.start())), default=0)
        inserts.setdefault(at, []).append(permissive_proto(ret, name, params) + "; /* port */")
    points = edits + [(at, at, "\n".join(ls) + "\n") for at, ls in inserts.items()]
    points.sort(key=lambda x: (x[0], x[1] != x[0]))
    pieces, pos = [], 0
    for s, e, r in points:
        pieces.append(text[pos:s])
        pieces.append(r)
        pos = e
    pieces.append(text[pos:])
    return "".join(pieces)


# ---------------------------------------------------------------- per-site fixups
# The few places the rules above cannot cover. Each is a spot where src/ would need a change to compile on a
# modern compiler; the rewrite only adds a cast GCC 2.8 applied implicitly. (file, old, new, why)
FIXUPS = [
    ("u_8001986C.cpp", "r = size > 0xBFFF ? func_80027E30(size) : 0;",
     "r = size > 0xBFFF ? (void *)func_80027E30(size) : 0;", "?: of a void * return and 0"),
    ("u_8003852C.cpp", "void *o = func_8002EB68(p);", "void *o = (void *)func_8002EB68(p);",
     "int return assigned to void *"),
    ("u_80029BBC.cpp", "int r = 0;\n    if (p->unk4) {", "int r = 0;\n    if (p->port_vb->unk4) {",
     "C_VD reads its virtual base C_VB's member unk4 (GCC 2.x virtual base pointer)"),
]


def apply_fixups(fname, text, stats):
    for f, old, new, _ in FIXUPS:
        if f != fname:
            continue
        if old not in text:
            sys.exit(f"hostify: fixup for {f} no longer applies: {old!r}")
        text = text.replace(old, new)
        stats["fixups"] += 1
    return text


# ---------------------------------------------------------------- implicit declarations
UNDECL_RE = re.compile(r"^(.*?):(\d+):(\d+): error: use of undeclared identifier '(\w+)'", re.M)


def syntax_errors(path, hinc):
    cmd = hostcc.compile_cmd(path, "NUL", includes=[PORT_INCLUDE, hinc], extra=GAME_FLAGS + ["-fsyntax-only",
                             "-ferror-limit=0"], opt="-O0")
    cmd.remove("-c")
    cmd = cmd[:cmd.index("-o")]
    return subprocess.run(cmd, capture_output=True, text=True).stderr


def add_implicit_decls(paths, hinc, stats, jobs=8):
    with ThreadPoolExecutor(jobs) as ex:
        errs = list(ex.map(lambda p: syntax_errors(p, hinc), paths))
    for p, err in zip(paths, errs):
        lines = p.read_text(encoding="utf-8").split("\n")
        names = []
        for m in UNDECL_RE.finditer(err):
            if Path(m.group(1)).resolve() != p.resolve():
                continue
            line, col, name = int(m.group(2)), int(m.group(3)), m.group(4)
            after = lines[line - 1][col - 1 + len(name):].lstrip()
            if after.startswith("(") and name not in names:
                names.append(name)
        if not names:
            continue
        i = next(k for k, ln in enumerate(lines) if ln.startswith('#include "common.h"'))
        lines[i + 1:i + 1] = [f"EXTERN_C port_pret {n}(...); /* port: implicit declaration */" for n in names]
        stats["implicit_decls"] += len(names)
        p.write_text("\n".join(lines), encoding="utf-8", newline="\n")


# ---------------------------------------------------------------- GCC 2.x virtual functions
CLASS_RE = re.compile(r"\b(struct|class)\s+(\w+)\s*(:[^{;()]*)?\{")
VDECL_RE = re.compile(r"\bvirtual\s+")


def class_bodies(text):
    """(name, bases, body_start, body_end) for every class definition (body_end is the closing brace)."""
    out = []
    for m in CLASS_RE.finditer(text):
        try:
            close = matching_brace(text, m.end() - 1)
        except (ValueError, IndexError):
            continue
        bases = []
        if m.group(3):
            for b in m.group(3)[1:].split(","):
                toks = [t for t in re.findall(r"[\w<>:]+", b) if t not in ("public", "private", "protected")]
                bases.append((toks[-1] if toks else "", "virtual" in toks))
        out.append((m.group(2), bases, m.end(), close))
    return out


def virtual_decls(body, offset):
    """[(start, end, decl_text)] for each top-level `virtual ...;` or `virtual ... { }` in a class body."""
    out, depth, i, n = [], 0, 0, len(body)
    while i < n:
        j = skip_noncode(body, i)
        if j is not None:
            i = j
            continue
        c = body[i]
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
        elif depth == 0 and VDECL_RE.match(body, i) and (i == 0 or not (body[i - 1].isalnum() or body[i - 1] == "_")):
            k, d = i, 0
            while k < n:  # to the ; at depth 0, or the end of an inline body
                jj = skip_noncode(body, k)
                if jj is not None:
                    k = jj
                    continue
                if body[k] == "(":
                    d += 1
                elif body[k] == ")":
                    d -= 1
                elif d == 0 and body[k] == ";":
                    break
                elif d == 0 and body[k] == "{":
                    k = matching_brace(body, k)
                    break
                k += 1
            out.append((offset + i, offset + k + 1, body[i:k + 1]))
            i = k + 1
            continue
        i += 1
    return out


def parse_vdecl(decl):
    """virtual decl -> (key, ret, name, params, const) or None. key is the slot key ('~' for destructors)."""
    d = VDECL_RE.sub("", decl, count=1).strip()
    d = re.sub(r"\{.*\}\s*$", "", d, flags=re.S).rstrip().rstrip(";").rstrip()
    d = re.sub(r"=\s*0\s*$", "", d).rstrip()
    const = d.endswith("const")
    if const:
        d = d[:-5].rstrip()
    if not d.endswith(")"):
        return None
    depth, i = 0, len(d) - 1
    while i >= 0:
        depth += d[i] == ")"
        depth -= d[i] == "("
        if depth == 0:
            break
        i -= 1
    head, params = d[:i].strip(), d[i + 1:-1]
    m = re.fullmatch(r"(.*?)\s*(~?\w+|operator\s*\S+)", head, re.S)
    if not m:
        return None
    ret, name = m.group(1).strip(), m.group(2)
    if name.startswith("~"):
        return "~", "", name, params, const
    return f"{name}/{len([p for p in split_params(params) if p not in ('', 'void')])}", ret, name, params, const


def split_param_name(p, i):
    """'const S &r' -> ('const S &', 'r'); unnamed params get p<i>."""
    p = p.strip()
    m = re.fullmatch(r"(.*?[\s*&])(\w+)", p, re.S)
    if m and m.group(1).strip() and m.group(2) not in INT_WORDS and not re.fullmatch(r"(const\s+)?(struct\s+)?",
                                                                                    m.group(1).strip()):
        return m.group(1).strip(), m.group(2)
    return p, f"p{i}_"


def scalar_type(t):
    t = t.strip()
    return t.endswith("*") or t.endswith("&") or all(x in INT_WORDS | {"const", "bool", "void"} for x in t.split())


def dispatcher(ret, name, params, const, slot, stats):
    ps = [p for p in split_params(params) if p not in ("", "void")]
    if any(p == "..." for p in ps):
        stats["virtual_skipped"] += 1
        return None
    tn = [split_param_name(p, i) for i, p in enumerate(ps)]
    sig = ", ".join(f"{t} {n}" for t, n in tn)
    types = "".join(f", {t}" for t, _ in tn)
    args = "".join(f", {n}" for _, n in tn)
    head = f"{ret} {name}({sig}){' const' if const else ''}"
    pre = (f"port_vt_entry *e_ = (port_vt_entry *)this->port_vptr + {slot}; "
           f"void *s_ = (char *)this + e_->delta; ")
    if ret == "void":
        body = f"((void (*)(void *{types}))e_->pfn)(s_{args});"
    elif scalar_type(ret):
        body = f"return (({ret} (*)(void *{types}))e_->pfn)(s_{args});"
    else:  # GCC 2.8 MIPS returns a class by value through a hidden pointer, before `this`
        body = (f"alignas({ret}) char r_[sizeof({ret})]; ((void (*)(void *, void *{types}))e_->pfn)(r_, s_{args}); "
                f"return *({ret} *)r_;")
    return f"{head} {{ {pre}{body} }} /* port: GCC 2.x vtable slot {slot} */"


def vcall_slots(text, stats):
    """include/game/b/vcall.h: the 64 varargs placeholder slots v00..v63 (slot k = entry k+1) become variadic
    templates calling through the GCC vtable (port_vslot_call), plus PORT_VCALL_SLOTS_FWD, the forwarders
    a class with VObj0 as its virtual base gets."""
    if "VCALL_SLOTS_10" not in text:
        return text
    disp = ("template <class... A_> int v##a##{d}(A_... x_) {{ return port_vslot_call(this->port_vptr, this, "
            "1##a##{d} - 99, port_promote(x_)...); }}")
    text, n = re.subn(r"virtual int v##a##(\d)\(\.\.\.\);", lambda m: disp.format(d=m.group(1)), text)
    stats["vcall_slots"] += n * 6
    text, n = re.subn(r"virtual int v(\d\d)\(\.\.\.\);", lambda m: (
        f"template <class... A_> int v{m.group(1)}(A_... x_) {{ return port_vslot_call(this->port_vptr, this, "
        f"{int(m.group(1)) + 1}, port_promote(x_)...); }}"), text)
    stats["vcall_slots"] += n
    fwd = "template <class... A_> int v##a##{d}(A_... x_) {{ return port_vb->v##a##{d}(x_...); }}"
    extra = ["", "/* port: forwarders for a class whose virtual base is VObj0 (tools/port/hostify.py) */",
             "#define PORT_VCALL_SLOTS_FWD_10(a) " + " ".join(fwd.format(d=d) for d in range(10)),
             "#define PORT_VCALL_SLOTS_FWD " + " ".join(f"PORT_VCALL_SLOTS_FWD_10({a})" for a in range(6)) + " " +
             " ".join(f"template <class... A_> int v{k}(A_... x_) {{ return port_vb->v{k}(x_...); }}"
                      for k in range(60, 64)), ""]
    i = text.rindex("#endif")
    return text[:i] + "\n".join(extra) + "\n" + text[i:]


def virtual_bases(texts, stats):
    """GCC 2.x virtual bases. `struct X : A, virtual B { m }` -> `struct X : A { B *port_vb; m B port_vb_obj; }`:
    GCC 2.x keeps a pointer to the virtual base subobject after the non-virtual bases, and puts the subobject
    at the end of the complete object. Conversions to B go through port_vb_conv (port/include/port_args.h):
    in permissive parameters, in `B *x = expr;` initialisations and in inline functions' B * parameters.
    X gets forwarders for B's virtual functions (p->f() where f is B's)."""
    # virtual functions of each class and its non-virtual bases, for the forwarders
    own, bases_of, slots_macro = {}, {}, set()
    for t in texts.values():
        for name, bases, bs, be in class_bodies(t):
            fs = [parse_vdecl(d) for _, _, d in virtual_decls(t[bs:be], bs)]
            if name not in own or (not own[name] and fs):
                own[name] = [x for x in fs if x and x[0] != "~"]
                bases_of[name] = [b for b, v in bases if not v]
            if "VCALL_SLOTS" in t[bs:be]:
                slots_macro.add(name)

    def vfuncs(name, seen=()):
        out = list(own.get(name, []))
        for b in bases_of.get(name, []):
            if b not in seen:
                out += vfuncs(b, seen + (name,))
        return out
    vbase_types = set()
    for t in texts.values():
        for m in CLASS_RE.finditer(t):
            if m.group(3) and "virtual" in m.group(3):
                for p in m.group(3)[1:].split(","):
                    if re.search(r"\bvirtual\b", p):
                        vbase_types.add(re.findall(r"[\w<>:]+", p)[-1])
    out = {}
    for f, t in texts.items():
        edits = []
        for m in CLASS_RE.finditer(t):
            if not m.group(3) or "virtual" not in m.group(3):
                continue
            parts = [p.strip() for p in m.group(3)[1:].split(",")]
            vb = [p for p in parts if re.search(r"\bvirtual\b", p)]
            if len(vb) != 1:
                stats["vbase_skipped"] += 1
                continue
            b = [x for x in re.findall(r"[\w<>:]+", vb[0]) if x not in ("virtual", "public", "private", "protected")][-1]
            rest = [p for p in parts if p not in vb]
            close = matching_brace(t, m.end() - 1)
            head = f"{m.group(1)} {m.group(2)}" + (f" : {', '.join(rest)}" if rest else "") + " {"
            fwd = [" PORT_VCALL_SLOTS_FWD"] if b in slots_macro else []
            for _, ret, fname, params, const in vfuncs(b):
                tn = [split_param_name(p, i) for i, p in enumerate(split_params(params)) if p not in ("", "void")]
                if any(x[0] == "..." for x in tn):
                    continue
                call = f"port_vb->{fname}({', '.join(n for _, n in tn)})"
                fwd.append(f" {ret} {fname}({', '.join(f'{ty} {n}' for ty, n in tn)}){' const' if const else ''} "
                           f"{{ {'' if ret == 'void' else 'return '}{call}; }}")
            edits.append((close, close, "".join(fwd) + f" {b} port_vb_obj; /* port: GCC 2.x virtual base subobject */ "))
            edits.append((m.start(), m.end(), head + f" {b} *port_vb; /* port: GCC 2.x virtual base pointer */"))
            stats["vbases"] += 1
        for s, e, r in sorted(edits, reverse=True):
            t = t[:s] + r + t[e:]
        for b in vbase_types:
            # B *x = expr;  ->  B *x = port_vb_conv<B>((expr), 0);   (B * stays B *; X * loads X::port_vb)
            t, n = re.subn(r"\b(%s\s*\*\s*\w+\s*=\s*)([^;,{}]+);" % re.escape(b),
                           lambda mm: f"{mm.group(1)}port_vb_conv<{b}>(({mm.group(2).strip()}), 0);", t)
            stats["vbase_inits"] += n
            # inline helpers taking B *: make the parameter a port_parg<B>
            t, n = re.subn(r"(\binline\s+[^;{}()]*\(\s*)%s\s*\*\s*(\w+)\s*\)(\s*)\{" % re.escape(b),
                           lambda mm: f"{mm.group(1)}port_parg<{b}> {mm.group(2)}_p_){mm.group(3)}{{ "
                                      f"{b} *{mm.group(2)} = {mm.group(2)}_p_.p;", t)
            stats["vbase_inits"] += n
            # later assignments to a B * local, within the function that declares it: name = expr;
            starts = item_starts(t) + [len(t)]
            pieces = [t[:starts[0]]]
            for s0, s1 in zip(starts, starts[1:]):
                item = t[s0:s1]
                for v in set(re.findall(r"\b%s\s*\*\s*(\w+)\s*[;=]" % re.escape(b), item)):
                    item, n = re.subn(r"(?<![\w*>.])(%s\s*=\s*)(?!=)([^;{}]+);" % re.escape(v),
                                      lambda mm: f"{mm.group(1)}port_vb_conv<{b}>(({mm.group(2).strip()}), 0);"
                                      if "port_vb_conv" not in mm.group(2) else mm.group(0), item)
                    stats["vbase_inits"] += n
                pieces.append(item)
            t = "".join(pieces)
        out[f] = t
    return out


def devirtualize(texts, stats):
    """GCC 2.x virtual functions, for the MSVC ABI build (docs/PORT_PHASE2.md section 2).

    The objects the game builds carry GCC 2.x vtables (asm data): entries {short delta; short index; pfn},
    entry 0 unused, a base's slots first and an override reusing its base's slot. The vtable pointer of the
    class that introduces virtual functions sits after that class's own data members (MSVC: at offset 0).
    So each class with virtual functions gets, instead of them, an explicit `void *port_vptr` member where
    GCC put it, and an inline non-virtual dispatcher per function that calls through the GCC vtable:
    f(this + delta, args), with a hidden return-buffer pointer first for a class returned by value.
    Virtual destructors keep their slot and are dropped (a `delete` of such an object frees without running
    the game's destructor; no decompiled EXE code does that through a virtual destructor)."""
    classes = {}   # name -> [(file, bases, decls)] ; decls: [(start, end, key, parsed)]
    for f, t in texts.items():
        for name, bases, bs, be in class_bodies(t):
            decls = []
            for s, e, d in virtual_decls(t[bs:be], bs):
                pv = parse_vdecl(d)
                decls.append((s, e, pv[0] if pv else None, pv))
            classes.setdefault(name, []).append((f, bases, decls, bs, be))
    memo = {}

    def info(name, f=None):
        """slot map, count, introduces_vptr for a class (same file's definition preferred)"""
        defs = classes.get(name)
        if not defs:
            return None
        d = next((x for x in defs if x[0] == f), defs[0])
        key = (name, d[0], d[3])
        if key in memo:
            return memo[key]
        memo[key] = None  # cycle guard
        slots, count, own_vptr = {}, 0, True
        for b, is_virtual in d[1]:
            bi = info(b, d[0])
            if bi and bi[1] and not is_virtual:
                slots, count, own_vptr = dict(bi[0]), bi[1], False
                break
        for _, _, k, _ in d[2]:
            if k and k not in slots:
                count += 1
                slots[k] = count
        r = (slots, count, own_vptr and bool(d[2]))
        memo[key] = r
        return r

    out = {}
    for f, t in texts.items():
        edits = []
        for name, bases, bs, be in class_bodies(t):
            defs = [x for x in classes[name] if x[0] == f and x[3] == bs]
            if re.search(r"^\s*VCALL_SLOTS\s*$", t[bs:be], re.M):  # vcall.h's VObj<N>, VObj0: own vptr
                edits.append((be, be, " void *port_vptr; /* port: GCC 2.x vptr, after the class's own data */ "))
                stats["vptr_members"] += 1
                continue
            if not defs or not defs[0][2]:
                continue
            slots, count, own_vptr = info(name, f) or ({}, 0, False)
            for s, e, k, pv in defs[0][2]:
                if pv is None:
                    stats["virtual_skipped"] += 1
                    continue
                _, ret, mname, params, const = pv
                if k == "~":
                    rep = f"/* port: virtual destructor {mname}, GCC 2.x vtable slot {slots['~']} */"
                else:
                    rep = dispatcher(ret, mname, params, const, slots[k], stats)
                    if rep is None:
                        continue
                stats["virtual_dispatchers"] += 1
                edits.append((s, e, rep))
            if own_vptr:
                edits.append((be, be, " void *port_vptr; /* port: GCC 2.x vptr, after the class's own data */ "))
                stats["vptr_members"] += 1
        for s, e, r in sorted(edits, reverse=True):
            t = t[:s] + r + t[e:]
        out[f] = t
    return out


def write(path, text):
    path.parent.mkdir(parents=True, exist_ok=True)
    if not path.exists() or path.read_text(encoding="utf-8") != text:
        path.write_text(text, encoding="utf-8", newline="\n")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--out", default=str(ROOT / "build" / "port"))
    ap.add_argument("--no-implicit", action="store_true", help="skip the clang pass for implicit declarations")
    a = ap.parse_args()
    out = Path(a.out)
    stats = {k: 0 for k in ("labels", "pins", "cdecl_members", "set_blocks", "asm_macros", "permissive_decls",
                            "definitions", "named_returns", "implicit_decls", "fixups", "thiscall_thunks",
                            "virtual_dispatchers", "vptr_members", "virtual_skipped", "vbases", "vbase_skipped", "vbase_inits", "vcall_slots")}
    aliases = []
    header_aliases = {}
    texts = {}
    for p in sorted((ROOT / "include").rglob("*.h")):
        rel = p.relative_to(ROOT / "include")
        if rel.as_posix() in ("common.h", "include_asm.h"):
            continue
        t = renames(p.read_text(encoding="utf-8"))
        t = drop_sets(t, aliases, stats)
        t = drop_asm_macros(t, stats)
        t = fix_labels(t, stats)
        t = permissive_decls(t, stats)
        t = vcall_slots(t, stats)
        header_aliases.update(asm_aliases(t))
        texts[out / "hinc" / rel] = t
    srcs = []
    for p in sorted((ROOT / "src" / "main").glob("*.cpp")):
        t = renames(p.read_text(encoding="utf-8"))
        t = drop_sets(t, aliases, stats)
        t = drop_asm_macros(t, stats)
        t = fix_labels(t, stats)
        t = permissive_decls(t, stats)
        t = rewrite_definitions(t, stats, header_aliases)
        t = apply_fixups(p.name, t, stats)
        dst = out / "hsrc" / "main" / p.name
        texts[dst] = t
        srcs.append(dst)
    for dst, t in devirtualize(virtual_bases(texts, stats), stats).items():
        write(dst, t)
    if not a.no_implicit:
        add_implicit_decls(srcs, out / "hinc", stats)
    write(out / "aliases.txt", "".join(f"{x} {y}\n" for x, y in aliases))
    print("hostify: " + ", ".join(f"{k} {v}" for k, v in stats.items()) + f", aliases {len(aliases)}")


if __name__ == "__main__":
    sys.exit(main())
