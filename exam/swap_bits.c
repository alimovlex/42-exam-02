/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   swap_bits.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:19:57 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:19:58 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
    return octet >> 4 | octet << 4;
}
