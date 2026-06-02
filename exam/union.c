/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   union.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:20:08 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:20:09 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_union_seen(char *str, unsigned int *seen)
{
    unsigned char c;
    unsigned int bit_mask, offset, index;
    unsigned int *bucket;

    while (*str)
    {
        c = (unsigned char)*str;

        index = c / 32;
        offset = c % 32;
        bit_mask = 1U << offset;

        bucket = seen + index;
        if (!(*bucket & bit_mask))
        {
            write(1, str, 1);
            *bucket |= bit_mask;
        }
        str++;
    }
}

void ft_union(char *s1, char *s2)
{
    // Array of 8 32-bit integers (256 bits total for all ASCII characters)
    unsigned int seen[8] = {0};
    unsigned int* ptr = seen;

    ft_union_seen(s1, ptr);
    ft_union_seen(s2, ptr);

    write(1, "\n", 1);
}

/*
void ft_seen(char *str, unsigned int seen[])
{
    unsigned char c;

    while(*str)
    {
        c = (unsigned char)*str;

        // Check if the specific bit is 0 (character hasn't been seen yet)
        if (!(seen[c / 32] & (1U << (c % 32))))
        {
            write(1, str, 1);
            // Set the specific bit to 1 (mark as printed)
            seen[c / 32] |= (1U << (c % 32));
        }
        str++;
    }
}
*/

/*
void ft_union(char *s1, char *s2)
{
    char printed[256] = {0};
    while (*s1)
    {
        unsigned char c = (unsigned char)*s1;
        if (!printed[c])
        {
            write(1, s1, 1);
            printed[c] = 1;
        }
        s1++;
    }

    while (*s2)
    {
        unsigned char c = (unsigned char)*s2;
        if (!printed[c])
        {
            write(1, s2, 1);
            printed[c] = 1;
        }
        s2++;
    }
    write(1, "\n", 1);
}

void ft_union(char *s1, char *s2)
{
    // Allocating 256 bits of memory on the stack
    unsigned int memory[8] = {0};
    unsigned int *seen = memory;
    unsigned char c;

    // 1. Process the first string
    while (*s1)
    {
        c = (unsigned char)*s1;

        // (c >> 5) moves the pointer to the correct 32-bit block (replaces c / 32)
        // (c & 31) gets the exact bit position inside that block (replaces c % 32)
        if (!(*(seen + (c >> 5)) & (1U << (c & 31))))
        {
            write(1, s1, 1);
            *(seen + (c >> 5)) |= (1U << (c & 31));
        }
        s1++;
    }

    // 2. Process the second string
    while (*s2)
    {
        c = (unsigned char)*s2;

        // Same pointer arithmetic logic
        if (!(*(seen + (c >> 5)) & (1U << (c & 31))))
        {
            write(1, s2, 1);
            *(seen + (c >> 5)) |= (1U << (c & 31));
        }
        s2++;
    }
    write(1, "\n", 1);
}

void ft_union(char *s1, char *s2)
{
    unsigned char seen[32] = {0};
    unsigned char c;
    while (*s1)
    {
        c = (unsigned char)*s1;
        if (!(seen[c >> 3] & (1 << (c & 7))))
        {
            write(1, s1, 1);
            seen[c >> 3] |= (1 << (c & 7));
        }
        s1++;
    }
    while (*s2)
    {
        c = (unsigned char)*s2;
        if (!(seen[c >> 3] & (1 << (c & 7))))
        {
            write(1, s2, 1);
            seen[c >> 3] |= (1 << (c & 7));
        }
        s2++;
    }
    write(1, "\n", 1);
}

void ft_union(char *s1, char *s2)
{
    // Array of 8 32-bit integers (256 bits total for all ASCII characters)
    unsigned int seen[8] = {0};
    unsigned char c;

    // 1. Process the first string
    while (*s1)
    {
        c = (unsigned char)*s1;

        // Check if the specific bit is 0 (character hasn't been seen yet)
        if (!(seen[c / 32] & (1U << (c % 32))))
        {
            write(1, s1, 1);
            // Set the specific bit to 1 (mark as printed)
            seen[c / 32] |= (1U << (c % 32));
        }
        s1++;
    }

    // 2. Process the second string
    while (*s2)
    {
        c = (unsigned char)*s2;

        // Same logic for the second string
        if (!(seen[c / 32] & (1U << (c % 32))))
        {
            write(1, s2, 1);
            seen[c / 32] |= (1U << (c % 32));
        }
        s2++;
    }
    write(1, "\n", 1);
}

void	ft_union(char *s1, char *s2)
{
    // Array for all 256 ASCII characters, initialized to 0
    unsigned char	seen[256] = {0};

    // 1. Process the first string
    while (*s1)
    {
        // If the character hasn't been printed yet
        if (seen[(unsigned char)*s1] == 0)
        {
            write(1, s1, 1);
            seen[(unsigned char)*s1] = 1; // Mark as printed
        }
        s1++;
    }

    // 2. Process the second string
    while (*s2)
    {
        // Same logic for the second string
        if (seen[(unsigned char)*s2] == 0)
        {
            write(1, s2, 1);
            seen[(unsigned char)*s2] = 1; // Mark as printed
        }
        s2++;
    }
    write(1, "\n", 1);
}

void	ft_union(char *s1, char *s2)
{
    char	*curr;
    char	*check;
    int		is_unique;

    // 1. Process the first string
    curr = s1;
    while (*curr)
    {
        check = s1;
        is_unique = 1;
        // Scan backwards from current position to the start of s1
        while (check < curr)
        {
            if (*check == *curr)
            {
                is_unique = 0;
                break ;
            }
            check++;
        }
        if (is_unique)
            write(1, curr, 1);
        curr++;
    }

    // 2. Process the second string
    curr = s2;
    while (*curr)
    {
        is_unique = 1;
        // First, check if the character exists anywhere in the entire s1
        check = s1;
        while (*check)
        {
            if (*check == *curr)
            {
                is_unique = 0;
                break ;
            }
            check++;
        }
        // If not in s1, check if it appeared earlier in s2
        if (is_unique)
        {
            check = s2;
            while (check < curr)
            {
                if (*check == *curr)
                {
                    is_unique = 0;
                    break ;
                }
                check++;
            }
        }
        if (is_unique)
            write(1, curr, 1);
        curr++;
    }
    write(1, "\n", 1);
}
*/
