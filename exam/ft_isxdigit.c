/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_isxdigit.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <alalimov@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/06/13 14:50:06 by alalimov       #+#    #+#                */
/*   Updated: 2026/06/13 14:50:09 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isxdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (c & 15);
    else if ((c | 32) >= 'a' && (c | 32) <= 'f')
        return ((c & 15) + 9);
    return (-1); // Invalid char
}
