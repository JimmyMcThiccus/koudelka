#ifndef GAME_B_FIELD_H
#define GAME_B_FIELD_H

/* Member at a byte offset, for objects whose layout isn't recovered yet:
   FIELD_AT(self, short, 0x5CA) is the short at self+0x5CA. */
#ifndef FIELD_AT
#define FIELD_AT(p, type, off) (*(type *)((char *)(p) + (off)))
#endif

#endif /* GAME_B_FIELD_H */
