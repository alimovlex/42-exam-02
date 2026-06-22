/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   sort_int_tab.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/22 09:58:22 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/22 09:58:24 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_swap(int *a, int *b);

void sort_int_tab(int *tab, unsigned int size)
{
    int bit;
    int *start;
    int *end;
    int *chunk_start;
    int *chunk_end;
    int *next_chunk;
    int *left;
    int *right;
    unsigned int p1;
    unsigned int p2;
    unsigned int target_l; // <--- Changed to unsigned int
    unsigned int target_r; // <--- Changed to unsigned int

    if (size <= 1)
        return;

    start = tab;
    end = tab + size - 1;

    bit = 31;
    while (bit >= 0)
    {
        chunk_start = start;

        while (chunk_start <= end)
        {
            chunk_end = chunk_start;

            while (chunk_end < end)
            {
                p1 = 0;
                p2 = 0;

                if (bit < 31)
                {
                    p1 = (unsigned int)(*chunk_end) >> (bit + 1);
                    p2 = (unsigned int)(*(chunk_end + 1)) >> (bit + 1);
                }

                if (p1 == p2)
                    chunk_end++;
                else
                    break;
            }

            next_chunk = chunk_end + 1;
            left = chunk_start;
            right = chunk_end;

            // Targets are now safely unsigned integers
            target_l = 0;
            target_r = 1;

            if (bit == 31)
            {
                target_l = 1;
                target_r = 0;
            }

            while (left <= right)
            {
                // Both sides of the == are strictly unsigned int
                while (left <= right && ((((unsigned int)*left >> bit) & 1) == target_l))
                    left++;

                while (left <= right && ((((unsigned int)*right >> bit) & 1) == target_r))
                    right--;

                if (left < right)
                {
                    ft_swap(left, right);
                    left++;
                    right--;
                }
            }
            chunk_start = next_chunk;
        }
        bit--;
    }
}

/*
void sort_int_tab(int *tab, unsigned int size)
{
    int *ptr = tab;

    // 2. Safety check is embedded cleanly in the loop condition
    while (size > 1 && ptr < tab + size - 1)
    {
        if (*ptr > *(ptr + 1))
        {
            ft_swap(ptr, ptr + 1);
            ptr = tab; // Reset to the start of the array after a swap
        }
        else
            ptr++; // Step forward if elements are in the right order
    }
}

void sort_int_tab(int *tab, unsigned int size) {
  int *ptr = tab;

  // Safety check for empty or single-element arrays
  if (size <= 1 || !tab)
    return;

  while (ptr < (tab + size - 1))
  {
    // If the current element is greater than the next one, swap them
    if (*ptr > *(ptr + 1))
    {
      // In-place XOR swap (no temp variable needed)
      *ptr ^= *(ptr + 1);
      *(ptr + 1) ^= *ptr;
      *ptr ^= *(ptr + 1);

      // Reset the pointer to the beginning to re-check the array
      ptr = tab;
    }
    else
      // Move to the next memory address
      ptr++;
  }
}

void sort_int_tab(int *tab, unsigned int size)
{
    int temp;
    int *ptr = tab;

    if (size <= 1)
        return;

    while (ptr < (tab + size - 1))
    {
        // Check if the current value is bigger than the next one
        if (*ptr > *(ptr + 1))
        {
            // Swap the values in memory
            temp = *ptr;
            *ptr = *(ptr + 1);
            *(ptr + 1) = temp;

            // Reset pointer back to the beginning of the array
            ptr = tab;
        }
        else
        {
            // If order is correct, move to the next memory address
            ptr++;
        }
    }
}
 */
