#include <unistd.h>

int ft_parse_args(char *str)
{
    while (*str)
    {
        
        int cnt = 0;
        if (*str >= 'a' && *str <= 'z')
            cnt = *str - 'a' + 1;
        else if (*str >= 'A' && *str <= 'Z')
            cnt = *str - 'A' + 1;
        else
            write(1, str, 1);

        while (cnt > 0)
        {
            write(1, str, 1);
            cnt--;
        }
    
        ++str;
    }
    return 0;
}

void ft_repeat_alpha(char* str)
{
    ft_parse_args(str);
    write(1, "\n", 1);
}

//int main(int argc, char **argv)
//{
//    while(*++argv)
//        printf("%s", *argv);
//    char nl = '\n';
//
//    if (argc < 2)
//        write(1, &nl, 1);
//    else if (!**(argv + 1))
//        write(1, &nl, 1);
//    else
//    {
//
//    }
//
//    return 0;
//}