/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_add_prime_sum.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/16 20:42:52 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/16 20:42:55 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(const char* str);
char	*ft_itoa(int nbr);
int is_prime(int a);

int ft_numlen(int num)
{
    int i = 0;
    while (num > 0) {
        num /= 10;
        i++;
    }
    return i;
}

void ft_itoa_print(int number)
{
    int divisor = 1, len = ft_numlen(number), size = --len, digit = 0;
    char c;

    if (number == 0)
    {
        write(1, "0\n", 2);
        return;
    }

    while (size-- > 0)
        divisor *= 10;

    while (divisor > 0) {
        digit = number / divisor;
        c = digit + '0';
        write(1, &c, 1);
        number %= divisor;
        divisor /= 10;
    }
    write(1, "\n", 1);
}

void ft_add_prime_sum(char *str)
{
    int digit = 0, sum = 0, i = 2;

    if (*str == '-' || *str == '\0')
    {
        write(1, "0\n", 2);
        return;
    }

    digit = ft_atoi(str);

    while(i <= digit)
    {
        if (is_prime(i))
            sum += i;
        i++;
    }

    ft_itoa_print(sum);
}

/*
void ft_add_prime_sum(char *str)
{
    int digit = 0;
    // Simple atoi: convert string to integer
    digit = ft_atoi(str);

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
    char* ptr = ft_itoa(digit);
    char *start = ptr;
    while(*ptr)
        write(1, ptr++, 1);
    free(start);
    write(1, "\n", 1);
}

void ft_add_prime_sum(char *str)
{
    int digit = 0, decimals = 1;
    char num;
    // Simple atoi: convert string to integer
    while((*str & 240) == 48) //(*str >= '0' && *str <= '9')
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
*/
