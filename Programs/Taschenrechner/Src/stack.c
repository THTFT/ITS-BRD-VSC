/**
 * @file stack.c
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief ???
 */

#include "display.h"
#include "errorhandler.h"
#include "stack.h"
#include "lcd.h"
#include "stdbool.h"
#include <stdio.h>
#include <stdlib.h>
#include "token.h"

#define STACK_SIZE 10

typedef struct {
   int array[STACK_SIZE];
   int stack_pointer;
} Stack;

static Stack stack;

void init_stack(void)
{
    stack.stack_pointer = 0;
}

int push(int number)
{
    if(is_full())
    {
        return STACK_OVERFLOW;
    }
    stack.array[stack.stack_pointer] = number;
    stack.stack_pointer += 1;
    return 0; 
}

int pop(int* result)
{
    if(is_empty())
    {
        return STACK_UNDERFLOW;
    }
    stack.stack_pointer -= 1;
    *result = stack.array[stack.stack_pointer];
    return 0;
}

int pop_twice(int *a, int *b)
{
    int error_code = pop(a);
    if(error_code != 0)
    {
        return error_code;
    }
    error_code = pop(b);
    if(error_code != 0)
    {
        push(*a);
        return error_code;
    }
    return 0;
}

bool is_empty()
{
    return (stack.stack_pointer <= 0);
}

bool is_full()
{
    return ((stack.stack_pointer - 1) >= STACK_SIZE);
}

void int_to_string(int a, char *result)
{
    snprintf(result,  sizeof(result), "%d", a);
}

int print_top()
{
    if (is_empty())
    {
        return STACK_UNDERFLOW;
    }
    int a;
    pop(&a);
    char top_number[20];
    int_to_string(a, top_number);
    print_stdout(top_number);
    push(a);
    return 0;
}

int swap()
{
    int a, b;
    int error_code = pop_twice(&a, &b);
    if (error_code != 0)
    {
        return error_code;
    }
    push(a);
    push(b);
    return 0;
}

int print_all()
{
    int a, b, c;
    int error_code;

    error_code = pop_twice(&a, &b);
    if (error_code != 0)
    {
        return error_code;
    }

    error_code = pop(&c);
    if (error_code != 0)
    {
        push(b);
        push(a);
        return error_code;
    }

    char result[20];
    int_to_string(a, result);
    print_stdout(result);
    int_to_string(b, result);
    print_stdout(result);
    int_to_string(c, result);
    print_stdout(result);

    push(c);
    push(b);
    push(a);

    return 0;
}
