// func_800CAF84: logic matches, but retail's `%` carries ASPSX's divide-by-zero and
// overflow checks (break 7 / break 6). tools/cc.py runs maspsx without --expand-div,
// so the build emits a bare div (built 56 bytes vs retail 92).
#include "field/field.h"

EXTERN_C int func_800CAF84(Unk_800CAF84* p, int a) {
    int n = first(&p->unk84)->unk4 - 1;
    return (a + n - 1) % n + 1;
}
