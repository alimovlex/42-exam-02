#include <unistd.h>
#include <stdio.h>

void tab_mult(char* str)
{
    int digit = 0, i = 1, arr[9];
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

    while(i <= 9)
    {
        arr[i] = digit * i;
        printf("%d %s %d %s %d\n", i, s1, digit, s2, arr[i]);
        i++;
    }

}
