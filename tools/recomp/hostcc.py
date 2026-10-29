"""The host toolchain: clang for i686-pc-windows-msvc with the MSVC x86 libraries and the Windows SDK.

clang finds Visual Studio and the Windows SDK by itself and puts its own resource headers first.
Do not pass the MSVC/SDK include folders with -isystem: that puts MSVC's vadefs.h ahead of
clang's, and on i686 every varargs function (printf included) then reads garbage arguments.
To point clang at another installation set RECOMP_VCTOOLS (.../VC/Tools/MSVC/<ver>) and/or
RECOMP_WINSDK (.../Windows Kits/10) and RECOMP_WINSDK_VER (e.g. 10.0.26100.0).
"""
import os
from pathlib import Path

CLANG = Path(os.environ.get("RECOMP_CLANG", "C:/Program Files/LLVM/bin/clang.exe"))
LLVM_BIN = CLANG.parent
TARGET = "i686-pc-windows-msvc"


def _toolchain_flags():
    out = []
    if os.environ.get("RECOMP_VCTOOLS"):
        out += ["-Xmicrosoft-visualc-tools-root", os.environ["RECOMP_VCTOOLS"]]
    if os.environ.get("RECOMP_WINSDK"):
        out += ["-Xmicrosoft-windows-sdk-root", os.environ["RECOMP_WINSDK"]]
    if os.environ.get("RECOMP_WINSDK_VER"):
        out += ["-Xmicrosoft-windows-sdk-version", os.environ["RECOMP_WINSDK_VER"]]
    return out


# -fno-strict-aliasing: the recompiled code and the game's own C both read the same bytes as different types.
# -fwrapv: the MIPS code relies on two's-complement wraparound.
COMMON_FLAGS = ["--target=" + TARGET, "-fno-strict-aliasing", "-fwrapv", "-fno-delete-null-pointer-checks"] + _toolchain_flags()


def sys_includes():
    return []


def compile_cmd(src, out, includes=(), defines=(), extra=(), lang=None, opt="-O2"):
    cmd = [str(CLANG)] + COMMON_FLAGS + [opt]
    if lang:
        cmd += ["-x", lang]
    for i in includes:
        cmd += ["-I", str(i)]
    for d in defines:
        cmd.append("-D" + d)
    cmd += list(extra)
    cmd += ["-c", str(src), "-o", str(out)]
    return cmd


def link_cmd(objs, out, extra=()):
    return [str(CLANG), "--target=" + TARGET, "-fuse-ld=lld"] + _toolchain_flags() + \
        [str(o) for o in objs] + ["-o", str(out)] + list(extra)
