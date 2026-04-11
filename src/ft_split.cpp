#include "tests.hpp"
#include <unistd.h>
#include <cstdlib>

int ft_word_count(char *str)
{
    int cnt = 0;
    int in_word = 0;

    while (*str)
    {
        if (*str != ' ' && *str != ',' && *str != '\t')
        {
            if (!in_word)
            {
                cnt++;
                in_word = 1;
            }
        }
        else
            in_word = 0;
        str++;
    }
    return cnt;
}

char **ft_split(char *str)
{
    int words = ft_word_count(str);
    char** split_str = (char**)malloc((words + 1) * sizeof(char*));
    char** start = split_str;

    while (*str && words > 0)
    {
        while (*str == ' ' || *str == '\t' || *str == '\n')
            str++;
        if (!*str)
            break;

        char* word_start = str;

        while (*str && *str != ' ' && *str != '\t' && *str != '\n')
            str++;

        int len = str - word_start;
        *start = (char*)malloc(len + 1);
        char* to = *start;
        char* from = word_start;
        while (from < str)
            *to++ = *from++;
        *to = '\0';

        start++;
        words--;
    }
    *start = nullptr;
    return split_str;
}

