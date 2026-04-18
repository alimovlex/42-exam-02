#include <unistd.h>

int ft_strcmp(char *s1, char *s2)
{
    // Loop forward as long as the characters match AND we haven't hit the end of s1
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }

    // Return the difference between the first non-matching characters.
    // Casting to unsigned char is standard behavior for strcmp.
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
