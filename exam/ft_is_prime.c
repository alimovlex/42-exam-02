/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_is_prime.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/06/22 05:52:05 by alalimov       #+#    #+#                */
/*   Updated: 2026/06/22 05:52:11 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_is_prime(int a)
{
    //Prime numbers starts from 2
    int i = 2;

    if (a <= 1)
        return (0);
    while (i * i <= a)
    {
        if (a % i == 0)
            return (0);
        i++;
    }
    return (1);
}

