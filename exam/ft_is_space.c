/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_is_space.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <alalimov@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/06/13 06:58:58 by alalimov       #+#    #+#                */
/*   Updated: 2026/06/13 06:59:09 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_is_space(char c)
{
    //Hardcoded mask for standard C whitespace (ASCII 9-13, and 32)
    //unsigned long long mask = 0x100003E00ULL;

    // Create a 64-bit unsigned int.
    // Shift 1 by 9 for tab, and 1 by 32 for space, then bitwise OR them.
    unsigned long long mask = (1ULL << '\t') | (1ULL << ' ') |
                              (1ULL << '\r') | (1ULL << '\n');

    // Protect against negative chars or chars > 63 to prevent
    // undefined behavior when shifting bits.
    if ((unsigned char)c > '?')
        return (0);

    // Shift the mask right by 'c' and bitwise AND with 1.
    // If the bit was set, this returns 1. Otherwise, 0.
    return ((mask >> c) & 1);
}
