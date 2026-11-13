/**
 * @file fms.h
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief Header file of fsm module.
 */

#ifndef FSM_H
#define FSM_H

#define ERROR     (-1)
#define IDLE        1
#define FORWARDS    2
#define BACKWARDS   3

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
 * @return: void
 ****************************************************************************************/
void set_event();

/*
 ****************************************************************************************
 * @brief:  This function updates the states of the fsm.
 *
 * @return: void
 ****************************************************************************************/
void update_state();


#endif
