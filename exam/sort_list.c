#include <unistd.h>

typedef struct s_list t_list;

struct s_list
{
    int data;
    t_list *next;
};

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    // Protection: if the list is empty or has only one node, no sorting needed
    if (lst == NULL || lst->next == NULL)
        return (lst);

    t_list	*start = lst; // Pointer to save the head of the list

    while (lst->next)
    {
        // If the elements are NOT in the right order according to 'cmp'
        if (cmp(lst->data, lst->next->data) == 0)
        {
            // Bitwise XOR swap algorithm to exchange data without a temp variable
            lst->data = lst->data ^ lst->next->data;
            lst->next->data = lst->data ^ lst->next->data;
            lst->data = lst->data ^ lst->next->data;

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
/*
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
