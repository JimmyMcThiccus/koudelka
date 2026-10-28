/* func_80032ED4: near miss. 35 differing: retail tests `xori v0,v0,1; bnez` on the bool result of func_8003074C and keeps q in v1 (`addu v1,s1`); the 5th-arg null test is the same shape as func_8003479C (`bnez` over the zero store). Uses include/game/a2/a2.h. */
EXTERN_C bool func_8003074C(char *p, char **q);
EXTERN_C int func_80032ED4(char *p, char **q)
{
    if (func_8003074C(p, q)) {
        char **r = q;
        return func_8003479C(p ? p + 0x34 : 0, r[0] ? r[0] + 0x34 : 0, r[1] ? r[1] + 0x34 : 0, r[2] ? r[2] + 0x34 : 0, !q[3] ? 0 : q[3] + 0x34);
    }
    return 0;
}
