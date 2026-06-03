/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_rrange.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/16 20:43:47 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/16 20:43:49 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
    int size = 0;
    if (start > end)
        size = start - end + 1;
    else
        size = end - start + 1;
    int *arr = (int *)malloc(size * sizeof(int));
    int *ptr = arr;

    while (size--)
    {
        if (start < end)
            *ptr++ = end--;
        else
            *ptr++ = end++;
    }

    return arr;
}
/* BUGGY VERSION FOR start = end !!!
int     *ft_rrange(int start, int end)
{
    int size = 0;
    if (start > end)
        size = start - end + 1;
    else if (end > start)
        size = end - start + 1;
    else
        return 0;
    int *arr = (int *)malloc(size * sizeof(int));
    int *ptr = arr;

    while(start >= end)
        *ptr++ = start--;
    while(end >= start)
        *ptr++ = end--;

    return arr;
}

int     *ft_rrange(int start, int end)
{
    int     size = 0;

    // 1. Calculate absolute size
    if (start > end)
        size = start - end + 1;
    else
        size = end - start + 1;

    // 2. Allocate memory for the integer array
    int *array = (int *)malloc(sizeof(int) * size);
    if (!array)
        return (NULL);

    // 3. Create a runner pointer to walk through the memory
    int *ptr = array;

    // 4. Fill the array depending on the direction directly
    if (start > end)
        while (size--)
            *ptr++ = end++; // Fill and increment end
    else
        while (size--)
            *ptr++ = end--; // Fill and decrement end

    // 5. Return the clean, unmodified start pointer
    return (array);
}
*/
