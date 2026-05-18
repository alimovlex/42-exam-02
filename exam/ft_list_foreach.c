#include <unistd.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    // Loop through each node of the list until the end
    while (begin_list)
    {
        // Apply the function 'f' to the data of the current node
        f(begin_list->data);
        // Move to the next node in the list
        begin_list = begin_list->next;
    }
}
