#include "fsm.h"
#include "gpio.h"
#include <stdint.h>
#include "../Inc/timer.h"

typedef enum {
    A=0, B=1, C=2, D=3                                  // todo: assign values
} states;

typedef struct{
    states state;
    uint32_t timestamp;
} state;

int event;
int state_counter;

static state state_new;
static state state_old;

void set_states(int channel_a, int channel_b) {
    states states_lookup[][2] = {{{A}, {D}}, // NOLINT
                                 {{B}, {C}}}; // NOLINT
    state_old = state_new;
    state_new = (state) { states_lookup[channel_a][channel_b], getTimeStamp() };
}

void set_event() {
    int event_lookup[][4] = {{{IDLE}, {FORWARDS}, {ERROR}, {BACKWARDS}}, //NOLINT
                             {{BACKWARDS}, {IDLE}, {FORWARDS}, {ERROR}}, //NOLINT
                             {{ERROR}, {BACKWARDS}, {IDLE}, {FORWARDS}}, //NOLINT
                             {{FORWARDS}, {ERROR}, {BACKWARDS}, {IDLE}}}; //NOLINT
    event = event_lookup[state_old.state][state_new.state];
}

void update_state(void) {
    int channel_a;
    int channel_b;
    read_channels(&channel_a, &channel_b);
    set_states(channel_a, channel_b);
}

