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

char    **ft_split(char *str)
{
    char **words;
    char **next_word;
    char  *word;

    words = (char **)malloc(sizeof(char *) * 1024);
    if (!words)
        return (NULL);
    next_word = words;
    while (*str)
    {
        if (*str == ' ' || *str == '\t' || *str == '\n')
            str++;
        else
        {
            word = (char *)malloc(1024);
            if (!word)
                return (NULL);
            *next_word++ = word;
            while (*str && !(*str == ' ' || *str == '\t' || *str == '\n'))
                *word++ = *str++;
            *word = '\0';
        }
    }
    *next_word = NULL;
    return (words);
}
/*
char    **ft_split(char *str)
{
    char **words_array = (char **)malloc(8000);
    char **next_slot = words_array;
    char  *current_word;

    if (!words_array)
        return (NULL);
    while (*str)
    {
        while (*str == ' ' || *str == '\t' || *str == '\n')
            str++;
        if (!*str)
            break;
        current_word = (char *)malloc(1000);
        if (!current_word)
            return (NULL);
        *next_slot++ = current_word;
        while (*str && *str != ' ' && *str != '\t' && *str != '\n')
            *current_word++ = *str++;
        *current_word = '\0';
    }
    *next_slot = NULL;
    return (words_array);
}

char    **ft_split(char *str)
{
    // Allocate space for 1000 string pointers directly
    char **res = malloc(sizeof(char *) * 1000);
    char **word_ptr = res;
    char *letter_ptr;

    if (!res)
        return (NULL);

    while (*str)
    {
        // Skip whitespace characters directly inline
        while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
            str++;
        if (!*str)
            break;

        // Allocate 1000 bytes for the current word
        *word_ptr = malloc(1000);
        if (!*word_ptr)
            return (NULL);

        letter_ptr = *word_ptr;
        // Collect characters until we hit a whitespace
        while (*str && *str != ' ' && *str != '\t' && *str != '\n')
        {
            *letter_ptr = *str;
            letter_ptr++;
            str++;
        }
        *letter_ptr = '\0'; // Null-terminate the current word
        word_ptr++;         // Move to the next slot in the array
    }
    *word_ptr = NULL; // Null-terminate the array of strings
    return (res);
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

 int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}


char	**ft_split(char *str)
{
	int i = 0;
	int word = 0;
	int letter;
	char **res = malloc(sizeof(char *)*1000);

	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (!str[i])
			break;

		res[word] = malloc(1000);
		letter = 0;
		while (str[i] && !is_space(str[i]))
		{
			res[word][letter] = str[i];
			letter++;
			i++;
		}
		res[word][letter] = '\0';
		word++;
	}
	res[word] = NULL;
	return res;
}

 */
