// func_800B76E4: 3 differ: retail epilogue is `addiu sp; jr ra; nop` (delay slot unfilled), as in other functions near the start of the overlay (func_800B7E0C, func_800B7728). Body matches; neither CC1PSX nor -O1/-fno-* flags reproduce it.
#include "common.h"
#include "capture/capture.h"

EXTERN_C void func_8008BE08(void *);
EXTERN_C void func_8008C3AC(void *);
EXTERN_C void func_800B76E4(char *p)
{
    func_8008BE08(*(void **)(p + 0x124));
    *(void **)(p + 0x124) = 0;
    *(void **)(p + 0x128) = 0;
    func_8008C3AC(*(void **)(p + 0x10));
    *(void **)(p + 0x10) = 0;
}
