#ifndef SHARED_EXE_H
#define SHARED_EXE_H

/* One prototype for each EXE function used outside its own area.

   - Decompiled functions: the definition's signature, with pointers to area-specific types written as
     void * (C++ won't convert one area's struct pointer to another's). Types passed by value or by
     reference keep their name and are forward-declared below; they are defined in the owning area.
   - Functions still in asm: read from the asm and the callers (argument registers, $v0 at return).
   - A unit never sees the entries for functions it defines with other types (or as C++ members): those
     sit under #ifndef EXE_H_IN_<unit>, and each EXE unit defines its macro before including this file.
   - A caller that only matches with another prototype keeps a local alias
     (EXTERN_C ... asm("func_X")) with a comment saying why. */

/* The dynamic array (shared/vbase.h). The array functions take it as List * so that a Holder converts to
   its virtual base, null checks included, as in retail. */
struct List;

struct B16_B;
struct Blk_8007D6D0;
struct Pair_80085A60;
struct S8_80085A08;
struct SBytes8_80089F10;
struct SV2C_80055020;
struct SV2_80069F74;
struct S_A2_Pt;
struct S_A2_RgbC;
struct S_A2_Sv;
struct S_A2_Sv0;
struct S_A2_V4;
struct S_Box2;
struct S_Pt2;
struct S_Rgb;
struct T_VEC;
struct Unk_Pt;
struct V4_80085578;
struct Vec_80086670;

/* main_a.cpp */
EXTERN_C void func_80018AF4(void);
EXTERN_C void func_80018B18(void);
#ifndef EXE_H_IN_main_a
EXTERN_C void func_800186E8(void *h);
#endif

/* u_8001986C.cpp */
EXTERN_C void func_800198AC(void *p, int a);
EXTERN_C void *func_800198E0(void *v, int n, int grow);
EXTERN_C void func_80019A6C(void *p, int v, int i);
EXTERN_C int func_80019C68(void *p, int i);
EXTERN_C void func_8001A610(void *v, int flags);
EXTERN_C int func_8001A678(void *v, int a);
EXTERN_C void func_8001B2D8(void *p);
#ifndef EXE_H_IN_u_8001986C
EXTERN_C void func_80019920(List *l, int flags);
EXTERN_C int func_80019A18(void *p, int v);
EXTERN_C int func_80019C24(List *a, int v);
EXTERN_C int func_80019CFC(List *a, int v);
EXTERN_C void func_80019D40(void *p);
EXTERN_C void *func_80019F64(List *l, int i);
EXTERN_C int func_8001A6E8(void *p);
EXTERN_C void *func_8001A744(void *head, void *n);
EXTERN_C void *func_8001A864(void *p, void *a);
EXTERN_C void *func_8001AA28(void *p, int n);
EXTERN_C void func_8001AA68(void *p, void *q);
EXTERN_C void func_8001AB50(void *p, void *q);
#endif

/* u_8001C2D0.cpp */
EXTERN_C void *func_8001CA10(int size);
EXTERN_C void func_8001D024(void *p, int a);
EXTERN_C void func_8001D150(void *, void *);
#ifndef EXE_H_IN_u_8001C2D0
EXTERN_C void *func_8001D25C(void *v, int key);
EXTERN_C void func_8001D324(void *v, void *q);
#endif

/* u_8001DDF4.cpp */
EXTERN_C void func_8001E508(char *p, int flags);
EXTERN_C int func_8001E848(char *cur, char *s);
#ifndef EXE_H_IN_u_8001DDF4
EXTERN_C void *func_8001E40C(void *p, void *a, unsigned short b, int c, int d);
EXTERN_C void func_8001EAAC(void *s);
EXTERN_C void *func_8001EB60(char *obj, int a);
EXTERN_C void *func_8001ED2C(char *s, int a, int b);
EXTERN_C void func_8001EFE4(void *obj, void *e);
#endif

/* u_8001F1A8.cpp */
EXTERN_C int func_8001FE20(void);
EXTERN_C int func_8001FF40(void);
EXTERN_C int func_800202C4(void);
EXTERN_C int func_800202CC(void);
EXTERN_C int func_800202D4(void);
#ifndef EXE_H_IN_u_8001F1A8
EXTERN_C void *func_8001FC38(void *p, int a, int b, int c);
EXTERN_C void func_8001FC78(void *p, int a, int b);
EXTERN_C int func_8001FD00(void *o, void *e);
EXTERN_C int func_8001FD90(void *o, void *e);
EXTERN_C int func_800201DC(void *p, void *e);
#endif

/* u_80020368.cpp */
EXTERN_C void func_800205D4(int a);

/* u_80020B70.cpp */
EXTERN_C void func_800215E8(void *q, void *x);
EXTERN_C void func_80021ACC(void *p, int a);
EXTERN_C void func_80021F48(void *p, int a);
EXTERN_C void func_800230E8(char *p, int a);
EXTERN_C int func_800232A0(char *p, void *);
EXTERN_C int func_80023F50(void *q, int a);
EXTERN_C int func_80025444(void *, void *, int);
EXTERN_C void func_80025714(void *q, void *r);
#ifndef EXE_H_IN_u_80020B70
EXTERN_C void func_80024524(void *p);
EXTERN_C int func_8002456C(void *p);
EXTERN_C void *func_80024BB0(void *n, unsigned short id);
EXTERN_C char *func_80024BF0(void *p, char *buf, short w, short h);
EXTERN_C short *func_80024CA0(void *p, short *buf, short w, short h);
EXTERN_C void func_80024FEC(void *p, void *o);
#endif

/* u_80025854.cpp */
EXTERN_C void *func_80025CE0(void *, void *, int);
EXTERN_C int func_80026014(int a);
EXTERN_C int func_800260A4(int a);

/* u_800278EC.cpp */
EXTERN_C void func_80027948(void);
EXTERN_C void func_8002798C(void);
EXTERN_C void func_800279A8(void);
#ifndef EXE_H_IN_u_800278EC
EXTERN_C void *func_80027FEC(void *p, void *q);
EXTERN_C void func_80028184(void *p);
#endif

/* u_80028428.cpp */
EXTERN_C void *func_8002860C(void *a, void *r, int b, int c, void *col);
EXTERN_C void func_80028A24(void *);
#ifndef EXE_H_IN_u_80028428
EXTERN_C void func_80028D10(void *p, void *cv);
EXTERN_C int func_80028F10(void *p);
EXTERN_C int func_80028F58(void *p);
EXTERN_C void *func_8002972C(void *p, int a, int b, int c, int d);
#endif

