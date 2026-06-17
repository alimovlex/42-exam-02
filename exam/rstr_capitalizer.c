/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rstr_capitalizer.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:19:39 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:19:41 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_is_space(char c);

void rstr_capitalizer(char *str)
{
    while(*str)
    {
        if ((*str | 32) >= 'a' && (*str | 32) <= 'z')
        {
            if (*str >= 'A' && *str <= 'Z')
                *str += 32;
            else if (ft_is_space(*(str + 1)) || (!*(str + 1)))
                *str -= 32;
        }
        write(1, str++, 1);
    }
    write(1, "\n", 1);
}

/*
void rstr_capitalizer(char *str)
{
    while (*str)
    {
        // Turning letters from uppercase into a lowercase
        if (*str >= 'A' && *str <= 'Z')
            *str += 32;

        // Turning letter uppercase because it's at the last position
        if ((*str >= 'a' && *str <= 'z') &&
            (ft_is_space(*(str + 1)) || !*(str + 1)))
            *str -= 32;

        write(1, str++, 1);
    }
    write(1, "\n", 1);
}


void rstr_capitalizer(char *str)
{
    while (*str)
    {
        // Turning letters from uppercase into a lowercase
        if (*str >= 'A' && *str <= 'Z')
            *str += 32;

        // Turning letter uppercase because it's at the last position
        if ((*str >= 'a' && *str <= 'z') &&
            (*(str + 1) == ' ' || *(str + 1) == '\t' || !*(str + 1)))
            *str -= 32;

        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}
*/