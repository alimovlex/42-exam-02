/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   sort_list.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/22 09:58:50 by alalimov       #+#    #+#                */
/*   Updated: 2026/06/26 02:09:54 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct s_list t_list;
void ft_swap(int *a, int *b);

struct s_list
{
  int data;
  t_list *next;
};

int compare(int a, int b)
{
    return (b >= a);
}

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *head = lst;
    //OPTIONAL but intuitive!!!
    //Can be any passed function that contains any comparison algorithm
    cmp = compare;
    // The loop inherently protects against NULL or single-node lists
    while (lst->next != NULL)
    {
        // 2. Execute the callback pointer. If 0 (wrong order), swap and restart.
        //looks like strcmp!!!
        if (cmp(lst->data, lst->next->data) == 0)
        {
            ft_swap(&lst->data, &lst->next->data);
            lst = head; // Restart from the beginning
        }
        else
            lst = lst->next; // Move forward if the order is correct
    }
    return (head);
}

/*
t_list *sort_list(t_list *lst, int (*cmp)(int, int)) {
  // Protection: if the list is empty or has only one node, no sorting needed
  if (lst == NULL || lst->next == NULL)
    return (lst);

  t_list *start = lst; // Pointer to save the head of the list

  while (lst->next)
  {
    // If the elements are NOT in the right order according to 'cmp'
    if (cmp(lst->data, lst->next->data) == 0) {
      // Bitwise XOR swap algorithm to exchange data without a temp variable
      lst->data ^= lst->next->data;
      lst->next->data ^= lst->data;
      lst->data ^= lst->next->data;

      // Restart from the beginning of the list after the swap
      lst = start;
    }
    else
      // If the order is correct, move to the next node
      lst = lst->next;
  }
  // Return the sorted list starting from the original head
  return (start);
}

t_list  *sort_list(t_list* lst, int (*cmp)(int, int))
{
    int     tmp;
    t_list  *start;

    if (!lst)
        return (NULL);

    start = lst;

    while (lst->next)
    {
        if (cmp(lst->data, lst->next->data) == 0)
        {
            tmp = lst->data;
            lst->data = lst->next->data;
            lst->next->data = tmp;
            lst = start;
        }
        else
            lst = lst->next;
    }
    return (start);
}
 */
