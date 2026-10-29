/* func_8003D3A0: near miss (fade state machine; switch order 1,2,3 matches retail). 135 differing: GCC hoists the 0xFFFF constant of the divu into the switch prologue and merges the return-0 tails; retail re-materialises it per case. Needs a2b.h. */
EXTERN_C int func_8003D3A0(void *p)
{
    void *h;
    int n;
    switch (AT(p, short, 0x18)) {
    case 1:
        func_8003D384(p, 1, (0xFFFF / AT(p, unsigned, 0x2C)) * AT(p, int, 0x28) >> 8);
        n = AT(p, int, 0x28) + 1;
        AT(p, int, 0x28) = n;
        if (n < AT(p, int, 0x2C))
            return 0;
        if (AT(p, void *, 0x1C)) {
            void *o = func_8001CA10(0x14);
            ((S_A2B_E2D0 *)o)->init(2, 0x16, 0, 1);
            func_8001EFE4(AT(p, void *, 0x1C), o);
        }
        h = AT(p, void *, 0x14);
        AT(p, short, 0x22) = 0;
        AT(p, short, 0x18) = 0;
        AT(p, short, 4) = 0;
        if (!h)
            return 1;
        break;
    case 2:
        func_8003D384(p, 1, (0xFFFF / AT(p, unsigned, 0x2C)) * AT(p, int, 0x28) >> 8);
        n = AT(p, int, 0x28) - 1;
        AT(p, int, 0x28) = n;
        if (n > 0)
            return 0;
        if (AT(p, void *, 0x1C)) {
            void *o = func_8001CA10(0x14);
            ((S_A2B_E2D0 *)o)->init(2, 0x16, 0, 1);
            func_8001EFE4(AT(p, void *, 0x1C), o);
        }
        AT(p, short, 0x22) = 0;
        AT(p, short, 0x18) = 0;
        AT(p, short, 4) = 0;
        if (!AT(p, void *, 0x14))
            return 1;
        AT(AT(p, void *, 0x14), short, 0x52) = 0;
        h = AT(p, void *, 0x14);
        break;
    case 3:
        if (AT(p, short, 0x24) == 0) {
            func_8003D384(p, 1, (0xFFFF / AT(p, unsigned, 0x2C)) * AT(p, int, 0x28) >> 8);
            n = AT(p, int, 0x28) + 1;
            AT(p, int, 0x28) = n;
            if (n < AT(p, int, 0x2C))
                return 0;
            AT(p, short, 0x24) = 1;
        } else {
            func_8003D384(p, 1, (0xFFFF / AT(p, unsigned, 0x2C)) * AT(p, int, 0x28) >> 8);
            n = AT(p, int, 0x28) - 1;
            AT(p, int, 0x28) = n;
            if (n < 1)
                AT(p, short, 0x24) = 0;
        }
        return 0;
    default:
        return 0;
    }
    func_800392F4(h);
    return 1;
}
