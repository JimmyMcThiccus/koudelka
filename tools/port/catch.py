"""Run the port under a minimal debugger and report the exceptions it hits (PC port, docs/PORT_PHASE2.md).

    python tools/port/catch.py [--timeout 60] [--all] [-- args for koudelka.exe]

For crashes the exe cannot report itself: a fault with a corrupt stack pointer, or a stack overflow,
never reaches its exception handlers and the process just dies. This uses the Win32 debug API (no
debugger install needed): first-chance exceptions are passed on to the program, and on a second-chance
(fatal) one it prints the exception, the registers and every stack word that is a code address,
symbolised from build/port/koudelka.exe.map. --all also prints first-chance exceptions.
"""
import argparse
import bisect
import ctypes
import re
import sys
import time
from ctypes import wintypes as W
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
EXE = ROOT / "build" / "port" / "koudelka.exe"

k32 = ctypes.WinDLL("kernel32", use_last_error=True)
DEBUG_ONLY_THIS_PROCESS = 0x2
DBG_CONTINUE, DBG_EXCEPTION_NOT_HANDLED = 0x00010002, 0x80010001
EXCEPTION_DEBUG_EVENT, CREATE_PROCESS_DEBUG_EVENT, EXIT_PROCESS_DEBUG_EVENT, LOAD_DLL_DEBUG_EVENT = 1, 3, 5, 6
SINGLE_STEP = 0x80000004
BENIGN = {0x80000003, 0x4000001F, 0x406D1388, 0x40010006, 0x4001000A}  # breakpoints, thread names, debug strings


class STARTUPINFO(ctypes.Structure):
    _fields_ = [("cb", W.DWORD), ("r", W.LPWSTR), ("d", W.LPWSTR), ("t", W.LPWSTR)] + \
               [(f"x{i}", W.DWORD) for i in range(8)] + [("w", W.WORD), ("c", W.WORD), ("p", ctypes.c_void_p),
                                                       ("h0", W.HANDLE), ("h1", W.HANDLE), ("h2", W.HANDLE)]


class PROCESS_INFORMATION(ctypes.Structure):
    _fields_ = [("hProcess", W.HANDLE), ("hThread", W.HANDLE), ("pid", W.DWORD), ("tid", W.DWORD)]


class EXCEPTION_RECORD(ctypes.Structure):
    _fields_ = [("code", W.DWORD), ("flags", W.DWORD), ("rec", ctypes.c_void_p), ("addr", ctypes.c_void_p),
                ("n", W.DWORD), ("info", ctypes.c_size_t * 15)]


class DEBUG_EVENT(ctypes.Structure):
    _fields_ = [("code", W.DWORD), ("pid", W.DWORD), ("tid", W.DWORD), ("pad", W.DWORD),
                ("u", ctypes.c_byte * 160)]


