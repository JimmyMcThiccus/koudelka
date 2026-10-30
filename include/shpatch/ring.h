// Shadow Hearts patch: Judgment Ring state (src/shpatch/battle/ring.cpp, docs/SH_PATCH_DESIGN.md 2).
#ifndef SHPATCH_RING_H
#define SHPATCH_RING_H

#define SH_RING_MAX_ZONES 3
#define SH_RING_PERIOD_VS 96  // one needle turn: SH's 1.6 s at 60 vsyncs/s
#define SH_RING_SPIN_VS 24    // intro: the coin spin about Y (SH StartSequence 4: 0.4 s)
#define SH_RING_GROW_VS 18    // then the needle grows in and the zones fade up (state 5: 0.3 s)
#define SH_RING_INTRO_VS (SH_RING_SPIN_VS + SH_RING_GROW_VS)
#define SH_RING_OUTRO_VS 30   // fade out, a success also swells to 1.5x (state 10: 0.5 s)
#define SH_RING_X 240         // centre: SH's (480, 160) on its 640x448 display
#define SH_RING_Y 86
#define SH_RING_Z 2           // OT depths Z..Z+5: the battle OT is reverse ordered, so low = in front (scene 5202..5717)

enum { SH_RING_OFF, SH_RING_INTRO, SH_RING_SWEEP, SH_RING_OUTRO };

struct ShZone { short start, end, strike; };  // degrees, absolute; strike area = [end - strike, end]

struct ShRing {
    int phase;
    void *mgr;
    int pad, arg;          // the targeting confirm, replayed into func_800CB174 when the ring ends
    int ev[8];             // a copy of the confirm's input event: the game reuses the original before the ring ends
    int nzones;
    ShZone zone[SH_RING_MAX_ZONES];
    int angle16;           // needle angle, 1/16 degree
    int presses, hits, strikes, missed;
    int mark[SH_RING_MAX_ZONES];       // needle angle at each press, -1 = none
    int mark_kind[SH_RING_MAX_ZONES];  // 0 miss, 1 hit, 2 strike
    int mark_vs[SH_RING_MAX_ZONES];    // VSync count at each press, for the labels
    int timer, last_vs;
    int result;            // last scale, Q8
};
EXTERN_C ShRing g_ring;

void ring_start(void *mgr, int pad, int arg);
void ring_press(void);
void ring_tick(void);
void ring_finish(void);    // ring_result.cpp: publish the scale, replay the confirm
void ring_draw(void *ot);
void ring_alloc_prims(void);
void ring_free_prims(void);  // the turn driver calls it once the action has resolved
int ring_sin(int deg);       // Q12
int ring_cos(int deg);
void ring_replay(void *mgr, int pad, int arg);  // input.cpp: the original func_800CB174

#endif
