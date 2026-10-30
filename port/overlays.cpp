/* Overlays (tools/port/overlays.py). The EXE loads an overlay by reading its file from the CD into the
   overlay area (ovl_header, or 0x800D5DAC for EFFECT) and then uses it through its header and vtables. On the
   host the overlay's code is compiled in (its functions carry the overlay's prefix) and its data exists as a
   host image of the PS1 bytes, pointers relocated (build/port/data/<name>_image.s). When the CD driver has
   delivered an overlay file's last sector into the overlay area, the image replaces the raw bytes there and
   the overlay becomes current. An overlay that is not linked into this build stops the run. */
#include <string.h>
#include "port_rt.h"
#include "overlays_linked.h"  /* build/port/ovl: PORT_OVL_IMAGE(name) for each linked overlay */

struct Overlay {
    const char *name;
    unsigned base, lba, size;
    const unsigned char *image, *image_end;
};

#define PORT_OVL_IMAGE(n) extern "C" const unsigned char port_ovl_image_##n[], port_ovl_image_##n##_end[];
PORT_OVL_LINKED
#undef PORT_OVL_IMAGE
#define LINKED(n) port_ovl_image_##n, port_ovl_image_##n##_end

static Overlay g_ovl[] = {
    {"MOVIE", 0x800B6DF0, 801, 89272, PORT_OVL_movie},
    {"FIELD", 0x800B6DF0, 1200, 211632, PORT_OVL_field},
    {"BATTLE", 0x800B6DF0, 1400, 126908, PORT_OVL_battle},
    {"CAPTURE", 0x800B6DF0, 1000, 50220, PORT_OVL_capture},
    {"GAMEEND", 0x800B6DF0, 2000, 3248, PORT_OVL_gameend},
    {"EFFECT", 0x800D5DAC, 1600, 64160, PORT_OVL_effect},
};

/* the overlay in the shared slot, and in EFFECT's area (-1: none) */
extern "C" int port_ovl_slot = -1, port_ovl_effect = -1;

/* the CD driver delivered sector lba; the game copied its data to dst (the last CdGetSector) */
extern "C" void port_overlay_sector(int lba, const void *dst)
{
    unsigned a = port_host_to_ps1(dst);
    for (int i = 0; i < (int)(sizeof g_ovl / sizeof g_ovl[0]); i++) {
        Overlay *o = &g_ovl[i];
        int last = o->lba + (o->size + 2047) / 2048 - 1;
        if (lba != last || a < o->base || a >= o->base + o->size)
            continue;
        if (!o->image)
            port_stop("overlay", "%s loaded (LBA %u into %08X): not linked into the host build yet", o->name,
                      o->lba, o->base);
        unsigned char *slot = port_hiram + (o->base - PORT_HIRAM_PS1);
        memcpy(slot, o->image, o->image_end - o->image);
        if (o->base == PORT_HIRAM_PS1)
            port_ovl_slot = i;
        else
            port_ovl_effect = i;
        port_log("overlay: %s loaded, host image installed (%u bytes at %08X)\n", o->name,
                 (unsigned)(o->image_end - o->image), o->base);
    }
}
