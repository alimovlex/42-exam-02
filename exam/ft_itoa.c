/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_itoa.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/22 10:03:24 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/22 10:03:26 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_numlen(long num);

char *ft_itoa(int nbr)
{
    long    n = nbr;
    int     len;
    int     total_len;
    long    divisor = 1;
    char    *str;
    char    *ptr;

    // 1. Calculate length and memory needed
    len = ft_numlen(n);
    total_len = len;

    if (n < 0)
        total_len++; // Add space for the minus sign
    // 2. Allocate memory (+1 for the null-terminator)
    str = (char *)malloc(sizeof(char) * (total_len + 1));
    ptr = str; // Use a secondary pointer to write characters
    // 3. Handle negative numbers
    if (n < 0)
    {
        *ptr++ = '-';
        n = -n; // Convert to absolute value
    }
    // 4. Build the divisor based on the length (e.g., length 3 -> divisor 100)
    // We use a pre-decrement on a copy of len to correctly size the divisor
    while (--len > 0)
        divisor *= 10;
    // 5. Break down and store each digit into the string
    while (divisor > 0)
    {
        *ptr++ = (n / divisor) + '0';
        n %= divisor;
        divisor /= 10;
    }
    // 6. Null-terminate and return the start of the string
    *ptr = '\0';
    return (str);
}

/*
char	*ft_itoa(int nbr)
{
    long	n = nbr, decimals = 1;
    int		len = 0;

    // Calculate the base length and handle negative sign or zero
    if (n <= 0)
        len = 1;

    if (n < 0)
        n = -n;

    // Find the highest power of 10 and count digits simultaneously
    while (n / decimals >= 10)
    {
        decimals *= 10;
        len++;
    }
    if (n > 0)
        len++; // Add the final digit to the total length

    // Allocate memory
    char	*str = (char *)malloc(sizeof(char) * (len + 1));
    char	*ptr = str; 	// Set pointer to the beginning of the string

    // Add minus sign if the original number was negative
    if (nbr < 0)
        *ptr++ = '-';

    // Extract and write each digit from left to right
    while (decimals > 0)
    {
        *ptr = (n / decimals % 10) + '0';
        // *ptr = (n / decimals % 10) | 48; // Get digit, convert to ASCII, write to pointer
        ptr++; // Move pointer to the next free byte
        decimals /= 10; // Decrease the divisor
    }

    *ptr = '\0'; // Null-terminate the string

    return (str); // Return the starting address
}

char *ft_itoa(int nbr)
{
    long n = nbr;
    long temp = n;
    int len = 0;

    // 1. Calculate base length
    if (n <= 0)
        len = 1; // Account for '-' sign or '0'

    // Make temp positive to safely count digits
    if (temp < 0)
        temp = -temp;

    // Count digits
    while (temp > 0)
    {
        len++;
        temp /= 10;
    }

    // 2. Allocate memory and PROTECT IT
    char *str = (char *)malloc(sizeof(char) * (len + 1));

    // 3. Move pointer to the end of the allocated memory
    char *ptr = str + len;
    *ptr = '\0'; // Null-terminate the string

    // 4. Handle zero explicitly
    if (n == 0)
    {
        *str = '0';
        return (str);
    }

    // 5. Handle negative numbers
    if (n < 0)
    {
        *str = '-'; // Put '-' at the beginning
        n = -n;     // Make n positive for extraction
    }

    // 6. Move backwards and extract digits using pointer arithmetic
    while (n > 0)
    {
        ptr--; // Step back
        *ptr = (n % 10) + '0';
        n /= 10;
    }

    return (str); // str still points to the beginning of allocated memory
}
 */
