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

//int ft_is_prime(int a);

void fprime(char *str)
{
    int num = atoi(str);
    int result = 1;
    int i = 2;

    if (num == 1)
    {
        printf("1");
        return;
    }

    while (result < num)
    {
        /* * OPTIMIZATION 1: (num / result) % i == 0
         * We divide num by our current result first, THEN use modulo.
         * This completely removes the risk of integer overflow.
         */
        if ((num / result) % i == 0)
        {
            printf("%d", i);
            result *= i;          /* Build up our target number */

            if (result < num)     /* Only print '*' if we aren't done building */
                printf("*");
        }
        else
            i++; /* Exhausted this factor, move to the next */
    }
    printf("\n");
}

/*
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
        //ft_is_prime(i) is a reduntant check, just to understand the exercise
        if (ft_is_prime(i) && (n % i == 0))
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