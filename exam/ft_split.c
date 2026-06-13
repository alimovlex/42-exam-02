/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_split.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:16:44 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:16:46 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int ft_is_space_bitwise(char c);

char    **ft_split(char *str)
{
    // Allocate space for 1000 string pointers directly
    char **res = malloc(sizeof(char *) * 1000);
    char **word_ptr = res;
    char *letter_ptr;

    while (*str)
    {
        // Skip whitespace characters directly inline
        while (*str && ft_is_space_bitwise(*str))
            str++;
        if (!*str)
            break;

        // Allocate 1000 bytes for the current word
        *word_ptr = malloc(1000);
        letter_ptr = *word_ptr;
        // Collect characters until we hit a whitespace
        while (*str && !ft_is_space_bitwise(*str))
            *letter_ptr++ = *str++;
        *letter_ptr = '\0'; // Null-terminate the current word
        word_ptr++;         // Move to the next slot in the array
    }
    *word_ptr = NULL; // Null-terminate the array of strings
    return (res);
}

/*
char    **ft_split(char *str)
{
    char **words;
    char **next_word;
    char  *word;

    words = (char **)malloc(sizeof(char *) * 1024);
    next_word = words;
    while (*str)
    {
        if (ft_is_space_bitwise(*str))
            str++;
        else
        {
            word = (char *)malloc(1024);
            *next_word++ = word;
            while (*str && !ft_is_space_bitwise(*str))
                *word++ = *str++;
            *word = '\0';
        }
    }
    *next_word = NULL;
    return (words);
}

char    **ft_split(char *str)
{
    char **words_array = (char **)malloc(8000);
    char **next_slot = words_array;
    char  *current_word;

    while (*str)
    {
        while (ft_is_space_bitwise(*str))
            str++;
        if (!*str)
            break;
        current_word = (char *)malloc(1000);
        *next_slot++ = current_word;
        while (*str && !ft_is_space_bitwise(*str))
            *current_word++ = *str++;
        *current_word = '\0';
    }
    *next_slot = NULL;
    return (words_array);
}

int ft_word_count(char *str)
{
    int cnt = 0;
    int in_word = 0;

    while (*str)
    {
        if (*str != ' ' && *str != ',' && *str != '\t')
        {
            if (!in_word)
            {
                cnt++;
                in_word = 1;
            }
        }
        else
            in_word = 0;
        str++;
    }
    return cnt;
}

char **ft_split(char *str)
{
    int words = ft_word_count(str);
    char** split_str = (char**)malloc((words + 1) * sizeof(char*));
    char** start = split_str;

    while (*str && words > 0)
    {
        while (*str == ' ' || *str == '\t' || *str == '\n')
            str++;
        if (!*str)
            break;

        char* word_start = str;

        while (*str && *str != ' ' && *str != '\t' && *str != '\n')
            str++;

        int len = str - word_start;
        *start = (char*)malloc(len + 1);
        char* to = *start;
        char* from = word_start;
        while (from < str)
            *to++ = *from++;
        *to = '\0';

        start++;
        words--;
    }
    *start = NULL;
    return split_str;
}
*/