/* u_80029BBC.cpp */
EXTERN_C void func_80029EC0(void);
EXTERN_C void *func_8002A09C(void *p, int x, int y);
#ifndef EXE_H_IN_u_80029BBC
EXTERN_C void *func_80029C54(void *p, int in_chrg, unsigned short a);
EXTERN_C void func_80029D74(void *p, int flags);
EXTERN_C S_Rgb func_80029EC8(void *p);
EXTERN_C S_Box2 func_80029F30(void *p);
EXTERN_C int func_80029FC0(void *p);
EXTERN_C void func_8002A004(void *p);
EXTERN_C void *func_8002A0D0(void *p, void *pt);
EXTERN_C void func_8002A110(void *p);
EXTERN_C void func_8002A118(void *p);
EXTERN_C void func_8002A168(void *p);
EXTERN_C void func_8002A1BC(void *p);
EXTERN_C void func_8002A210(void *p);
EXTERN_C void func_8002A37C(void *p, int a);
EXTERN_C void func_8002A400(void *p, int a);
EXTERN_C int func_8002A484(void *p);
EXTERN_C void func_8002A4C8(void *p, int x, int y);
EXTERN_C void func_8002A55C(void *p, int w, int h);
EXTERN_C void func_8002A65C(void *p, int a);
EXTERN_C void func_8002A698(void *p, int a);
EXTERN_C void func_8002A728(void *p, void *ev);
EXTERN_C int func_8002A7B8(void *p, int a);
EXTERN_C int func_8002A864(void *p, int a);
EXTERN_C int func_8002A910(void *p, int a);
EXTERN_C int func_8002A9BC(void *p, int a);
EXTERN_C int func_8002AA8C(void *p, int a);
EXTERN_C int func_8002AB5C(void *p, int a);
EXTERN_C void func_8002AC2C(void *p);
EXTERN_C void func_8002AFEC(void *p, int flags);
EXTERN_C void *func_8002B174(void *p, void *c, int i);
EXTERN_C void func_8002B27C(void *p, void *c);
EXTERN_C void func_8002B518(void *p, int x, int y);
EXTERN_C void func_8002BA94(void *p);
EXTERN_C void func_8002BD34(void *p);
#endif

/* u_8002C90C.cpp */
EXTERN_C void func_8002D24C(void *, void *);
EXTERN_C void func_8002D780(void *vp, S_Pt2 pos);
EXTERN_C void *func_8002DA94(void *p, void *it);
EXTERN_C void func_8002DB50(void *p, int del);
EXTERN_C int func_8002DC34(void *p, int a, int del);
EXTERN_C void *func_8002DD34(void *, void *, int);

/* u_8002DED8.cpp */
EXTERN_C void *func_8002E714(void *vp, int n);
EXTERN_C void func_8002EABC(void);
EXTERN_C void func_8002EAC4(void);
EXTERN_C void func_8002EC30(void);
EXTERN_C int func_8002EC38(void);
EXTERN_C void func_8002ECE0(void);
EXTERN_C void func_8002ECE8(void);
#ifndef EXE_H_IN_u_8002DED8
EXTERN_C void *func_8002E600(void *p);
EXTERN_C void *func_8002EA70(void *p, void *src);
EXTERN_C void func_8002EADC(void *p, int a, int b);
EXTERN_C void func_8002EAE8(void *p, int a, int b);
EXTERN_C int func_8002EB68(void *p);
EXTERN_C void *func_8002EBF0(void *p);
EXTERN_C void *func_8002EC00(void *p);
EXTERN_C void *func_8002EC18(void *p);
EXTERN_C void func_8002EC40(void *p, void *);
EXTERN_C void func_8002EC90(void *p, void *);
#endif

/* u_8002ED44.cpp */
EXTERN_C void func_8002EE9C(void *p, int a);
EXTERN_C void func_8002EEFC(void *vp, int flags);
EXTERN_C void *func_80030AA8(void *vp, void *vq, int *out);
#ifndef EXE_H_IN_u_8002ED44
EXTERN_C void *func_8002EEC4(void *, void *);
#endif

/* u_80032264.cpp */
#ifndef EXE_H_IN_u_80032264
EXTERN_C int func_80032A9C(void *s, void *a, void *b, void *c, void *d);
#endif

/* u_80033ECC.cpp */
EXTERN_C void func_80035304(void *p, int flags);
EXTERN_C int func_8003546C(void *, void *);
EXTERN_C void func_8003556C(void *);
EXTERN_C void func_800356F4(void *p);
EXTERN_C void func_80035B28(void *p, int a);
EXTERN_C void func_80035BF8(void);
EXTERN_C void func_80035C28(void);
EXTERN_C unsigned char func_80035C30(int);
EXTERN_C void func_80035CF8(void);
EXTERN_C void func_80035DE0(int a);
EXTERN_C void func_80035EB4(int a);
EXTERN_C void func_80036110(void *p, int a);
EXTERN_C int func_80036850(void *);
EXTERN_C int func_80036FC0(void *, int, int);
EXTERN_C void func_800370D0(void *p);
EXTERN_C int func_8003714C(void *);
#ifndef EXE_H_IN_u_80033ECC
EXTERN_C int func_80035B98(void *p, unsigned int n);
EXTERN_C void func_80036554(void *, unsigned char, unsigned char *);
EXTERN_C void func_80036674(void *p);
EXTERN_C int func_800366F8(void *p);
EXTERN_C void func_80036D8C(void *p);
#endif

/* u_80037398.cpp */
EXTERN_C void *func_80037688(void *);
EXTERN_C int func_800382A4(void *p, int a, int b);

/* u_8003852C.cpp */
EXTERN_C void *func_80038654(void *p, int a, int b);
EXTERN_C void func_800386B8(void *p, int flags);
EXTERN_C void func_80038764(void *p, int a);
EXTERN_C void func_80038938(void *p);
EXTERN_C void func_80038978(void *p);
EXTERN_C void *func_8003912C(void *p, short a);
EXTERN_C void func_8003944C(void *h, void *o);
EXTERN_C void func_80039A88(void *, int);
EXTERN_C void func_80039BEC(void *p, void *item);
EXTERN_C int func_80039C88(void *p, void *q);
EXTERN_C void func_80039DD8(void *p);
EXTERN_C void *func_8003A754(void *p, short a);
EXTERN_C void func_8003A7FC(void *, void *);
EXTERN_C void func_8003AD78(void *, void *);
EXTERN_C S_A2_V4 func_8003B310(void *s);
EXTERN_C S_A2_V4 func_8003B450(void *m, void *v);
EXTERN_C void *func_8003BC10(void *p, int a);
EXTERN_C void func_8003BEC4(void *p, int a);
EXTERN_C void func_8003C320(void *p, int a);
#ifndef EXE_H_IN_u_8003852C
EXTERN_C void func_80038834(void *p);
EXTERN_C void func_80038898(void *p);
EXTERN_C void func_800388FC(void *p, int a);
EXTERN_C int func_800392C8(void *p);
EXTERN_C void *func_8003950C(void *, void *);
EXTERN_C void *func_80039610(void *, void *);
EXTERN_C void *func_80039710(void *, void *);
EXTERN_C void *func_80039824(void *, void *);
EXTERN_C void func_80039A14(void *);
EXTERN_C void *func_8003A150(void *r, char *m, void *v);
EXTERN_C S_A2_Sv0 func_8003B168(void *m);
EXTERN_C void *func_8003B2F0(void *p, void *v);
EXTERN_C void *func_8003B35C(void *r, void *a, void *b);
EXTERN_C void *func_8003B3EC(void *r, void *a, void *b);
EXTERN_C void *func_8003BEF8(void *);
#endif

