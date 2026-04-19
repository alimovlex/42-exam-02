#include <unistd.h>

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