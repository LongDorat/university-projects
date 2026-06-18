#include "ex03.h"

static int min_int(int a, int b)
{
    return a < b ? a : b;
}

static int max_int(int a, int b)
{
    return a > b ? a : b;
}

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

big_int karasubat_multiply(big_int x, big_int y)
{
    if (x.size == 0 || y.size == 0)
    {
        return big_int_init(0, 0);
    }
    if (x.size == 1 && y.size == 1)
    {
        int product = x.digits[0] * y.digits[0];
        big_int result = big_int_init(2, 2);
        result.digits[0] = product % 10;
        result.digits[1] = product / 10;
        if (result.digits[1] == 0)
        {
            result.size = 1;
        }
        else
        {
            result.size = 2;
        }
        return result;
    }

    int max_length = max_int(x.size, y.size);
    int half_length = max_length / 2;

    int x_low_len = min_int(half_length, x.size);
    int x_high_len = x.size - x_low_len;
    int y_low_len = min_int(half_length, y.size);
    int y_high_len = y.size - y_low_len;

    big_int a = big_int_init(x_high_len, x_high_len == 0 ? 1 : x_high_len);
    big_int b = big_int_init(x_low_len, x_low_len == 0 ? 1 : x_low_len);
    big_int c = big_int_init(y_high_len, y_high_len == 0 ? 1 : y_high_len);
    big_int d = big_int_init(y_low_len, y_low_len == 0 ? 1 : y_low_len);

    for (int i = 0; i < a.size; ++i)
    {
        a.digits[i] = x.digits[i + x_low_len];
    }
    for (int i = 0; i < b.size; ++i)
    {
        b.digits[i] = x.digits[i];
    }
    for (int i = 0; i < c.size; ++i)
    {
        c.digits[i] = y.digits[i + y_low_len];
    }
    for (int i = 0; i < d.size; ++i)
    {
        d.digits[i] = y.digits[i];
    }

    big_int ac = karasubat_multiply(a, c);
    big_int bd = karasubat_multiply(b, d);

    big_int abcd = karasubat_multiply(big_int_add(a, b), big_int_add(c, d));
    big_int mid = big_int_subtract(big_int_subtract(abcd, ac), bd);

    int result_capacity = x.size + y.size + 1;
    big_int result = big_int_init(result_capacity, result_capacity);

    for (int i = 0; i < ac.size; ++i)
    {
        result.digits[i + 2 * half_length] += ac.digits[i];
    }
    for (int i = 0; i < mid.size; ++i)
    {
        result.digits[i + half_length] += mid.digits[i];
    }
    for (int i = 0; i < bd.size; ++i)
    {
        result.digits[i] += bd.digits[i];
    }
    normalize_digits(&result);
    result.isNegative = (x.isNegative != y.isNegative);
    if (result.size == 1 && result.digits[0] == 0)
    {
        result.isNegative = 0;
    }
    return result;
}