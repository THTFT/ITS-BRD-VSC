/**
 * @file alu.hut
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief ???
 */

#include "errorhandler.h"
#include "stack.h"
#include <stdint.h>


int add()
{
    int a = 0, b = 0;

    int error_code = pop_twice(&a, &b);

    if(error_code != 0)
    {
        return error_code;
    }

    if((a > 0 && b > 0 && INT32_MAX - b) ||
        (a < 0 && b < 0 && a < INT32_MIN - b))
    {
        return OVERFLOW;
    }

    return push((a + b));
}
