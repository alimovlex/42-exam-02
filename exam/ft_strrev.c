#include <unistd.h>

char* ft_strrev(char* str)
{
    char* start = str;
    char* end = str;

    while(*end)
        end++;
    end--;

    while(end > start)
    {
        char tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
    return str;
}