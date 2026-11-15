#include "angle.h"
#include "fsm.h"
#include "clock.h"
#include <stdint.h>

#define DEGREES_PER_EVENT (0.3)
#define DISPLAY_UPDATE_INTERVAL_TICKS 27000000
#define IDLE_TIMEOUT_TICKS 270000000

uint32_t timer;

// 0: werte wurden nicht geupdatet; 1: 300ms sind vergangen
int update(int state_counter, uint32_t state_counter_timestamp, int event) {
    timer += state_counter_timestamp;
    uint64_t event_time_delta = get_timestamp() - state_counter_timestamp;

    if (timer <= DISPLAY_UPDATE_INTERVAL_TICKS) {
        return 0;
    }

    if ((event == IDLE) && (event_time_delta > IDLE_TIMEOUT_TICKS)) {
        angle_velocity = 0;
    }
    else {
        update_angle_velocity(event);
    }
    update_angle(state_counter);
    timer = 0;
    return 1;
}

void update_angle(int state_counter) {
    angle = DEGREES_PER_EVENT * state_counter;
}

void update_angle_velocity(int event) {
    angle_velocity = event / DEGREES_PER_EVENT;
}

double get_angle() {
    return angle;
}

double get_angle_velocity() {
    return angle_velocity;
}