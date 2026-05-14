#include <algorithm>
#include <string>

class DivineAndConquer
{
private:
    long pow(long base, int exponent)
    {
        long result = 1;
        for (int i = 0; i < exponent; i++)
        {
            result *= base;
        }
        return result;
    }

public:
    long multiply(long x, long y)
    {
        if (x == 0 || y == 0)
            return 0;
        if (x < 10 && y < 10)
            return x * y;

        int maxLength = std::max(std::to_string(x).length(), std::to_string(y).length());
        int halfLength = maxLength / 2;

        long a = x / pow(10, halfLength);
        long b = x % static_cast<long>(pow(10, halfLength));
        long c = y / pow(10, halfLength);
        long d = y % static_cast<long>(pow(10, halfLength));

        long ac = multiply(a, c);
        long ad = multiply(a, d);
        long bc = multiply(b, c);
        long bd = multiply(b, d);

        return ac * pow(10, 2 * halfLength) + ((ad + bc) * pow(10, halfLength)) + bd;
    }
};