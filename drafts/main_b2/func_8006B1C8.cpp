// func_8006B1C8: MATCHES (0 in try_compile, round-4 track C), not landed: it isn't on track C's list and main_b2 belongs to
// track B. Twin of func_8006B180 (landed) with '-'. Goes over its INCLUDE_ASM in src/main/u_80068770.cpp.
EXTERN_C void func_8006B1C8(void *self, int d)
{
    short s = FIELD_AT(self, unsigned short, 0x2A0);
    short r = s - d;
    s = r;
    if (r > 0xF6E) s = 0xF6E;
    if (s < 0xE42) s = 0xE42;
    FIELD_AT(self, short, 0x2A0) = s;
}
