#include <unistd.h>

char* ft_strrev(char* str)
{
    char *start = str;
    char *end = str;
    while(*end)
        end++;
    end--;

    while(start < end)
    {
        char tmp = *start;
        *start++ = *end;
        *end-- = tmp;
    }
    return str;
}