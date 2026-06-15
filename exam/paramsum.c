/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   paramsum.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:18:36 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:18:38 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_itoa(int nbr);

void paramsum(int argc, char **argv)
{
    (void)argv;

    char *str = ft_itoa(argc);
    char* ptr = str;
    while(*ptr)
        write(1, ptr++, 1);
    free(str);
    // Print the final newline character
    write(1, "\n", 1);
}

/*

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

void paramsum(int argc, char **argv)
{
    (void)argv;
    ft_itoa(--argc);
    // Print the final newline character
    write(1, "\n", 1);
}

//DOES NOT work with numbers over 100
void paramsum(int argc, char** argv)
{
    (void)argv;
	char decimal = (argc / 10) | 48;
	char digit = (argc % 10) | 48;
	if (argc >= 10)
		write(1, &decimal, 1);
	write(1, &digit, 1);
	write(1, "\n", 1);
}

*/
