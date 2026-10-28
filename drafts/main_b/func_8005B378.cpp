struct Ent16d { char p[0xE]; unsigned short h; };
EXTERN_C void func_8005B378(void *self, int n)
{
    unsigned i;
    int idx = D_800B4CF0_w;
    int v = func_80060118(&D_800AE640, 0);
    int w = func_800600A4(&D_800AE640, 0xB);
    for (i = 0; i < FIELD_AT(self, unsigned, 0x18); i += 2) {
        if (FIELD_AT(self, Ent16d *, 0x14)[i + idx].h != (unsigned short)w) {
            FIELD_AT(self, Ent16d *, 0x14)[i + idx].h = v;
        }
    }
    func_8005F1D8(self);
}
