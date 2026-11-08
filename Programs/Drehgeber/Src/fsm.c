#include "fsm.h"


typedef struct{
    char phase;
    int channel_a;
    int channel_b;
} phase;

static phase phase_alt;
static phase phase_aktuell;
int ergebnis;
int anzahl_phasen;

