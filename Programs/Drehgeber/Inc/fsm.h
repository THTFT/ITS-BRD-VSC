/**
 * @file fms.h
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief Header file of fsm module.
 */

#ifndef FSM_H
#define FSM_H

#define STATE_ERROR   (-1)
#define IDLE            0
#define FORWARDS        1
#define BACKWARDS       2

/*
 ****************************************************************************************
 * @brief:  This function sets the state of the fsm.
 *
 * @return: void
 ****************************************************************************************/
void set_states(int channel_a, int channel_b);

/*
 ****************************************************************************************
 * @brief:  This function sets the current event of the fsm.
 *
 * @return: the event direction.
 ****************************************************************************************/
int set_event();

/*
 ****************************************************************************************
 * @brief:  This function updates the state counter of the fsm.
 *
 * @return: void
 ****************************************************************************************/
void update_state_counter();

/*
 ****************************************************************************************
 * @brief:  This function updates the states of the fsm.
 *
 * @return: void
 ****************************************************************************************/
void update_state();

int get_event();
int get_state_counter();
void init_fsm();


#endif
