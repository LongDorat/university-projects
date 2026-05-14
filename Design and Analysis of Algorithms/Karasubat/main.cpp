#include <iostream>

#include "ex01.cpp"

int main(int argc, char* argv[]) {
    long a = 123456789;
    long b = 987654321;

    BasicMultiplication bm;
    std::cout << "Basic Multiplication of " << a << " and " << b << " is: " << bm.multiply(a, b) << std::endl;
    return 0;
}