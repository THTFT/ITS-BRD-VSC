/**
 * @file fms.h
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief Header file of fsm module.
 */

#ifndef FSM_H
#define FSM_H

#include <stdint.h>
#define STATE_ERROR   (-1)
#define IDLE            0
#define FORWARDS        1
#define BACKWARDS       2

typedef enum {
    A=0, B=1, C=2, D=3,
} states;

typedef struct {
    states state;
    uint64_t timestamp;
} state;

typedef struct {
    int event;
    uint64_t timestamp;
} event;

typedef struct {
    int counter;
    uint64_t timestamp;
} state_counter;

/*
 ****************************************************************************************
 * @brief:  This function updates the states of the fsm.
 *
 * @return: void
 ****************************************************************************************/
int update_state();

int get_event();
int get_state_counter();
uint64_t get_event_duration();
int get_state_counter_diff();
void init_fsm();


#endif
