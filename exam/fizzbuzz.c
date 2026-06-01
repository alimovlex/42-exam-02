/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   fizzbuzz.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:16:06 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:16:09 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_fizzbuzz()
{
    char *fizz = "fizz\n", *buzz = "buzz\n", *fizzbuzz = "fizzbuzz\n";
    char *fizz_ptr = fizz, *buzz_ptr = buzz, *fizzbuzz_ptr = fizzbuzz;
    int i = 1, decimal = 0, digit = 0;
    while(i <= 100)
    {
        fizz_ptr = fizz;
        buzz_ptr = buzz;
        fizzbuzz_ptr = fizzbuzz;
        decimal = i / 10 + '0';
        digit = i % 10 + '0';
        if ((i % 3 == 0) && (i % 5 == 0))
            while(*fizzbuzz_ptr)
                write(1, fizzbuzz_ptr++, 1);
        else if (i % 3 == 0)
            while(*fizz_ptr)
                write(1, fizz_ptr++, 1);
        else if (i % 5 == 0)
            while(*buzz_ptr)
                write(1, buzz_ptr++, 1);
        else
        {
            if (i >= 10)
                write(1, &decimal, 1);
            write(1, &digit, 1);
            write(1, "\n", 1);
        }
        i++;
    }
}
