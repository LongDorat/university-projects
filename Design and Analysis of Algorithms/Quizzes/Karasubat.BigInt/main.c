#include <stdio.h>

#include "big_int.h"
#include "ex01.h"

int main()
{
    big_int a, b;

    a = big_int_from_cstr("12345");
    b = big_int_from_cstr("67890");

    big_int basic_multiplication = big_int_multiply(a, b);
    printf("Basic Multiplication of %s and %s is: ", "12345", "67890");
    for (int i = basic_multiplication.size - 1; i >= 0; --i)
    {
        printf("%d", basic_multiplication.digits[i]);
    }
    printf("\n");

    return 0;
}