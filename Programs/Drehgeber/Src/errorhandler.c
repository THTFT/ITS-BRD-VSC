#include "errorhandler.h"
#include "fsm.h"

bool error_state;

void handle_error(int event) {
    if (event != STATE_ERROR) {
        return;
    }
    error_state = true;
}