/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   max.c                                               :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:18:28 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:18:30 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int max(int* tab, unsigned int len)
{
    if (len == 0)
        return 0;
    int max = *tab;
    while(len-- > 0)
    {
        if (*tab > max)
            max = *tab;
        tab++;
    }
    return max;
}
