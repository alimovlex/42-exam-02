#include <unistd.h>

void ft_search_and_replace(int argc, char** argv)
{
    char *str;
    char find;
    char rep;
    int i = 0;

    // If there are exactly 3 arguments (plus the program name = 4)
    if (argc == 4)
    {
        // Grab the characters to find and replace
        find = **(argv + 2); //character to search
        rep = **(argv + 3); //character to replace

        // Check if 2nd and 3rd args are exactly 1 char long (followed by '\0')
        // to prevent processing strings like "art" or "zul"
        if (*(*(argv + 2) + 1) == '\0' && *(*(argv + 3) + 1) == '\0')
        {
            // Pointer to our main string (1st argument)
            str = *(argv + 1);

            // Loop through the string until the null-terminator
            while (*str)
            {
                // If we find the target char, write the replacement
                if (*str == find)
                    write(1, &rep, 1);
                    // Otherwise, write the original char
                else
                    write(1, str, 1);

                // Move the pointer to the next char
                str++;
                i++;
            }
        }
    }
    // Always print a newline at the end
    write(1, "\n", 1);
}