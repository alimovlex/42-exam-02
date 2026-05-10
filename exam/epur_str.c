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

void epur_str(char *str)
{
    /* 1. Skip initial spaces and tabs */
    while (*str == ' ' || *str == '\t')
        str++;

    while (*str)
    {
        /* 2. Print the current word */
        while (*str && *str != ' ' && *str != '\t')
        {
            write(1, str, 1);
            str++;
        }

        /* 3. Skip the "garbage" (spaces/tabs) after the word */
        while (*str == ' ' || *str == '\t')
            str++;

        /* 4. Look ahead: if there's another word, print exactly one space */
        if (*str)
            write(1, " ", 1);
    }
    /* Always end with a newline */
    write(1, "\n", 1);
}
