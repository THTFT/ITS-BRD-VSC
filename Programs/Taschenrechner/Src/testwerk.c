/**
 * @file testwerk.c
 * @author Cord Harms, Timo Hinrichs, Duc Nguyen
 * @date Oct 2026
 * @brief ???
 */


#include "display.h"
#include "stdbool.h"
#include "speicherwerk.h"
#include "token.h"
#include <stdio.h>

void test()
{
    printf("Test");
}

bool test_push_pop()
{
    push(3);
    return (pop() == 3); 
};

