/**
 * @file alu.h
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief Dieses Modul implementiert das Rechenwerk in unserem Taschenrechner.
 */

#include "errorhandler.h"
#include "stack.h"
#include <stdint.h>

int add()
{
    int result1 = 0;
    int result2 = 0;

    int error_code = pop_twice(&result1, &result2);

    if (error_code != 0)
    {
        return error_code;
    }

    if (
        (result1 > 0 && result2 > 0 && result1 > INT32_MAX - result2) ||
        (result1 < 0 && result2 < 0 && result1 < INT32_MIN - result2))
    {
        return OVERFLOW;
    }

    return push((result1 + result2));
}

int sub()
{
    int result1 = 0;
    int result2 = 0;

    int error_code = pop_twice(&result1, &result2);

    if (error_code != 0)
    {
        return error_code;
    }

    if (
        (result1 > 0 && result2 < 0 && result1 >INT32_MAX + result2) ||
        (result1 < 0 && result2 > 0 && result1 < INT32_MIN + result2))
    {
        return OVERFLOW;
    }

    return push((result1 - result2));
}

int mul()
{
    int result1 = 0;
    int result2 = 0;

    int error_code = pop_twice(&result1, &result2);

    if (error_code != 0)
    {
        return error_code;
    }

    if (
        ((result1 > 0 && result2 > 0) && (result1 > (INT32_MAX / result2))) ||
        ((result1 > 0 && result2 < 0) && (result1 < (INT32_MIN / result2))) ||
        ((result1 < 0 && result2 > 0) && (result1 < (INT32_MIN / result2))) ||
        ((result1 < 0 && result2 < 0) && (result1 < (INT32_MAX / result2))))
    {
        return OVERFLOW;
    }

    return push((result1 * result2));
}

int div()
{
    int result1 = 0;
    int result2 = 0;

    int error_code = pop_twice(&result1, &result2);

    if (error_code != 0)
    {
        return error_code;
    }

    if (result2 == 0)
    {
        return ZERO_DIV;
    }
    if (result1 == INT32_MIN && result2 == -1)  
    {
        return OVERFLOW;
    }

    return push((result1 / result2));
}