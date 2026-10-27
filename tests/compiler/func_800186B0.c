typedef struct S { void *p; int data[1]; } S;
extern void func_800198E0(void *a, int b, int c);
S *func_800186B0(S *s)
{
    s->p = s->data;
    func_800198E0(s->data, 2, 0);
    return s;
}
