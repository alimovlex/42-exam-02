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
