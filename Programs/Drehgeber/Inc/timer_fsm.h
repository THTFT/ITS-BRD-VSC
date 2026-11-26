/**
 * @file gpio.h
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief Header file of timer_fsm module.
 */

#include <stdint.h>

/*
 ****************************************************************************************
 * @brief:  Updates the timer.
 *
 * @return: void
 ****************************************************************************************/
void update_timer();

/*
 ****************************************************************************************
 * @brief:  Gets the timestamp of the timer.
 *
 * @return: The timestamp.
 ****************************************************************************************/
uint64_t get_timestamp();

/*
 ****************************************************************************************
 * @brief:  Gets the time difference between now and the last time messurement.
 *
 * @return: The delta in ticks.
 ****************************************************************************************/
uint32_t get_time_diff();

/*
 ****************************************************************************************
 * @brief:  Initializes the timer.
 *
 * @return: void.
 ****************************************************************************************/
void init_timer_fsm();