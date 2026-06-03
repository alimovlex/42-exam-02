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
/*

// Your pocket pow function for integers
int ft_power(int decimal, int power)
{
    int result = 1;

    while (power > 0)
    {
        result *= decimal;
        power--;
    }
    return (result);
}

void ft_itoa(int number)
{
    int tmp = number, cnt = 0, divisor = 0;
    char current_digit;

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

    // --- STEP 1: Find out the number of digits (cnt) ---
    while (tmp > 0)
    {
        cnt++;
        tmp /= 10;
    }

    // --- STEP 2: Pure math via exponentiation ---
    // We need the power of (cnt - 1). For a three-digit number (cnt=3), we do 10^2 = 100
    divisor = ft_power(10, --cnt);

    // --- STEP 3: Your scheme for breaking down the number on the fly ---
    while (divisor > 0)
    {
	    //REVERSE ATOI PART
        current_digit = number / divisor;
	    current_digit += '0'; // Extract the pure digit
        write(1, &current_digit, 1);

        number %= divisor;            // Bite it off from the number
        divisor /= 10;                // Reduce the divisor
    }
}
//-------------------------------------ANOTHER_ITOA_FUNCTION----------------------------------
void ft_itoa(int number)
{
    int temp = number, cnt = 0, decimals = 1;
    char c;

    // Base case: check if the number is zero
    if (!number)
    {
        write(1, "0", 1);
    	return;
    }
    //count the total digits
    while (temp > 0)
        temp /= 10, cnt++;

    while (cnt-- > 1)
        decimals *= 10;

    // 3. Extract each digit from left to right and print it
    while (decimals > 0)
    {
        c = number / decimals % 10 + '0';
        write(1, &c, 1);
        decimals /= 10;
    }
}
//-------------------------------------ANOTHER_ITOA_FUNCTION----------------------------------
My buggy itoa function that works for numbers before 100.
void ft_itoa(int number)
{
	int decimal = 0, digit = 0;
	decimal = number / 10 + '0';
	digit = number % 10 + '0';
	if (number >= 10)
		write(1, &decimal, 1);
	write(1, &digit, 1);
}

void ft_tab_mult(char *str)
{
	int digit = 0, i = 1;
	char c = '1';

	while(*str)
	{
		digit *= 10;
		digit += *str - '0';
		str++;
	}

	while (i <= 9)
	{
		if (c >= '1' && c <= '9')
		{
			write(1, &c, 1);
			write(1, " x ", 3);
			ft_itoa(digit);
			write(1, " = ", 3);
			ft_itoa(digit * i);
			write(1, "\n", 1);
			c++;
			i++;
		}
	}

}
//-------------------------------------ANOTHER_ITOA_FUNCTION----------------------------------
// Helper function to print an integer using only write
static  void ft_itoa(int number)
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
    int	number = 0, i = 1;

    // Simple atoi: convert string to integer
    while (*str >= '0' && *str <= '9')
    {
        number *= 10;
        number += *str - '0';
        str++;
    }

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
//-------------------------------------ANOTHER_ITOA_FUNCTION----------------------------------
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
