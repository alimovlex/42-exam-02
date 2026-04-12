#include <unistd.h>

void ft_wdmatch(char** argv)
{
    char *a;
    char *b;
    char *s;

    a = *++argv;
    b = *++argv;
    s = a;
    while (*a)
    {
        while (*b && *a != *b)
            b++;
        if (!*b)
            break;
        a++;
        b++;
    }
    if (!*a)
        write(1, s, a - s);
    write(1, "\n", 1);
}
