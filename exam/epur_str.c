/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   epur_str.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:15:49 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:15:51 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_is_space(char c);

void ft_epur_str(char *str)
{

    int i = 0;
    //Skip leading spaces right away so we don't print a space before the first word
    while (ft_is_space(*str))
        str++;

    while(*str)
    {
        i = 0;
        while(ft_is_space(*str))
        {
            i++;
            str++;
        }
        // If the string ends after skipping spaces (we hit \0),
        // we must break out immediately. Otherwise, we'll print a space
        // and step into out-of-bounds memory (which caused that SHELL output)
        if (!*str)
            break;

        if (i >= 1)
            write(1, " ", 1);
        else
            write(1, str++, 1);
    }
    write(1, "\n", 1);
}

/*
void epur_str(char *str)
{
    // 1. Skip initial spaces and tabs
    while (ft_is_space(*str))
        str++;

    while (*str)
    {
        // 2. Print the current word
        while (*str && !ft_is_space(*str))
            write(1, str++, 1);

        // 3. Skip the "garbage" (spaces/tabs) after the word
        while (ft_is_space(*str))
            str++;

        // 4. Look ahead: if there's another word, print exactly one space
        if (*str)
            write(1, " ", 1);
    }
    // Always end with a newline
    write(1, "\n", 1);
}

void epur_str(char *str)
{
    // 1. Skip initial spaces and tabs
    while (*str == ' ' || *str == '\t')
        str++;

    while (*str)
    {
        // 2. Print the current word
        while (*str && *str != ' ' && *str != '\t')
        {
            write(1, str, 1);
            str++;
        }

        // 3. Skip the "garbage" (spaces/tabs) after the word
        while (*str == ' ' || *str == '\t')
            str++;

        // 4. Look ahead: if there's another word, print exactly one space
        if (*str)
            write(1, " ", 1);
    }
    // Always end with a newline
    write(1, "\n", 1);
}
*/