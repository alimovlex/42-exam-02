#include <unistd.h>

void rstr_capitalizer(char *str)
{
    while (*str)
    {
        // Turning letters from uppercase into a lowercase
        if (*str >= 'A' && *str <= 'Z')
            *str += 32;

        // Turning letter uppercase because it's at the last position
        if ((*str >= 'a' && *str <= 'z') &&
            (*(str + 1) == ' ' || *(str + 1) == '\t' || *(str + 1) == '\0'))
            *str -= 32;

        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}
