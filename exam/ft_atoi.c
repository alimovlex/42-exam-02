#include <unistd.h>

int ft_atoi(const char *str)
{
    int sign = 1;
    int number = 0;
    int i = 0;
    long len = 0;
    const char *start = str;

    /* 1. Skip whitespace characters */
    while ((*start == ' ') || (*start >= '\t' && *start <= '\r'))
        start++;

    /* 2. Handle sign */
    if (*start == '-' || *start == '+')
    {
        if (*start == '-')
            sign = -1;
        start++;
    }

    /* 3. Calculate length of DIGITS ONLY to avoid garbage in the array */
    const char *check_len = start;
    while (*check_len >= '0' && *check_len <= '9')
    {
        len++;
        check_len++;
    }

    /* If no digits found, return 0 immediately */
    if (len == 0)
        return (0);

    /* 4. Create the array based on actual digit count */
    int arr[len];

    /* 5. Fill the array with digit values */
    while (i < len)
    {
        arr[i] = *start - '0';
        start++;
        i++;
    }

    /* 6. Convert the array of integers into a single number */
    i = 0;
    int temp_len = (int)len; // Use a copy because we'll decrement it
    while (temp_len--)
    {
        number *= 10;
        number += arr[i++];
    }

    return (number * sign);
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