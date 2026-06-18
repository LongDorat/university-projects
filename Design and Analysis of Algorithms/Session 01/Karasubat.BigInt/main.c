#include <stdio.h>
#include <stdlib.h>

#include "big_int.h"
#include "ex01.h"
#include "ex02.h"
#include "ex03.h"

int main(int argc, char **argv)
{
    big_int a, b;
    const char *a_str = "12345";
    const char *b_str = "67890";

    if (argc >= 3)
    {
        a_str = argv[1];
        b_str = argv[2];
    }

    a = big_int_from_cstr(a_str);
    b = big_int_from_cstr(b_str);

    big_int basic_multiplication = big_int_multiply(a, b);
    printf("Basic Multiplication of %s and %s is: ", a_str, b_str);
    printf(basic_multiplication.isNegative ? "-" : "");
    for (int i = basic_multiplication.size - 1; i >= 0; --i)
    {
        printf("%d", basic_multiplication.digits[i]);
    }
    printf("\n");

    big_int divine_and_conquer_result = divine_and_conquer_multiply(a, b);
    printf("Divine and Conquer Multiplication of %s and %s is: ", a_str, b_str);
    printf(divine_and_conquer_result.isNegative ? "-" : "");
    for (int i = divine_and_conquer_result.size - 1; i >= 0; --i)
    {
        printf("%d", divine_and_conquer_result.digits[i]);
    }
    printf("\n");

    big_int karasubat_result = karasubat_multiply(a, b);
    printf("Karasubat Multiplication of %s and %s is: ", a_str, b_str);
    printf(karasubat_result.isNegative ? "-" : "");
    for (int i = karasubat_result.size - 1; i >= 0; --i)
    {
        printf("%d", karasubat_result.digits[i]);
    }
    printf("\n");

    return 0;
}