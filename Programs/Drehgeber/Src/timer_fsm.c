#include "timer_fsm.h"
#include "timer.h"
#include <stdint.h>

static uint64_t timer_fsm;
static uint32_t time_new;
static uint32_t time_old;

void init_timer_fsm() { timer_fsm = 0; }

void update_timer() {
   time_old = time_new;
   time_new = getTimeStamp();
   timer_fsm += (time_new - time_old);
}

uint64_t get_timestamp() { return timer_fsm; }

uint32_t get_time_diff() { return time_new - time_old; }