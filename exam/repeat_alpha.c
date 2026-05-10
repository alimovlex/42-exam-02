/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   repeat_alpha.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:18:59 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:19:06 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_repeat_alpha(char* str)
{
    int counter = 0;
    while(*str)
    {
        if (*str >= 'a' && *str <= 'z')
            counter = *str - 'a' + 1;
        else if (*str >= 'A' && *str <= 'Z')
            counter = *str - 'A' + 1;
        else
            write(1, str, 1);
        while(counter-- > 0)
            write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}