/* u_8003C510.cpp */
EXTERN_C void *func_8003C510(void *);
EXTERN_C int func_8003C908(void *, void *);
EXTERN_C void *func_8003CA10(void *p, void *q);
EXTERN_C void func_8003CB50(void *);
EXTERN_C void func_8003CC78(void *, int);
EXTERN_C void *func_8003CEB4(void *p, int a);
EXTERN_C void func_8003CF24(void *);
EXTERN_C void func_8003D00C(void *);
EXTERN_C void func_8003D384(void *p, int a, int b);
EXTERN_C void func_8003D68C(void *, int, void *, int, int);
EXTERN_C void func_8003DEA8(void *);
EXTERN_C void func_8003E124(void *p);
EXTERN_C void func_8003E198(void *, void *, int);
EXTERN_C short func_8003E658(void *, int);
EXTERN_C int func_8003ED90(void *, void *);
#ifndef EXE_H_IN_u_8003C510
EXTERN_C void func_8003D358(void *p, int a, S_Rgb c);
EXTERN_C void *func_8003D37C(void *p);
EXTERN_C int func_8003E170(void *p);
EXTERN_C void func_8003ECFC(void *p, int a, int b);
#endif

/* u_8003F7E8.cpp */
EXTERN_C void func_8003FA50(void *, void *, int, int);
EXTERN_C void func_8003FB88(void *p, int a, S_A2_RgbC c);
EXTERN_C void func_8003FC48(void *p);
EXTERN_C int func_800401F0(void *p, short a, short b);
EXTERN_C void func_80040718(void *);
EXTERN_C unsigned int func_80041C18(int *p);
EXTERN_C void func_80042430(void *p, int a, int b, short c);
EXTERN_C void func_80042838(void *, int);
EXTERN_C void func_80042D3C(void *p);
EXTERN_C int func_80042E20(void *p, int x, int y);
EXTERN_C void func_80043460(void *p, S_A2_Pt a, int b, int c);
EXTERN_C void func_800435AC(void *p, int a, int b);
EXTERN_C void func_800435E8(void *p);
EXTERN_C int func_80043700(void *p, short a, int b, int c);
EXTERN_C void func_80043740(void *p, short a);
EXTERN_C void func_800437CC(void *p, short a, char b, short c);
EXTERN_C void func_80043808(void *p);
EXTERN_C void func_80043DF0(void *);
EXTERN_C void func_80044590(void *p);
EXTERN_C short func_80044890(void *p, int a);
EXTERN_C void func_80044990(void *, int, int, int, int, int);
#ifndef EXE_H_IN_u_8003F7E8
EXTERN_C void func_80043540(void *p, S_A2_Pt v, int t);
EXTERN_C void func_8004377C(void *p, int a);
EXTERN_C void func_800437A4(void *p, int a);
EXTERN_C void func_80043D38(void *p, S_A2_Sv v);
EXTERN_C void func_80043DC0(void *p);
#endif

/* u_80044BE4.cpp */
EXTERN_C int func_80044F18(void *, int, int, int, int);
#ifndef EXE_H_IN_u_80044BE4
EXTERN_C void *func_80044BE4(void *);
#endif

/* u_80045850.cpp */
EXTERN_C int func_80045EB8(void *, void *, int, void *, int, int, int, int, int);
EXTERN_C int func_800461F4(void *p, int a, int b, void *cc);
EXTERN_C int func_800464E4(void *p, int a, int b, void *cc);
EXTERN_C int func_80046658(void *p, int a, int b, int c);
EXTERN_C void func_800468D0(void);
EXTERN_C int func_800468D8(void *, int, int, void *, void *);
EXTERN_C int func_80046948(void *p, void *q, int a);
EXTERN_C int func_80046998(void *, void *);
EXTERN_C void func_80048D2C(void *p, int a);
EXTERN_C void *func_80048D54(void *p);
EXTERN_C void *func_80049398(void *p);
EXTERN_C void func_800499D0(void *, void *);
EXTERN_C void func_8004A954(void *p, void *q);
EXTERN_C void func_8004A98C(void *p, int a);
EXTERN_C int func_8004A9E4(void *p);
EXTERN_C int func_8004AC04(void *, void *, void *, void *, void *);
EXTERN_C void func_8004AE24(void *d, void *s);
EXTERN_C char *func_8004C314(void *, char *);
EXTERN_C void func_8004D0F4(void *, void *);
EXTERN_C char *func_8004F9E4(void *, char *);
EXTERN_C void *func_80050874(void *, int *, void *, int, int);
EXTERN_C int func_80050EA4(void *, int, int);
EXTERN_C void func_80051514(void *p, int a);
EXTERN_C void func_800515A4(void *p, int a);
EXTERN_C void func_800518A8(void *p, int a, int b, int c);
EXTERN_C void func_80051A2C(void *p, void *a);
EXTERN_C void func_80051AA4(void *p, void *o);
EXTERN_C void func_80051B70(void *p, void *o);
EXTERN_C int func_80051E50(void *p);
EXTERN_C void func_80052B60(void *p);
EXTERN_C void func_80052E40(void *, int);
EXTERN_C void func_80052FB8(void *);
EXTERN_C void *func_80053250(void *p, int a, int b, short c);
EXTERN_C void func_800534F8(void *p);
EXTERN_C void func_80053658(void *pv, int qq);
EXTERN_C void func_800536F0(void *pv, int qq);
EXTERN_C void func_800537DC(void *p, int flags);
EXTERN_C void func_8005388C(void *p, int a);
EXTERN_C void func_800538B4(int v);
EXTERN_C void *func_800538CC(void *p, void *q, int a);
EXTERN_C void *func_80053928(void *p);
EXTERN_C void func_80053964(void *p, int flags);
EXTERN_C void *func_80053AE4(void *ret, void *s, unsigned i);
EXTERN_C void func_80053B68(void *p);
EXTERN_C void func_80053BCC(void *p, void *q, int a);
EXTERN_C void func_80053C6C(void *p, void *q);
EXTERN_C void func_80053CD8(void *p);
EXTERN_C void func_80053FB0(void *p, int a, unsigned b);
EXTERN_C void func_800540A8(void *);
EXTERN_C void *func_80054414(void *pv, void *qv);
EXTERN_C void func_800544AC(void *pv, void *qv);
EXTERN_C void *func_80054584(void *, int);
EXTERN_C void func_80054708(void *, int);
#ifndef EXE_H_IN_u_80045850
EXTERN_C void *func_80050838(void *p);
EXTERN_C void func_800514C8(void *);
EXTERN_C void func_80051564(void *);
EXTERN_C void func_80051A7C(void *p, int a);
EXTERN_C void *func_80051C3C(void *, void *);
EXTERN_C void *func_800537C0(void *p);
EXTERN_C int func_80053830(void *p);
EXTERN_C void func_80053848(void *p);
EXTERN_C int func_80053874(void *p);
EXTERN_C int func_80053880(void *p);
EXTERN_C void *func_800539D0(void *, void *);
EXTERN_C int func_80053BB4(void *p);
EXTERN_C int func_80053BC0(void *p);
EXTERN_C void func_80053DDC(void *s, void *o);
EXTERN_C void func_80053F28(void *p, S_Rgb c);
EXTERN_C void func_80053F48(void *p, S_A2_Pt v);
EXTERN_C int func_80054048(void *p);
EXTERN_C S_Rgb func_80054054(void *p);
EXTERN_C int func_80054074(void *p);
EXTERN_C void func_8005408C(void *p, int v);
EXTERN_C void func_80054094(void *p, int v);
EXTERN_C int func_8005409C(void *p);
EXTERN_C void func_8005457C(void *p, int v);
EXTERN_C void *func_8005464C(void *);
EXTERN_C int func_800549C4(void *p, int a);
EXTERN_C int func_800549D8(void *p);
EXTERN_C void func_800549E4(void *p, int v);
EXTERN_C void func_800549EC(void *p, int v);
#endif

