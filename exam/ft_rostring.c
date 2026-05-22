#include <unistd.h>

void ft_rostring(char *str)
{
    char *first_start;
    char *first_end;
    int word_printed = 0;

    // Skip leading whitespaces
    while (*str == ' ' || *str == '\t')
        str++;

    // Mark the start of the first word
    first_start = str;

    // Move pointer to the end of the first word
    while (*str && *str != ' ' && *str != '\t')
        str++;

    // Mark the end of the first word
    first_end = str;

    // Skip whitespaces exactly after the first word
    while (*str == ' ' || *str == '\t')
        str++;

    // Process the rest of the string
    while (*str)
    {
        if (*str != ' ' && *str != '\t')
        {
            // Print characters of the remaining words
            write(1, str, 1);
            word_printed = 1;
            str++;
        }
        else
        {
            // Skip all consecutive whitespaces
            while (*str == ' ' || *str == '\t')
                str++;

            // If there is another word ahead, print a single space separator
            if (*str)
                write(1, " ", 1);
        }
    }

    // Print the first word at the end if it exists
    if (first_start < first_end)
    {
        // Add a space before it, ONLY if we printed other words before
        if (word_printed)
            write(1, " ", 1);

        // Print the first word using the pointers we saved
        while (first_start < first_end)
        {
            write(1, first_start, 1);
            first_start++;
        }
        write(1, "\n", 1);
    }
}

/*
void    ft_rostring(char *str)
{
    char *first_start;
    char *first_end;
    int   started;

    started = 0;

    // Skip leading spaces/tabs
    while (*str == ' ' || *str == '\t')
        str++;

    // If the string is empty or only spaces/tabs
    if (*str == '\0')
        return ;

    // Save the first word (start and end)
    first_start = str;
    while (*str && *str != ' ' && *str != '\t')
        str++;
    first_end = str - 1;

    // Print all words after the first one
    while (*str)
    {
        // Skip spaces/tabs between words
        while (*str == ' ' || *str == '\t')
            str++;

        if (*str == '\0')
            break;

        // Print space before every word except the very first printed one
        if (started)
            write(1, " ", 1);
        started = 1;

        // Print current word
        while (*str && *str != ' ' && *str != '\t')
        {
            write(1, str, 1);
            str++;
        }
    }

    // Print space before the first word if we already printed something
    if (started)
        write(1, " ", 1);

    // Print the first word
    while (first_start <= first_end)
    {
        write(1, first_start, 1);
        first_start++;
    }
    write(1, "\n", 1);
}
 */