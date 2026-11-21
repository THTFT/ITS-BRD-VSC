#include "angle.h"
#include "fsm.h"
#include "timer_fsm.h"
#include <stdint.h>

#define DEGREES_PER_EVENT (0.3)
#define DISPLAY_UPDATE_INTERVAL_TICKS 27000000
#define IDLE_TIMEOUT_TICKS 270000000
#define MEASURING_RANGE 999

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
    timer = 0;
    return update_angle();
}

int update_angle() {
    int error_code = 0;
    angle = DEGREES_PER_EVENT * get_state_counter();
    if ((angle > MEASURING_RANGE) || (angle < (-MEASURING_RANGE))) {
        error_code = 1;
    }
    return error_code;
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