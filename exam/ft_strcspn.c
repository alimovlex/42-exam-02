#include <unistd.h>
#include <stddef.h>
/*
 * The strcspn() function searches for the first occurrence in a string of
 * any of the specified characters and returns the length of the string up to that point.
 * If none of the characters are found then the length of the string is returned.
 */

size_t ft_strcspn(const char *s, const char *reject)
{
    const char *start = s, *reader = reject;

    while (*start)
    {
        // 1. Did we step on a bad thing?
        if (*start == *reader)
            return (size_t)(start - s);

        // 2. Are we at the end of the blacklist?
        if (!*reader++)
        {
            reader = reject; // Reset the blacklist to the top
            start++;        // Take one step forward on the sidewalk
        }
    }
    return (size_t)(start - s);
}

/*
size_t ft_strcspn(const char *s, const char *reject)
{
    // 1. Drop a pin where we started so we can measure distance later.
    char *start = s;

    // 2. We need a second pointer to read our "blacklist" paper.
    char *reader;

    // Walk down the sidewalk (the main string 's') until we hit the end '\0'
    while (*s)
    {
        // For EVERY step we take, pull out the blacklist paper
        // and start reading it from the very beginning.
        reader = reject;

        while (*reader) // Read through the blacklist items one by one
        {
            if (*s == *reader)
            {
                // UH OH! The thing we are standing on (*s) matches
                // a bad thing on our list (*r). STOP WALKING!

                // Return our distance: Current position minus Starting position.
                return (size_t)(s - start);
            }
            reader++; // Move to the next item on the blacklist
        }

        // If we checked the whole blacklist and are safe, take a step forward!
        s++;
    }

    // If we walked the ENTIRE sidewalk and never stepped on anything bad,
    // we still need to return the total distance we walked.
    return (size_t)(s - start);
}
*/
