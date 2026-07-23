#include <iostream>
#include <vector>
#include<chrono>

class Timer {
public:
    Timer() : start_time(std::chrono::high_resolution_clock::now()) {}
    void reset() { start_time = std::chrono::high_resolution_clock::now(); }
    double elapsed() const {
        auto end_time = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double>(end_time - start_time).count();
    }
private:
    std::chrono::high_resolution_clock::time_point start_time;
};

long fibonacci_naive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long fibonacci_memoized(int n, std::vector<long>& memo) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fibonacci_memoized(n - 1, memo) + fibonacci_memoized(n - 2, memo);
    return memo[n];
}

long fibonacci_optimized(int n) {
    if (n <= 1) {
        return n;
    }
    long a = 0, b = 1, current;
    for (long i = 2; i <= n; ++i) {
        current = a + b;
        a = b;
        b = current;
    }
    return b;
}

int main()
{
    long n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    Timer timer;
    std::cout << "Fibonacci of " << n << " (naive): " << fibonacci_naive(n) << std::endl;
    std::cout << "Time taken (naive): " << timer.elapsed() << " seconds" << std::endl;

    std::vector<long> memo(n + 1, -1);
    timer.reset();
    std::cout << "Fibonacci of " << n << " (memoized): "<< fibonacci_memoized(n, memo) << std::endl;
    std::cout << "Time taken (memoized): " << timer.elapsed() << " seconds" << std::endl;

    timer.reset();
    std::cout << "Fibonacci of " << n << " (optimized): " << fibonacci_optimized(n) << std::endl;
    std::cout << "Time taken (optimized): " << timer.elapsed() << " seconds" << std::endl;
    return 0;
}