#include <unistd.h>

void ft_alpha_mirror(char* str)
{
    while(*str)
    {
        if (*str >= 'a' && *str <= 'z')
            *str = 'z' - (*str - 'a');
        else if (*str >= 'A' && *str <= 'Z')
            *str = 'Z' - (*str - 'A');
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}
