/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strlen.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:17:24 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:17:25 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
    char* start = str;
    while(*str)
        str++;
    return str - start;
}
