/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strdup.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:17:16 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:17:17 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_strlen(char *str);

char *ft_strdup(char *src)
{
    char *end = src;
    int len = ft_strlen(end);
    char *dup = (char *)malloc(++len);
    char *ptr = dup;
    while(*src)
        *ptr++ = *src++;
    *ptr = '\0';
    return dup;
}
