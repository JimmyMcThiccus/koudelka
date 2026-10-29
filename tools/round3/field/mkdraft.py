import re,sys
from pathlib import Path
def sect(f,s):
    t=Path(f).read_text()
    pre,*parts=re.split(r"^### (\S+)\s*$",t,flags=re.M)
    d=dict(zip(parts[0::2],parts[1::2]))
    return d[s]
specs=[
 ("func_800DEED4","scratch_c/t19b.txt","func_800DEED4","11 differing: tail of func_800DEED4 -- retail keeps the angle in a register separate from a1 (`bgez; a1=v0; a1=v0+0x1FF; a0=s0; a1>>=9`), the build does the /512 in place in v0. Header declares (void*, Unk_W3); this uses an int-arg alias."),
 ("func_800C1EFC","scratch_c/t24.txt","func_800C1EFC","48 differing, logic matches: register allocation. Retail keeps self=s1, in_chrg=s2 and the 0x68 sub-object pointer in s0 (recomputed in both delay slot and after the call); the build puts self in s0."),
 ("func_800BF9D8","scratch_c/t10b.txt","func_800BF9D8@3","7 differing: retail sets a1=0x10 in the first call's delay-slot area (before the vptr lui/addiu); the build keeps it next to its use."),
 ("func_800D2458","scratch_c/t13.txt","func_800D2458@10","16 differing: statement/load scheduling of the quad edit (tried 18 orderings)."),
 ("func_800BF3B0","scratch_c/t6.txt","func_800BF3B0@0","29 differing: retail keeps the source pointer a1 as its own IV and the dest in a3; the build copies a1 to a3 first. 8-byte element copy loop."),
 ("func_800BB25C","scratch_c/t26.txt","func_800BB25C@0","17 differing: constant materialisation order (retail loads 1 into v1 first)."),
 ("func_800DBF0C","scratch_c/t21.txt","func_800DBF0C","24 differing: retail tests `f&0x10 && unk3C` with a0 loaded straight from p->unk3C and falls into the 0x40 test; the build branches differently."),
 ("func_800E8AF0","scratch_c/t21.txt","func_800E8AF0","23 differing: same as func_800DBF0C."),
 ("func_800C1AF0","scratch_c/t20.txt","func_800C1AF0@0","29 differing: inlined iterator next() on Unk_TblIt at +0x23C. Retail folds the index to 0 for the compare (blez) but reloads it for the array index. Same for func_800C1BB8 (vf02, func_800CE7AC) and func_800BB538/func_800BB480 (same 5-instruction delay-slot issue: retail's first insn after the beqz is the table lw, the build puts the sll there)."),
]
for name,f,s,note in specs:
    body=sect(f,s)
    decl,_,fn=body.partition("//--\n")
    p=Path(f"drafts/field/{name}.cpp")
    p.write_text(f'// {name}: {note}\n#include "field/field.h"\n\n{decl.strip()}\n\n{fn.strip()}\n',newline="\n")
    print("wrote",p)
