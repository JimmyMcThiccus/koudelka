#ifndef GAME_B_DECLS_B_H
#define GAME_B_DECLS_B_H

/* Generated once by tools/hoist_decls.py from the units' inline declarations; edit freely. */

/* from main_b.cpp */
EXTERN_C void func_80053964(void *self, int b);

/* from main_b.cpp */
EXTERN_C void func_80058830(void *self, void *b);

/* from main_b.cpp */
EXTERN_C void func_800581E0(void *self);

/* from main_b.cpp */
EXTERN_C void func_80057F20(void *self, unsigned short b);

/* from main_b.cpp */
EXTERN_C int func_80053880(void *self);

/* from main_b.cpp */
EXTERN_C void func_8005800C(void *self);

/* from main_b.cpp */
EXTERN_C void func_80019D40(List *l);

/* from main_b.cpp */
EXTERN_C void func_80019A6C(List *l, int b, int c);

/* from main_b.cpp */
EXTERN_C int func_80054048(void *self);

/* from main_b.cpp */
struct SV_80054F30 {
    short x, y, z, w;
};

/* from main_b.cpp */
struct Obj_80054F30 {
    char pad[0x44];
    short a;
    SV_80054F30 v;
    short d;
};

/* from main_b.cpp */
EXTERN_C void func_8005854C(void *self, int a, void *v, int d);

/* from main_b.cpp */
EXTERN_C void func_800550FC(void *self, int b);

/* from main_b.cpp */
struct Heap_800A4578 {
    void *p;
    int pad[2];
};
EXTERN_C Heap_800A4578 D_800A4578;
EXTERN_C void func_8002B27C(void *heap, void *p);

/* from main_b.cpp */
EXTERN_C void *D_800B4D84;
EXTERN_C int func_8001A6E8(void *self);

/* from main_b.cpp */
EXTERN_C void func_80053BCC(void *self, void *b, int c);

/* from main_b.cpp */
struct Rec_800557C8 {
    signed char k;
    char pad[3];
    char data[0x14];
};

/* from main_b.cpp */
struct Pair_800557C8 {
    Rec_800557C8 a;
    Rec_800557C8 b;
};

/* from main_b.cpp */
EXTERN_C char D_80013BA0[];
EXTERN_C char D_80013BB8[];
EXTERN_C void func_8001E508(void *self, int flags);

/* from main_b.cpp */
EXTERN_C int D_800B4D98;

/* from main_b.cpp */
EXTERN_C void func_8001FC78(void *p, int b, int c);

/* from main_b.cpp */
struct Str_800AE620 {
    void *p0;
    int n4;
    void *p8;
    int buf[0x20];
};
EXTERN_C Str_800AE620 D_800AE620;
EXTERN_C void func_80019920(void *a, int b);

/* from u_80056E0C.cpp */
EXTERN_C void func_8005717C(void *self);

/* from u_80056E0C.cpp */
EXTERN_C void func_8005388C(void *self, int b);

/* from u_80056E0C.cpp */
EXTERN_C void func_8002A210(void *self);
EXTERN_C void func_80056FE0(void *self);

/* from u_80056E0C.cpp */
EXTERN_C void *func_8002EEC4(void *self, void *b);
EXTERN_C void func_8002BA94(void *self);

/* from u_80056E0C.cpp */
EXTERN_C short D_800B4DA8;
EXTERN_C short D_800B4DAA;

/* from u_80056E0C.cpp */
EXTERN_C void func_80059B5C(void *p);

/* from u_80056E0C.cpp */
EXTERN_C void func_80059C54(void *self, int b, int c);
EXTERN_C int func_80059D94(void *self, int b);
EXTERN_C void func_8005CCB0(void *self, int b);

/* from u_80056E0C.cpp */
EXTERN_C int func_80058B98(void *self);
EXTERN_C int func_80058C5C(void *self);

/* from u_80056E0C.cpp */
EXTERN_C void func_80059EF8(void *self, int b);

/* from u_80056E0C.cpp */
EXTERN_C void func_80058F08(VObj<0x2C> *self, int b);

/* from u_80056E0C.cpp */
EXTERN_C void func_80027FEC(void *self, void *b);

/* from u_80056E0C.cpp */
struct V_80059584 {
    int a, b, c, d;
};

/* from u_80056E0C.cpp */
struct Obj_80059584 {
    char pad[0xC];
    V_80059584 v[2];
};

/* from u_80056E0C.cpp */
EXTERN_C void func_8001A610(void *self, int flags);

/* from u_80056E0C.cpp */
struct C4_8005AF70 {
    char v[4];
};

/* from u_80056E0C.cpp */
struct Pair_8005B424 {
    short a;
    short b;
};

/* from u_80056E0C.cpp */
struct Ent_8005B424 {
    int pad[2];
    short a;
    short b;
    int pad2;
};

/* from u_80056E0C.cpp */
struct Obj_8005B424 {
    char pad[0x14];
    Ent_8005B424 *ents;
};

/* from u_80056E0C.cpp */
struct VEnt_8005B560 {
    short delta;
    short index;
    void (*pfn)(void *, int, int);
};

/* from u_80056E0C.cpp */
struct Ent_8005B560 {
    int pad[2];
    short a;
    short b;
    int pad2;
};

/* from u_80056E0C.cpp */
struct Obj_8005B560 {
    VEnt_8005B560 *vt;
    char pad[0x10];
    Ent_8005B560 *ents;
};

/* from u_80056E0C.cpp */
EXTERN_C void *func_8005C26C(void *self, void *b, int c);
EXTERN_C void func_8002A110(void *self);

/* from u_80056E0C.cpp */
EXTERN_C void func_8005C1E8(void *self);

/* from u_80056E0C.cpp */
EXTERN_C void func_8005C088(void *self, int b, int c);

/* from u_80056E0C.cpp */
struct V_8005C238 {
    char pad[0x2C];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
};

/* from u_80056E0C.cpp */
struct V_8005C344 {
    char pad[0x2C];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
};

/* from u_80056E0C.cpp */
EXTERN_C void func_8005F120(void *self, int flags);

/* from u_80056E0C.cpp */
EXTERN_C void func_8005F1D8(void *self);

/* from u_80056E0C.cpp */
struct VEnt_8005D334 {
    short delta;
    short index;
    void (*pfn)(void *, int, int);
};

/* from u_80056E0C.cpp */
EXTERN_C void *func_8005D754(void *self, void *b);

/* from u_80056E0C.cpp */
EXTERN_C void func_8005F120(void *self, int flags);

/* from u_80056E0C.cpp */
EXTERN_C void func_8005F1D8(void *self);

/* from u_80056E0C.cpp */
struct Entry_8005DF10 {
    char pad[0x30];
    unsigned short x;
    unsigned short y;
};

