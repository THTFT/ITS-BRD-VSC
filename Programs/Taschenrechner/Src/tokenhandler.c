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
   switch (token.tok) { //NOLINT(bugprone-switch-missing-default-case)
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
   case DIV:
      handle_error(div());
      break;
   case PRT:
      handle_error(print_top());
      break;
   case SWAP:
      handle_error(swap());
      break;
   case PRT_ALL:
      handle_error(print_all());
      break;
   case CLEAR:
      clear();
      break;
   case DOUBLE:
      handle_error(dup());
      break;
   case UNEXPECTED:
      handle_error(UNEXPECTED_ERR);
      break;
   case OVERFLOW:
      handle_error(OVERFLOW);
      break;
   }
}