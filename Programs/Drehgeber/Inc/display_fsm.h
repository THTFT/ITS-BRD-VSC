/**
 * @file fms.h
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief Header file of display_fsm module.
 */

#ifndef DISPLAY_FSM_H
#define DISPLAY_FSM_H

/*
 ****************************************************************************************
 * @brief:  Initializes the start text on the display.
 *
 * @return: void
 ****************************************************************************************/
void init_display_fsm();

/*
 ****************************************************************************************
 * @brief:  Updates the display with the newest angle and angle velocity values.
 *
 * @return: void
 ****************************************************************************************/
void update_display_fsm();

#endif