/* main_b.cpp */
EXTERN_C void *func_80054AF0(void *, int);
EXTERN_C void func_80054B98(void *);
EXTERN_C void func_80054C34(void *self, int b);
EXTERN_C void func_80054CA0(void *self);
EXTERN_C void func_80054CE4(void *self);
EXTERN_C void func_80054D48(void *self, int b);
EXTERN_C int func_80054D78(void *self);
EXTERN_C void func_80054DA8(void *self, void *b);
EXTERN_C void func_80054E18(void *self, int b);
EXTERN_C int func_80054E90(void *self);
EXTERN_C void func_80054EB4(void *self, int b, int c);
EXTERN_C void *func_80054F28(void *self);
EXTERN_C void func_80054F5C(void *self);
EXTERN_C void func_80054FC0(void *self);
EXTERN_C void func_80054FE0(void *self);
EXTERN_C void func_80055020(void *self, SV2C_80055020 v);
EXTERN_C void func_800550BC(void *self);
EXTERN_C void func_800550FC(void *, int);
EXTERN_C void func_80055330(int a);
EXTERN_C void func_800553D8(int a);
EXTERN_C void func_8005549C(int a, void *b, void *c, int d);
EXTERN_C void func_8005556C(void *a, int b);
EXTERN_C void func_80055624(void *, int);
EXTERN_C int func_800557A0(void);
EXTERN_C void func_800557C8(void *self, int b, int c);
EXTERN_C void *func_8005584C(void *self, int b);
EXTERN_C int func_8005618C(void *p);
EXTERN_C void *func_80056198(void *, int, int, int, int);
EXTERN_C void *func_80056364(void *, int, int, int);
EXTERN_C void func_8005652C(void *, int);
EXTERN_C void func_800566E4(void *);
EXTERN_C void func_80056874(void *);
EXTERN_C void func_80056B3C(void);
EXTERN_C int func_80056B44(void *self, int x);
EXTERN_C void func_80056D60(void *self, int b);
EXTERN_C int func_80056D9C(void);
#ifndef EXE_H_IN_main_b
EXTERN_C void func_80054F30(void *self, int a, void *v, int d);
EXTERN_C int func_80056BA8(void *self, void *b);
#endif

/* u_80056E0C.cpp */
EXTERN_C void *func_80056E0C(void *, int);
EXTERN_C void func_80056F9C(void *self, int a, int b);
EXTERN_C void func_80056FBC(void *self, int a, int b);
EXTERN_C void func_80056FE0(void *self);
EXTERN_C void *func_80057368(void *, int);
EXTERN_C void func_80057558(void *, int);
EXTERN_C void func_8005783C(short v);
EXTERN_C void func_80057F20(void *, unsigned short);
EXTERN_C void func_8005800C(void *self, void *b);
EXTERN_C void func_8005816C(void *self, int b);
EXTERN_C int func_80058270(void *, int);
EXTERN_C int func_80058404(void *self, int b);
EXTERN_C int func_80058488(void *self, int b);
EXTERN_C void func_800588C8(void *self);

/* u_80059A84.cpp */
EXTERN_C void func_8005BDA4(void *, int);
EXTERN_C void func_8005BF04(void *self, int a, int b);
EXTERN_C void func_8005BF50(void *self);
EXTERN_C void func_8005BFA4(void *self);
EXTERN_C void func_8005BFE4(void *self);
EXTERN_C void func_8005C088(void *, int, int);
EXTERN_C void func_8005D9D4(void *self, int b);
EXTERN_C void *func_8005F0E4(void *self, int b);
EXTERN_C void func_8005F120(void *self, int flags);
EXTERN_C int func_8005F1B4(void *self);
EXTERN_C void func_8005F1D8(void *self);
#ifndef EXE_H_IN_u_80059A84
EXTERN_C void *func_8005BC84(void *p, int in_chrg, int a2, int a3);
EXTERN_C void func_8005C238(void *self);
EXTERN_C void *func_8005D8C4(void *p, int in_chrg, int a2);
EXTERN_C void func_8005F148(void *self, short *v);
#endif

/* u_8005F238.cpp */
EXTERN_C void *func_8005F238(void *self);
EXTERN_C void func_8005F248(void *self, int flags);
EXTERN_C int func_8005F28C(void *self);
EXTERN_C void func_8005F298(void *, int, int);
EXTERN_C void func_8005F3E0(void *self);
EXTERN_C void func_8005F440(int a, int b);
EXTERN_C int func_8005F87C(void *self);
EXTERN_C unsigned short func_800600A4(void *self, int b);
EXTERN_C unsigned short func_80060154(void *self, int b);
EXTERN_C void *func_800601D8(void *self, void *src);
EXTERN_C int func_80060230(signed char *a, signed char *b);
EXTERN_C void func_80060588(void *, int);
EXTERN_C void func_800609D0(void *, void *);
EXTERN_C void func_80061058(void *self);
EXTERN_C void func_80061138(void *self);
EXTERN_C void func_80061758(void *, void *);
EXTERN_C int func_80061A20(void *, void *);
EXTERN_C void *func_80062118(void *self);
EXTERN_C void *func_80062158(void *self);
EXTERN_C void func_80062160(unsigned int *out);
EXTERN_C void func_80062188(void *self);
EXTERN_C void *func_800621F8(void *self);
EXTERN_C int func_80062280(void *self, int b);
#ifndef EXE_H_IN_u_8005F238
EXTERN_C void *func_8005F5F4(void *self, int a, int b);
EXTERN_C void *func_80060188(void *out, void *self, unsigned int i);
EXTERN_C void func_80061114(void *self, int i, int j);
EXTERN_C void *func_80061164(void *self, int i);
EXTERN_C void *func_80061188(void *self, int i);
EXTERN_C void func_800614BC(void *self, int i);
EXTERN_C int func_800619F4(void *self);
EXTERN_C void func_80061AAC(void *self, int i, int j);
EXTERN_C void func_80061F80(void *self, int i);
EXTERN_C void func_80062120(void *self, void *src);
EXTERN_C void func_80062214(void *self);
#endif

