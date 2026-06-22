#include <unistd.h>

int ft_is_space(char c);

int count_words(char *str)
{
    int count = 0;

    while (*str)
    {
        if (ft_is_space(*str))
            str++;
        else
        {
            count++;
            while (*str && !ft_is_space(*str))
                str++;
        }
    }
    return (count);
}