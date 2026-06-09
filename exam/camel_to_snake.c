/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   camel_to_snake.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:15:30 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:15:43 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void camel_to_snake(char *str)
{
    while(*str)
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            // Print the underscore separator before the word
            //write(1, "_", 1);
            *str += 32;
            *--str = '_';
        }
        write(1, str++, 1);
    }
    write(1, "\n", 1);
}
