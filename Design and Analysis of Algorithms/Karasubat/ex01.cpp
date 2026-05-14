class BasicMultiplication
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
    long multiply(long a, long b)
    {
        long result = 0;
        int numberOfDigits = 0;
        while (b > 0)
        {
            int lastDigit = b % 10;
            long intermediate = (a * lastDigit);
            result += intermediate * pow(10, numberOfDigits);
            numberOfDigits++;
            b /= 10;
        }
        return result;
    }
};