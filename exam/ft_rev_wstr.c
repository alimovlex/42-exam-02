/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_rev_wstr.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/22 09:52:19 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/22 09:52:22 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

//char **ft_split(char *str);
char *ft_last_word(char *str);
int ft_is_space(char c);

void ft_rev_wstr(char *str)
{
    char *end = str;
    char *word_start;
    char *print_ptr;

    // 1. Move the pointer to the null-terminator '\0'
    while (*end)
        end++;

    // Step back to the last valid character of the string
    end--;

    // 2. Loop backwards until the pointer goes past the start address
    while (end >= str)
    {
        word_start = end;

        // Move backwards until hitting a space, tab, or the start of the string
        while (word_start >= str && *word_start != ' ' && *word_start != '\t')
            word_start--;

        // word_start is now on a space or before 'str'.
        // The word itself starts at the next memory address.
        print_ptr = word_start + 1;

        // 3. Print the current word from left to right
        while (print_ptr <= end)
            write(1, print_ptr++, 1);

        // 4. If word_start is still within bounds, it means a space was found.
        // Print a space to separate words.
        if (word_start >= str)
            write(1, " ", 1);

        // Shift 'end' past the space to prepare for the next word
        end = word_start - 1;
    }
    write(1, "\n", 1);
}

/*
void ft_rev_wstr(char *str)
{
    char *word;
    char *ptr;
    char *print_ptr;
    int first_word = 1;

    // Loop until the string is completely empty
    while (*str)
    {
        // Extract the last word
        word = ft_last_word(str);
        if (!word)
            break;

        // Print a space before the next word (except for the very first one we print)
        if (!first_word)
            write(1, " ", 1);
        first_word = 0;

        // Print the extracted word
        print_ptr = word;
        while (*print_ptr)
            write(1, print_ptr++, 1);

        // Free the memory allocated by ft_strdup
        free(word);

        // --- TRUNCATION PHASE ---
        // We must shorten the original string so the next loop finds the previous word
        ptr = str;
        while (*ptr)
            ptr++;
        ptr--;

        // Skip trailing spaces
        while (ptr >= str && ft_is_space(*ptr))
            ptr--;
        // Skip the word we just printed
        while (ptr >= str && !ft_is_space(*ptr))
            ptr--;

        // If we found a space before the word, turn it into a null-terminator
        if (ptr >= str)
            *ptr = '\0';
        else
            *str = '\0'; // We printed the last remaining word, clear the string to break the loop
    }
}

void ft_rev_wstr(char *str)
{
    char **tab = ft_split(str);
    char **ptr = tab;
    char *tmp;

    if (tab && *tab)
    {
        // 1. Move the pointer to the NULL terminator of the array
        while (*ptr)
            ptr++;

        // Step back to point to the actual last word
        ptr--;

        // 2. Loop backwards through the array of string pointers
        while (ptr >= tab)
        {
            tmp = *ptr;

            // Print the current word
            while (*tmp)
                write(1, tmp++, 1);

            // Print a space if we haven't reached the very first word yet
            if (ptr > tab)
                write(1, " ", 1);

            // Free the string memory immediately after printing it
            free(*ptr);
            ptr--;
        }
    }

    // 3. Free the main container array
    if (tab)
        free(tab);

    write(1, "\n", 1);
}

*/