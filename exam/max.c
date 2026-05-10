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
    // Guard against an empty array
    if (len == 0)
        return 0;

    // Initialize the maximum with the very first element
    int current_max = *tab;

    // Loop as long as there are elements remaining
    while (len > 0)
    {
        if (*tab > current_max)
            current_max = *tab; // Update the highest value found so far
        tab++; // Move the pointer FORWARD to the next element
        len--; // Decrease the counter of remaining elements
    }

    return current_max;
}