/* from u_80056E0C.cpp */
struct Entry_8005DF54 {
    char pad[0x2C];
    unsigned char rgb[3];
};

/* from u_80056E0C.cpp */
struct VEnt_8005DF98 {
    short delta;
    short index;
    void (*pfn)(void *, int, int);
};

/* from u_80056E0C.cpp */
EXTERN_C void func_8005F120(void *self, int flags);

/* from u_80056E0C.cpp */
EXTERN_C void *func_8005EF58(void *self, void *b);

/* from u_80056E0C.cpp */
EXTERN_C void func_8005F120(void *self, int flags);

/* from u_80056E0C.cpp */
struct Snd_800AE640 {
    int pad[4];
};
EXTERN_C Snd_800AE640 D_800AE640;
EXTERN_C void func_8005FC78(Snd_800AE640 *self, int b, int c);

/* from u_80056E0C.cpp */
EXTERN_C char D_80010178[];
EXTERN_C char D_800111BC[];
EXTERN_C char D_80014BD0[];

/* from u_80056E0C.cpp */
EXTERN_C void func_8005FB04(Snd_800AE640 *self, int b);

/* from u_80056E0C.cpp */
EXTERN_C void func_8005F8EC(Snd_800AE640 *self);

/* from u_8005F238.cpp */
EXTERN_C void func_8005F3E0(void *self);
EXTERN_C void __builtin_delete(void *p);

/* from u_8005F238.cpp */
EXTERN_C void func_80036D8C(void *p);

/* from u_8005F238.cpp */
EXTERN_C int D_800B4DC8;
EXTERN_C int D_800B4DCC;
EXTERN_C void func_8005F47C(void);

/* from u_8005F238.cpp */
EXTERN_C int D_800B4DC4;

/* from u_8005F238.cpp */
struct Arr_8005F704 {
    int pad[2];
    unsigned int count;
    int *items;
};

/* from u_8005F238.cpp */
EXTERN_C signed char D_800AE66C[0x100];
EXTERN_C signed char D_800AE76C[0x100];

/* from u_8005F238.cpp */
EXTERN_C unsigned int func_80053BB4(void *self);
EXTERN_C void *func_80053AE4(void *out, void *self, int i);
EXTERN_C int func_8005F834(signed char *p);

/* from u_8005F238.cpp */
struct Ev_8005F87C {
    signed char v[8];
};

/* from u_8005F238.cpp */
struct Pair_80060188 {
    short a;
    short b;
};

/* from u_8005F238.cpp */
EXTERN_C void func_80060218(void *self, void *src);

/* from u_8005F238.cpp */
EXTERN_C int func_80060D9C(void *self);

/* from u_8005F238.cpp */
struct Obj_80060D9C {
    char pad[0x124];
    signed char a[0x80];
    signed char b[0x7C];
};

/* from u_8005F238.cpp */
struct Obj_800610E4 {
    char pad[0x120];
    short *out;
    char pad2[0xB0];
    short vals[1];
};

/* from u_8005F238.cpp */
struct Obj_80061114 {
    char pad[0x1D4];
    short vals[1];
};

/* from u_8005F238.cpp */
EXTERN_C void func_8008CC20(int b);

/* from u_8005F238.cpp */
struct Ent_80061164 {
    char pad[0x94];
};

/* from u_8005F238.cpp */
EXTERN_C Ent_80061164 D_800AE984[];

/* from u_8005F238.cpp */
struct Ent_80061188 {
    char pad[0x94];
};

/* from u_8005F238.cpp */
struct Obj_80061188 {
    int pad[2];
    Ent_80061188 cur;
    int sel;
    char pad2[0x184];
    Ent_80061188 e[1];
};

/* from u_8005F238.cpp */
struct Ent_800619F4 {
    char pad[0x94];
};

/* from u_8005F238.cpp */
struct Obj_800619F4 {
    char pad[0x23C];
    Ent_800619F4 e[0x30];
};

/* from u_8005F238.cpp */
struct Ent_800620D8 {
    char pad[0x18];
    unsigned char used;
    char pad2[0x7B];
};

/* from u_8005F238.cpp */
struct Blk_80062120 {
    int v[6];
};

/* from u_8005F238.cpp */
struct Clock_800A4534 {
    int pad[3];
    volatile unsigned int ticks;
};

/* from u_8005F238.cpp */
EXTERN_C Clock_800A4534 D_800A4534;

/* from u_8005F238.cpp */
EXTERN_C void func_80062160(unsigned int *out);

/* from u_8005F238.cpp */
struct Obj_80062214 {
    char pad[0xA0];
    char a[0x80];
};

/* from u_8005F238.cpp */
struct Ent_800AE86C : VObj<0x18> {
};

/* from u_8005F238.cpp */
EXTERN_C Ent_800AE86C D_800AE86C[10];

/* from u_8005F238.cpp */
EXTERN_C void func_80053928(void *self);

/* from u_80062610.cpp */
struct Entry_800627E8 {
    int w[40];
};

/* from u_80062610.cpp */
EXTERN_C Entry_800627E8 *D_800B4E30;

/* from u_80062610.cpp */
EXTERN_C int D_800B4E34;

/* from u_80062610.cpp */
EXTERN_C void func_800566E4(void *self);
EXTERN_C void func_80056874(void *self);

/* from u_80062610.cpp */
EXTERN_C void func_8008EF40(int b);

/* from u_80062610.cpp */
EXTERN_C void func_80054FE0(void *self);
EXTERN_C void func_8008EF40(int b);

/* from u_80062610.cpp */
EXTERN_C void func_800588EC(void *self, unsigned int b);

/* from u_80062610.cpp */
EXTERN_C int func_80058270(void *self, int b);

/* from u_80062610.cpp */
struct Entry_800643DC {
    char pad[0x30];
    unsigned short x;
    unsigned short y;
};

/* from u_80062610.cpp */
struct VEnt_80064428 {
    short delta;
    short index;
    void (*pfn)(void *, int, int);
};

/* from u_80062610.cpp */
EXTERN_C void func_8005F120(void *self, int flags);

