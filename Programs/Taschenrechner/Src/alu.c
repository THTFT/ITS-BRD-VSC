/**
 * @file alu.h
 * @author Cord Harms, Timo Hinrichs
 * @date Oktober 2026
 * @brief ???
 */

#include "errorhandler.h"
#include "stack.h"
#include <stdint.h>

// https://www.c-plusplus.net/forum/topic/36129/schnellste-m%C3%B6glichkeit-f%C3%BCr-den-betrag-einer-zahl/10
int betrag(int a)
{
    int result = a;
    if (a < 0)
    {
        result = -a;
    }
    return result;
}

int add()
{
    int a = 0, b = 0;

    int error_code = pop_twice(&a, &b);

    if (error_code != 0)
    {
        return error_code;
    }

    if (
        (a > 0 && b > 0 && a > INT32_MAX - b) ||
        (a < 0 && b < 0 && a < INT32_MIN - b))
    {
        return OVERFLOW;
    }

    return push((a + b));
}

int sub()
{
    int a = 0, b = 0;

    int error_code = pop_twice(&a, &b);

    if (error_code != 0)
    {
        return error_code;
    }

    if (
        (a > 0 && b < 0 && a >INT32_MAX + b) ||
        (a < 0 && b > 0 && a < INT32_MIN + b))
    {
        return OVERFLOW;
    }

    return push((a - b));
}

int mul()
{
    int a = 0, b = 0; // In mul

    int error_code = pop_twice(&a, &b);

    if (error_code != 0)
    {
        return error_code;
    }

    if (
        ((a > 0 && b > 0) && (a > (INT32_MAX / b))) ||
        ((a > 0 && b < 0) && (a < (INT32_MIN / b))) ||
        ((a < 0 && b > 0) && (a < (INT32_MIN / b))) ||
        ((a < 0 && b < 0) && (a < (INT32_MAX / b))))
    {
        return OVERFLOW;
    }

    return push((a * b));
}

int div()
{
    int a = 0, b = 0;

    int error_code = pop_twice(&a, &b);

    if (error_code != 0)
    {
        return error_code;
    }

    if (b == 0)
    {
        return ZERO_DIV;
    }
    else if (a == INT32_MIN && b == -1)
    {
        return OVERFLOW;
    }

    return push((a / b));
}