/* u_80062610.cpp */
EXTERN_C void *func_80062610(void *self);
EXTERN_C void func_80062764(void *self, int flags);
EXTERN_C void *func_80062834(void *self);
EXTERN_C int func_8006283C(void);
EXTERN_C int func_80062978(void *self);
EXTERN_C void func_800631D4(void *self);
EXTERN_C void func_8006323C(void *self);
EXTERN_C void func_80063270(void *self, Unk_Pt p);
EXTERN_C void func_80063340(void *, void *);
EXTERN_C void func_800635FC(void *, void *);
EXTERN_C void func_80063714(void *self, unsigned int b);
EXTERN_C int func_80063744(void *self, int b);
EXTERN_C void *func_800638A8(void *, int);
EXTERN_C void func_80063B14(void *self, short *v, unsigned short c);
EXTERN_C void func_80063BE4(void *);
EXTERN_C void *func_800646FC(void *, int, short *, int);
EXTERN_C void func_80064884(int *s, int a, int b);
EXTERN_C void func_800648E8(void *, int);
#ifndef EXE_H_IN_u_80062610
EXTERN_C void func_800627E8(void *out, int i);
EXTERN_C void *func_80062848(void *p, int in_chrg, int a2, int a3, int e, int f);
EXTERN_C void func_80062A90(void *p, int flags);
EXTERN_C void *func_80062C3C(void *p, int in_chrg, int a2, int a3, int e);
EXTERN_C void *func_80062D60(void *p, int in_chrg);
EXTERN_C void *func_80062FA4(void *p, int in_chrg, int a2, int a3);
EXTERN_C void *func_800630BC(void *p, int in_chrg, int a2);
#endif

/* u_800658E0.cpp */
EXTERN_C void func_80065D20(void *self, int i, short a, short b, short c, int d, int e, int f);
EXTERN_C void func_80065E10(void *self, int i);
EXTERN_C void *func_800663EC(void *, int, void *, int, int, int);
EXTERN_C int func_800665C8(void *self);
EXTERN_C void *func_80066DA4(void *self, int b, int c, int d, int e);
EXTERN_C int func_80066E04(void *self);
EXTERN_C void *func_80066FB0(void *, void *, int, int, int);
EXTERN_C int func_800670A4(void *self);

/* u_80067450.cpp */
EXTERN_C void *func_8006753C(void *, int);
EXTERN_C void func_80067ABC(void *self, void *b);
EXTERN_C void func_800680A0(void *self);
EXTERN_C int func_80068660(int *, int *, void *);

/* u_80068770.cpp */
EXTERN_C void func_80068770(void *, int);
EXTERN_C void func_8006897C(void *self, int b, int c);
EXTERN_C void func_800689E0(void *self);
EXTERN_C int func_80068A5C(void *self);
EXTERN_C void func_80068B14(void *);
EXTERN_C void func_80068E60(void *self);
EXTERN_C int func_80068F3C(void *self, void *m);
EXTERN_C int func_800690C8(void *self, void *b);
EXTERN_C void func_80069264(void *, int);
EXTERN_C void func_800694BC(void *, int, int, int);
EXTERN_C void func_800697A4(void *);
EXTERN_C void func_80069958(void *self);
EXTERN_C void func_80069B2C(void *, int);
EXTERN_C void *func_80069D1C(void *self, int a, int b);
EXTERN_C void func_80069E60(void *self, int flags);
EXTERN_C int func_80069ECC(void *self, int a, int b);
EXTERN_C int func_80069F74(void *self, int n, SV2_80069F74 s, void *src);
EXTERN_C void func_8006A440(void *self, void *m);
EXTERN_C void func_8006A4E4(void *self, int v);
EXTERN_C void func_8006A608(void *self, int v);
EXTERN_C void func_8006A6D4(void *self);
EXTERN_C char *func_8006A82C(void *, int, void *);
EXTERN_C void func_8006AE68(void *);
EXTERN_C void func_8006AF94(void *self_);
EXTERN_C void func_8006B058(void *self, int b);
EXTERN_C void func_8006B08C(void *self, int b);
EXTERN_C void func_8006B0C0(void *self, int b);
EXTERN_C void func_8006B120(void *self, int b);
EXTERN_C void func_8006B180(void *, int);
EXTERN_C void func_8006B1C8(void *, int);
EXTERN_C void func_8006B258(void *self, int b);
EXTERN_C void func_8006B2F8(void *self, int b);
EXTERN_C void func_8006B350(void *self, int b);
EXTERN_C void func_8006B390(void *self, int b);
EXTERN_C void func_8006B3D0(void *self, void *p);
EXTERN_C void func_8006B5D4(void *self);
EXTERN_C void func_8006B618(void *self, int b);
EXTERN_C void func_8006B690(void *self, int b);
EXTERN_C void func_8006B740(void *self, int b);
EXTERN_C void func_8006B7D8(void *self, int b);
EXTERN_C void func_8006B814(void *self, int b);
EXTERN_C void func_8006B850(void *self);
EXTERN_C void func_8006B988(void *self);
EXTERN_C int func_8006BA1C(void *self);
EXTERN_C int func_8006BA64(void *self);
EXTERN_C void func_8006BB04(void *);
EXTERN_C int func_8006BC98(void *self);
EXTERN_C int func_8006BCF4(void *self);
EXTERN_C int func_8006BD34(void *self);
EXTERN_C int func_8006BDE0(void *self);
EXTERN_C int func_8006BE4C(void *self);
#ifndef EXE_H_IN_u_80068770
EXTERN_C void func_80068EE8(void *self);
EXTERN_C void func_800691EC(void *self, int i, int c);
EXTERN_C void func_80069914(void *self);
EXTERN_C void func_80069978(void *self, void *pp, int dx, int dy, int step);
EXTERN_C void func_8006A3C0(void *self, void *b);
EXTERN_C void func_8006A588(void *self, void *b);
#endif

/* u_8006BFE4.cpp */
EXTERN_C void func_8006C4EC(void *, int);
EXTERN_C void *func_8006C95C(void *, void *, int);
EXTERN_C int func_8006CA80(void *self);
#ifndef EXE_H_IN_u_8006BFE4
EXTERN_C void func_8006C3C8(void *self, int b, void *c);
#endif

