/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_atoi_base.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:16:28 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:16:30 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi_base(const char *str, int str_base)
{
    int result = 0;
    int sign = 1;
    int digit;

    // If the base is invalid, return 0
    if (str_base < 2 || str_base > 16)
        return (0);

    // If the first character is a minus sign, store it and advance
    if (*str == '-')
    {
        sign = -1;
        str++;
    }

    // Iterate until the end of the string ('\0')
    while (*str)
    {
        // Convert the character to its numeric value (digit)
        if (*str >= '0' && *str <= '9')
            digit = *str - '0';
        else if (*str >= 'a' && *str <= 'f')
            digit = *str - 'a' + 10;
        else if (*str >= 'A' && *str <= 'F')
            digit = *str - 'A' + 10;
        else
            break; // Stop if invalid characters (spaces, symbols, etc.) are found

        // If the digit is not valid for the given base, stop
        if (digit >= str_base)
            break;

        // Accumulate the result
        result = (result * str_base) + digit;

        // Move the pointer to the next character
        str++;
    }

    // Return the result with the correct sign
    return (result * sign);
}