/* from u_800658E0.cpp */
EXTERN_C char D_80015384[];
EXTERN_C void func_80039A88(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_80066054(void *self, int b, int c);

/* from u_800658E0.cpp */
struct Vec_80066220 {
    int x, y, z, w;
};

/* from u_800658E0.cpp */
struct Vec_80066260 {
    int x, y, z, w;
};

/* from u_800658E0.cpp */
struct Vec_80066294 {
    int x, y, z, w;
};

/* from u_800658E0.cpp */
struct SVec_800662D4 {
    short x, y, z, w;
};

/* from u_800658E0.cpp */
EXTERN_C void func_80066128(void *self, int b);

/* from u_800658E0.cpp */
struct Word_80066360 {
    char b[4];
};

/* from u_800658E0.cpp */
struct Quad_80066388 {
    int w[4];
};

/* from u_800658E0.cpp */
EXTERN_C void func_80066C7C(void *self);

/* from u_800658E0.cpp */
EXTERN_C char D_800154B4[];

/* from u_800658E0.cpp */
EXTERN_C char D_800154D4[];

/* from u_800658E0.cpp */
EXTERN_C void func_8001D024(void *self, int b);

/* from u_800658E0.cpp */
struct Mgr_800A4544 {
    int pad[4];
};
EXTERN_C Mgr_800A4544 D_800A4544;
EXTERN_C char D_80010338[];
EXTERN_C void func_8001D150(void *self, void *b);

/* from u_800658E0.cpp */
EXTERN_C short func_8008C928(int b);

/* from u_800658E0.cpp */
EXTERN_C char D_800154EC[];

/* from u_800658E0.cpp */
EXTERN_C void func_80054094(void *self, int b);
EXTERN_C void func_80067B1C(void *self, int b, void *c, void *d, int e);

/* from u_800658E0.cpp */
EXTERN_C void func_8006323C(void *self);
EXTERN_C void func_80053CD8(void *self);

/* from u_800658E0.cpp */
struct E28_80068EE8 {
    char pad[0x28];
};

/* from u_800658E0.cpp */
struct Obj_80068EE8 {
    char pad[0x1548];
    E28_80068EE8 e[0x31];
};

/* from u_800658E0.cpp */
struct E6C_800691EC {
    char pad[0x6C];
};

/* from u_800658E0.cpp */
struct E28_800691EC {
    char pad[0x28];
};

/* from u_800658E0.cpp */
struct Obj_800691EC {
    char pad[0x9C];
    E6C_800691EC a[0x31];
    E28_800691EC b[0x31];
};

/* from u_800658E0.cpp */
EXTERN_C void func_80054FC0(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_80054FE0(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_800A0D0C(void *p);

/* from u_800658E0.cpp */
struct Word_8006A04C {
    char b[4];
};

/* from u_800658E0.cpp */
// A field copy returned by value; the FIELD cast form calls memcpy instead.
struct Obj_8006A04C {
    char pad[0x20];
    Word_8006A04C w;
};

/* from u_800658E0.cpp */
EXTERN_C char D_800159C4[];

/* from u_800658E0.cpp */
EXTERN_C void func_8006B3D0(void *self, void *b);

/* from u_800658E0.cpp */
EXTERN_C void func_8006B058(void *self, int b);
EXTERN_C void func_8006B180(void *self, int b);
EXTERN_C void func_8006B0C0(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C void func_8006B08C(void *self, int b);
EXTERN_C void func_8006B1C8(void *self, int b);
EXTERN_C void func_8006B120(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C void func_8006B3D0(void *self, void *b);

/* from u_800658E0.cpp */
EXTERN_C void func_8006BB04(void *self);
EXTERN_C void *func_8006D344(void *self, void *b, int c, int d, int e);
EXTERN_C int func_8006D8EC(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_8006DA60(void *self);

/* from u_800658E0.cpp */
EXTERN_C void *func_8006C95C(void *self, void *b, int c);
EXTERN_C int func_8006CA80(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_8006B618(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C void func_8006B690(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C void func_800BE09C(void *a);
EXTERN_C void func_800BE18C(void *a, void *b);

/* from u_800658E0.cpp */
struct Tmp_8006B850 {
    int a, b;
};

/* from u_800658E0.cpp */
struct Blk_8006B8E8;
EXTERN_C void func_8006C3C8(void *self, int b, Blk_8006B8E8 *c);

/* from u_800658E0.cpp */
struct Blk_8006B8E8 {
    int v[4];
};

/* from u_800658E0.cpp */
EXTERN_C void func_8006C4EC(void *self, int b);

/* from u_800658E0.cpp */
struct V_8006B928 {
    int v[4];
};

/* from u_800658E0.cpp */
EXTERN_C V_8006B928 func_8003B310(void);

/* from u_800658E0.cpp */
EXTERN_C int func_8006BC98(void *self);
EXTERN_C void *func_800A0D2C(int size);
EXTERN_C void func_80025CE0(void *p, int b, int c);

/* from u_800658E0.cpp */
EXTERN_C void func_8008D4C0(void *p);

/* from u_800658E0.cpp */
EXTERN_C void func_8002DC34(void *self, int b, int c);

/* from u_800658E0.cpp */
EXTERN_C void *func_80066FB0(void *self, void *b, int c, int d, int e);
EXTERN_C void func_800670A4(void *self);

/* from u_800658E0.cpp */
struct Blk_8006BEA0 {
    int v[4];
};

/* from u_800658E0.cpp */
EXTERN_C int D_800B4ED8;

/* from u_800658E0.cpp */
EXTERN_C int D_800B4ED4;

/* from u_800658E0.cpp */
EXTERN_C int D_800B4ED0;

/* from u_800658E0.cpp */
EXTERN_C void func_8002BD34(void *self);
EXTERN_C void func_8003944C(void *self, void *b);

/* from u_800658E0.cpp */
struct Data_800B4D1C {
    int pad[4];
};

/* from u_800658E0.cpp */
EXTERN_C Data_800B4D1C D_800B4D1C;

/* from u_800658E0.cpp */
EXTERN_C void func_8002B518(void *self, int b, int c);

/* from u_800658E0.cpp */
struct Vec_8006C61C {
    int x, y, z, w;
};

/* from u_800658E0.cpp */
EXTERN_C char D_80015DBC[];
EXTERN_C void func_8002EC90(void *self, void *b);
EXTERN_C void func_8002EC40(void *self, void *b);

/* from u_800658E0.cpp */
struct Data_800B4C78 {
    int pad[4];
};

/* from u_800658E0.cpp */
struct Data_800B4C98 {
    int pad[4];
};

/* from u_800658E0.cpp */
EXTERN_C Data_800B4C78 D_800B4C78;
EXTERN_C Data_800B4C98 D_800B4C98;

/* from u_800658E0.cpp */
EXTERN_C void func_8002EEFC(void *self);

/* from u_800658E0.cpp */
EXTERN_C char D_80015EB8[];

/* from u_800658E0.cpp */
EXTERN_C char D_80015FD0[];
struct Sub_8006FDD8 {
    int a, b, c, d;
};
struct Obj_8006FDD8 {
    int a;
    int b;
    int c;
    Sub_8006FDD8 sub;
    int d;
};
EXTERN_C Obj_8006FDD8 *func_8006FDD8(Obj_8006FDD8 *self);
struct Flag_800AF408 {
    int v;
    int pad[2];
};
EXTERN_C Flag_800AF408 D_800AF408;
struct Flag_800AF40C {
    int v;
    int pad[2];
};
EXTERN_C Flag_800AF40C D_800AF40C;

/* from u_800658E0.cpp */
struct VEnt_8006F154 {
    short delta;
    short index;
    void (*pfn)(void *, int);
};

/* from u_800658E0.cpp */
struct VEnt_8006F268 {
    short delta;
    short index;
    void (*pfn)(void *, int);
};

/* from u_800658E0.cpp */
EXTERN_C void func_8006F194(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_8006F10C(void *self);

/* from u_800658E0.cpp */
struct Obj_8006F31C {
    int pad0;
    int b;
    char pad8[0x9C];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int b);
};

/* from u_800658E0.cpp */
struct VEnt_8006F35C {
    short delta;
    short index;
    void (*pfn)(void *, int);
};

/* from u_800658E0.cpp */
EXTERN_C void func_8006F268(void *self);

/* from u_800658E0.cpp */
struct Four_8006FE6C {
    int v[4];
};

/* from u_800658E0.cpp */
struct Obj_8006FE6C {
    int a;
    int pad;
    int b;
    Four_8006FE6C s;
    int h;
};

/* from u_800658E0.cpp */
struct Four_8006FEA4 {
    int v[4];
};

/* from u_800658E0.cpp */
struct Obj_8006FEA4 {
    int a;
    int b;
    int c;
    Four_8006FEA4 s;
    int h;
};

/* from u_800658E0.cpp */
EXTERN_C char D_80016280[];
EXTERN_C char D_80016298[];
EXTERN_C void *func_8007778C(void *self);
EXTERN_C void *func_800756F8(void *self);

/* from u_800658E0.cpp */
struct Obj_8006FEEC {
    char pad[0x44];
    short items[0x10];
};

/* from u_800658E0.cpp */
EXTERN_C int func_80077854(void *self, int b, int c);
EXTERN_C void func_80077210(void *self, void *b);
EXTERN_C void func_800766D8(void *self);

/* from u_800658E0.cpp */
struct V_80070440 {
    int a, b, c, d;
};

/* from u_800658E0.cpp */
struct V_8007049C {
    int a, b, c, d;
};

/* from u_800658E0.cpp */
struct V_800704F8 {
    int a, b, c, d;
};

/* from u_800658E0.cpp */
EXTERN_C void func_8007AD14(void *self, int b, int c, int d, int e, int f, int g);

/* from u_800658E0.cpp */
EXTERN_C int func_8007ADCC(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_8007D744(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_8006F3DC(void *self, int b, int c, int d, int e, int f);

/* from u_800658E0.cpp */
EXTERN_C void func_800DE3B8(void *self, int b, int c, int d, int e, int f, int g);

/* from u_800658E0.cpp */
EXTERN_C void func_8007D6D0(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_8007FB30(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C void func_8008022C(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_800802E0(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C int func_8007FE4C(void *self, int b, int c);

/* from u_800658E0.cpp */
EXTERN_C void func_8007FF58(void *self, int b, int c, int d);

/* from u_800658E0.cpp */
EXTERN_C int func_80080110(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C int func_80080130(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C int func_80080180(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C int func_800801D0(void *self, int b, int c);

/* from u_800658E0.cpp */
EXTERN_C void func_800DF758(void *self, int b, int c, int d);

/* from u_800658E0.cpp */
EXTERN_C void func_800DF938(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_800DF9A8(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_800DFB10(void *p);

/* from u_800658E0.cpp */
EXTERN_C void func_8007E214(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_8007E30C(void *self);

/* from u_800658E0.cpp */
struct V_800714BC {
    int a, b, c, d;
};

/* from u_800658E0.cpp */
EXTERN_C void func_800DED18(void *self, V_800714BC v);

/* from u_800658E0.cpp */
EXTERN_C void func_800DED9C(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_800DEDD4(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_800DEE50(void *self);

/* from u_800658E0.cpp */
EXTERN_C void func_800DEED4(void *self);

/* from u_800658E0.cpp */
EXTERN_C void *func_8006FEEC(void *self);
EXTERN_C void func_8006FF50(void *self, int b, int c, void *d);

/* from u_800658E0.cpp */
EXTERN_C void func_80076EF8(void *self, int b);

/* from u_800658E0.cpp */
EXTERN_C void *func_80076EA8(void *self);

/* from u_80071A74.cpp */
EXTERN_C void *func_800751AC(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_8007505C(void *self, void *node);

/* from u_80071A74.cpp */
EXTERN_C void func_80074F78(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void *func_80074E28(void *self);
EXTERN_C char D_80016270[];

/* from u_80071A74.cpp */
struct Obj_80071BDC {
    char pad[0x1C];
    int list[4];
};

/* from u_80071A74.cpp */
EXTERN_C void func_80074E44(void *self, int flags);

/* from u_80071A74.cpp */
EXTERN_C void func_800777E8(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void *func_8003912C(void *self, int b);
EXTERN_C void func_80039BEC(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_80039C88(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_80072B84(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_80074564(void *self);
EXTERN_C void func_80073960(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_800232A0(void *self, void *b);

/* from u_80071A74.cpp */
struct Tgt_80072970 {
    char pad[0x1A4];
    short a;
    short b;
    char pad2[0xB0];
    short c;
};

/* from u_80071A74.cpp */
struct View_80072970 {
    char pad[0x44];
    Tgt_80072970 *p;
};

/* from u_80071A74.cpp */
EXTERN_C void func_80044590(void *self);
EXTERN_C void func_80073960(void *self);

/* from u_80071A74.cpp */
struct Vec_8007460C {
    int x, y, z, w;
};

/* from u_80071A74.cpp */
EXTERN_C char D_80010300[];
EXTERN_C char D_800102D0[];
EXTERN_C void *func_8001CA10(int size);
EXTERN_C void func_8001EFE4(void *self, void *p);

/* from u_80071A74.cpp */
EXTERN_C void *func_8001CA10(int size);
EXTERN_C void func_8001EFE4(void *self, void *p);

/* from u_80071A74.cpp */
struct D_80074744 : VPad<0x1DC>, virtual VObj0 {
};

/* from u_80071A74.cpp */
struct A_80074744 {
    int x;
};

/* from u_80071A74.cpp */
struct B_80074744 : A_80074744 {
    int y;
};

/* from u_80071A74.cpp */
struct Vec_80074C50 {
    int x, y, z, w;
};

/* from u_80071A74.cpp */
EXTERN_C char D_800166A8[];

/* from u_80071A74.cpp */
struct Node_80074E78 {
    Node_80074E78 *next;
    Node_80074E78 *prev;
};

/* from u_80071A74.cpp */
struct Node_80074EA4 {
    Node_80074EA4 *next;
    Node_80074EA4 *prev;
};

/* from u_80071A74.cpp */
struct Node_80074EE8 {
    Node_80074EE8 *next;
};

/* from u_80071A74.cpp */
EXTERN_C void func_80074E78(Node_80074E78 *a, Node_80074E78 *b);

/* from u_80071A74.cpp */
EXTERN_C char D_800166B8[];

/* from u_80071A74.cpp */
struct Node_80074FAC {
    Node_80074FAC *next;
    Node_80074FAC *prev;
};

/* from u_80071A74.cpp */
struct List_80074FAC {
    Node_80074FAC *head;
    Node_80074FAC *cur;
};

/* from u_80071A74.cpp */
EXTERN_C int func_80074EE8(Node_80074EE8 *a);

/* from u_80071A74.cpp */
struct List_80075004 {
    Node_80074E78 *head;
    Node_80074E78 *cur;
    int count;
};

/* from u_80071A74.cpp */
EXTERN_C Node_80074EA4 *func_80074EA4(Node_80074EA4 *head);

/* from u_80071A74.cpp */
EXTERN_C void *func_800752B8(void *self);

/* from u_80071A74.cpp */
struct Node_800753F8 {
    Node_800753F8 *next;
    Node_800753F8 *prev;
};

/* from u_80071A74.cpp */
struct Node_80075620 {
    Node_80075620 *next;
    Node_80075620 *prev;
};

/* from u_80071A74.cpp */
EXTERN_C char D_800167F8[];

/* from u_80071A74.cpp */
struct Obj_80075744 {
    void *vtable;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

/* from u_80071A74.cpp */
EXTERN_C void func_8007589C(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_80075EC8(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_8003546C(void *a, void *b);
EXTERN_C void func_8003714C(void *a);

/* from u_80071A74.cpp */
EXTERN_C void func_80076370(void *self);

/* from u_80071A74.cpp */
EXTERN_C char D_80016878[];

/* from u_80071A74.cpp */
EXTERN_C char D_80016868[];
EXTERN_C void *func_80074F58(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_80076E60(void *self);

/* from u_80071A74.cpp */
EXTERN_C void *func_800752B8(void *self);

/* from u_80071A74.cpp */
EXTERN_C void *func_800785DC(void *self);
EXTERN_C void *func_80076DC4(void *self);

/* from u_80071A74.cpp */
EXTERN_C int func_80075448(void *self, void *b);

/* from u_80071A74.cpp */
EXTERN_C void func_80078564(void *self);

/* from u_80071A74.cpp */
EXTERN_C void *func_800773B0(void *self);

/* from u_80071A74.cpp */
EXTERN_C void *func_800774D0(void *self, int b);
EXTERN_C void *func_80077478(void *self);

/* from u_80071A74.cpp */
EXTERN_C void *func_800751AC(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_8007505C(void *self, void *node);

/* from u_80071A74.cpp */
EXTERN_C char D_80016BD0[];

/* from u_80071A74.cpp */
EXTERN_C void func_800A0D0C(void *p);

/* from u_80071A74.cpp */
EXTERN_C int func_80077C68(void *self);
EXTERN_C int func_80077EA8(void *self);

/* from u_80071A74.cpp */
EXTERN_C char D_80016BC0[];

/* from u_80071A74.cpp */
EXTERN_C void func_800786A0(void *self);
EXTERN_C void func_80074F78(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_800CB174(void *self, int b, int c);

/* from u_80071A74.cpp */
EXTERN_C void func_800CB8EC(void *p);
EXTERN_C void func_8001FC78(void *p, int b, int c);

/* from u_80071A74.cpp */
struct D_80079104 : VPad<0xF8>, virtual VObj0 {
};

/* from u_80071A74.cpp */
EXTERN_C void func_8007A1F4(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_8007B538(void *p, int b, int c, int d, int e, int f);

/* from u_80071A74.cpp */
struct Base0_80079824 {
    char pad[0xB8];
};

/* from u_80071A74.cpp */
struct Base1_80079824 {
    int unk0;
};

/* from u_80071A74.cpp */
struct Derived_80079824 : Base0_80079824, Base1_80079824 {
};

/* from u_80071A74.cpp */
EXTERN_C void func_8007E5B0(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_8007EDAC(void *self, int b, int c);

/* from u_80071A74.cpp */
EXTERN_C void func_8007A1F4(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_80079F6C(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C char D_80017370[];

/* from u_80071A74.cpp */
EXTERN_C void func_8007AF04(void *self);

/* from u_80071A74.cpp */
EXTERN_C void *func_8007A9DC(void *self);

/* from u_80071A74.cpp */
struct Set_8007AFD0 {
    int unk0;
    int count;
    int items[3];
};

/* from u_80071A74.cpp */
struct Set_8007B014 {
    int unk0;
    int count;
    int items[3];
};

/* from u_80071A74.cpp */
struct Obj_8007B058 {
    int pad;
    int count;
    void *items[1];
};

/* from u_80071A74.cpp */
EXTERN_C void func_800BFABC(void *self, void *b);

/* from u_80071A74.cpp */
EXTERN_C void func_80019D40(List *l);

/* from u_80071A74.cpp */
struct Global_800B4C18 {
    void *p;
    int pad[2];
};
EXTERN_C Global_800B4C18 D_800B4C18;
EXTERN_C void *func_800758F8(void *self, int b, void *c, void *d);
EXTERN_C void func_8001E848(void *self, void *b);

/* from u_80071A74.cpp */
EXTERN_C void func_800766F8(void *self, int b, int c, int d, int e);

/* from u_80071A74.cpp */
EXTERN_C void func_80076848(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_8007698C(void *self, int b, int c, int d);

/* from u_80071A74.cpp */
EXTERN_C int func_8007669C(void *self, int b, int c);

/* from u_80071A74.cpp */
EXTERN_C void func_800766D8(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_80042430(void *a, void *b, int c, int d);
EXTERN_C void func_8007C070(void *self, int b);

/* from u_80071A74.cpp */
struct Obj_8007BFA8 {
    int pad[2];
    void *items[3];
};

/* from u_80071A74.cpp */
EXTERN_C void func_800CF080(void *a, void *b, int c);

/* from u_80071A74.cpp */
EXTERN_C void func_8007C0A8(void *self, int b);
EXTERN_C void func_8007C3C8(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C char D_800172E8[];
EXTERN_C char D_800172B0[];
EXTERN_C char D_800172F8[];
EXTERN_C void func_8007A994(void *self, int b);
EXTERN_C void func_8006F0B0(void *self, int flags);

/* from u_80071A74.cpp */
EXTERN_C void func_8007DEE8(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_8007DEE8(void *self, int b);

/* from u_80071A74.cpp */
struct Global_800B4D40 {
    void *p;
    int pad[2];
};
EXTERN_C Global_800B4D40 D_800B4D40;
EXTERN_C void func_8007A400(void *self, int b);
EXTERN_C void func_800518A8(void *a, int b, int c, int d);

/* from u_80071A74.cpp */
EXTERN_C void func_800CEE18(void *a);
EXTERN_C void func_800CEFE8(void *a);

/* from u_80071A74.cpp */
EXTERN_C void func_8007B0C8(void *p);
EXTERN_C void func_8007BB48(void *p, int b, int c);

/* from u_80071A74.cpp */
struct Base0_8007CC14 {
    char pad[0xB8];
};

/* from u_80071A74.cpp */
struct Base1_8007CC14 {
    int unk0;
};

/* from u_80071A74.cpp */
struct Derived_8007CC14 : Base0_8007CC14, Base1_8007CC14 {
};

/* from u_80071A74.cpp */
EXTERN_C int func_8007CAA8(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_8007CC60(void *self, int b, int c, int d);

/* from u_80071A74.cpp */
struct Blk_8007D6D0 {
    int v[4];
};
EXTERN_C void func_8006FAC0(void *self, void *a, void *b, void *c, void *d, void *e, void *f, Blk_8007D6D0 g, int h);

/* from u_80071A74.cpp */
EXTERN_C void func_80084B78(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_8007FE1C(void *self, int b);
EXTERN_C void func_800DE97C(void *self, int b);
EXTERN_C void func_8007DE74(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_80084674(void *self);

/* from u_80071A74.cpp */
struct Base0_8007DE74 {
    char pad[0xB8];
};

/* from u_80071A74.cpp */
struct Base1_8007DE74 {
    int unk0;
    int unk4;
    void *unk8;
    void *unkC;
    void *unk10;
};

/* from u_80071A74.cpp */
struct Derived_8007DE74 : Base0_8007DE74, Base1_8007DE74 {
};

/* from u_80071A74.cpp */
struct Slot_8007E658 {
    void *p;
    int pad;
};

/* from u_80071A74.cpp */
struct Obj_8007E658 {
    char pad[0x1C4];
    Slot_8007E658 slots[4];
};

/* from u_80071A74.cpp */
EXTERN_C void func_8007D994(void *p);

/* from u_80071A74.cpp */
EXTERN_C int func_8006F52C(void *self, int *a, int *b);

/* from u_80071A74.cpp */
EXTERN_C int func_8006F5B4(void *self, int *a, int *b, int *c);

/* from u_80071A74.cpp */
EXTERN_C int func_8006F570(void *self, int *a, int *b);

/* from u_80071A74.cpp */
EXTERN_C void func_8007DDCC(char *p);

/* from u_80071A74.cpp */
EXTERN_C void func_8007A1F4(void *self, int b);

/* from u_80071A74.cpp */
struct Base0_8007FB30 {
    char pad[0xB8];
};

/* from u_80071A74.cpp */
struct Base1_8007FB30 {
    int unk0;
    int unk4;
    void *unk8;
};

/* from u_80071A74.cpp */
struct Derived_8007FB30 : Base0_8007FB30, Base1_8007FB30 {
};

/* from u_80071A74.cpp */
EXTERN_C int func_8007FE4C(void *self, int b, int c);

/* from u_80071A74.cpp */
EXTERN_C void func_8001A744(void *self, void *p);

/* from u_80071A74.cpp */
EXTERN_C char D_800171B0[];

/* from u_80071A74.cpp */
EXTERN_C void func_800DF6F0(void *self);

/* from u_80071A74.cpp */
EXTERN_C char D_80017190[];
EXTERN_C void *func_800756F8(void *self);

/* from u_80071A74.cpp */
struct Obj_80080468 {
    void *vtable;
    int unk4, unk8, unkC, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38;
    int pad[5];
    int unk50, unk54;
};

/* from u_80071A74.cpp */
EXTERN_C void func_80080828(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_800808AC(void *self);
EXTERN_C int func_8008D1F4(int a, int b);
EXTERN_C void func_800806F4(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_8008ECB4(int a);
EXTERN_C void func_8007EF90(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_800852DC(void *self, int b);

/* from u_80071A74.cpp */
EXTERN_C void func_8008316C(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_800DFB10(void *p);

/* from u_80071A74.cpp */
struct Arr_80080D4C {
    char pad[0x8];
    int items[1];
};

/* from u_80071A74.cpp */
// The 0x328 member points at a class whose second base sits at +0xB8; the
// upcast's null check is what retail compiles.
struct Base0_80080D74 {
    char pad[0xB8];
};

/* from u_80071A74.cpp */
struct Base1_80080D74 {
    int unk0;
    int unk4;
    int unk8;
};

/* from u_80071A74.cpp */
struct Derived_80080D74 : Base0_80080D74, Base1_80080D74 {
};

/* from u_80071A74.cpp */
EXTERN_C void func_80080828(void *self);

/* from u_80071A74.cpp */
EXTERN_C void func_8001A610(void *self, int flags);

/* from u_80071A74.cpp */
EXTERN_C char D_800171C0[];

/* from u_80071A74.cpp */
EXTERN_C void func_8001A610(void *self, int flags);

/* from u_80071A74.cpp */
EXTERN_C char D_800171D0[];

/* from u_80071A74.cpp */
struct Cmd_800810B8 {
    unsigned char a, b, c, d;
};

/* from u_80071A74.cpp */
struct Obj_800810B8 {
    char pad[0x3B0];
    Cmd_800810B8 q[0x20];
};

/* from u_80071A74.cpp */
struct Cmd_80081114 {
    unsigned char a, b, c, d;
};

/* from u_80071A74.cpp */
struct Obj_80081114 {
    char pad[0x3B0];
    Cmd_80081114 q[0x20];
};

/* from u_80071A74.cpp */
struct Cmd_80081190 {
    unsigned char a, b, c, d;
};

/* from u_80071A74.cpp */
struct Obj_80081190 {
    char pad[0x3B0];
    Cmd_80081190 q[0x20];
};

/* from u_80071A74.cpp */
struct Cmd_80081204 {
    unsigned char a, b, c, d;
};

/* from u_80071A74.cpp */
struct Obj_80081204 {
    char pad[0x3B0];
    Cmd_80081204 q[0x20];
};

/* from u_80071A74.cpp */
struct Cmd_800812E4 {
    unsigned char a, b, c, d;
};

/* from u_80071A74.cpp */
struct Obj_800812E4 {
    char pad[0x3B0];
    Cmd_800812E4 q[0x20];
};

/* from u_80071A74.cpp */
struct Cmd_80081350 {
    unsigned char a, b, c, d;
};

/* from u_80071A74.cpp */
struct Obj_80081350 {
    char pad[0x3B0];
    Cmd_80081350 q[0x20];
};

/* from u_80071A74.cpp */
struct Cmd_800813BC {
    unsigned char a, b, c, d;
};

/* from u_80071A74.cpp */
struct Obj_800813BC {
    char pad[0x3B0];
    Cmd_800813BC q[0x20];
};

/* from u_80071A74.cpp */
EXTERN_C void *memset(void *dst, int c, unsigned int n);

/* from u_80071A74.cpp */
struct Obj_800815B4 {
    char pad[0x8];
    int items[1];
};

/* from u_80071A74.cpp */
EXTERN_C char D_80017360[];

/* from u_80071A74.cpp */
struct Obj_80081620 {
    void *vtable;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
};

/* from u_80071A74.cpp */
EXTERN_C char D_80017380[];

/* from u_80071A74.cpp */
EXTERN_C char D_800173C0[];

/* from u_80071A74.cpp */
EXTERN_C void func_800817C8(void *self);

/* from u_80071A74.cpp */
EXTERN_C char D_80017390[];
EXTERN_C char D_800173A8[];
struct Global_800AFA88 {
    int v;
    int pad[2];
};
EXTERN_C Global_800AFA88 D_800AFA88;
EXTERN_C void *func_8001E40C(void *self, int b, int c, int d, int e);

/* from u_80071A74.cpp */
struct Obj_80081FF8 {
    void *vtable;
    char pad[0x88];
    void *vt8C;
};

/* from u_80071A74.cpp */
EXTERN_C void *func_80081748(void *self);

/* from u_80082174.cpp */
EXTERN_C void func_80081DCC(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_80081CB8(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_80081BA4(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_80081A74(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_80081970(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_80081820(Global_800AFA74 *p, int a, int b, int c, int d, int e);

/* from u_80082174.cpp */
EXTERN_C void func_800817C8(void *self);

/* from u_80082174.cpp */
struct Obj_80082470 {
    short items[0x1A];
    int unk34;
    int unk38;
};

/* from u_80082174.cpp */
EXTERN_C void func_800824C8(void *self);

/* from u_80082174.cpp */
EXTERN_C unsigned short D_800173E0[][10][16];

/* from u_80082174.cpp */
struct Obj_80082670 {
    short items[0x1A];
    int mode;  /* 0x34 */
};

/* from u_80082174.cpp */
EXTERN_C char D_80017758[];

/* from u_80082174.cpp */
struct Obj_800826C0 {
    void *vtable;
    int unk4;
    char unk8;
    char unk9;
    short unkA;
    int unkC, unk10, unk14, unk18, unk1C, unk20;
};

/* from u_80082174.cpp */
struct Obj_80082714 {
    void *vtable;
    int unk4;
    char unk8;
    char unk9;
    short unkA;
    int unkC, unk10, unk14, unk18, unk1C, unk20;
};

/* from u_80082174.cpp */
EXTERN_C char D_80017748[];

/* from u_80082174.cpp */
EXTERN_C void func_80083310(void *self);

/* from u_80082174.cpp */
EXTERN_C void func_80083F40(void *self, int b);
EXTERN_C void func_80083310(void *self);

/* from u_80082174.cpp */
EXTERN_C void func_80083310(void *self);

/* from u_80082174.cpp */
EXTERN_C void func_80083310(void *self);

/* from u_80082174.cpp */
EXTERN_C void func_80083310(void *self);

/* from u_80082174.cpp */
EXTERN_C int func_800833F8(void *self);

/* from u_80082174.cpp */
struct Obj_80083EB4 {
    char pad[0x9A];
    short items[0x20];
};

/* from u_80082174.cpp */
struct Obj_80083ED8 {
    char pad[0x9A];
    short ids[0x20];
};

/* from u_80082174.cpp */
struct Obj_80084090 {
    char pad[0xC];
    int items[1];
};

/* from u_80082174.cpp */
EXTERN_C void func_8001A610(void *self, int flags);

/* from u_80082174.cpp */
struct Obj_800840F8 {
    short items[1];
};

/* from u_80082174.cpp */
EXTERN_C void func_800846EC(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_8003D68C(void *a, int b, void *c, int d, int e);

/* from u_80082174.cpp */
EXTERN_C void func_8008299C(void *p, int b, int c, int d, int e, int f, int g);
EXTERN_C void func_80082E14(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_80042838(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_80085168(void *self, int b);
EXTERN_C void func_80084F58(void *self, int b);
EXTERN_C void func_80084D58(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_8004377C(void *self, short b);

/* from u_80082174.cpp */
EXTERN_C void func_80043740(void *self, short b);

/* from u_80082174.cpp */
EXTERN_C void func_800437A4(void *self, int b);
EXTERN_C void func_800437CC(void *self, int b, int c, int d);

/* from u_80082174.cpp */
EXTERN_C void func_80039DD8(void *p);

/* from u_80082174.cpp */
EXTERN_C void func_800435AC(void *self);

/* from u_80082174.cpp */
EXTERN_C void func_800CDAC8(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_800CDAE8(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_800832F0(void *self);
EXTERN_C void func_800CF2D0(void *p, int b);

/* from u_80082174.cpp */
struct Base0_80085820 {
    char pad[0x2A0];
};

/* from u_80082174.cpp */
struct Base1_80085820 {
    int unk0;
};

/* from u_80082174.cpp */
struct Derived_80085820 : Base0_80085820, Base1_80085820 {
};

/* from u_80082174.cpp */
struct S8_80085A08 {
    char v[8];
};

/* from u_80082174.cpp */
struct Pair_80085A60 {
    short a;
    short b;
};

/* from u_80082174.cpp */
EXTERN_C char D_80017BA4[];

/* from u_80082174.cpp */
struct S4_80085B28 {
    char v[4];
};

/* from u_80082174.cpp */
EXTERN_C char D_80017B94[];

/* from u_80082174.cpp */
EXTERN_C void func_80074F78(void *self, int b);

/* from u_80082174.cpp */
struct Derived_80085D7C;
EXTERN_C void func_80085D7C(Derived_80085D7C *self);
EXTERN_C void func_80085DC0(void *self);
EXTERN_C void func_80085C60(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C void func_8008299C(void *p, int b, int c, int d, int e, int f, int g);

/* from u_80082174.cpp */
struct Base0_80085D7C {
    char pad[0x2A0];
};

/* from u_80082174.cpp */
struct Base1_80085D7C {
    int unk0;
};

/* from u_80082174.cpp */
struct Derived_80085D7C : Base0_80085D7C, Base1_80085D7C {
};

/* from u_80082174.cpp */
struct Base0_80085DC0 {
    char pad[0x2A0];
};

/* from u_80082174.cpp */
struct Base1_80085DC0 {
    int unk0;
};

/* from u_80082174.cpp */
struct Derived_80085DC0 : Base0_80085DC0, Base1_80085DC0 {
};

/* from u_80082174.cpp */
struct Derived_80085F90;
EXTERN_C void func_80085F90(Derived_80085F90 *self);
EXTERN_C void func_80085FD4(void *self);
EXTERN_C void func_80085E74(void *self, int b);

/* from u_80082174.cpp */
struct Base0_80085F90 {
    char pad[0x2A0];
};

/* from u_80082174.cpp */
struct Base1_80085F90 {
    int unk0;
};

/* from u_80082174.cpp */
struct Derived_80085F90 : Base0_80085F90, Base1_80085F90 {
};

/* from u_80082174.cpp */
struct Base0_80085FD4 {
    char pad[0x2A0];
};

/* from u_80082174.cpp */
struct Base1_80085FD4 {
    int unk0;
};

/* from u_80082174.cpp */
struct Derived_80085FD4 : Base0_80085FD4, Base1_80085FD4 {
};

/* from u_80082174.cpp */
struct Derived_800861A4;
EXTERN_C void func_800861A4(Derived_800861A4 *self);
EXTERN_C void func_800861E8(void *self);
EXTERN_C void func_80086088(void *self, int b);

/* from u_80082174.cpp */
struct Base0_800861A4 {
    char pad[0x2A0];
};

/* from u_80082174.cpp */
struct Base1_800861A4 {
    int unk0;
};

/* from u_80082174.cpp */
struct Derived_800861A4 : Base0_800861A4, Base1_800861A4 {
};

/* from u_80082174.cpp */
struct Base0_800861E8 {
    char pad[0x2A0];
};

/* from u_80082174.cpp */
struct Base1_800861E8 {
    int unk0;
};

/* from u_80082174.cpp */
struct Derived_800861E8 : Base0_800861E8, Base1_800861E8 {
};

/* from u_80082174.cpp */
struct Pair_80086338 {
    short a;
    short b;
};

/* from u_80082174.cpp */
struct Pair_80086350 {
    short a;
    short b;
};

/* from u_80082174.cpp */
struct Quad_80086380 {
    short a;
    short b;
    short c;
    short d;
};

/* from u_80082174.cpp */
struct Vec_800863D0 {
    int v[4];
};

/* from u_80082174.cpp */
struct Obj_8008647C {
    char pad[0x4F6];
    short items[1];
};

/* from u_80082174.cpp */
EXTERN_C char D_80017C00[];
EXTERN_C void func_8001AA28(void *self, int b);

/* from u_80082174.cpp */
struct Vec_80086670 {
    short v[5];
};
struct Pair_800867B0 {
    int a;
    int b;
};
struct Snap_800867B0 {
    unsigned short unk0;
    unsigned short unk2;
    int unk4;
    int unk8;
    Pair_800867B0 unkC;
    Vec_80086670 unk14;
    unsigned char unk1E;
};

/* from u_80082174.cpp */
EXTERN_C Vec_80086670 func_80086670(Vec_80086670 &a, void *b);

/* from u_80082174.cpp */
struct Obj_80086DB4 {
    char pad0[0x6];
    short unk6[5];
    char pad10[0x6];
    short unk16[5];
    char pad20[0x50];
    signed char unk70[5];
    char pad75[0xD];
    char unk82;
};

/* from u_80082174.cpp */
EXTERN_C void func_800898F0(void *self);
EXTERN_C void func_8008655C(short *p);
struct Obj_80086DB4;
EXTERN_C void func_80086DB4(Obj_80086DB4 *self);

/* from u_80082174.cpp */
EXTERN_C void func_80089178(void *self, int b);
EXTERN_C void func_80087880(void *self, int b);

/* from u_80082174.cpp */
struct Hist_80089024 {
    short v[4];
};

/* from u_80082174.cpp */
struct Hist_8008906C {
    short v[4];
};

/* from u_80082174.cpp */
struct Bytes4_800890B4 {
    char c[4];
};

/* from u_80082174.cpp */
EXTERN_C void *func_8008672C(char *p);
EXTERN_C void func_800D9218(void *self, int b);

/* from u_80082174.cpp */
union Col_800899AC {
    unsigned char c[8];
    int w[2];
};
EXTERN_C unsigned char *func_800898FC(unsigned char *a, signed char *b);

/* from u_80082174.cpp */
EXTERN_C unsigned char *func_80089954(unsigned char *a, signed char *b);

/* from u_80082174.cpp */
// Eight bytes divided by d, returned by value. Needs maspsx --expand-div (the ASPSX zero checks).
struct Bytes8_80089A4C { unsigned char b[8]; int align[0]; };

/* from u_80082174.cpp */
EXTERN_C int rand(void);

/* from u_80082174.cpp */
EXTERN_C signed char *func_80089DB8(signed char *a, signed char *b);

/* from u_80082174.cpp */
EXTERN_C signed char *func_80089E14(signed char *a, signed char *b);

/* from u_80082174.cpp */
// Signed twin of func_80089A4C.
struct SBytes8_80089F10 { signed char b[8]; int align[0]; };

/* from u_80082174.cpp */
EXTERN_C void func_80023F50(void *self, int b);

/* from u_80082174.cpp */
struct Base0_80089F84 {
    char pad[0x58];
};

/* from u_80082174.cpp */
struct Base1_80089F84 {
    int unk0;
};

/* from u_80082174.cpp */
struct Derived_80089F84 : Base0_80089F84, Base1_80089F84 {
};

/* from u_80082174.cpp */
EXTERN_C void func_800870E4(void *self, int b);

/* from u_80082174.cpp */
EXTERN_C int func_8008B444(int n);

/* from u_80082174.cpp */
struct Hdr_8008B5B4 {
    int w[9];
};
struct Pair16_8008B5B4 {
    unsigned short a;
    unsigned short b;
};
struct Pair32_8008B5B4 {
    int a;
    int b;
};
struct Packed_8008B5B4 {
    Hdr_8008B5B4 hdr;
    Pair16_8008B5B4 e[9];
};
struct Unpacked_8008B5B4 {
    Hdr_8008B5B4 hdr;
    Pair32_8008B5B4 e[9];
};

EXTERN_C char D_80016808[];
struct Col_80065870 {
    short r, g, b, a;
};
EXTERN_C Col_80065870 D_800B4E38;
EXTERN_C Col_80065870 D_800B4E40;
EXTERN_C Col_80065870 D_800B4E48;
EXTERN_C Col_80065870 D_800B4E50;
EXTERN_C char D_80014C38[];
EXTERN_C void func_8008E504(void *p);
EXTERN_C char D_80013B70[];

#endif /* GAME_B_DECLS_B_H */
