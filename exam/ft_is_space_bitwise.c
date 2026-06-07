#include <unistd.h>

int ft_is_space_bitwise(char c)
{
    // Create a 64-bit unsigned int.
    // Shift 1 by 9 for tab, and 1 by 32 for space, then bitwise OR them.
    unsigned long long mask = (1ULL << '\t') | (1ULL << ' ');

    // Protect against negative chars or chars > 63 to prevent
    // undefined behavior when shifting bits.
    if ((unsigned char)c > '?')
        return (0);

    // Shift the mask right by 'c' and bitwise AND with 1.
    // If the bit was set, this returns 1. Otherwise, 0.
    return ((mask >> c) & 1);
}