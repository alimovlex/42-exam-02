#include <stdlib.h>

int pgcd(const char *s1, const char *s2)
{
    int a = atoi(s1), b = atoi(s2);
    while (b != 0)
    {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

