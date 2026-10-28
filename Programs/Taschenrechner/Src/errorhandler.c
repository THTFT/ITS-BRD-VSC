/**
 * @file errorhandler.c
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief Die Fehlerbehandlung des Taschenrechners.
 */

#include "errorhandler.h"
#include "display.h"

void handle_error(int err)
{
    switch(err)
    {
        case ZERO_DIV:
            print_stdout("Es kann nicht durch 0 geteil werden!\n");
            break;
        case OVERFLOW:
            print_stdout("Es gab eine Bereichsüberschreitung bei einer arithmetischen Operation!\n");
            break;
        case STACK_OVERFLOW:
            print_stdout("Es wurde versucht auf ein Element außerhalb des Stacks zuzugreifen!\n");
            break;
        case STACK_UNDERFLOW:
            print_stdout("Es sind nicht ausreichend Elemente auf dem Stack vorhanden!\n");
            break;
        case UNEXPECTED_ERR:
            print_stdout("Es ist ein unerwarteter Fehler aufgetreren\n");
            break;
        default:
            return;
    }
}