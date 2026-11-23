#include "angle.h"
#include "fsm.h"
#include "timer_fsm.h"
#include <stdint.h>

#define DEGREES_PER_EVENT (0.3)
#define ONE_SECOND 90000000
#define DISPLAY_UPDATE_INTERVAL_TICKS 27000000
#define IDLE_TIMEOUT_TICKS 270000000
#define MEASURING_RANGE 9999

uint32_t timer;
uint64_t event_time_delta;
//1mi    90
//1ms    90 000
//300ms  27 000 000

int update() {
    timer += get_time_diff();
    if (timer < DISPLAY_UPDATE_INTERVAL_TICKS) {
        return 0;
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
        error_code = STATE_ERROR;
    }
    return error_code;
}

void update_angle_velocity() {
    angle_velocity = (get_state_counter_diff() * DEGREES_PER_EVENT) / ((double) get_event_duration() / ONE_SECOND);
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