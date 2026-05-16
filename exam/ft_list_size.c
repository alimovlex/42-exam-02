/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_list_size.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/16 20:43:15 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/16 20:43:17 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// The structure given in the assignment
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int ft_list_size(t_list *begin_list)
{
    int count = 0;
    // Loop through the train until we hit the end (NULL)
    while (begin_list != NULL)
    {
        count++;                  // Count the current wagon
        begin_list = begin_list->next; // Jump to the next wagon using the coupling
    }

    return (count); // Return the total number of wagons
}
