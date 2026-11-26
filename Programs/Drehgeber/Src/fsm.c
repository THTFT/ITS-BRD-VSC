#include "fsm.h"
#include "gpio.h"
#include "timer_fsm.h"
#include <stdint.h>

static event event_new;
static state_counter state_counter_new;
static state_counter state_counter_old;
static state state_new;
static state state_old;
static const states states_lookup[][2] = {{A, D}, {B, C}};
static const int event_lookup[][4] = {
       {{IDLE}, {FORWARDS}, {STATE_ERROR}, BACKWARDS},
       {{BACKWARDS}, {IDLE}, {FORWARDS}, {STATE_ERROR}},  // NOLINT
       {{STATE_ERROR}, {BACKWARDS}, {IDLE}, {FORWARDS}},  // NOLINT
       {{FORWARDS}, {STATE_ERROR}, {BACKWARDS}, {IDLE}}}; // NOLINT
static int channel_a = 0;
static int channel_b = 0;

static void set_state(int channel_a, int channel_b) {
   state_new = (state){states_lookup[channel_a][channel_b], get_timestamp()};
}

static int set_event() {
   event_new = (event){event_lookup[state_old.state][state_new.state],
                       state_new.timestamp};
   return event_new.event;
}

static void update_state_counter() {
   int direction = event_new.event;
   if (direction == FORWARDS) {
      state_counter_old = state_counter_new;
      state_counter_new.timestamp = event_new.timestamp;
      ++state_counter_new.counter;
   } else if (direction == BACKWARDS) {
      state_counter_old = state_counter_new;
      state_counter_new.timestamp = event_new.timestamp;
      --state_counter_new.counter;
   }
}

void update_state() {
   state_old = state_new;
   set_state(channel_a, channel_b);
}

void calc_values() {
   set_event();
   update_state_counter();
}

void read_sensors() {
   read_channels(&channel_a, &channel_b);
}

int get_event() { return event_new.event; }

int get_state_counter() { return state_counter_new.counter; }

uint64_t get_event_duration() {
   return state_counter_new.timestamp - state_counter_old.timestamp;
}

int get_state_counter_diff() {
   return state_counter_new.counter - state_counter_old.counter;
}

void init_fsm() {
   state_counter_new = (state_counter){0, 0};
   read_channels(&channel_a, &channel_b);
   set_state(channel_a, channel_b);
   event_new = (event){IDLE, 0};
}

// 0,3/event_new.timestamp = Winkelgeschw.