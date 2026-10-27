// func_8006B180 (and its twin func_8006B1C8, which subtracts): clamp a short at +0x2A0 to [0xE42, 0xF6E].
// Best attempt: 2 differing instructions. Retail keeps the loaded value in $v1 and computes
// `addu $a1, $v1, $a1`; this version loads into $v0 and emits `addu $a1, $a1, $v0`.
// The same body with '-' for func_8006B1C8 is further off (7): retail still does the arithmetic in $a1.
EXTERN_C void func_8006B180(void *self, int d)
{
    unsigned short u = FIELD_AT(self, unsigned short, 0x2A0);
    short v;

    d = u + d;
    v = d;
    if (v > 0xF6E) {
        v = 0xF6E;
    }
    if (v < 0xE42) {
        v = 0xE42;
    }
    FIELD_AT(self, short, 0x2A0) = v;
}
