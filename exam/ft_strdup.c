#include <stdlib.h>
#include "exam.h"

char* ft_strdup(char* src)
{
    int len = ft_strlen(src);
    char* str = (char*)malloc(len * sizeof(src) + 1);
    char* start = str;
    while(*src)
        *str++ = *src++;
    *str = '\0';

    return start;
}
