/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   print_bits.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:18:47 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:18:48 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_bits(unsigned char octet)
{
    int i = 8;
    while (i--)
    {
        if (octet & 128)
            write(1, "1", 1);
        else
            write(1, "0", 1);

        octet <<= 1;
    }
}

/*
void	print_bits(unsigned char octet)
{
	int i = 7;

	while (i >= 0)
	{
		if ((octet >> i) & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
}
 */

/*
void print_bits(unsigned char octet)
{
    int i = 8;
    unsigned char bit = 0; 

    while (i--) 
    {
        bit = (octet >> i & 1) + '0';
        write (1, &bit, 1);
    }
}
*/
