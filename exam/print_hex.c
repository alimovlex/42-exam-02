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
#include <stdint.h>

int ft_atoi(const char* str);

void print_hex(char *str)
{
    unsigned int number = 0;
    unsigned int digit;
    unsigned int divisor = 1;
    char c;

    // 1. Pointer traversal to convert string to unsigned integer
    number = ft_atoi(str);

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
    unsigned int number = ft_atoi(str);

    // Table 1 holds "01234567"
    uint64_t t1 = ((uint64_t)'0' << 0)  | ((uint64_t)'1' << 8)  |
                  ((uint64_t)'2' << 16) | ((uint64_t)'3' << 24) |
                  ((uint64_t)'4' << 32) | ((uint64_t)'5' << 40) |
                  ((uint64_t)'6' << 48) | ((uint64_t)'7' << 56);

    // Table 2 holds "89abcdef"
    uint64_t t2 = ((uint64_t)'8' << 0)  | ((uint64_t)'9' << 8)  |
                  ((uint64_t)'a' << 16) | ((uint64_t)'b' << 24) |
                  ((uint64_t)'c' << 32) | ((uint64_t)'d' << 40) |
                  ((uint64_t)'e' << 48) | ((uint64_t)'f' << 56);

    int shift = 28;

    // Skip leading zeros.
    // Stop if we find the first significant digit or if we reach shift == 0
    // (to ensure '0' is printed if the input value is zero).
    while (shift > 0 && ((number >> shift) & 0xF) == 0)
        shift -= 4;

    // Main printing loop
    while (shift >= 0)
    {
        unsigned int digit = (number >> shift) & 0xF;

        // BRANCHLESS TABLE SELECTION
        uint64_t mask = -((uint64_t)(digit >> 3) & 1);
        uint64_t active_table = (t1 & ~mask) | (t2 & mask);

        // Extract the character
        char c = (active_table >> ((digit & 7) * 8)) & 0xFF;

        write(1, &c, 1);
        shift -= 4;
    }
    write(1, "\n", 1);
}

void print_hex(char *str)
{
    unsigned int number = ft_atoi(str);
    // Create our two 64-bit halves
    uint64_t t1 = ((uint64_t)'0' << 0)  | ((uint64_t)'1' << 8)  |
                  ((uint64_t)'2' << 16) | ((uint64_t)'3' << 24) |
                  ((uint64_t)'4' << 32) | ((uint64_t)'5' << 40) |
                  ((uint64_t)'6' << 48) | ((uint64_t)'7' << 56);

    // Table 2 holds "89abcdef"
    uint64_t t2 = ((uint64_t)'8' << 0)  | ((uint64_t)'9' << 8)  |
                  ((uint64_t)'a' << 16) | ((uint64_t)'b' << 24) |
                  ((uint64_t)'c' << 32) | ((uint64_t)'d' << 40) |
                  ((uint64_t)'e' << 48) | ((uint64_t)'f' << 56);

    // Pack them into a single 128-bit variable
    // Shift the second table up by 64 bits, then OR it with the first table
    unsigned __int128 table = ((unsigned __int128)t2 << 64) | t1;

    int shift = 28;

    // Skip leading zeros.
    // Stop if we find the first significant digit or if we reach shift == 0
    // (to ensure '0' is printed if the input value is zero).
    while (shift > 0 && ((number >> shift) & 0xF) == 0)
        shift -= 4;

    while (shift >= 0)
    {
        unsigned int digit = (number >> shift) & 15; //0xF

        // THE MAGIC FORMULA
        // Because the table is 128 bits, we can safely multiply by 8 up to digit 15
        char c = (table >> (digit * 8)) & 255; //0xFF

        write(1, &c, 1);
        shift -= 4;
    }
    write(1, "\n", 1);
}

void print_hex(char *str)
{
    unsigned int number = 0;
    unsigned int divisor = 1;

    // 1. Convert string to number (custom atoi)
    number = ft_atoi(str);

    // 2. Find the maximum power of 16 for our number n
    while (number / divisor >= 16)
        divisor *= 16;

    // 3. Process left to right: divide, print, get remainder
    while (divisor > 0)
    {
        // Get the raw digit (0 through 15)
        unsigned int digit = number / divisor;

        // --- THE BITMASK REPLACEMENT ---
        // Create a flag: 0 if digit is 0-9, 1 if digit is 10-15
        unsigned int flag = (digit + 6) >> 4;

        // Apply the bitmask to bridge the 39-character ASCII gap to 'a'
        char c = digit + '0' + ((-flag) & '\'');

        write(1, &c, 1);

        number %= divisor; // Drop the processed left-most digit
        divisor /= 16;     // Decrease the divisor for the next digit
    }
    write(1, "\n", 1);
}

void print_hex(char *str)
{
    unsigned int number = 0;
    unsigned int digit;
    unsigned int divisor = 1;
    char c;

    // 1. Parsing Base 10 using the bitwise & 0x0F trick
    number = ft_atoi(str);

    while (number / divisor >= 16)
        divisor *= 16;

    while (divisor > 0)
    {
        digit = number / divisor;

        // --- THE PURE BITWISE ARRAY REPLACEMENT ---
        // 1. Create a boolean flag (0 if digit < 10, 1 if digit >= 10)
        unsigned int flag = (digit + 6) >> 4;

        // 2. Use Two's Complement negation to turn the flag into a full bitmask
        // If flag == 0, mask = 0x00000000
        // If flag == 1, mask = 0xFFFFFFFF
        unsigned int mask = ~flag + 1;

        // 3. Apply the mask! If >= 10, it adds 39. If < 10, it adds 0.
        c = digit + '0' + (mask & 39);

        write(1, &c, 1);

        number %= divisor;
        divisor /= 16;
    }
    write(1, "\n", 1);
}

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