/* u_8006CBCC.cpp */
EXTERN_C void *func_8006D344(void *, void *, int, int, int);
EXTERN_C int func_8006D8EC(void *self);
EXTERN_C void func_8006DA60(void *self);
EXTERN_C void func_8006EACC(void *, int, short);
EXTERN_C void func_8006EBB0(void *, void *);
EXTERN_C void func_8006EC70(void *, void *);
EXTERN_C void func_8006EDD8(void *self, void *m);
EXTERN_C void func_8006EE94(void *);
EXTERN_C void *func_8006F04C(void *self);
EXTERN_C void func_8006F0B0(void *self, int flags);
EXTERN_C void func_8006F0E4(void *self, int b);
EXTERN_C void func_8006F0F4(void *self, int b, int c, int d, int e);
EXTERN_C void func_8006F10C(void *);
EXTERN_C void func_8006F154(void *self);
EXTERN_C void func_8006F194(void *self);
EXTERN_C void func_8006F268(void *self);
EXTERN_C void func_8006F3DC(void *, int, int, int, int, int);
EXTERN_C int func_8006F52C(void *self, int *a, int *b);
EXTERN_C int func_8006F570(void *self, int *a, int *b);
EXTERN_C int func_8006F5B4(void *self, int *a, int *b, int *c);
EXTERN_C int func_8006F630(void);
EXTERN_C void func_8006F67C(void *self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, V4_80085578 v, int a12);
EXTERN_C void func_8006F8B4(void *self, int a1, int a2, int a3, int a4, int a5, int a6, V4_80085578 v, int a11);
EXTERN_C void func_8006FAC0(void *self, void *a, void *b, void *c, void *d, void *e, void *f, Blk_8007D6D0 g, int h);
EXTERN_C void func_8006FCC0(void *, int, int, int);
EXTERN_C void *func_8006FEEC(void *p);
EXTERN_C void func_8006FF50(void *self_, int a, int b, void *c);
EXTERN_C void func_800715B0(void *self, int a, int b, int c);
EXTERN_C void func_8007164C(void *self, void *b);
#ifndef EXE_H_IN_u_8006CBCC
EXTERN_C void *func_8006FDD8(void *self);
#endif

/* u_80071A74.cpp */
EXTERN_C void func_80071C78(void *self, void *b);
EXTERN_C void func_80071D90(void *self, void *b, int c);
EXTERN_C void func_80071E90(void *self);
EXTERN_C void func_80072970(void *self);
EXTERN_C short func_800729E8(void *, int);
EXTERN_C void func_80072B84(void *self, int a);
EXTERN_C void func_80073960(void *self);
EXTERN_C void func_80074564(void *self);
EXTERN_C void *func_80074E28(void *self);
EXTERN_C void func_80074E44(void *self, int flags);
EXTERN_C void *func_80074F58(void *self);
EXTERN_C void func_80074F78(void *self, int b);
EXTERN_C void func_8007505C(void *self, void *node);
EXTERN_C void *func_800751AC(void *self);
EXTERN_C void *func_800752B8(void *self);
EXTERN_C int func_80075448(void *self, void *x);
EXTERN_C void *func_800756F8(void *self);
EXTERN_C void *func_8007570C(void *self);
EXTERN_C void *func_80075788(void *, int, int, int, int);
EXTERN_C void func_80075828(void *self, int flags);
EXTERN_C void func_80075894(void *self, int b);
EXTERN_C void func_8007589C(void *self);
EXTERN_C void *func_800758F8(void *self, int b, void *c, void *d);
EXTERN_C void func_80075EC8(void *, int);
EXTERN_C void func_80076370(void *);
EXTERN_C int func_8007669C(void *self, int b, int c);
EXTERN_C void func_800766D8(void *self);
EXTERN_C void func_800766F8(void *, int, int, int, int);
EXTERN_C void func_80076848(void *self, int a1, int a2, int a3);
EXTERN_C void func_8007698C(void *, int, int, int);
EXTERN_C void *func_80076DC4(void *self);
EXTERN_C void func_80076DF8(void *self, int flags);
EXTERN_C void func_80076E60(void *self);
EXTERN_C void *func_80076EA8(void *self);
EXTERN_C void func_80076EF8(void *self, int flags);
EXTERN_C int func_80076FD8(void *self);
EXTERN_C void func_800770B4(void *self, int a1, int a2);
EXTERN_C int func_800771D4(void *self);
EXTERN_C void func_80077210(void *self, void *b);
EXTERN_C int func_80077234(void *self, void *b);
EXTERN_C void *func_80077254(void *self);
EXTERN_C void *func_800773B0(void *self, int b);
EXTERN_C void func_80077444(void *self, int b);
EXTERN_C void *func_80077478(void *self);
EXTERN_C void *func_800774D0(void *self, int b);
EXTERN_C void *func_80077538(void *self, int b);
EXTERN_C void *func_800775F0(void *self);
EXTERN_C void *func_8007778C(void *self);
EXTERN_C void func_800777E8(void *self, int b);
EXTERN_C int func_80077854(void *, int, int);
EXTERN_C int func_80077C68(void *);
EXTERN_C int func_80077EA8(void *);
EXTERN_C void func_80078520(void *self, void *p);
EXTERN_C void func_80078564(void *self);
EXTERN_C int func_800785A8(void *self);
EXTERN_C void *func_800785DC(void *self);
EXTERN_C void func_80078610(void *self, int b);
EXTERN_C void func_80078658(void *self);
EXTERN_C void func_800786A0(void *self);
EXTERN_C void *func_800787B4(void);
EXTERN_C int func_80078C38(void);
EXTERN_C void func_800798EC(void *self, int b);
EXTERN_C int func_80079F6C(void *self, int k);
EXTERN_C void func_8007A1F4(void *, int);
EXTERN_C void func_8007A400(void *self, int b);
EXTERN_C void *func_8007A960(void *self);
EXTERN_C void func_8007A994(void *self, int b);
EXTERN_C void func_8007AD14(void *self, int a1, int a2, int a3, int a4, int a5, int a6);
EXTERN_C int func_8007ADCC(void *self, int b);
EXTERN_C void func_8007AF04(void *self);
EXTERN_C void func_8007AF5C(void *);
EXTERN_C void func_8007B08C(void *self);
EXTERN_C void func_8007B0C8(void *self);
EXTERN_C int func_8007B1FC(void *self, int v, int kind);
EXTERN_C int func_8007B2E4(void *self, int x);
EXTERN_C void func_8007B538(void *self, int mask, int a2, int a3, int a4, int a5);
EXTERN_C void func_8007BB48(void *p, int b, int c);
EXTERN_C void func_8007BDB4(void *self_, int a, int b, int c);
EXTERN_C void func_8007BE44(void *self);
EXTERN_C void func_8007BEA8(void *self, int b, int c, int d, int e);
EXTERN_C void func_8007BF48(void *self, int b, int c, int d);
EXTERN_C void func_8007C070(void *self, int b);
EXTERN_C int func_8007C0A8(void *self, int i);
EXTERN_C int func_8007C3C8(void *p, int i);
EXTERN_C int func_8007CAA8(void *self, int b);
EXTERN_C void func_8007CAB4(void *self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, B16_B s, int a12);
EXTERN_C void func_8007CC60(void *self, int b, int c, int d);
EXTERN_C int func_8007D024(void *, int, int, int);
EXTERN_C void func_8007D24C(void *self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, B16_B s, int a12);
EXTERN_C void func_8007D6D0(void *self);
EXTERN_C void func_8007D744(void *);
EXTERN_C void func_8007D994(void *);
EXTERN_C void func_8007DDCC(char *p);
EXTERN_C void func_8007DE74(void *self, int b);
EXTERN_C void func_8007DEE8(void *, int);
EXTERN_C void func_8007E214(void *self);
EXTERN_C void func_8007E30C(void *self);
EXTERN_C void func_8007E47C(void *);
EXTERN_C void func_8007E5B0(void *);
EXTERN_C void *func_8007E684(void *, int, void *);
EXTERN_C void func_8007EDAC(void *p, int a1, int a2);
EXTERN_C void func_8007EF90(void *p);
EXTERN_C void func_8007F0A8(void *self, int a, int b, int c, int d);
EXTERN_C void func_8007F138(void *p);
EXTERN_C void func_8007F434(void *p);
EXTERN_C int func_8007F538(void *self, int *a, int *b);
EXTERN_C void func_8007F5B8(void *self);
EXTERN_C void func_8007F6C4(void *self);
EXTERN_C void func_8007F820(void *self);
EXTERN_C void func_8007FB30(void *self, int b);
EXTERN_C void func_8007FE1C(void *self, int b);
EXTERN_C int func_8007FE4C(void *p, int pos, int n);
EXTERN_C void func_8007FF58(void *, int, int, int);
EXTERN_C int func_80080110(void *self, int b);
EXTERN_C int func_80080130(void *self, int b);
EXTERN_C int func_80080180(void *self, int b);
EXTERN_C int func_800801D0(void *self, int b, int c);
EXTERN_C void func_8008022C(void *, int, int);
EXTERN_C void func_800802E0(void *self, int b);
EXTERN_C void func_80080530(void *self, int a, int b, int c);
EXTERN_C void func_800806F4(void *self);
EXTERN_C void func_80080828(void *self);
EXTERN_C void func_800808AC(void *self);
EXTERN_C void func_80080990(void *self, int a, int b, int c);
EXTERN_C int func_80080A2C(void *self, int a1, int a2, int a3, int a4);
EXTERN_C void func_80080AE8(void *self, int b);
EXTERN_C void func_80080B60(void *self, int b);
EXTERN_C void func_80080BC4(void *self, int b);
EXTERN_C int func_80080CC8(void *self, int b);
EXTERN_C void *func_80081748(void *self);
EXTERN_C void func_800817C8(void *self);
EXTERN_C void func_80081820(void *, int, int, int, void *, int);
EXTERN_C int func_80081970(void *self, void *x);
EXTERN_C void func_80081A74(void *self, int x);
EXTERN_C void func_80081BA4(void *self, int x);
EXTERN_C void func_80081CB8(void *self, int x);
EXTERN_C void func_80081DCC(void *self, int x);
#ifndef EXE_H_IN_u_80071A74
EXTERN_C void func_80074E78(void *a, void *b);
EXTERN_C void *func_80074EA4(void *head);
EXTERN_C int func_80074EE8(void *a);
EXTERN_C void func_80075004(void *self, void *n);
EXTERN_C void *func_8007A9DC(void *l, int x);
EXTERN_C void *func_8007AB78(void *l, int x);
EXTERN_C void *func_8007AC38(void *l, int x);
EXTERN_C int func_8007E658(void *self);
#endif

