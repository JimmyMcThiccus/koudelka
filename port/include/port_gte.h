/* Host versions of the GTE inline-asm macros the game's headers define (tools/port/hostify.py removes the
   MIPS ones). They go through PsyCross's software GTE, like the recompiled code (tools/recomp/runtime/recomp.h).
   The command words are the ones in the original macros. */
#ifndef PORT_GTE_H
#define PORT_GTE_H

#ifdef __cplusplus
extern "C" {
#endif
void MTC2(unsigned int value, int reg);
unsigned int MFC2(int reg);
int doCOP2(int op);
#ifdef __cplusplus
}
#endif

#define PORT_LWC2(reg, addr) MTC2(*(unsigned int *)(addr), (reg))

/* h_u_8002ED44.h */
#define gte_ldv3c(r0) do { const char *p_ = (const char *)(r0); \
    PORT_LWC2(0, p_ + 0); PORT_LWC2(1, p_ + 4); PORT_LWC2(2, p_ + 8); \
    PORT_LWC2(3, p_ + 12); PORT_LWC2(4, p_ + 16); PORT_LWC2(5, p_ + 20); } while (0)
#define gte_ldv3m(v) do { PORT_LWC2(0, &(v)[0]); PORT_LWC2(1, &(v)[1]); PORT_LWC2(2, &(v)[2]); \
    PORT_LWC2(3, &(v)[3]); PORT_LWC2(4, &(v)[4]); PORT_LWC2(5, &(v)[5]); } while (0)
#define gte_rtpt() doCOP2(0x0280030)

#endif
