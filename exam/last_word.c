#include <unistd.h>

void	ft_last_word(char *str)
{
    char	*end = str;

    if (!str)
        return;
    // 1. Go to the end of the string
    while (*end)
        end++;

    end--; // Stand on the last actual character before \0

    // 2. Skip trailing spaces and tabs (cut off the tail)
    while (end > str && (*end == ' ' || *end == '\t'))
        end--;

    // 3. Skip the word backwards to find its start
    while (end > str && *end != ' ' && *end != '\t')
        end--;

    // If we stopped on a space, the word starts at the NEXT character
    if (*end == ' ' || *end == '\t')
        end++;

    // 4. Print the word until we hit a space, tab, or \0
    while (*end && *end != ' ' && *end != '\t')
        write(1, end++, 1);

}