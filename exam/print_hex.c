/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   print_hex.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:18:53 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:18:55 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_hex(char *str)
{
    unsigned int number = 0;
    unsigned int digit;
    unsigned int divisor = 1;
    char c;

    // 1. Pointer traversal to convert string to unsigned integer
    while (*str)
    {
        number *= 10;
        number += *str - '0';
        str++;
    }

    // 2. Find the highest power of 16 (iterative alternative to recursion)
    while (number / divisor >= 16)
        divisor *= 16;

    // 3. Extract and print digits from left to right
    while (divisor > 0)
    {
        digit = number / divisor;

        // 4. The dirty ASCII conversion tactic
        if (digit < 10)
            c = digit + '0';
        else
            c = digit + 'x' - '!'; // 'x'(120) - '!'(33) = 87. 10 + 87 = 97 ('a')

        write(1, &c, 1);

        number %= divisor;
        divisor /= 16;
    }
    write(1, "\n", 1);
}

/*
void print_hex(char *str)
{
    unsigned int number = 0;
    unsigned int digit;
    unsigned int divisor = 1;
    char c;

    // 1. Convert string to unsigned integer
    while (*str)
    {
        number *= 10;
        number += *str - '0';
        str++;
    }

    // 2. Find the largest power of 16 that fits in n
    while (number / divisor >= 16)
        divisor *= 16;

    // 3. Extract and print digits from left to right
    while (divisor > 0)
    {
        digit = number / divisor;

        // 4. Calculate ASCII value without a base string
        if (digit < 10)
            c = digit + '0';      // Map 0-9 to '0'-'9'
        else
            c = (digit - 10) + 'a'; // Map 10-15 to 'a'-'f'

        write(1, &c, 1);

        number %= divisor;
        divisor /= 16;
    }
    write(1, "\n", 1);
}


void print_hex(char *str)
{
    unsigned int number = 0;
    unsigned int divisor = 1;
    char *base = "0123456789abcdef";

    // 1. Convert string to number (our custom atoi)
    while (*str)
    {
        number *= 10;
        number += *str - '0';
        str++;
    }
    // 2. Find the maximum power of 16 for our number n
    while (number / divisor >= 16)
        divisor *= 16;

    // 3. Process left to right: divide, print, get remainder
    while (divisor > 0)
    {
        // Calculate the correct character using pointer arithmetic *(pointer + offset)
        char c = *(base + (number / divisor));

        write(1, &c, 1);

        number %= divisor;   // Drop the processed left-most digit
        divisor /= 16;  // Decrease the divisor for the next digit
    }
    write(1, "\n", 1);
}
 */
