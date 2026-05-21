#include <unistd.h>
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
    long	n = nbr, decimals = 1;
    int		len = 0;

    // Calculate the base length and handle negative sign or zero
    if (n <= 0)
        len = 1;

    if (n < 0)
        n = -n;

    // Find the highest power of 10 and count digits simultaneously
    while (n / decimals >= 10)
    {
        decimals *= 10;
        len++;
    }
    if (n > 0)
        len++; // Add the final digit to the total length

    // Allocate memory
    char	*str = (char *)malloc(sizeof(char) * (len + 1));
    char	*ptr = str; 	// Set pointer to the beginning of the string

    // Add minus sign if the original number was negative
    if (nbr < 0)
        *ptr++ = '-';

    // Extract and write each digit from left to right
    while (decimals > 0)
    {
        *ptr = (n / decimals % 10) + '0'; // Get digit, convert to ASCII, write to pointer
        ptr++; // Move pointer to the next free byte
        decimals /= 10; // Decrease the divisor
    }

    *ptr = '\0'; // Null-terminate the string

    return (str); // Return the starting address
}

/*
char	*ft_itoa(int nbr)
{
	long	n = nbr, temp = nbr;
	int		len = 0;

	// 1. Calculate the required string length
	if (n <= 0)
		len = 1; // Account for negative sign or zero

	while (temp > 0)
	{
		len++;
		temp /= 10;
	}

	// 2. Allocate memory
	char	*str = (char *)malloc(sizeof(char) * (len + 1));

	// 3. Move pointer to the end of the allocated memory
	char	*ptr = str + len;
	*ptr = '\0'; // Null-terminate the string

	// 4. Handle zero and negative numbers
	if (n == 0)
	{
		*str = '0'; // Put '0' at the very beginning
		return (str);
	}

	if (n < 0)
	{
		*str = '-'; // Put '-' at the beginning of the string
		n = -n;     // Convert to positive
	}

	// 5. Move backwards and extract digits
	while (n > 0)
	{
		ptr--; // Step back
		*ptr = (n % 10) + '0'; // Convert digit to ASCII and store it
		n /= 10; // Remove the last digit from the number
	}

	return (str); // Return the pointer to the start of the string
}
 */