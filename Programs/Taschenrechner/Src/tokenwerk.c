/**
 ******************************************************************************
 * @file    tokenwerk.c
 * @author  Cord Harms, Timo Hinrichs, Duc Nguyen
 ******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/

#include "token.h"
#include "tokenwerk.h"

void verarbeite_token(T_token token)
{
    switch(token.tok)
    {
        case NUMBER:                // auf Stack speichern
        case PLUS:
        case MINUS:
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