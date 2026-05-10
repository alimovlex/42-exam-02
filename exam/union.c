/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   union.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:20:08 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:20:09 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_union(char *s1, char *s2)
{
    // Array for all 256 ASCII characters, initialized to 0
    unsigned char	seen[256] = {0};

    // 1. Process the first string
    while (*s1)
    {
        // If the character hasn't been printed yet
        if (seen[(unsigned char)*s1] == 0)
        {
            write(1, s1, 1);
            seen[(unsigned char)*s1] = 1; // Mark as printed
        }
        s1++;
    }

    // 2. Process the second string
    while (*s2)
    {
        // Same logic for the second string
        if (seen[(unsigned char)*s2] == 0)
        {
            write(1, s2, 1);
            seen[(unsigned char)*s2] = 1; // Mark as printed
        }
        s2++;
    }
    write(1, "\n", 1);
}

/*
void	ft_union(char *s1, char *s2)
{
    char	*curr;
    char	*check;
    int		is_unique;

    // 1. Process the first string
    curr = s1;
    while (*curr)
    {
        check = s1;
        is_unique = 1;
        // Scan backwards from current position to the start of s1
        while (check < curr)
        {
            if (*check == *curr)
            {
                is_unique = 0;
                break ;
            }
            check++;
        }
        if (is_unique)
            write(1, curr, 1);
        curr++;
    }

    // 2. Process the second string
    curr = s2;
    while (*curr)
    {
        is_unique = 1;
        // First, check if the character exists anywhere in the entire s1
        check = s1;
        while (*check)
        {
            if (*check == *curr)
            {
                is_unique = 0;
                break ;
            }
            check++;
        }
        // If not in s1, check if it appeared earlier in s2
        if (is_unique)
        {
            check = s2;
            while (check < curr)
            {
                if (*check == *curr)
                {
                    is_unique = 0;
                    break ;
                }
                check++;
            }
        }
        if (is_unique)
            write(1, curr, 1);
        curr++;
    }
    write(1, "\n", 1);
}
*/
