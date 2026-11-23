#include "errorhandler.h"
#include "fsm.h"
#include "gpio.h"

void error_state() {
    set_led_error();
    while(1) {}
}

void handle_error(int event) {
    if (event != STATE_ERROR) {
        return;
    }
    error_state();
}
