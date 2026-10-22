/**
 * @file errorhandler.h
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief ???
 */

#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#define ZERO_DIV -1
#define OVERFLOW -2
#define STACK_OVERFLOW -3
#define STACK_UNDERFLOW -4

/*
 ****************************************************************************************
 * @brief : Führt ggf. eine Fehlerbehandlung durch.
 *
 * @return  void
 ****************************************************************************************/
void handle_error(int err);

#endif /* ERRORHANDLER_H */
// EOF