struct U8b { char c[8]; };
EXTERN_C void func_800624A4(void *unused, void *s0, void *s1)
{
    int r = rand();
    int a = (r >> 8) & 3;
    int v;
    if ((r >> 8) & 1) v = a - 1; else v = a + 1;
    FIELD_AT(s0, short, 0x88) = 0x8000 >> v;
    if ((r >> 4) & 1) {
        short *p = &FIELD_AT(s0, short, 0x80 + (r & 3) * 2);
        *p = 0x8000 >> a;
    }
    *(U8b *)s1 = *(U8b *)func_80053BC0((char *)D_800AE86C + a * 28);
}
