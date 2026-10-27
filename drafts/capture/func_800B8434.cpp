// func_800B8434: 0x7E0-byte copy; retail is a 0x7E-iteration loop copying 16 bytes with the first word loaded last; struct assignment gives a different block-move loop.
#include "common.h"
#include "capture/capture.h"

struct Big { int w[0x1F8]; };
EXTERN_C void func_800B8434(Big *d, Big *s) { *d = *s; }
