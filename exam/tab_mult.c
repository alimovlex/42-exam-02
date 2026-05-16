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
#include <stdio.h>

// Helper function to print an integer using only write
void	ft_itoa(int number)
{
    int	decimals;
    char c;

    if (number == 0)
    {
        write(1, "0", 1);
        return;
    }
    decimals = 1;
    // Find the highest power of 10 that is less than or equal to n
    while (number / decimals >= 10)
        decimals *= 10;
    // Extract and print each digit from left to right
    while (decimals > 0)
    {
        c = number / decimals % 10 + '0';
        write(1, &c, 1);
        decimals /= 10;
    }
}

void	tab_mult(char *str)
{
    int	number = 0;
    int	j = 1;

    // Simple atoi: convert string to integer
    while (*str >= '0' && *str <= '9')
    {
        number *= 10;
        number += *str - '0';
        str++;
    }

    // Loop from 1 to 9 to display the table
    while (j <= 9)
    {
        ft_itoa(j);             // Print current multiplier
        write(1, " x ", 3);
        ft_itoa(number);        // Print the target number
        write(1, " = ", 3);
        ft_itoa(j * number);    // Print the result
        write(1, "\n", 1);
        j++;
    }
}
/*
void ft_itoa(int number)
{
    char c;

    if (number >= 100)
    {
        c = number / 100 + '0';
        write(1, &c, 1);
        c = (number / 10) % 10 + '0';
        write(1, &c, 1);
        c = number % 10 + '0';
        write(1, &c, 1);
    }
    else if (number >= 10)
    {
        c = number / 10 + '0';
        write(1, &c, 1);
        c = number % 10 + '0';
        write(1, &c, 1);
    }
    else
    {
        c = number + '0';
        write(1, &c, 1);
    }
}

void tab_mult(char *str)
{
    int digit = 0, i = 1, n;
    char *s1 = " x ", *s2 = " = ";
    char c;

    // atoi
    while(*str)
    {
        digit *= 10;
        digit += *str - '0';
        str++;
    }

    // loop from 1 to 9
    while (i <= 9)
    {
        n = digit * i;

        ft_itoa(i);
        write(1, s1, 3);
        ft_itoa(digit);
        write(1, s2, 3);
        ft_itoa(n);
        write(1, "\n", 1);

        i++;
    }
}

void tab_mult(char* str)
{
    int digit = 0, i = 0, arr[9], j = 1;
    char* s1 = "x";
    char* s2 = "=";
    //ATOI
    while(*str)
    {
        digit *= 10;
        digit += *str - '0';
        str++;
    }

    while(i <= 8)
    {
        *(arr + i) = digit * j;
        printf("%d%s%d%s%d\n", j, s1, digit, s2, arr[i]);
        i++;
        j++;
    }

}
*/
