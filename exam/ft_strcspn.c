/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strcspn.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:17:08 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:17:09 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
/*
 * The strcspn() function searches for the first occurrence in a string of
 * any of the specified characters and returns the length of the string up to that point.
 * If none of the characters are found then the length of the string is returned.
 */
int ft_strchr(char *s2, char s1);

size_t ft_strcspn(const char *s, const char *reject)
{
    const char *ptr = s;
    const char *rej_ptr = reject;
    while (*ptr)
    {
        if (ft_strchr((char*)rej_ptr, *(char *)ptr))
            break;
        ptr++;
    }
    return ptr - s;
}
/*
size_t ft_strcspn(const char *s, const char *reject)
{
    unsigned int map[8] = {0};
    const unsigned char *str = (const unsigned char *)s;
    const unsigned char *rej = (const unsigned char *)reject;

    unsigned int *bucket;
    unsigned int offset;
    unsigned int bit_mask;

    // 1. Populate the bitmask with 'reject' characters using pointers
    while (*rej)
    {
        bucket = map + (*rej / 32);   // Pointer arithmetic: points directly to the target 32-bit block
        offset = *rej % 32;
        bit_mask = 1U << offset;

        *bucket |= bit_mask;          // Dereference and modify the memory directly
        rej++;
    }

    // 2. Scan 's' against the bitmask using pointers
    while (*str)
    {
        bucket = map + (*str / 32);
        offset = *str % 32;
        bit_mask = 1U << offset;

        // Dereference the pointer to check the bit
        if (*bucket & bit_mask)
            return (size_t)((const char *)str - s);

        str++;
    }

    return (size_t)((const char *)str - s);
}

size_t ft_strcspn(const char *s, const char *reject)
{
    unsigned int map[8] = {0};
    const unsigned char *str = (const unsigned char *)s;
    const unsigned char *rej = (const unsigned char *)reject;

    unsigned int index;
    unsigned int offset;
    unsigned int bit_mask;

    // 1. Populate the bitmask with the 'reject' characters
    while (*rej)
    {
        index = *rej / 32;          // Find which of the 8 integers this char belongs to
        offset = *rej % 32;         // Find the exact bit position (0-31) inside that integer
        bit_mask = 1U << offset;    // Create a mask with a 1 at that specific position

        map[index] |= bit_mask;     // Flip that bit to 1 in our lookup table
        rej++;
    }

    // 2. Scan 's' against the lookup table
    while (*str)
    {
        index = *str / 32;
        offset = *str % 32;
        bit_mask = 1U << offset;

        // If the bit is 1, we found a match
        if (map[index] & bit_mask)
            return (size_t)((const char *)str - s);

        str++;
    }

    return (size_t)((const char *)str - s);
}

size_t ft_strcspn(const char *s, const char *reject)
{
    const char *start = s;
    const char *reader;

    while (*start & 255)
    {
        reader = reject;

        while (*reader & 255)
        {
            // ASCII compare via xor
            if (!((*start ^ *reader) & 255))
                return (size_t)(start - s);

            reader++;
        }

        start++;
    }

    return (size_t)(start - s);
}

size_t ft_strcspn(const char *s, const char *reject)
{
    const char *start = s, *reader = reject;

    while (*start)
    {
        // 1. Did we step on a bad thing?
        if (*start == *reader)
            return (size_t)(start - s);

        // 2. Are we at the end of the blacklist?
        if (!*reader++)
        {
            reader = reject; // Reset the blacklist to the top
            start++;        // Take one step forward on the sidewalk
        }
    }
    return (size_t)(start - s);
}

size_t ft_strcspn(const char *s, const char *reject)
{
    // 1. Drop a pin where we started so we can measure distance later.
    char *start = s;

    // 2. We need a second pointer to read our "blacklist" paper.
    char *reader;

    // Walk down the sidewalk (the main string 's') until we hit the end '\0'
    while (*s)
    {
        // For EVERY step we take, pull out the blacklist paper
        // and start reading it from the very beginning.
        reader = reject;

        while (*reader) // Read through the blacklist items one by one
        {
            if (*s == *reader)
            {
                // UH OH! The thing we are standing on (*s) matches
                // a bad thing on our list (*r). STOP WALKING!

                // Return our distance: Current position minus Starting position.
                return (size_t)(s - start);
            }
            reader++; // Move to the next item on the blacklist
        }

        // If we checked the whole blacklist and are safe, take a step forward!
        s++;
    }

    // If we walked the ENTIRE sidewalk and never stepped on anything bad,
    // we still need to return the total distance we walked.
    return (size_t)(s - start);
}
*/
