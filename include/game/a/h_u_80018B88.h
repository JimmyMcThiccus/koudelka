#ifndef GAME_A_H_U_80018B88_H
#define GAME_A_H_U_80018B88_H

/* Declarations for src/main/u_80018B88.cpp only. */

struct S_Block {
    S_Block *next;
    unsigned int size;
};
EXTERN_C S_Block *D_800B4EE8;
EXTERN_C void func_80018BE4(S_Block *b);
static inline void link_80018C1C(S_Block *p, S_Block *n)
{
    p->next = n;
    func_80018BE4(p);
}

struct S_Array {
    int *data;
    int count;
    int cap;
    int grow;
    int unk10;
};
struct S_VDel {
    virtual ~S_VDel();
};
struct S_Own {
    void **vt;
    S_VDel *ptr;
};
struct S_Holder24 {
    S_Array *vb;
    int unk4;
    S_Array *unk8;
};
struct S_80019158 {
    void **vt;
    int unk4;
    int unk8;
    int unkC;
    S_Own m10;
    S_Own m18;
    int unk20;
    S_Holder24 h;
    S_Array list;
    int unk44;
};
struct S_Link {
    int unk0;
    S_Link *next;
};
struct S_8001921C {
    int unk0;
    S_VDel *unk4;
    S_VDel *unk8;
};
EXTERN_C void *D_800100D0[];
EXTERN_C void *D_80010328[];
EXTERN_C void *func_800A0D2C(int size);
EXTERN_C void func_800A0D0C(void *p);

#endif /* GAME_A_H_U_80018B88_H */
