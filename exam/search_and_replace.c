/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   search_and_replace.c                                :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:19:46 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:19:47 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str);

void	ft_replace(char *s1, char *s2, char *s3)
{
    while (*s1)
    {
        if (*s1 == *s2)
            *s1 = *s3;
        write(1, s1++, 1);
    }
    write(1, "\n", 1);
}

void ft_search_and_replace(int argc, char** argv)
{
    if (argc == 4)
    {
        char* s1 = *++argv;
        char* s2 = *++argv;
        char* s3 = *++argv;
        if (ft_strlen(s2) == 1 && ft_strlen(s3) == 1)
            ft_replace(s1, s2, s3);
        else
            write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);
}

/*
void ft_search_and_replace(int argc, char** argv)
{
    char *str;
    char find;
    char rep;
    int i = 0;

    // If there are exactly 3 arguments (plus the program name = 4)
    if (argc == 4)
    {
        // Grab the characters to find and replace
        find = **(argv + 2); //character to search
        rep = **(argv + 3); //character to replace

        // Check if 2nd and 3rd args are exactly 1 char long (followed by '\0')
        // to prevent processing strings like "art" or "zul"
        if (*(*(argv + 2) + 1) == '\0' && *(*(argv + 3) + 1) == '\0')
        {
            // Pointer to our main string (1st argument)
            str = *(argv + 1);

            // Loop through the string until the null-terminator
            while (*str)
            {
                // If we find the target char, write the replacement
                if (*str == find)
                    write(1, &rep, 1);
                    // Otherwise, write the original char
                else
                    write(1, str, 1);

                // Move the pointer to the next char
                str++;
                i++;
            }
        }
    }
    // Always print a newline at the end
    write(1, "\n", 1);
}
*/