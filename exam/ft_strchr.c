#include <unistd.h>

int ft_strchr(char *s2, char s1)
{
    while (*s2 && *s2 != s1)
        s2++;
    return (*s2 == s1);
}
