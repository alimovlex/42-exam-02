#include <unistd.h>

void snake_to_camel(char* str)
{
    while(*str)
    {
        if (*str == '_')
            *++str -= 32;
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}
