#include <unistd.h>

void ft_rotone(char* str)
{
    while(*str)
    {
        if ((*str >= 'a' && *str < 'z') || (*str >= 'A' && *str < 'Z'))
            *str += 1;
        else if (*str == 'z' || *str == 'Z')
            *str-=25;
        write(1, str, 1);
            str++;
    }
    write(1, "\n", 1);
}