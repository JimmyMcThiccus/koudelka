struct Item { virtual void run(); };
struct List { int pad; int count; };
struct Holder : virtual List { };
extern void func_80094990();
extern Item *func_80019F64(List *l, int i);
inline int count_of(List *l) { return l->count; }
static int s_count;
void func_800186E8(Holder *h)
{
    if (++s_count == 1) {
        func_80094990();
        for (int i = 0; i < count_of(h); i++)
            func_80019F64(h, i)->run();
    }
}
