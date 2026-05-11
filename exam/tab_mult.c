#include <unistd.h>
#include <stdio.h>

void tab_mult(char* str)
{
    int digit = 0, i = 0, arr[9], j = 1;
    char* s1 = "x";
    char* s2 = "=";
    //char num;
    while(*str)
    {
        digit *= 10;
        digit += *str - '0';
        str++;
    }
    //printf("DIGIT SUBMITTED: %d\n", digit);

    while(i <= 8)
    {
        arr[i] = digit * j;
        printf("%d %s %d %s %d\n", j, s1, digit, s2, arr[i]);
        i++;
        j++;
    }

}
