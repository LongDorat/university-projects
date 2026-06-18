#include "ex01.h"

static long pow10_int(int exponent)
{
    long result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= 10;
    }
    return result;
}

long basic_multiply(long a, long b)
{
    long result = 0;
    int number_of_digits = 0;
    while (b > 0)
    {
        int last_digit = (int)(b % 10);
        long intermediate = a * last_digit;
        result += intermediate * pow10_int(number_of_digits);
        number_of_digits++;
        b /= 10;
    }
    return result;
}
