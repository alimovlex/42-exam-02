/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rotone.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:19:34 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:19:35 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_rotone(char *str)
{
    while(*str)
    {
        if ((*str | 32) >= 'a' && (*str | 32) <= 'z')
        {
            if ((*str | 32) == 'z')
                *str -= 25;
            else
                *str += 1;
        }
        write(1, str++, 1);
    }
    write(1, "\n", 1);
}

/*
void ft_rotone(char* str)
{
    while(*str)
    {
        if ((*str >= 'a' && *str < 'z') || (*str >= 'A' && *str < 'Z'))
            *str += 1;
        else if (*str == 'z' || *str == 'Z')
            *str-=25;
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}


void ft_rotone(char *str)
{
    char *start = str;

    while (*str)
    {
        //That line is a bitwise trick to instantly convert
        // any lowercase letter to uppercase. 223 = 0xDF
        char caps = *str & 223;

        // Check if it's a letter (A-Z)
        if ((unsigned)(caps - 'A') < '\x1A')
        {
            // If it's Z/z (caps == 90), subtract 25 to get A/a. Otherwise, add 1.
            if (caps == 'Z')
                *str -= 25;
            else
                *str += 1;
        }
        str++;
    }

    write(1, start, str - start);
    write(1, "\n", 1);
}
*/