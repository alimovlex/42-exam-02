#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    fprime(char *str)
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