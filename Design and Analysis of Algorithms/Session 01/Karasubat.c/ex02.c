#include "ex02.h"

static long pow10_int(int exponent)
{
    long result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= 10;
    }
    return result;
}

static int num_digits(long value)
{
    int digits = 1;
    while (value >= 10)
    {
        value /= 10;
        digits++;
    }
    return digits;
}

long divine_and_conquer_multiply(long x, long y)
{
    if (x == 0 || y == 0)
    {
        return 0;
    }
    if (x < 10 && y < 10)
    {
        return x * y;
    }

    int max_length = num_digits(x);
    int y_digits = num_digits(y);
    if (y_digits > max_length)
    {
        max_length = y_digits;
    }

    int half_length = max_length / 2;
    long power = pow10_int(half_length);

    long a = x / power;
    long b = x % power;
    long c = y / power;
    long d = y % power;

    long ac = divine_and_conquer_multiply(a, c);
    long ad = divine_and_conquer_multiply(a, d);
    long bc = divine_and_conquer_multiply(b, c);
    long bd = divine_and_conquer_multiply(b, d);

    return ac * pow10_int(2 * half_length) + ((ad + bc) * power) + bd;
}
