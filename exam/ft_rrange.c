#include <stdlib.h>

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