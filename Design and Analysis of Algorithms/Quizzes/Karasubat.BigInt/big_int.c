#include "big_int.h"

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
