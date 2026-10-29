/**
 * @file errorhandler.h
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief Header file of display module.
 */

#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#define ZERO_DIV_ERR (-1)
#define OVERFLOW_ERR (-2)
#define STACK_OVERFLOW_ERR (-3)
#define STACK_UNDERFLOW_ERR (-4)
#define UNEXPECTED_ERR (-5)

/*
 ****************************************************************************************
 * @brief : Führt eine Fehlerbehandlung durch.
 *
 * @return  void
 ****************************************************************************************/
void handle_error(int err);

#endif /* ERRORHANDLER_H */
       // EOF