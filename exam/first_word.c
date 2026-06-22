/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   first_word.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:15:58 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:16:01 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_is_space(char c);

void first_word(char *str)
{
    // 1. Guard against empty strings immediately to prevent pointer UB
    if (!str || !*str)
        return;
    while(ft_is_space(*str))
        str++;

    while(*str)
    {
        if (ft_is_space(*str))
            break;
        write(1, str++, 1);
    }

    write(1, "\n", 1);
}

/*
void first_word(char *str)
{
    while(*str == ' ' || *str == '\t')
        str++;

    while(*str)
    {
        if (*str == ' ' || *str == '\t')
            break;
        write(1, str++, 1);
    }

    write(1, "\n", 1);
}

void first_word(char *str)
{
    while (*str == ' ' || *str == '\t')
        str++;

    while (*str != '\0' && *str != ' ' && *str != '\t')
        write(1, str++, 1);
    write(1, "\n", 1);
}
*/