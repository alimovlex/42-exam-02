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

char *ft_strdup(char *src)
{
    char *end = src;
    int len = 0;
    while(*end)
        end++;
    len = end - src;
    char *dup = (char *)malloc(++len);
    char *ptr = dup;
    while(*src)
        *ptr++ = *src++;
    *ptr = '\0';
    return dup;
}
