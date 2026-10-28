// func_8002DD34: all but the deleter's inline base ctor: retail copies `this` ($s0) to $v1 and stores
// vt/unk4 through $v1 (one more inline level than func_8002CC60 & co., which match with the same classes).
// Needs main_a.h: void *func_8002DD34(void *p, void *it, int del) (and func_8002DED8 passing all three).
EXTERN_C void *func_8002DD34(void *p, void *it, int del)
{
    void *o;
    ((S_Iter *)it)->it = 0;
    while ((o = ((S_Iter *)it)->next()) != 0) {
        if (!func_8002DC34(p, (int)o, 0))
            del = 0;
    }
    if (del)
        new S_DeleteObj(func_8002E600((Holder *)it));
    return it;
}
