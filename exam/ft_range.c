#include <unistd.h>
#include <stdlib.h>

int *ft_range(int start, int end)
{
    int size;

    // 1. Calculate the exact positive size of the array
    if (start <= end)
        size = end - start + 1;
    else
        size = start - end + 1;

    // 2. Allocate memory using malloc
    int *array = (int *)malloc(size * sizeof(int));
    if (!array)
        return (NULL);

    int *ptr = array;

    // 3. Fill the memory using two clean, separate loops
    if (start <= end)
        while (size--)
            *ptr++ = start++; // Put start into ptr, then move both forward
    else
        while (size--)
            *ptr++ = start--; // Put start into ptr, move ptr forward, decrease start

    // 4. Return the untouched pointer to the beginning
    return (array);
}

/*
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