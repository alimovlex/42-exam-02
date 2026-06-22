/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_first_word.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/06/22 05:50:45 by alalimov       #+#    #+#                */
/*   Updated: 2026/06/22 05:51:14 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_is_space(char c);
char *ft_strdup(char *src);

char *ft_first_word(char *str)
{
    char *word, *end, temp_char;

    if (!str || !*str)
        return (NULL);

    // Skip leading spaces
    while (ft_is_space(*str))
        str++;
    // Use a secondary pointer to find the end of the word
    end = str;
    while (*end && !ft_is_space(*end))
        end++;
    // Save whatever character is currently at the end of the word
    temp_char = *end;
    // Temporarily inject a null-terminator to isolate the word
    *end = '\0';
    // Now ft_strdup will only copy up to the '\0' we just injected
    word = ft_strdup(str);
    // Put the original character back so the main loop doesn't break
    *end = temp_char;

    return (word);
}

