#include <unistd.h>

void ft_ulstr(char* str)
{
    while(*str)
    {
        if (*str >= 'a' && *str <= 'z')
            *str -= 32;
        else if (*str >= 'A' && *str <= 'Z')
            *str += 32;
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}
