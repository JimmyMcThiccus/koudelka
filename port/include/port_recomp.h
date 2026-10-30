/* Force-included before tools/recomp/runtime/recomp.h when the port compiles the recompiled functions:
   indirect calls go through port_icall_target (port/recomp_rt.c), which stops on PS1 addresses, null and
   the overlay area, and passes host pointers through. */
#ifndef PORT_RECOMP_H
#define PORT_RECOMP_H
unsigned int port_icall_target(unsigned int x);
#define RECOMP_ICALL_TARGET(x) port_icall_target(x)
#endif
