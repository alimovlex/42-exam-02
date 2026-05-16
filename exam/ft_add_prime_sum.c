#include <unistd.h>

void ft_add_prime_sum(char *str)
{
    int digit = 0, decimals = 1;
    char num;
    while(*str >= '0' && *str <= '9')
    {
        digit *= 10;
        digit += *str - '0';
        str++;
    }

    // 2. Calculate the sum of prime numbers directly inside
    int max_num = digit;
    int sum = 0;
    int current = 2; // Primes start from 2

    while (current <= max_num)
    {
        int is_prime = 1;
        int divisor = 2;

        // Inline prime check without any helper functions
        while (divisor * divisor <= current)
        {
            if (current % divisor == 0)
                is_prime = 0; // Found a divisor, not prime
            divisor++;
        }

        if (is_prime == 1)
            sum += current; // Add to total sum if prime
        current++;
    }

    // Put the calculated sum into digit so your printing logic can use it
    digit = sum;

    while (digit / decimals >= 10)
        decimals *= 10;

    // Extract and print each digit one by one
    while (decimals > 0)
    {
        // Convert digit to ASCII and use its address as a pointer for write
        num = digit / decimals + '0';
        write(1, &num, 1);
        // Update num to the remainder and decrease divisor
        digit %= decimals;
        decimals /= 10;
    }

    write(1, "\n", 1);
}