/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_expand_str.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/16 20:43:03 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/16 20:43:05 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_expand_str(char *str)
{
    int flag = 0;

    // 1. Skip all spaces and tabs at the very beginning
    while (*str == ' ' || *str == '\t')
        str++;

    // 2. Loop through the rest of the string
    while (*str)
    {
        // If we hit a space or a tab
        if (*str == ' ' || *str == '\t')
        {
            flag = 1; // Remember that we are in a space block between words
        }
        else // If we hit a regular character
        {
            // If the flag is up, it means a new word is starting
            if (flag == 1)
            {
                write(1, "   ", 3); // Print exactly 3 spaces
                flag = 0;           // Reset the flag since we are now inside a word
            }
            // Print the current character
            write(1, str, 1);
        }
        str++; // Move to the next character
    }
    write(1, "\n", 1);
}
