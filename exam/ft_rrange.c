#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
    int     *arr;
    int     size;
    int     step;
    int     i;

    // 1. Calculate absolute size without ternary operators
    if (start > end)
        size = start - end + 1;
    else
        size = end - start + 1;

    // 2. Allocate memory for the integer array
    arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
        return (NULL);

    // 3. Determine the direction: do we increment or decrement end?
    if (end < start)
        step = 1;
    else
        step = -1;

    // 4. Fill the array using pointer incrementation
    i = size;
    while (i > 0)
    {
        *arr++ = end;  // Assign value to current address, then move pointer
        end += step;   // Adjust value for the next iteration
        i--;
    }

    // 5. Return the original start of the array by offsetting the current pointer
    return (arr - size);
}
