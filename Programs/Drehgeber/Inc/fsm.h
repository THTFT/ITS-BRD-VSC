/**
 * @file fms.h
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief Header file of fsm module.
 */

#ifndef FSM_H
#define FSM_H

#include <stdint.h>
#define STATE_ERROR (-1)
#define IDLE 0
#define FORWARDS 1
#define BACKWARDS 2

typedef enum {
   A = 0,
   B = 1,
   C = 2,
   D = 3,
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
 * @return: An errorcode, if an error has occured.
 ****************************************************************************************/
void update_state();

/*
 ****************************************************************************************
 * @brief:  Gets the current rotation direction.
 *
 * @return: The rotation as a constant.
 ****************************************************************************************/
int get_event();

/*
 ****************************************************************************************
 * @brief:  Gets the current state counter.
 *
 * @return: The counter.
 ****************************************************************************************/
int get_state_counter();

/*
 ****************************************************************************************
 * @brief:  Gets the delta between the newest and last event.
 *
 * @return: The delta in ticks.
 ****************************************************************************************/
uint64_t get_event_duration();

/*
 ****************************************************************************************
 * @brief:  Gets the delta of the state counter of the last and newest event.
 *
 * @return: The counter difference.
 ****************************************************************************************/
int get_state_counter_diff();

/*
 ****************************************************************************************
 * @brief:  Initializes the fsm.
 *
 * @return: void
 ****************************************************************************************/
void init_fsm();

/*
 ****************************************************************************************
 * @brief:  Reads the sensors.
 *
 * @return: void
 ****************************************************************************************/
void read_sensors();

/*
 ****************************************************************************************
 * @brief:  Calculates the values vor the output.
 *
 * @return: void
 ****************************************************************************************/
void calc_values();

#endif
