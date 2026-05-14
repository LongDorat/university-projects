#include "big_int.h"

static int compare_abs(big_int a, big_int b)
{
    int a_size = a.size;
    while (a_size > 1 && a.digits[a_size - 1] == 0)
    {
        a_size--;
    }
    int b_size = b.size;
    while (b_size > 1 && b.digits[b_size - 1] == 0)
    {
        b_size--;
    }

    if (a_size != b_size)
    {
        return a_size > b_size ? 1 : -1;
    }
    for (int i = a_size - 1; i >= 0; --i)
    {
        if (a.digits[i] != b.digits[i])
        {
            return a.digits[i] > b.digits[i] ? 1 : -1;
        }
    }
    return 0;
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
    if (value->size == 1 && value->digits[0] == 0)
    {
        value->isNegative = 0;
    }
}

static big_int add_abs(big_int a, big_int b)
{
    int max_size = a.size > b.size ? a.size : b.size;
    big_int result = big_int_init(max_size + 1, max_size + 1);

    for (int i = 0; i < max_size; ++i)
    {
        int digit_a = i < a.size ? a.digits[i] : 0;
        int digit_b = i < b.size ? b.digits[i] : 0;
        result.digits[i] += digit_a + digit_b;
    }
    normalize_digits(&result);
    return result;
}

static big_int sub_abs(big_int a, big_int b)
{
    int max_size = a.size > b.size ? a.size : b.size;
    big_int result = big_int_init(max_size + 1, max_size + 1);

    for (int i = 0; i < max_size; ++i)
    {
        int digit_a = i < a.size ? a.digits[i] : 0;
        int digit_b = i < b.size ? b.digits[i] : 0;
        result.digits[i] += digit_a - digit_b;
    }
    normalize_digits(&result);
    return result;
}

big_int big_int_init(int size, int capacity)
{
    big_int x;
    x.size = size;
    x.capacity = capacity;
    x.digits = calloc(capacity, sizeof(int));
    x.isNegative = 0;
    return x;
}

big_int big_int_from_cstr(const char *s)
{
    int n = (int)strlen(s);
    big_int x;
    x.size = n;
    x.capacity = n;
    x.digits = calloc(n, sizeof(int));
    x.isNegative = 0;

    if (s[0] == '-')
    {
        x.isNegative = 1;
        s++;
        n--;
    }

    for (int i = 0; i < n; ++i)
    {
        char c = s[n - 1 - i];
        x.digits[i] = c - '0';
    }
    return x;
}

big_int big_int_subtract(big_int a, big_int b)
{
    if (a.isNegative != b.isNegative)
    {
        big_int result = add_abs(a, b);
        result.isNegative = a.isNegative;
        return result;
    }

    int cmp = compare_abs(a, b);
    if (cmp == 0)
    {
        big_int result = big_int_init(1, 1);
        result.digits[0] = 0;
        result.isNegative = 0;
        return result;
    }

    big_int result;
    if (cmp > 0)
    {
        result = sub_abs(a, b);
        result.isNegative = a.isNegative;
    }
    else
    {
        result = sub_abs(b, a);
        result.isNegative = !a.isNegative;
    }
    return result;
}

big_int big_int_add(big_int a, big_int b)
{
    if (a.isNegative != b.isNegative)
    {
        return big_int_subtract(a, (big_int){ .digits = b.digits, .size = b.size, .capacity = b.capacity, .isNegative = !b.isNegative });
    }
    big_int result = add_abs(a, b);
    result.isNegative = a.isNegative;
    return result;
}
