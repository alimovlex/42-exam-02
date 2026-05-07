#include <unistd.h>

unsigned int gcd(unsigned int a, unsigned int b)
{
    while (b != 0)
    {
        unsigned int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

unsigned int lcm(unsigned int a, unsigned int b)
{
    if (a == 0 || b == 0)
        return 0;

    return (a * b) / gcd(a, b);
}

