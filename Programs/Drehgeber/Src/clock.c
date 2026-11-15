#include "clock.h"
#include "timer.h"

uint64_t time;
uint32_t time_new;
uint32_t time_old;

void update_clock() {
    time_old = time_new;
    time_new = getTimeStamp();
    time += time_new - time_old;
}

uint64_t get_timestamp() {
    return time;
}