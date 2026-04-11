#include <unistd.h>

void ft_ulstr(char* str)
{
    char     c;
    while (*str)
    {
        c = *str;
        if (c >= 'a' && c <= 'z')
            c -= 32;
        else if (c >= 'A' && c <= 'Z')
            c += 32;
        write(1, &c, 1);
        str++;
    }
    write(1, "\n", 1);
}
