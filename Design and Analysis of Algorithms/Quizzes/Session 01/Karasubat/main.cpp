#include <iostream>

#include "ex01.cpp"
#include "ex02.cpp"
#include "ex03.cpp"

int main(int argc, char* argv[]) {
    long a = 123456789;
    long b = 987654321;

    std::cout << "Multiplying " << a << " and " << b << " is: " << (a * b) << std::endl;

    BasicMultiplication bm;
    std::cout << "Basic Multiplication of " << a << " and " << b << " is: " << bm.multiply(a, b) << std::endl;

    DivineAndConquer dc;
    std::cout << "Divine and Conquer Multiplication of " << a << " and " << b << " is: " << dc.multiply(a, b) << std::endl;

    Karasubat k;
    std::cout << "Karasubat Multiplication of " << a << " and " << b << " is: " << k.multiply(a, b) << std::endl;

    return 0;
}