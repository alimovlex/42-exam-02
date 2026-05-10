/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rev_print.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:19:11 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:19:13 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_rev_print(char* str)
{
    char *start = str;
    while(*str)
        str++;
    str--;
    while (str >= start)
        write(1, str--, 1);
    write(1, "\n", 1);
}
