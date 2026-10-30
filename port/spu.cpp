/* SPU transfers. The sound driver queues SPU DMA transfers (src/main/sound.cpp func_8008CA50): it sets a busy
   flag, installs a transfer-complete callback (func_8008C9A8, which clears the flag and starts the next
   transfer) and calls SpuWrite/SpuRead; elsewhere it busy-waits on the flag. On the PS1 the callback is the
   DMA-complete interrupt, after SpuWrite has returned. PsyCross calls it inside SpuWrite instead, and the
   game installs it through an unnamed PsyQ function, func_8009F6D0 (SpuSetTransferCallback, by its use
   here). So the port keeps the callback and raises it as an interrupt on the game thread after each
   transfer (port_spu_poll, from port/intr.cpp). PsyCross's versions are renamed psyx_*. */
#include "port_rt.h"

typedef void (*SpuTransferCB)(void);

extern "C" {
unsigned int psyx_SpuWrite(unsigned char *addr, unsigned int size);
unsigned int psyx_SpuRead(unsigned char *addr, unsigned int size);
}

static SpuTransferCB g_xfer_cb;
static int g_xfer_pending;

extern "C" SpuTransferCB SpuSetTransferCallback(SpuTransferCB f)
{
    SpuTransferCB old = g_xfer_cb;
    g_xfer_cb = f;
    return old;
}

extern "C" SpuTransferCB func_8009F6D0(SpuTransferCB f)  /* SpuSetTransferCallback */
{
    return SpuSetTransferCallback(f);
}

extern "C" unsigned int SpuWrite(unsigned char *addr, unsigned int size)
{
    unsigned int r = psyx_SpuWrite(addr, size);
    g_xfer_pending = 1;
    return r;
}

extern "C" unsigned int SpuRead(unsigned char *addr, unsigned int size)
{
    unsigned int r = psyx_SpuRead(addr, size);
    g_xfer_pending = 1;
    return r;
}

/* called by port/intr.cpp with interrupts masked, on the game thread */
extern "C" void port_spu_poll(void)
{
    if (!g_xfer_pending)
        return;
    g_xfer_pending = 0;
    if (g_xfer_cb)
        g_xfer_cb();
}
