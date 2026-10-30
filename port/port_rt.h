/* PC port runtime: logging and the single stop path (docs/PORT_PHASE2.md section 7). */
#ifndef PORT_RT_H
#define PORT_RT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Log to koudelka.log (next to the exe) and stderr. */
void port_log(const char *fmt, ...);
/* Log once per name (a skipped PsyQ call, a divide check, ...). */
void port_log_once(const char *kind, const char *name);
/* "STOP <kind>: <what>", the call stack, then exit. kind names the reason: overlay, unimplemented,
   hardware, fault, psyq, ... The last STOP line in the log is where the port stops. */
__declspec(noreturn) void port_stop(const char *kind, const char *fmt, ...);
/* PS1 symbol nearest at or below addr (from ps1_syms.txt next to the exe), or "" */
const char *port_ps1_symbol(unsigned int addr, char *buf, int n);

/* The contiguous block that stands for PS1 0x800A4000-0x80200000 (tools/port/gen_data.py). */
extern unsigned char port_ram[];
extern unsigned char port_hiram[];
#define PORT_RAM_PS1 0x800A4000u
#define PORT_RAM_SIZE (0x80200000u - PORT_RAM_PS1)
#define PORT_HIRAM_PS1 0x800B6DF0u
/* host address <-> PS1 address inside that block (0 if outside) */
unsigned int port_host_to_ps1(const void *p);

#ifdef __cplusplus
}
#endif
#endif
