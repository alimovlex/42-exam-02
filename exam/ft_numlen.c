/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_numlen.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/06/22 08:37:38 by alalimov       #+#    #+#                */
/*   Updated: 2026/06/22 08:37:41 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_numlen(long num)
{
    int i = 0;

    if (num == 0)
        return (1);
    if (num < 0)
        num = -num;
    while (num > 0)
    {
        num /= 10;
        i++;
    }
    return (i);
}
