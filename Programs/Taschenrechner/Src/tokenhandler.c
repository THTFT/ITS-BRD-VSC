/**
 * @file tokenhandler.c
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief Die Eingabeverarbeitung des Taschenrechneres.
 */

#include "tokenhandler.h"
#include "alu.h"
#include "errorhandler.h"
#include "stack.h"
#include "token.h"

void process_token(T_token token) {
   switch (token.tok) {
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
      handle_error(mul());
      break;
   case DIV: // Zahlen holen, Rechnung durchführen, ergebnis auf Stack speichern
      handle_error(div());
      break;
   case PRT: // letzte Zahl holen, auf Display ausgegben
      handle_error(print_top());
      break;
   case SWAP: // letzten beiden Zahlen auf Stack tauschen
      handle_error(swap());
      break;
   case PRT_ALL: // die drei obersten Zahlen vom Stack auf Display ausgeben
      handle_error(print_all());
      break;
   case CLEAR: // Stack leeren
      clear();
      break;
   case DOUBLE: // letzte Zahl vom Stack verdoppeln
      handle_error(dup());
      break;
   case UNEXPECTED: // Error-Handler
      handle_error(UNEXPECTED_ERR);
      break;
   case OVERFLOW: // Error-Handler
      handle_error(OVERFLOW);
      break;
   }
}