/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_list_foreach.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/22 10:02:40 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/22 10:02:42 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

char *ft_itoa(int nbr);

void print_data(void *data)
{
    char *str = ft_itoa(*(int*)data);
    while(*str)
        write(1, str++, 1);
}

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    //OPTIONAL but intuitive!!!
    //Can be any passed function that does any operation
    f = print_data;
    // Loop through each node of the list until the end
    while (begin_list != NULL)
    {
        // Apply the function 'f' to the data of the current node
        f(begin_list->data);
        // Move to the next node in the list
        begin_list = begin_list->next;
    }
}
