/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   tab_mult.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/16 20:45:17 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/16 20:45:18 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int ft_atoi(const char* str);
char    *ft_itoa(int nbr);

void	tab_mult(char *str)
{
    int		number = 0, i = 1;
    char	*s1;
    char	*s2;
    char	*s3;
    char	*ptr;

    // Simple atoi: convert string to integer
    number = ft_atoi(str);
    // Convert the target number to string ONCE outside the loop (optimization)
    s2 = ft_itoa(number);
    // Loop from 1 to 9 to display the table
    while (i <= 9)
    {
        s1 = ft_itoa(i);             // String for current multiplier (1 to 9)
        s3 = ft_itoa(i * number);    // String for the result

        // Print multiplier (s1) using a pointer
        ptr = s1;
        while (*ptr)
            write(1, ptr++, 1);

        write(1, " x ", 3);

        // Print target number (s2)
        ptr = s2;
        while (*ptr)
            write(1, ptr++, 1);

        write(1, " = ", 3);

        // Print result (s3)
        ptr = s3;
        while (*ptr)
            write(1, ptr++, 1);

        write(1, "\n", 1);

        // Free memory for strings created inside the loop
        free(s1);
        free(s3);
        i++;
    }

    // Free the target number string created outside the loop
    free(s2);
}

/*--------------------------------------------

int ft_atoi(char *str)
{
        int digit = 0;
        while(*str)
        {
                digit *= 10;
                digit += *str & 15;
                str++;
        }
        return digit;
}

int ft_numlen(int num)
{
    int i = 0;
    while (num > 0) {
        num /= 10;
        i++;
    }
    return i;
}

void ft_itoa(int number)
{
    int divisor = 1, len = ft_numlen(number), size = --len, digit = 0;
    if (number == 0)
    {
            write(1, "0", 1);
            return;
    }
    else if (number < 0)
    {
            write(1, "-", 1);
            number *= -1;
    }

    // Build the divisor directly based on the length (e.g., length 3 -> divisor 100)
    while (size-- > 0)
        divisor *= 10;

    // Break down and print
    while (divisor > 0) {
        digit = number / divisor;
        char c = digit + '0';
        write(1, &c, 1);
        number %= divisor;
        divisor /= 10;
    }
}

void    ft_tab_mult(char *str)
{
    int number = ft_atoi(str), i = 1;

    // Loop from 1 to 9 to display the table
    while (i <= 9)
    {
        ft_itoa(i);             // Print current multiplier
        write(1, " x ", 3);
        ft_itoa(number);        // Print the target number
        write(1, " = ", 3);
        ft_itoa(i * number);    // Print the result
        write(1, "\n", 1);
        i++;
    }
}
*/