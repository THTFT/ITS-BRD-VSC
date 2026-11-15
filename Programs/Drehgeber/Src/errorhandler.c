#include "errorhandler.h"
#include "fsm.h"

void handle_error(int event) {
    if (event != ERROR) {
        return;
    }
    error_state = true;
}