#include <unistd.h>

void ft_union(char* s1, char* s2)
{
    char *start = s1;
    char *beginning = s2;

    while(*s1)
    {
        beginning = s2;
        while(*s2)
        {
            if (*s1 == *s2)
            {
                write(1, s1, 1);
                s2++;
                break;
            }
        }
        s1++;
    }
    write(1, "\n", 1);
}
