/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   alpha_mirror.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:15:19 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:15:23 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_alpha_mirror(char* str)
{
    while(*str)
    {
        if (*str >= 'a' && *str <= 'z')
            *str = 'z' - (*str - 'a');
        else if (*str >= 'A' && *str <= 'Z')
            *str = 'Z' - (*str - 'A');
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}
