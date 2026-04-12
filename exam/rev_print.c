#include <unistd.h>

void ft_rev_print(char *str)
{
    int i = 0;
    while(*str)
    {
        str++;
        i++;
    }
    str--;
    while(i > 0)
    {
        write(1, str, 1);
        str--;
        i--;
    }
    write(1, "\n", 1);
}