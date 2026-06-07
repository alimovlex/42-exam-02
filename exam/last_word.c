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

int ft_is_space_bitwise(char c);

void ft_last_word(char *str)
{
    char *ptr = str;
    // 1. Guard against empty strings immediately to prevent pointer UB
    if (!ptr || !*ptr)
        return;
    // 2. Shift to the null terminator
    while (*ptr)
        ptr++;
    // 3. Step back to the actual last character
    ptr--;
    // 4. Skip trailing tabs and spaces safely
    while (ptr >= str && ft_is_space_bitwise(*ptr))
        ptr--;
    // If the string was purely spaces, we walked off the front. Return safely.
    if (ptr < str)
        return;
    // 5. Walk backward to find the start of the last word
    while (ptr >= str)
    {
        if (ft_is_space_bitwise(*ptr))
            break;
        ptr--;
    }
    // 6. Move 1 step forward to sit on the first letter of the word
    ptr++;
    // 7. Print the word until we hit a space, tab, or '\0'
    while (*ptr)
    {
        if (ft_is_space_bitwise(*ptr))
            break;
        write(1, ptr++, 1);
    }
}

/*
void ft_last_word(char *str)
{
    char *end = str;
    //Shifting to the end of a string
    while(*end)
        end++;
    //Going 1 step back because of a null string terminator '\0'
    end--;
    //Skipping all tabs and spaces and reverting the pointer backwards.
    while (end >= str && (*end == ' ' || *end == '\t'))
        end--;
    //Advancing pointer back up to the spaces or tabs.
    while(end >= str)
    {
        if (*end == ' ' || *end == '\t')
            break;
        end--;
    }
    //Moving 1 step further due to the space or tab address
    end++;
    //Printing the word and heading to the string null terminator '\0'

    while(*end)
    {
        if (*end == ' ' || *end == '\t')
            break;
        write(1, end++, 1);
    }
    write(1, "\n", 1);

}

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

void ft_last_word(char *str)
{
    char *end = str;
    // Define the bit mask for space (bit 32) and tab (bit 9)
    unsigned long long mask = (1ULL << 32) | (1ULL << 9);

    if (!str)
        return;

    // Go to the end of the string
    while (*end)
        end++;
    end--;

    // Skip spaces and tabs from the end using the bit mask directly
    while (end >= str && (unsigned char)*end < 64 && ((mask >> *end) & 1))
        end--;

    // If there are no symbols, then we have no words
    if (end < str)
        return;

    char *start = end;

    // Go to the start of the word using the bit mask directly
    while (start > str && !((unsigned char)*(start - 1) < 64 &&
    ((mask >> *(start - 1)) & 1)))
        start--;

    // Printing the word
    while (start <= end)
        write(1, start++, 1);
}

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

