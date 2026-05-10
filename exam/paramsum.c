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

void paramsum(int argc, char **argv)
{
    /* Ignore argv to prevent unused variable warnings */
    (void)argv;
    /* Handle the case with no arguments separately */
    if (argc == 0)
        return;

    /* Find the largest divisor (power of 10) for the number */
    int divisor = 1;
    char digit;
    while (argc / divisor >= 10)
        divisor *= 10;

    /* Extract and print each digit one by one */
    while (divisor > 0)
    {
        /* Convert digit to ASCII and use its address as a pointer for write */
        digit = (argc / divisor) + '0';
        write(1, &digit, 1);

        /* Update n to the remainder and decrease divisor */
        argc %= divisor;
        divisor /= 10;
    }

    /* Print the final newline character */
    write(1, "\n", 1);
}

/*
int paramsum(char *str)
{
    if (*str >= '0' && *str <= '9')
    {
        int num = 0, sum = 0, final = 0;
        char digit, decimal;
        while (*str)
        {
            num *= 10;
            num += *str - '0';
            str++;
        }
        sum += num;
        final = sum;
        while (sum > 0)
        {
            if (sum / 10 == 0)
                break;
            digit = (sum % 10) + '0';
            decimal = (sum / 10) + '0';
            sum /= 10;
        }
        write(1, &decimal, 1);
        write(1, &digit, 1);
        write(1, "\n", 1);
        return final;
    }
    else
        return 0;
}
*/
