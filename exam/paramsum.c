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
    (void)argv;

    int decimals = 1, num = argc;
    char digit;
    while (num / decimals >= 10)
        decimals *= 10;

    // Extract and print each digit one by one
    while (decimals > 0)
    {
        // Convert digit to ASCII and use its address as a pointer for write
        digit = num / decimals + '0';
        write(1, &digit, 1);
        // Update n to the remainder and decrease divisor
        argc %= decimals;
        decimals /= 10;
    }

    // Print the final newline character
    write(1, "\n", 1);
}


/*

//DOES NOT work with numbers over 100
void pasum(int argc, char** argv)
{
    (void)argv;
    char digit;
    int num = argc;

    //While decimals are more 10
    while (num >= 10)
    {
        digit = (num / 10) + '0';
        write(1, &digit, 1);
        num %= 10;  //Going to digits
    }

    digit = num + '0';  // The last digit
    write(1, &digit, 1);
    write(1, "\n", 1);
}

//DOES NOT work with numbers with zeros, e.g. 10, 100, 1000
void paramsum(int argc, char **argv)
{
    (void)argv;
    while(argc > 0)
    {
        char digit = argc % 10 + '0';
        write(1, &digit, 1);
        argc /= 10;
    }
    write(1, "\n", 1);
}
*/
