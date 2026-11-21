#include "angle.h"
#include "fsm.h"
#include "timer_fsm.h"
#include <stdint.h>

#define DEGREES_PER_EVENT (0.3)
#define DISPLAY_UPDATE_INTERVAL_TICKS 27000000
#define IDLE_TIMEOUT_TICKS 270000000

uint32_t timer;
uint64_t event_time_delta;


int update() {
    timer += get_time_diff();
    if (timer < DISPLAY_UPDATE_INTERVAL_TICKS) {
        return -1;
    }
    if ((timer > IDLE_TIMEOUT_TICKS) && (get_event() == IDLE)) {
        angle_velocity = 0;
        return 0;
    }
    update_angle_velocity();
    update_angle();
    timer = 0;
    return 0;
}

void update_angle() {
    angle += DEGREES_PER_EVENT * get_state_counter();
}

void update_angle_velocity() {
    angle_velocity = DEGREES_PER_EVENT / get_time_diff();
}

double get_angle() {
    return angle;
}

double get_angle_velocity() {
    return angle_velocity;
}

void init_angle() {
    timer = 0;
}