/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_last_word.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/06/22 06:49:36 by alalimov       #+#    #+#                */
/*   Updated: 2026/06/22 07:07:05 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_is_space(char c);
char *ft_strdup(char *src);

char *ft_last_word(char *str)
{
    char *ptr = str;
    char *word_start;
    char *word;
    char temp_char;

    if (!str || !*str)
        return (NULL);

    // 1. Shift to the null terminator
    while (*ptr)
        ptr++;
    ptr--; // Step back to the last character

    // 2. Skip trailing tabs and spaces safely
    while (ptr >= str && ft_is_space(*ptr))
        ptr--;

    // If the string was purely spaces, return safely
    if (ptr < str)
        return (NULL);

    // 3. Walk backward to find the start of the last word
    word_start = ptr;
    while (word_start >= str && !ft_is_space(*word_start))
        word_start--;

    // Move 1 step forward to sit on the first letter of the word
    word_start++;

    // 4. Temporarily inject a null-terminator AFTER the word
    // ptr is on the last char of the word, so ptr + 1 is safe to overwrite
    temp_char = *(ptr + 1);
    *(ptr + 1) = '\0';

    // 5. Duplicate the isolated word
    word = ft_strdup(word_start);

    // 6. Put the original character back so we don't break the string permanently here
    *(ptr + 1) = temp_char;

    return (word);
}
