#include <unistd.h>

void sort_int_tab(int *tab, unsigned int size)
{
    int *ptr = tab;

    // Safety check for empty or single-element arrays
    if (size <= 1 || !tab)
        return;

    while (ptr < (tab + size - 1))
    {
        // If the current element is greater than the next one, swap them
        if (*ptr > *(ptr + 1))
        {
            // In-place XOR swap (no temp variable needed)
            *ptr ^= *(ptr + 1);
            *(ptr + 1) ^= *ptr;
            *ptr ^= *(ptr + 1);

            // Reset the pointer to the beginning to re-check the array
            ptr = tab;
        }
        else
            // Move to the next memory address
            ptr++;
    }
}

/*
void sort_int_tab(int *tab, unsigned int size)
{
    int temp;
    int *ptr = tab;

    if (size <= 1)
        return;

    while (ptr < (tab + size - 1))
    {
        // Check if the current value is bigger than the next one
        if (*ptr > *(ptr + 1))
        {
            // Swap the values in memory
            temp = *ptr;
            *ptr = *(ptr + 1);
            *(ptr + 1) = temp;

            // Reset pointer back to the beginning of the array
            ptr = tab;
        }
        else
        {
            // If order is correct, move to the next memory address
            ptr++;
        }
    }
}
 */
