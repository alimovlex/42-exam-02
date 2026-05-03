#include <unistd.h>

void camel_to_snake(char *str)
{
    while (*str)
    {
        // Check if the current character is an uppercase letter
        if (*str >= 'A' && *str <= 'Z')
        {
            // Print the underscore separator before the word
            write(1, "_", 1);
            // Convert to lowercase by adding 32 (ASCII offset)
            *str += 32;
        }
        // Print the character (either original lowercase or converted)
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}
