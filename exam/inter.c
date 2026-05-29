/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   inter.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:17:58 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:17:59 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_inter_seen(char *str, unsigned int *primary, unsigned int *secondary, int mode)
{
    unsigned int bit_mask, offset, index;
    unsigned int *bucket_p, *bucket_s;

    while (*str)
    {
        unsigned char c = (unsigned char)*str;
        offset = c % 32;
        index = c / 32;
        bit_mask = 1U << offset;
        bucket_p = primary + index; // Pointer arithmetic to the primary bucket

        if (mode == 0)
        {
            // Mode 0: Just record the character into the primary bitset (seen_in_s2)
            *bucket_p |= bit_mask;
        }
        else if (mode == 1)
        {
            bucket_s = secondary + index; // Pointer arithmetic to the secondary bucket

            // Mode 1: If it IS in secondary (seen_in_s2) AND NOT in primary (printed)
            if ((*bucket_s & bit_mask) && !(*bucket_p & bit_mask))
            {
                write(1, str, 1);
                *bucket_p |= bit_mask; // Mark as printed
            }
        }
        str++;
    }
}

void ft_inter(char *s1, char *s2)
{
    unsigned int seen_in_s2[8] = {0};
    unsigned int printed[8] = {0};

    // 1. Pass s2 to silently populate the seen_in_s2 array (mode 0)
    ft_inter_seen(s2, seen_in_s2, NULL, 0);
    // 2. Pass s1 to check against seen_in_s2 and print results (mode 1)
    ft_inter_seen(s1, printed, seen_in_s2, 1);
    write(1, "\n", 1);
}