/* u_80082174.cpp */
EXTERN_C void func_800824C8(void *, int);
EXTERN_C void func_800825FC(short *self, int b);
EXTERN_C void *func_80082690(void *self);
EXTERN_C void *func_80082768(void *self);
EXTERN_C void *func_80082798(void *self, int b, int c);
EXTERN_C void func_800827C4(void *self, int flags);
EXTERN_C void func_8008299C(void *, int, int, int, int, int, int);
EXTERN_C void func_80082E14(void *self, int b);
EXTERN_C void func_8008316C(void *self);
EXTERN_C void func_800832F0(void *self);
EXTERN_C void func_80083310(void *self);
EXTERN_C int func_800833F8(void *);
#ifndef EXE_H_IN_u_80082174
EXTERN_C void *func_80082470(void *self);
EXTERN_C void *func_80082714(void *self, int b, int c, int d, int e, int f, int g);
EXTERN_C void func_80082C68(void *self, short b, int c, int d, unsigned short e);
EXTERN_C void func_80082D44(void *self, short b, int c, int d, int e);
#endif

/* u_80083EB4.cpp */
EXTERN_C int func_80083F40(void *self, int id);
EXTERN_C void func_80084674(void *self);
EXTERN_C void func_800846EC(void *, int);
EXTERN_C void func_80084824(void *, int);
EXTERN_C void func_800849D0(void *q, T_VEC v, int a, int b);
EXTERN_C void func_80084B78(void *self, int b);
EXTERN_C void func_80084D58(void *, int);
EXTERN_C void func_80084F58(void *, int);
#ifndef EXE_H_IN_u_80083EB4
EXTERN_C void func_80083EB4(void *self);
#endif

/* u_80085168.cpp */
EXTERN_C void func_80085168(void *, int);
EXTERN_C void func_800852DC(void *self, int b);
EXTERN_C void *func_80085A08(void *self, S8_80085A08 s, int d);
EXTERN_C void func_80085A58(void *self);
EXTERN_C int func_80085A60(void *self, Pair_80085A60 v);
EXTERN_C void *func_80085AD4(void *self, int b, int c);
EXTERN_C void *func_80085BA4(void *self);
EXTERN_C void func_80085BD8(void *self, int b);
EXTERN_C void func_80085C00(void *self);
EXTERN_C void func_80085C60(void *self, int b);
EXTERN_C void func_80085DC0(void *self);
EXTERN_C void func_80085E14(void *self);
EXTERN_C void func_80085E74(void *self, int b);
EXTERN_C void func_80085FD4(void *self);
EXTERN_C void func_80086028(void *self);
EXTERN_C void func_80086088(void *self, int b);
EXTERN_C void func_800861E8(void *self);
EXTERN_C void func_8008655C(short *p);
EXTERN_C void *func_80086578(void *, void *);
EXTERN_C Vec_80086670 func_80086670(Vec_80086670 &a, void *b);
EXTERN_C void *func_8008672C(char *p);
EXTERN_C void func_8008687C(void *, int);
EXTERN_C void func_8008691C(void *self);
EXTERN_C void func_80086990(void *self, int n, signed char *first, ...);
EXTERN_C void func_80086B70(void *self, int v);
EXTERN_C void func_80086CAC(void *self, int v);
EXTERN_C void func_80086E14(char *self);
EXTERN_C void func_80086E74(void *self);
EXTERN_C int func_80086F94(char *self, void *b, int c);
EXTERN_C int func_800872B8(char *self, char *b, int c);
EXTERN_C void func_800873A8(void *self, void *b, int c);
EXTERN_C void func_800874C4(void *self, void *b, int c);
EXTERN_C void func_80087620(void *self, void *b, int c);
EXTERN_C void func_80087764(void *self, void *b, int c);
EXTERN_C void func_80087880(void *self, int b);
EXTERN_C void func_80087C2C(void *self, void *b, int c, int d);
EXTERN_C void func_8008816C(void *self, void *b, int c);
#ifndef EXE_H_IN_u_80085168
EXTERN_C void *func_80085B28(void *self, void *b);
EXTERN_C void func_80085D7C(void *self);
EXTERN_C void func_80085F90(void *self);
EXTERN_C void func_800861A4(void *self);
EXTERN_C void func_800867B0(void *self, void *s);
EXTERN_C void *func_80086814(void *self, void *s);
EXTERN_C void func_80086DB4(void *self);
EXTERN_C int func_800870E4(char *self, void *b, void *c, int d);
#endif

