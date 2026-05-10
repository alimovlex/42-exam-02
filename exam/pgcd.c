/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pgcd.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:18:42 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:18:43 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int pgcd(const char *s1, const char *s2)
{
    int a = atoi(s1), b = atoi(s2);

    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}


/*
int pgcd(const char *s1, const char *s2)
{
    int a = atoi(s1), b = atoi(s2);

    while (b != 0)
    {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}


//Binary GCD algorithm using bitwise operations.
//Much faster than the standard Euclidean algorithm on most CPUs.
int pgcd(const char *s1, const char *s2)
{
    int a = atoi(s1);
    int b = atoi(s2);
    int shift = 0;

    if (a <= 0 || b <= 0)
        return 0;

    // 1. Find the greatest power of 2 that divides both (the common 'shift')
    while (((a | b) & 1) == 0)
    {
        a >>= 1;
        b >>= 1;
        shift++;
    }

    // 2. Remove all factors of 2 from a
    while ((a & 1) == 0)
        a >>= 1;

    // 3. The core loop
    while (b != 0)
    {
        // Remove all factors of 2 from b
        while ((b & 1) == 0)
            b >>= 1;

        // XOR Swap if a > b, so we always do (larger - smaller)
        if (a > b)
          ft_swap(&a, &b);

        // Subtract the smaller from the larger
        b -= a;
    }

    // 4. Restore the common power of 2
    return (a << shift);
}
*/
