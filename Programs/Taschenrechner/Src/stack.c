/**
 * @file stack.c
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief ???
 */

#include "errorhandler.h"
#include "stack.h"
#include "stdbool.h"
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
    if(isFull())
    {
        return STACK_OVERFLOW;
    }
    stack.array[stack.stack_pointer] = number;
    stack.stack_pointer += 1;
    return 0; 
}

int pop(int* result)
{
    if(isEmpty())
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
        return error_code;
    }
    return 0;
}

bool isEmpty()
{
    return (stack.stack_pointer <= 0);
}

bool isFull()
{
    return ((stack.stack_pointer - 1) >= STACK_SIZE);
}