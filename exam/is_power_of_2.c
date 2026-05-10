/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   is_power_of_2.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:18:06 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:18:07 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_power_of_2(unsigned int n)
{
    if (n == 0)
        return 0;
    while ((n & 1) == 0)
        n >>= 1;
    return n == 1;
}

/*

int is_power_of_2(unsigned int n)
{
    if (n == 0)
        return 0;
    if ((n & (n - 1)) == 0)
        return 1;
    return 0;
}

int is_power_of_2(unsigned int n)
{
    if (n == 0)
        return 0;
    while (n % 2 == 0)
        n /= 2;
    return (n == 1);
}

*/
