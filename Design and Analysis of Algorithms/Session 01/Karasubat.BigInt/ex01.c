#include "ex01.h"

#include "big_int.h"
#include "pow10.h"

static void normalize_digits(big_int *value)
{
    int carry = 0;
    for (int i = 0; i < value->capacity; ++i)
    {
        int current = value->digits[i] + carry;
        if (current < 0)
        {
            int borrow = (-current + 9) / 10;
            current += borrow * 10;
            carry = -borrow;
        }
        else
        {
            carry = current / 10;
            current %= 10;
        }
        value->digits[i] = current;
    }

    int new_size = value->capacity;
    while (new_size > 1 && value->digits[new_size - 1] == 0)
    {
        new_size--;
    }
    value->size = new_size;
}

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
    normalize_digits(&result);
    if (a.isNegative != b.isNegative)
    {
        result.isNegative = 1;
    }
    return result;
}