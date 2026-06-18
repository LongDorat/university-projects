#include <stdio.h>

#include "ex01.h"
#include "ex02.h"
#include "ex03.h"

int main(void)
{
    long a = 123456789;
    long b = 987654321;

    printf("Multiplying %ld and %ld is: %ld\n", a, b, a * b);

    printf("Basic Multiplication of %ld and %ld is: %ld\n",
           a, b, basic_multiply(a, b));

    printf("Divine and Conquer Multiplication of %ld and %ld is: %ld\n",
           a, b, divine_and_conquer_multiply(a, b));

    printf("Karasubat Multiplication of %ld and %ld is: %ld\n",
           a, b, karasubat_multiply(a, b));

    return 0;
}
