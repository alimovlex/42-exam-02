#include <unistd.h>

void ft_rev_print(char* str)
{
    char *start = str;
    while(*str)
        str++;
    str--;
    while (str >= start)
        write(1, str--, 1);
    write(1, "\n", 1);
}