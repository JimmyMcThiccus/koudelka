// func_80019D5C: dynamic array move(from, to, n). Same code, register allocation differs: retail keeps the array in
// $s4 (v in $s2, tmp in $s3); here the array gets $s2. ~30 instructions (all register numbers).
struct S_Array { int *data; int count; int cap; int grow; int unk10; };
extern "C" void func_80019D5C(void *p, int from, int to, int n)
{
    int v;
    int *tmp;
    S_Array *a = (S_Array *)p;
    if (from < 0)
        from += a->count;
    if (from < a->count && from >= 0) {
        if (to < 0)
            to += a->count;
        if (to < a->count && to >= 0 && from != to && !a->unk10 && n > 0) {
            if (n == 1) {
                v = a->data[from];
                if (from < to)
                    func_8001A8F0(&a->data[from], (int)(&a->data[from] + 1), to - from);
                else
                    func_8001A970(&a->data[to] + 1, &a->data[to], from - to);
                a->data[to] = v;
            } else {
                tmp = (int *)func_800A0D2C(n * 4);
                func_8001A8F0(tmp, (int)&a->data[from], n);
                if (from < to)
                    func_8001A8F0(&a->data[from], (int)(&a->data[from] + n), to - from);
                else
                    func_8001A970(&a->data[to] + 1, &a->data[to], from - to);
                func_8001A8F0(&a->data[to], (int)tmp, n);
                if (tmp)
                    func_800A0D0C(tmp);
            }
        }
    }
}
