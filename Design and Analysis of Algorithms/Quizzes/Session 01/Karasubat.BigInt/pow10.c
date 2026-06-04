#include "pow10.h"

long pow10_int(int exponent)
{
    long result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= 10;
    }
    return result;
}
