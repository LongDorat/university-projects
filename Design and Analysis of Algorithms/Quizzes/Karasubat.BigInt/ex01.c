#include "ex01.h"

#include "big_int.h"
#include "pow10.h"

big_int big_int_multiply(big_int a, big_int b)
{
    big_int result;
    result = big_int_init(a.size + b.size, a.size + b.size);

    for (int i = 0; i < a.size; ++i)
    {
        int carry = 0;
        for (int j = 0; j < b.size || carry > 0; ++j)
        {
            long long current = result.digits[i + j] +
                                (long long)a.digits[i] * (j < b.size ? b.digits[j] : 0) + carry;
            result.digits[i + j] = (int)(current % 10);
            carry = (int)(current / 10);
        }
    }
    if (result.digits[result.size - 1] == 0)
    {
        result.size--;
    }
    if (a.isNegative != b.isNegative)
    {
        result.isNegative = 1;
    }
    return result;
}