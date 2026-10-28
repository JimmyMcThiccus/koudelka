/* func_8003ED10: near miss. GCC keeps the difference in a new register instead of reusing $a1. Uses include/game/a2/a2.h (AT etc.). */
EXTERN_C int func_8003ED10(void *p, int b, int c, int d, int e)
{
    int neg = 0;
    int x;
    if (d) {
        x = b - c;
        if (x < 0) {
            neg = 1;
            x = ~x + neg;
        }
        x = ((x << 4) * e) / d >> 4;
        if (neg)
            x = ~x + 1;
        return x;
    }
    return neg;
}
