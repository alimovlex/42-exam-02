#include <unistd.h>

int	max(int* tab, unsigned int len)
{
    int max = 0;
    if (!tab)
    {
        len = 0;
        return len;
    }

    while(*tab)
    {
        int *prev = tab--;
        if (*prev > *tab)
            max = *prev;
        else
            max = *tab;
        tab++;
    }
    return max;
}
