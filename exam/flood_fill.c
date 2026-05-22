/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   flood_fill.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:20:35 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:20:36 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct  s_point
{
    int           x;
    int           y;
} t_point;


void flood_fill(char **tab, t_point size, t_point begin)
{
    char target;
    char *row;

    // Get target char at starting point using pure pointer arithmetic
    row = *(tab + begin.y);
    target = *(row + begin.x);
    if (target == 'F')
        return;

    // Allocate a manual stack on the system stack framework
    // Big enough for typical exam test matrices (e.g., up to 64x64 grids)
    t_point stack[4096];

    // Create a moving pointer that acts as our stack top tracker
    t_point *stack_ptr = stack;

    // Push starting point: assign value to where stack_ptr points, then increment it
    *stack_ptr = begin;
    stack_ptr++;

    // While our moving pointer hasn't dropped back to the base of the stack
    while (stack_ptr > stack)
    {
        // Pop last point: decrement pointer first, then extract the data
        stack_ptr--;
        t_point p = *stack_ptr;
        int x = p.x;
        int y = p.y;

        // Bounds check for the current popped point
        if (x < 0 || x >= size.x || y < 0 || y >= size.y)
            continue;

        row = *(tab + y);

        // Skip if this cell does not match our target character
        if (*(row + x) != target)
            continue;

        // Fill current cell with 'F'
        *(row + x) = 'F';

        // Prepare neighbors to push
        t_point right = {x + 1, y};
        t_point left  = {x - 1, y};
        t_point down  = {x, y + 1};
        t_point up    = {x, y - 1};

        // Safety check: Only push if we have enough space left in our 4096 stack array
        // (stack + 4092) ensures we always have room to safely push 4 elements
        if (stack_ptr < (stack + 4092))
        {
            *stack_ptr = right; stack_ptr++;
            *stack_ptr = left;  stack_ptr++;
            *stack_ptr = down;  stack_ptr++;
            *stack_ptr = up;    stack_ptr++;
        }
    }
}