/* u_80089024.cpp */
EXTERN_C int func_80089024(void *self);
EXTERN_C int func_8008906C(void *self);
EXTERN_C int func_800890B4(void *self);
EXTERN_C void func_800890F0(void *self, void *b, int c);
EXTERN_C void func_80089178(void *self, int b);
EXTERN_C unsigned short func_800891C0(void *, void *, void *);
EXTERN_C void func_80089804(char *out, char *src, int idx, int lo, int hi);
EXTERN_C void func_800898F0(void *self);
EXTERN_C unsigned char *func_800898FC(unsigned char *a, signed char *b);
EXTERN_C unsigned char *func_80089954(unsigned char *a, signed char *b);
EXTERN_C unsigned char *func_80089AC0(unsigned char *a, unsigned char *b, unsigned char *c, unsigned int d, unsigned int e, unsigned int f);
EXTERN_C signed char *func_80089B44(signed char *, signed char *, signed char *);
EXTERN_C void func_80089D80(unsigned char *p, int n);
EXTERN_C signed char *func_80089DB8(signed char *a, signed char *b);
EXTERN_C signed char *func_80089E14(signed char *a, signed char *b);
EXTERN_C SBytes8_80089F10 func_80089F10(signed char *src, int d);
EXTERN_C int func_8008A2A0(void *);
EXTERN_C int func_8008A54C(void *self, int b);
EXTERN_C int func_8008A5C8(char *self, char *b, char *c);
EXTERN_C int func_8008B130(void *self, int b);
EXTERN_C void func_8008B150(void *, void *, int, int, int);
EXTERN_C int func_8008B444(int n);
#ifndef EXE_H_IN_u_80089024
EXTERN_C void func_800894AC(char *self, char *b, int c, void *d);
EXTERN_C void *func_800899AC(void *out, void *a, signed char *b);
EXTERN_C int func_8008B4E8(void *p, int b);
EXTERN_C void func_8008B5B4(void *d, void *s);
EXTERN_C void *func_8008B630(void *s, void *d);
#endif

/* sound.cpp */
EXTERN_C int func_8008B888(void);
EXTERN_C void func_8008BA68(void);
EXTERN_C void func_8008BAC4(void);
EXTERN_C void *func_8008BC0C(int size);
EXTERN_C void func_8008BE08(char *);
EXTERN_C void func_8008BF78(char *, int);
EXTERN_C int func_8008C060(int size, unsigned short id);
EXTERN_C int func_8008C3AC(int id);
EXTERN_C void func_8008C724(int a, int b, int c, int d);
EXTERN_C unsigned char func_8008C928(int flags);
EXTERN_C void func_8008CBE4(void);
EXTERN_C void func_8008CC20(int mode);
EXTERN_C void func_8008CD1C(int v, int dur);
EXTERN_C void *func_8008D1F4(void *hdr, int arg);
EXTERN_C void func_8008D4C0(void *bank);
EXTERN_C void *func_8008E360(int a);
EXTERN_C int func_8008E504(char *s);
EXTERN_C void func_8008E590(void *s, int b, int c);
EXTERN_C void func_8008E70C(void *self, int a);
EXTERN_C void func_8008ECB4(void *s);
EXTERN_C void func_8008ED44(void *s);
EXTERN_C void func_8008EF40(int a);
EXTERN_C void func_8008EF64(int a, int b, int c);
EXTERN_C void func_8008FAB4(int id);
EXTERN_C void func_8008FB80(int id, int dur);
EXTERN_C void func_8008FC38(unsigned short id);
EXTERN_C int func_8008FD94(unsigned short id);
EXTERN_C void func_8009482C(int a, int b);
EXTERN_C void func_8009484C(int a, int b);
EXTERN_C void func_80094890(void *p);
EXTERN_C void func_80094908(void);
#ifndef EXE_H_IN_sound
EXTERN_C void *func_8008B6B0(void *p, int n, int mode);
EXTERN_C void func_80093D8C(void *s);
EXTERN_C void func_80093E80(void *s);
#endif

/* PsyQ library functions without a name (0x80094910-0x800B5000) */
EXTERN_C void func_80094990(void);
EXTERN_C void func_800949A0(void);
EXTERN_C void func_800949B0(void *);
EXTERN_C int func_80094A20(void);
EXTERN_C int func_80094FD0(char *);
EXTERN_C int func_800950A0(int);
EXTERN_C int func_80098DA0(void *);
EXTERN_C void func_80098DC0(void *, int);
EXTERN_C void func_80098DF0(void *);
EXTERN_C void func_80098E10(void *);
EXTERN_C void func_80099C60(int, int);
EXTERN_C void func_80099C80(int);
EXTERN_C void func_8009A470(void);
EXTERN_C int func_8009C9C0(void);
EXTERN_C int func_8009C9D0(void);
EXTERN_C int func_8009C9E0(void);
EXTERN_C int func_8009CA80(int, void *);
EXTERN_C void func_8009CAC0(int);
EXTERN_C void func_8009CAE0(int);
EXTERN_C void func_8009D000(int);
EXTERN_C void func_8009DDC0(int);
EXTERN_C void func_8009EAE0(void);
EXTERN_C void func_8009EBC0(int, int);
EXTERN_C void func_8009F0E0(int, int);
EXTERN_C int func_8009F2C0(void);
EXTERN_C unsigned long func_8009F5E0(unsigned char *, unsigned long);
EXTERN_C void (*func_8009F6D0(void (*f)(void)))(void);
EXTERN_C void func_8009F700(int, int);
EXTERN_C void func_800A0800(int, int);
EXTERN_C void func_800A0A10(long *);
EXTERN_C void func_800A0D0C(void *);
EXTERN_C void *func_800A0D2C(int);
EXTERN_C int func_800A1B9C(void);

#endif /* SHARED_EXE_H */
