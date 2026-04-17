#include <unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
    int a, b;
    a = octet >> 4;
    b = octet << 4;
    return a+b;
}