#include <unistd.h>
#include <stdio.h>

void ft_fizzbuzz()
{
    int counter = 1;
    char *fizz = "fizz\n";
    char *buzz = "buzz\n";
    char* fizzbuzz = "fizzbuzz\n";
    char* fizz_start = fizz;
    char* buzz_start = buzz;
    char* fizzbuzz_start = fizzbuzz;
    while(counter++ < 100)
    {
        fizz = fizz_start;
        buzz = buzz_start;
        fizzbuzz = fizzbuzz_start;
        if (counter % 3 == 0 && counter % 5 == 0)
            while(*fizzbuzz)
                write(1, fizzbuzz++, 1);
        else if (counter % 3 == 0)
            while(*fizz)
                write(1, fizz++, 1);
        else if (counter % 5 == 0)
            while(*buzz)
                write(1, buzz++, 1);
        else
            printf("%d\n", counter);
    }
}
