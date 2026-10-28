/* func_8003FEF4: near miss (class ctor: S_A2_X0 base, vt D_800127D4, shorts copied from the source struct e, two func_800A0D2C buffers). 94 differing: only param-copy / load scheduling (retail loads the 4th stack arg late and copies a2/a3 to saved regs late). Logic from Ghidra. */
struct C_8003FEF4 : S_A2_X0 {
    C_8003FEF4(void *b, void *c, void *d, void *e, short f, short g, void *h, void *i) asm("func_8003FEF4");
};
//// func_8003FEF4
C_8003FEF4::C_8003FEF4(void *b, void *c, void *d, void *e, short f, short g, void *h, void *i)
{
    short v;
    vt = D_800127D4;
    AT(this, short, 8) = f;
    AT(this, short, 0xA) = g;
    AT(this, short, 0xC) = AT(e, short, 6);
    AT(this, short, 0xE) = AT(e, short, 8);
    AT(this, short, 0x10) = AT(e, short, 4);
    AT(this, char, 0x12) = AT(e, char, 2);
    AT(this, char, 0x13) = AT(e, char, 3);
    v = AT(e, short, 0xC);
    AT(this, void *, 0x18) = h;
    AT(this, int, 0x14) = v;
    AT(this, short, 0x2C) = AT(e, short, 10);
    AT(this, short, 0x34) = AT(e, short, 0xE);
    AT(this, short, 0x36) = 1;
    if (AT(this, short, 0x34) == 0) {
        AT(this, int, 0x30) = 0;
    } else {
        void *m = func_800A0D2C(AT(this, short, 0x34));
        AT(this, void *, 0x30) = m;
        func_80025CE0((int)m, (char *)d, AT(this, short, 0x34));
    }
    AT(this, void *, 0x24) = func_800A0D2C(AT(this, short, 0xE) * AT(this, short, 0xC) * 0xC);
    AT(this, void *, 0x28) = func_800A0D2C(AT(this, short, 0xE) << 4);
    func_80025CE0((int)AT(this, void *, 0x24), (char *)b, AT(this, short, 0xE) * AT(this, short, 0xC) * 0xC);
    func_80025CE0((int)AT(this, void *, 0x28), (char *)c, AT(this, short, 0xE) << 4);
    AT(this, int, 0x18) = 0;
    AT(this, int, 0x20) = 0;
}
