# Compiler tests

Each file reproduces one retail function exactly with PsyQ 4.4 (GCC 2.8.1, ASPSX 2.79). Together they pin the
compiler (see `config/toolchain.toml`):

| File | Flags | 4.1 (2.7.2) | 4.3 (2.8.0) | 4.4 (2.8.1) | 4.5 (egcs 2.91) | 4.6 (2.95.2) |
|---|---|---|---|---|---|---|
| `func_800186B0.c` | `-O2 -G8` | — | match | match | — | match |
| `func_800186E8.cpp` | `-O2 -G8` | 3 diff (epilogue) | match | match | 28 diff (loop inverted) | 28 diff (loop inverted) |
| `func_8006F630.c` | `-O2 -G0` | 4 diff | match | match | 10 diff | 13 diff |

Run one:

```powershell
.venv/Scripts/python.exe tools/try_compile.py tests/compiler/func_800186E8.cpp func_800186E8
.venv/Scripts/python.exe tools/try_compile.py tests/compiler/func_8006F630.c func_8006F630 --cflags "-O2 -G0"
```

Add `--psyq bin/psyq4.5 --aspsx 2.81` (etc.) to try another version.
