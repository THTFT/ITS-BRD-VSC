#include "fsm.h"
#include "gpio.h"
#include <stdint.h>
#include "timer.h"
#include "clock.h"
#include "stm32f4xx_hal_tim.h"
#include "errorhandler.h"

typedef enum {
    A=0, B=1, C=2, D=3
} states;

typedef struct {
    states state;
    uint64_t timestamp;
} state;

typedef struct {
    int event;
    uint64_t timestamp;
} event;

typedef struct {
    int counter;
    uint64_t timestamp;
} state_counter;

event event_new;
state_counter state_counter_new;
// state_counter state_counter_old;

static state state_new;
static state state_old;

void set_states(int channel_a, int channel_b) {
    states states_lookup[][2] = {{{A}, {D}}, // NOLINT
                                 {{B}, {C}}}; // NOLINT
    state_old = state_new;
    state_new = (state) { states_lookup[channel_a][channel_b], get_timestamp() };
}

int set_event() {
    int event_lookup[][4] = {{{IDLE}, {FORWARDS}, {ERROR}, {BACKWARDS}}, //NOLINT
                             {{BACKWARDS}, {IDLE}, {FORWARDS}, {ERROR}}, //NOLINT
                             {{ERROR}, {BACKWARDS}, {IDLE}, {FORWARDS}}, //NOLINT
                             {{FORWARDS}, {ERROR}, {BACKWARDS}, {IDLE}}}; //NOLINT
    event_new = (event) { event_lookup[state_old.state][state_new.state], state_new.timestamp };
    return event_new.event;
}

void update_state_counter() {
    int direction = event_new.event;
    // state_counter_old = state_counter_new;
    if (direction == FORWARDS) {
        state_counter_new.timestamp = event_new.timestamp;
        state_counter_new.counter++;
    }
    else if (direction == BACKWARDS) {
        state_counter_new.timestamp = event_new.timestamp;      
        state_counter_new.counter--;
    }
}

void update_state(void) {
    if (error_state) {
        return;
    }
    int channel_a;
    int channel_b;
    read_channels(&channel_a, &channel_b);
    set_states(channel_a, channel_b);
    handle_error(set_event());
    update_state_counter();
}




// 0,3/event_new.timestamp = Winkelgeschw.