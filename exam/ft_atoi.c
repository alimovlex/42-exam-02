#include <unistd.h>

int ft_atoi (const char* str)
{
    int sign = 1, number = 0, i = 0;
    long len = 0;
    const char* start = str;
    const char* end = str;

    while ((*start == ' ') || (*start == '\t') || (*start == '\n') || (*start == '\v')
           || (*start == '\f') || (*start == '\r'))
        start++;

    if (*start == '-')
    {
        sign *= -1;
        start++;
    }

    while(*end)
        end++;
    len = end - start;
    int arr[len];

    while(*start && i < len)
    {
        if (*start >= '0' && *start <= '9')
            arr[i] = *start - '0';
        start++;
        i++;
    }
    i = 0;
    while(len--)
    {
        number *= 10;
        number += arr[i++];
    }

    return number * sign;
}

/*
int ft_atoi(const char* str)
{
    int result = 0;
    int sign = 1;
    int current_digit = 0;

    // 1. Skip all whitespace characters (strictly at the beginning)
    while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
        str++;

    // 2. Handle the sign (exactly once and only one sign)
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }

    // 3. Process digits one by one
    while (*str >= '0' && *str <= '9')
    {
        // Extract the numerical value of the current character (the "unit")
        current_digit = *str - '0';

        // Shift the existing result to the left to make it "tens"
        result *= 10;

        // Add the new "unit" to our shifted result
        result += current_digit;

        str++;
    }

    return result * sign;
}
*/