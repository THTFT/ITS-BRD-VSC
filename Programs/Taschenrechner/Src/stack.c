/**
 * @file stack.c
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief Das Speicherwerk des Taschenrechners.
 */

#include "stack.h"
#include "display.h"
#include "errorhandler.h"
#include "stdbool.h"
#include <stdio.h>

#define STACK_SIZE 20

typedef struct {
   int array[STACK_SIZE];
   int stack_pointer;
} Stack;

static Stack stack;

void init_stack(void) { stack.stack_pointer = 0; }

int push(int number) {
   if (is_full()) {
      return STACK_OVERFLOW_ERR;
   }
   stack.array[stack.stack_pointer] = number;
   stack.stack_pointer += 1;
   return 0;
}

int pop(int *result1) {
   if (is_empty()) {
      return STACK_UNDERFLOW_ERR;
   }
   stack.stack_pointer -= 1;
   *result1 = stack.array[stack.stack_pointer];
   return 0;
}

int pop_twice(int *result1, int *result2) {
   int error_code = pop(result1);
   if (error_code != 0) {
      return error_code;
   }
   error_code = pop(result2);
   if (error_code != 0) {
      push(*result1);
      return error_code;
   }
   return 0;
}

bool is_empty() { return (stack.stack_pointer <= 0); }

bool is_full() { return (stack.stack_pointer >= STACK_SIZE); }

void int_to_string(int result1, char *result) {
   snprintf(result, STACK_SIZE, "%d", result1);
}

int print_top() {
   if (is_empty()) {
      return STACK_UNDERFLOW_ERR;
   }
   int result1;
   pop(&result1);
   char top_number[STACK_SIZE];
   int_to_string(result1, top_number);
   print_stdout(top_number);
   push(result1);
   return 0;
}

int swap() {
   int result1;
   int result2;
   int error_code = pop_twice(&result1, &result2);
   if (error_code != 0) {
      return error_code;
   }
   push(result1);
   push(result2);
   return 0;
}

int print_all() {
   int result1;
   int result2;
   int result3;
   int error_code;

   error_code = pop_twice(&result1, &result2);
   if (error_code != 0) {
      return error_code;
   }

   char result[STACK_SIZE];
   int_to_string(result1, result);
   print_stdout(result);
   print_stdout("\n");
   int_to_string(result2, result);
   print_stdout(result);
   print_stdout("\n");

   error_code = pop(&result3);
   if (error_code != 0) {
      push(result2);
      push(result1);
      return error_code;
   }

   int_to_string(result3, result);
   print_stdout(result);
   print_stdout("\n");

   push(result3);
   push(result2);
   push(result1);

   return 0;
}

void clear() {
   stack.stack_pointer = 0;
   clear_stdout();
}

int dup() {
   int result1;
   int error_code = pop(&result1);
   if (error_code != 0) {
      return error_code;
   }
   error_code = push(result1);
   if (error_code != 0) {
      return error_code;
   }
   error_code = push(result1);
   if (error_code != 0) {
      return error_code;
   }
   return 0;
}