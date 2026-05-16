/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   lcm.c                                               :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:18:20 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:18:22 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int gcd(unsigned int a, unsigned int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

unsigned int lcm(unsigned int a, unsigned int b)
{
    if (a == 0 || b == 0)
        return 0;

    return (a * b) / gcd(a, b);
}

