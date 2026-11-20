#include "timer.h"
#include "timer_fsm.h"
#include <stdint.h>

uint64_t timer_fsm;
uint32_t time_new;
uint32_t time_old;

void update_timer() {
    time_old = time_new;
    time_new = getTimeStamp();
    timer_fsm += time_new - time_old;
}

uint64_t get_timestamp() {
    return timer_fsm;
}

uint32_t get_time_diff() {
    return time_new - time_old;
}