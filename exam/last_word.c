/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   last_word.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:18:13 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:18:14 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_last_word(char *str)
{
    char *end = str;

    if (!str)
        return;
    while (*end) //Go to the end of the string
        end++;
    end--; //Go to the last symbol

    //Skip spaces and tabs from the end via moving to the beginning
    while (end >= str && (*end == ' ' || *end == '\t'))
        end--;
    //If there are no symbols, than we have no words
    if (end < str)
        return;
    char *start = end;
    //Go to the start of the word
    while (start > str && (*(start - 1) != ' ' && *(start - 1) != '\t'))
        start--;
    //Printing a word
    while (start <= end)
        write(1, start++, 1);
}

/*
void	ft_last_word(char *str)
{
    char	*end = str;

    if (!str)
        return;
    // 1. Go to the end of the string
    while (*end)
        end++;

    end--; // Stand on the last actual character before \0

    // 2. Skip trailing spaces and tabs (cut off the tail)
    while (end > str && (*end == ' ' || *end == '\t'))
        end--;

    // 3. Skip the word backwards to find its start
    while (end > str && *end != ' ' && *end != '\t')
        end--;

    // If we stopped on a space, the word starts at the NEXT character
    if (*end == ' ' || *end == '\t')
        end++;

    // 4. Print the word until we hit a space, tab, or \0
    while (*end && *end != ' ' && *end != '\t')
        write(1, end++, 1);
}
 */