/*
void ft_inter(char *s1, char *s2)
{
    unsigned int seen_in_s2[8] = {0};
    unsigned int printed[8] = {0};

    // 'index' is gone. Just tracking the mask, offset, and the destination pointer.
    unsigned int bit_mask, offset;
    unsigned int *bucket;

    // Phase 1: Populate seen_in_s2 using pointer arithmetic
    while (*s2)
    {
        unsigned char c = (unsigned char)*s2;

        offset = c % 32;
        bit_mask = 1U << offset;

        // Base address + element offset = direct pointer to the bucket
        bucket = seen_in_s2 + (c / 32);
        *bucket |= bit_mask;
        s2++;
    }

    // Phase 2: Parse s1 using pointer arithmetic
    while (*s1)
    {
        unsigned char c = (unsigned char)*s1;

        offset = c % 32;
        bit_mask = 1U << offset;

        // Check s2 bucket via pointer arithmetic
        bucket = seen_in_s2 + (c / 32);
        unsigned int is_in_s2 = *bucket & bit_mask;

        // Move bucket pointer to the printed array
        bucket = printed + (c / 32);
        unsigned int is_printed = *bucket & bit_mask;

        if (is_in_s2 && !is_printed)
        {
            write(1, s1, 1);
            *bucket |= bit_mask; // Direct mutation of the printed bucket
        }
        s1++;
    }
    write(1, "\n", 1);
}

void ft_inter(char *s1, char *s2)
{
    char seen_in_s2[256] = {0};
    char printed[256] = {0};

    // Populate the character array from s2
    while (*s2)
    {
        seen_in_s2[(unsigned char)*s2] = 1;
        s2++; // Move the pointer to the next character
    }

    // Check characters from s1
    while (*s1)
    {
        unsigned char c = (unsigned char)*s1;
        if (seen_in_s2[c] && !printed[c])
        {
            write(1, s1, 1); // Pass the s1 pointer directly since it is already an address
            printed[c] = 1;
        }
        s1++; // Move the pointer to the next character
    }
    write(1, "\n", 1);
}

void ft_inter(char *s1, char *s2)
{
    // 8 ints * 32 bits = 256 bits. One unique bit for each ASCII character!
    unsigned int seen_in_s2[8] = {0};
    unsigned int printed[8] = {0};

    // 1. Populate the bitmask for string s2 using pointer arithmetic
    while (*s2)
    {
        unsigned char c = (unsigned char)*s2;

        // *(seen_in_s2 + (c / 32)) targets the correct 32-bit integer block
        // 1U << (c % 32) creates the bitmask for the specific character
        *(seen_in_s2 + (c / 32)) |= (1U << (c % 32));
        s2++;
    }

    // 2. Check characters from s1 against the bitmasks
    while (*s1)
    {
        unsigned char c = (unsigned char)*s1;

        // Check if the bit is set in seen_in_s2 AND NOT set in printed
        if ((*(seen_in_s2 + (c / 32)) & (1U << (c % 32))) &&
            !(*(printed + (c / 32)) & (1U << (c % 32))))
        {
            write(1, s1, 1); // Pass the s1 pointer directly to write

            // Mark the character as printed by setting its bit to 1
            *(printed + (c / 32)) |= (1U << (c % 32));
        }
        s1++;
    }
    write(1, "\n", 1);
}

void ft_inter(char *s1, char *s2)
{
    char seen_in_s2[256] = {0};
    char printed[256] = {0};

    // Populate the seen_in_s2 array using pointer arithmetic
    while (*s2)
    {
        // seen_in_s2 is the base address.
        // We add the character value to it and dereference with '*'
        *(seen_in_s2 + (unsigned char)*s2) = 1;
        s2++;
    }

    // Check characters from s1
    while (*s1)
    {
        unsigned char c = (unsigned char)*s1;

        // Equivalent to: if (seen_in_s2[c] && !printed[c])
        if (*(seen_in_s2 + c) && !*(printed + c))
        {
            write(1, s1, 1); // s1 is already a pointer (address), pass it directly
            *(printed + c) = 1; // Mark as printed using pointer arithmetic
        }
        s1++;
    }
    write(1, "\n", 1);
}

void ft_inter(char* s1, char* s2)
{
    // 256 bits total = 4 separate 64-bit variables. No arrays used.
    unsigned long long s2_m0 = 0, s2_m1 = 0, s2_m2 = 0, s2_m3 = 0;
    unsigned long long pr_m0 = 0, pr_m1 = 0, pr_m2 = 0, pr_m3 = 0;
    unsigned char c;
    unsigned long long bit;

    // 1. Map all characters present in s2 using pointer arithmetic
    while (*s2)
    {
        c = (unsigned char)*s2;
        bit = 1ULL << (c & 63); // Bit position inside the 64-bit block

        // Distribute to the correct variable based on ASCII range
        if (c < 64)         s2_m0 |= bit;
        else if (c < 128)   s2_m1 |= bit;
        else if (c < 192)   s2_m2 |= bit;
        else                s2_m3 |= bit;

        s2++; // Advance pointer
    }

    // 2. Check s1 characters against the bitmasks without any indices
    while (*s1)
    {
        c = (unsigned char)*s1;
        bit = 1ULL << (c & 63);

        if (c < 64)
        {
            if ((s2_m0 & bit) && !(pr_m0 & bit))
            {
                write(1, s1, 1);
                pr_m0 |= bit;
            }
        }
        else if (c < 128)
        {
            if ((s2_m1 & bit) && !(pr_m1 & bit))
            {
                write(1, s1, 1);
                pr_m1 |= bit;
            }
        }
        else if (c < 192)
        {
            if ((s2_m2 & bit) && !(pr_m2 & bit))
            {
                write(1, s1, 1);
                pr_m2 |= bit;
            }
        }
        else
        {
            if ((s2_m3 & bit) && !(pr_m3 & bit))
            {
                write(1, s1, 1);
                pr_m3 |= bit;
            }
        }
        s1++;
    }
    write(1, "\n", 1);
}

void ft_inter(char* s1, char* s2)
{
    char* s1_temp = s1;
    char* s2_temp;
    char* check; // Pointer to look back at the history of s1

    while (*s1_temp)
    {
        // 1. Check if the current character has appeared in s1 before this position
        check = s1;
        while (check < s1_temp)
        {
            if (*check == *s1_temp)
                break; // Character was already processed, exit the look-back loop
            check++;
        }

        // 2. If check reached s1_temp, it means this character is appearing for the first time
        // Only in this case do we proceed to search for it in the second string
        if (check == s1_temp)
        {
            s2_temp = s2;
            while (*s2_temp)
            {
                if (*s1_temp == *s2_temp)
                {
                    write(1, s1_temp, 1);
                    break; // Found in s2, print it once and move to the next s1 character
                }
                s2_temp++;
            }
        }
        s1_temp++;
    }
}


void ft_inter(char *s1, char *s2)
{
    char *p1 = s1;
    char *p1_scan;
    char *p2;

    while (*p1)
    {
        // 1. Check for duplicates in s1 by scanning from the start up to p1
        p1_scan = s1;
        while (p1_scan < p1 && *p1_scan != *p1)
            p1_scan++;

        // 2. If p1_scan reached p1, this is the FIRST time we've seen this char
        if (p1_scan == p1)
        {
            // 3. Scan s2 to see if the char exists there
            p2 = s2;
            while (*p2 && *p2 != *p1)
                p2++;

            // 4. If *p2 isn't null, we found a match
            if (*p2)
                write(1, p1, 1);
        }
        p1++;
    }
    write(1, "\n", 1);
}
*/
