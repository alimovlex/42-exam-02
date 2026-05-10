/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strrev.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:17:33 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:17:34 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char* ft_strrev(char* str)
{
    char* start = str;
    char* end = str;

    while(*end)
        end++;
    end--;

    while(end > start)
    {
        char tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
    return str;
}
