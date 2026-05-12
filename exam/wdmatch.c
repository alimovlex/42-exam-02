/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   wdmatch.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:20:13 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:20:15 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int ft_strlen(char* str)
{
    char* end = str;

    while(*end)
        end++;
    return end - str;
}

void ft_wdmatch(char *s1, char *s2)
{
    int len = ft_strlen(s1), size = 0;
    char* start = s1;

    while(*s2)
    {
        if(*s1 == *s2)
        {
            size++;
            s1++;
        }
        s2++;
    }

    if (len == size)
        while(*start)
            write(1, start++, 1);

    write(1, "\n", 1);
}
/*
void ft_wdmatch(char *s1, char *s2)
{
    char *ptr = s1;
    while (*s2 && *ptr)
        ptr += (*ptr == *s2), s2++;
    if (*ptr == '\0')
        write(1, s1, ptr - s1);
    write(1, "\n", 1);
}

void ft_wdmatch(char *s1, char *s2)
{
    // 1. We create a 'tracker' pointer (ptr).
    // We need to keep the original 's1' pointing at the start so we can print it later.
    char *ptr = s1;

    // 2. We scan the second string (s2) entirely.
    // We never stop scanning s2 until it hits '\0'.
    while (*s2)
    {
        // 3. If the current character in s2 is the one we are looking for in s1:
        if (*ptr == *s2)
            ptr++; // Move the tracker to the next character we need to find.
        // 4. Success Check:
        // If our tracker hits '\0', it means we found every single char of s1 in s2.
        if (*ptr == '\0')
        {
            // Now we print the original s1 from the start.
            while (*s1)
            {
                write(1, s1, 1);
                s1++;
            }
            break; // We are done. Exit the function.
        }
        // 5. Always move s2 forward to keep searching.
        s2++;
    }
    write(1, "\n", 1);
}


void ft_wdmatch(char** argv)
{
    char *a;
    char *b;
    char *s;

    a = *++argv;
    b = *++argv;
    s = a;
    while (*a)
    {
        while (*b && *a != *b)
            b++;
        if (!*b)
            break;
        a++;
        b++;
    }
    if (!*a)
        write(1, s, a - s);
    write(1, "\n", 1);
}
*/
