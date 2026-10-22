/**
 * @file tokenhandler.c
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief ???
 */

#include "alu.h"
#include "errorhandler.h"
#include "stack.h"
#include "token.h"
#include "tokenhandler.h"

int process_token(T_token token)
{
    switch(token.tok)
    {
        case NUMBER:
            handle_error(push(token.val));
            break;
        case PLUS:
            handle_error(add());
            break;
        case MINUS:
            handle_error(sub());
            break;

        case MULT:
        case DIV:                   // Zahlen holen, Rechnung durchführen, ergebnis auf Stack speichern
        case PRT:                   // letzte Zahl holen, auf Display ausgegben
        case SWAP:                  // letzten beiden Zahlen auf Stack tauschen
        case PRT_ALL:               // die drei obersten Zahlen vom Stack auf Display ausgeben
        case CLEAR:                 // Stack leeren
        case DOUBLE:                // letzte Zahl vom Stack verdoppeln
        case ENTER:
        case UNEXPECTED:            // Error-Handler
        case OVERFLOW:              // Error-Handler
        default:
    }
};