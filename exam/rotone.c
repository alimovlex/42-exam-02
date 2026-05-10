/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rotone.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:19:34 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:19:35 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_rotone(char* str)
{
    while(*str)
    {
        if ((*str >= 'a' && *str < 'z') || (*str >= 'A' && *str < 'Z'))
            *str += 1;
        else if (*str == 'z' || *str == 'Z')
            *str-=25;
        write(1, str, 1);
            str++;
    }
    write(1, "\n", 1);
}
