#include <unistd.h>

void ft_rot_13(char* str)
{
    while (*str)
    {
        if ((*str >= 'a' && *str <= 'm') || (*str >= 'A' && *str <= 'M'))
            *str += 13;
        else if ((*str >= 'n' && *str <= 'z') || (*str >= 'N' && *str <= 'Z'))
            *str -= 13;
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}