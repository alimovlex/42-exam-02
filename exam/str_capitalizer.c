/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   str_capitalizer.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/16 20:45:07 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/16 20:45:09 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void str_capitalizer(char *str)
{
    // 1. Handle the first character explicitly so we can safely look back later
    if (*str)
    {
        if (*str >= 'A' && *str <= 'Z')
            *str += 32; // Force lowercase
        if (*str >= 'a' && *str <= 'z')
            *str -= 32; // Capitalize since it's the absolute start
        write(1, str++, 1); // Print and move pointer forward
    }

    // 2. Loop through the rest using your exact style
    while (*str)
    {
        // Turn uppercase into lowercase first
        if (*str >= 'A' && *str <= 'Z')
            *str += 32;

        // Turn lowercase into uppercase if the previous char was a space/tab
        if ((*str >= 'a' && *str <= 'z') && (*(str - 1) == ' ' || *(str - 1) == '\t'))
            *str -= 32;

        write(1, str++, 1); // Print and move pointer forward
    }
    write(1, "\n", 1);
}

/*
void str_capitalizer(char *str)
{
    // 1. Handle the very first character of the string safely
    if (*str)
    {
        // If the first char is a lowercase letter, capitalize it
        if (*str >= 'a' && *str <= 'z')
            *str -= 32;
        write(1, str, 1);
        str++;
    }

    // 2. Loop through the rest of the string using pointers
    while (*str)
    {
        // If the current character is a letter
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
        {
            // If the PREVIOUS character was a space or a tab, this is the start of a new word
            if (*(str - 1) == ' ' || *(str - 1) == '\t')
            {
                if (*str >= 'a' && *str <= 'z')
                    *str -= 32; // Make it uppercase
            }
            else // If we are inside a word, every other letter must be lowercase
            {
                if (*str >= 'A' && *str <= 'Z')
                    *str += 32; // Make it lowercase
            }
        }

        // Print the processed character and move the pointer forward
        write(1, str, 1);
        str++;
    }

    // Print a newline after finishing the current string argument
    write(1, "\n", 1);
}
 */
