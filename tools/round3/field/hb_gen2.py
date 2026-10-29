pre='''struct Unk_800CD428_s { char pad0[0x1C]; int unk1C; };
struct Unk_800CD428 { char pad0[0x1C]; Unk_800BFB64_list unk1C; char pad20[0xB4]; Unk_EB88 unkD4[8]; unsigned short unk514; };
EXTERN_C void func_800D103C_1(void*) asm("func_800D103C");
EXTERN_C Unk_800CD428_s* func_800620D8(void*, unsigned int);
EXTERN_C void func_80054CE4_2(void*, void*) asm("func_80054CE4");
//--
EXTERN_C void func_800CD428(Unk_800CD428* p) {
    func_80019D40(first(&p->unk1C));
    Unk_800CD428_s* s;
'''
body='''        func_800D103C_1(&p->unkD4[p->unk514]);
        func_80053BCC(&p->unkD4[p->unk514], (int)&s->unk1C, 0);
        func_800540A8(&p->unkD4[p->unk514]);
        func_80054094(&p->unkD4[p->unk514], 0);
        func_80054E18(p, &p->unkD4[p->unk514]);
'''
vs={}
vs[10]='''    for (s = func_800620D8(D_800B4DD0[0], p->unk514 = 0); s; ) {
'''+body+'''        unsigned short n = p->unk514 + 1;
        p->unk514 = n;
        s = func_800620D8(D_800B4DD0[0], n);
    }
    func_80054CE4_2(p, s);
}
'''
vs[11]='''    p->unk514 = 0;
    s = func_800620D8(D_800B4DD0[0], 0);
    while (s) {
'''+body+'''        unsigned short n = p->unk514 + 1;
        p->unk514 = n;
        s = func_800620D8(D_800B4DD0[0], n);
    }
    func_80054CE4_2(p, s);
}
'''
vs[12]='''    p->unk514 = 0;
    s = func_800620D8(D_800B4DD0[0], 0);
    while (s) {
'''+body+'''        Unk_800B4DD0* d = D_800B4DD0[0];
        p->unk514++;
        s = func_800620D8(d, p->unk514);
    }
    func_80054CE4_2(p, s);
}
'''
vs[13]='''    p->unk514 = 0;
    s = func_800620D8(D_800B4DD0[0], 0);
    while (s) {
'''+body+'''        s = func_800620D8(D_800B4DD0[0], p->unk514 = p->unk514 + 1);
    }
    func_80054CE4_2(p, s);
}
'''
vs[14]='''    s = func_800620D8(D_800B4DD0[0], p->unk514 = 0);
    while (s) {
'''+body+'''        s = func_800620D8(D_800B4DD0[0], ++p->unk514);
    }
    func_80054CE4_2(s ? 0 : p, s);
}
'''
open('scratch_c/hb_7.txt','a').write(''.join('### func_800CD428@%d\n'%k+pre+v for k,v in vs.items()))
