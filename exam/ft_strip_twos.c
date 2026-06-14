#include <unistd.h>

int strip_twos(int x)
{
    while ((x & 1) == 0)
        x >>= 1;
    return x;
}
