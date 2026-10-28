// func_8001F9C0 (u_8001F1A8): 5 instructions off inside the inlined iterator next(): retail loads
// list->data first and shifts idx after (lw v0,0(v1); sll v1,a0,2), GCC here shifts first. Tried data[idx],
// *(data+idx), byte offsets, a local for data, if/else forms. Types: S_TimerIter/S_List in h_u_8001F1A8.h.
extern "C" void func_8001F9C0()
{
    Item *it;
    if (D_800B4C34) {
        func_80018AF4();
        ((S_TimerIter *)D_800B4C34)->idx = 0;
        while ((it = ((S_TimerIter *)D_800B4C34)->next()) != 0)
            it->run();
        func_80018B18();
    }
}
