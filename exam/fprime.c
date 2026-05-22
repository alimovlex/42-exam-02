/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   fprime.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/22 09:50:21 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/22 09:50:25 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fprime(char *str)
{
  int n = atoi(str);
  int i = 2;

  if (n == 1)
  {
    printf("1");
    return;
  }
  while (i <= n)
  {
    if (n % i == 0)
    {
      printf("%d", i);
      n /= i;
      if (n > 1)
        printf("*");
    }
    else
      i++;
  }
  printf("\n");
}
