/**
 * @file fms.h
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief Header file of errorhandler module.
 */

#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <stdbool.h>

extern bool error_state;

/*
 ****************************************************************************************
 * @brief:  This function handles an error of the fsm event.
 *
 * @return: void
 ****************************************************************************************/
void handle_error(int event);

bool get_errorstate();

#endif