#include <unistd.h>
#include <stdlib.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list  *cur;
    t_list  *prev;
    t_list  *tmp;

    if (!begin_list)
        return;

    cur = *begin_list;
    prev = NULL;

    while (cur)
    {
        if (cmp(cur->data, data_ref) == 0)
        {
            // Node must be removed
            tmp = cur->next;          // save next node

            if (prev == NULL)
                *begin_list = tmp;     // removing head: move head
            else
                prev->next = tmp;      // link previous to next, skipping cur

            free(cur);                 // free removed node
            cur = tmp;                 // continue from next node
        }
        else
        {
            // Node stays in the list
            prev = cur;                // move prev forward
            cur = cur->next;           // move cur forward
        }
    }
}

/*
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    // Protection: if the list doesn't exist or is empty, exit
    if (begin_list == NULL || *begin_list == NULL)
        return;

    t_list *current = *begin_list; // Start at the first node (head)
    t_list *prev = NULL;           // No previous node yet
    t_list *temp_to_free;          // Temporary pointer for the node to be freed

    while (current != NULL)
    {
        // Check if current node's data matches data_ref
        if (cmp(current->data, data_ref) == 0)
        {
            temp_to_free = current; // Store the node to be removed

            if (prev == NULL)
            {
                // If we are removing the very first node (head)
                *begin_list = current->next; // Update the head pointer to the next node
                current = *begin_list;       // Move current pointer to the new head
            }
            else
            {
                // If the node is in the middle or at the end
                prev->next = current->next; // Link previous node to the next one, bypassing current
                current = current->next;    // Move current pointer to the next node
            }

            // Free the memory of the detached node
            free(temp_to_free);
        }
        else
        {
            // If data doesn't match, just move forward
            prev = current;             // Current node becomes the previous one
            current = current->next;    // Move to the next node
        }
    }
}
*/