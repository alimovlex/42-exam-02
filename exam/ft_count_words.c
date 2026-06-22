/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_count_words.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/06/22 05:50:15 by alalimov       #+#    #+#                */
/*   Updated: 2026/06/22 05:50:20 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_is_space(char c);

int count_words(char *str)
{
    int count = 0;

    while (*str)
    {
        if (ft_is_space(*str))
            str++;
        else
        {
            count++;
            while (*str && !ft_is_space(*str))
                str++;
        }
    }
    return (count);
}