def symbols():
    mp = Path(str(EXE) + ".map")
    addrs, names = [], []
    if mp.exists():
        for line in mp.read_text(errors="replace").splitlines():
            # link.exe format (lld-link /map): " 0001:00000090       _func_80018788    0000000000401090     main_a.obj"
            m = re.match(r"\s*[0-9a-fA-F]{4}:[0-9a-fA-F]{8}\s+(\S+)\s+([0-9a-fA-F]{8,16})\b", line)
            if m:
                addrs.append(int(m.group(2), 16))
                names.append(m.group(1))
    order = sorted(range(len(addrs)), key=lambda i: addrs[i])
    return [addrs[i] for i in order], [names[i] for i in order]


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--timeout", type=float, default=60)
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--watch", type=lambda x: int(x, 16), help="hex address: log every write to that word "
                    "(a hardware watchpoint on the game thread)")
    ap.add_argument("--hits", type=int, default=40)
    ap.add_argument("--ignore", type=lambda x: int(x, 16), action="append", default=[],
                    help="hex value: do not report writes that leave this value")
    ap.add_argument("args", nargs=argparse.REMAINDER)
    a = ap.parse_args()
    addrs, names = symbols()

    def sym(x):
        i = bisect.bisect_right(addrs, x) - 1
        return f"{names[i]}+0x{x - addrs[i]:X}" if i >= 0 and x - addrs[i] < 0x10000 else ""

    si, pi = STARTUPINFO(), PROCESS_INFORMATION()
    si.cb = ctypes.sizeof(si)
    cmd = " ".join([f'"{EXE}"'] + [x for x in a.args if x != "--"])
    if not k32.CreateProcessW(None, ctypes.create_unicode_buffer(cmd), None, None, False, DEBUG_ONLY_THIS_PROCESS,
                              None, str(EXE.parent), ctypes.byref(si), ctypes.byref(pi)):
        sys.exit(f"catch: CreateProcess failed ({ctypes.get_last_error()})")
    hproc = pi.hProcess
    ev = DEBUG_EVENT()
    end = time.time() + a.timeout
    dumped = False  # the first access violation, first chance or not, gets a stack dump
    hits = 0
    while True:
        if not k32.WaitForDebugEvent(ctypes.byref(ev), 1000):
            if time.time() > end:
                print("catch: timeout, terminating")
                k32.TerminateProcess(hproc, 1)
            continue
        cont = DBG_CONTINUE
        if ev.code == EXCEPTION_DEBUG_EVENT:
            er = EXCEPTION_RECORD.from_buffer_copy(bytes(ev.u)[:ctypes.sizeof(EXCEPTION_RECORD)])
            first = ctypes.c_uint32.from_buffer_copy(bytes(ev.u)[ctypes.sizeof(EXCEPTION_RECORD):][:4]).value
            if er.code in (SINGLE_STEP, 0x4000001E) and a.watch is not None:  # WOW64 reports STATUS_WX86_SINGLE_STEP
                val = ctypes.c_uint32()
                k32.ReadProcessMemory(hproc, ctypes.c_void_p(a.watch), ctypes.byref(val), 4, None)
                hits += val.value not in a.ignore
                if hits <= a.hits and val.value not in a.ignore:
                    print(f"catch: write #{hits} to {a.watch:08X}: now {val.value:08X}")
                    dump(ev.tid, hproc, sym, frames=6)
            elif er.code not in BENIGN:
                cont = DBG_EXCEPTION_NOT_HANDLED
                if a.all or not first:
                    pc = er.addr or 0
                    info = " ".join(f"{er.info[i]:08X}" for i in range(min(er.n, 2)))
                    print(f"catch: {'first' if first else 'SECOND'}-chance exception {er.code:08X} at {pc:08X} "
                          f"{sym(pc)} [{info}] thread {ev.tid}")
                if not first or (er.code == 0xC0000005 and not dumped):
                    dump(ev.tid, hproc, sym)
                    dumped = True
        elif ev.code == CREATE_PROCESS_DEBUG_EVENT:
            k32.CloseHandle(ctypes.c_void_p.from_buffer_copy(bytes(ev.u)[:8]).value)
            if a.watch is not None:
                watch(ev.tid, a.watch)
        elif ev.code == LOAD_DLL_DEBUG_EVENT:
            k32.CloseHandle(ctypes.c_void_p.from_buffer_copy(bytes(ev.u)[:8]).value)
        elif ev.code == EXIT_PROCESS_DEBUG_EVENT:
            code = ctypes.c_uint32.from_buffer_copy(bytes(ev.u)[:4]).value
            print(f"catch: process exited with {code:08X}")
            k32.ContinueDebugEvent(ev.pid, ev.tid, DBG_CONTINUE)
            break
        k32.ContinueDebugEvent(ev.pid, ev.tid, cont)


def watch(tid, addr):
    """DR0 = addr, write, 4 bytes, on the (32-bit) thread tid."""
    ht = k32.OpenThread(0x1FFFFF, False, tid)
    ctx = (ctypes.c_uint32 * 179)()
    ctx[0] = 0x10010  # WOW64_CONTEXT_DEBUG_REGISTERS
    k32.Wow64GetThreadContext(ht, ctx)
    ctx[1] = addr                                   # Dr0
    ctx[6] = 0x1 | (0x1 << 16) | (0x3 << 18)        # Dr7: L0, R/W0 = write, LEN0 = 4 bytes
    if not k32.Wow64SetThreadContext(ht, ctx):
        print(f"catch: Wow64SetThreadContext failed ({ctypes.get_last_error()})")
    print(f"catch: watching writes to {addr:08X} on thread {tid}")


def dump(tid, hproc, sym, frames=30):
    """Registers of the faulting (32-bit) thread and the code addresses on its stack."""
    ht = k32.OpenThread(0x1FFFFF, False, tid)
    ctx = (ctypes.c_uint32 * 179)()  # WOW64_CONTEXT
    ctx[0] = 0x10007  # WOW64_CONTEXT_FULL
    if not k32.Wow64GetThreadContext(ht, ctx):
        print(f"catch: Wow64GetThreadContext failed ({ctypes.get_last_error()})")
        return
    # WOW64_CONTEXT dword offsets: Ebp 45, Eip 46, Esp 49
    ebp, eip, esp = ctx[45], ctx[46], ctx[49]
    print(f"catch: eip {eip:08X} {sym(eip)}  esp {esp:08X}  ebp {ebp:08X}")
    for base in (esp, ebp):
        buf = (ctypes.c_uint32 * 2048)()
        got = ctypes.c_size_t()
        ok = False
        for pages in range(7, -1, -1):  # a fiber stack ends at its top page
            size = min(ctypes.sizeof(buf), 0x1000 - (base & 0xFFF) + 0x1000 * pages)
            if k32.ReadProcessMemory(hproc, ctypes.c_void_p(base), buf, size, ctypes.byref(got)):
                ok = True
                break
        if not ok:
            print(f"catch: stack at {base:08X} unreadable")
            continue
        n = 0
        for i in range(got.value // 4):
            s = sym(buf[i])
            if s and 0x00401000 <= buf[i] < 0x01000000:
                print(f"  [{base + 4 * i:08X}] {buf[i]:08X} {s}")
                n += 1
                if n >= frames:
                    break
        break


if __name__ == "__main__":
    main()
