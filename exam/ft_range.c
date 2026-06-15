/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_range.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/16 20:43:41 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/16 20:43:43 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int *ft_range(int start, int end)
{
    int size = 0;

    // 1. Calculate the exact positive size of the array
    if (start <= end)
        size = end - start + 1;
    else if (end >= start)
        size = start - end + 1;
    else
        return 0;

    // 2. Allocate memory using malloc
    int *array = (int *)malloc(size * sizeof(int));
    int *ptr = array;
    // 3. Fill the memory using two clean, separate loops
    while (size--)
    {
        if (start <= end)
            *ptr++ = start++; // Put start into ptr, then move both forward
        else if (start >= end)
            *ptr++ = start--; // Put start into ptr, move ptr forward, decrease start
    }
    // 4. Return the untouched pointer to the beginning
    return (array);
}

/*
int *ft_range(int start, int end)
{
    int size = 0, step = 0;

    // Calculate the size of the array
    if (start > end)
    {
        size = start - end + 1;
        step = -1;
    }
    else if (end > start)
    {
        size = end - start + 1;
        step = 1;
    }
    int *arr = (int *)malloc(size * sizeof(int));
    int *ptr = arr;

    // A single loop that runs exactly 'size' times
    while (size--)
    {
        *ptr++ = start;
        start += step; // Move to the next number
    }

    return (arr);
}

int *ft_range(int start, int end)
{
    int size = 0;

    // 1. Calculate the exact positive size of the array
    if (start <= end)
        size = end - start + 1;
    else
        size = start - end + 1;

    // 2. Allocate memory using malloc
    int *array = (int *)malloc(size * sizeof(int));
    if (!array)
        return (NULL);

    // 3. Point the runner to the start of our newly allocated memory
    int *ptr = array;

    // 4. Fill the memory until we've processed all elements
    while (size--)
    {
        *ptr = start; // Put the number into the memory block ptr is pointing to
        ptr++;        // Move the pointer to the next memory block

        if (start < end)
            start++;
        else
            start--;
    }

    // 5. Return the original pointer that is still pointing to the very beginning
    return (array);
}
*/
