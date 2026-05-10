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
#include "exam.h"

char *ft_strdup(char* src)
{
    char* start = src;
    while(*start)
        start++;
    int len = start - src;

    char* dup = (char*)malloc(len + 1);
    if (!dup)
        return NULL;

    char* begin = dup;
    while(*src)
        *dup++ = *src++;
    *dup = '\0';

    return begin;
}
