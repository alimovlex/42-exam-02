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

int ft_is_prime(int a);

void fprime(char *str)
{
    int result = 1, i = 2, is_printed = 1;
    int num = atoi(str);

    if (num == 1)
    {
        printf("1");
        return;
    }

    while (result < num)
    {
        if (ft_is_prime(i) && (num % (result * i) == 0))
        {
            if (!is_printed)
                printf("*");
            printf("%d", i);
            is_printed = 0;
            result *= i;
        }
        else
            i++;
    }
    printf("\n");
}

/*
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

void fprime(char *str)
{
    int n = atoi(str);
    int i = 2;

    if (n == 1)
    {
        printf("1");
        return;
    }

    while (i * i <= n)
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

    if (n > 1)
        printf("%d", n);
    printf("\n");
}

*/