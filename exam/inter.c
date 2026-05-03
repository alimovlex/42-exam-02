#include <unistd.h>

void ft_inter(char* s1, char* s2)
{
    char* s1_temp = s1;
    char* s2_temp;
    char* check; // Pointer to look back at the history of s1

    while (*s1_temp)
    {
        // 1. Check if the current character has appeared in s1 before this position
        check = s1;
        while (check < s1_temp)
        {
            if (*check == *s1_temp)
                break; // Character was already processed, exit the look-back loop
            check++;
        }

        // 2. If check reached s1_temp, it means this character is appearing for the first time
        // Only in this case do we proceed to search for it in the second string
        if (check == s1_temp)
        {
            s2_temp = s2;
            while (*s2_temp)
            {
                if (*s1_temp == *s2_temp)
                {
                    write(1, s1_temp, 1);
                    break; // Found in s2, print it once and move to the next s1 character
                }
                s2_temp++;
            }
        }
        s1_temp++;
    }
}

/*
void ft_inter(char *s1, char *s2)
{
    char *p1 = s1;
    char *p1_scan;
    char *p2;

    while (*p1)
    {
        // 1. Check for duplicates in s1 by scanning from the start up to p1
        p1_scan = s1;
        while (p1_scan < p1 && *p1_scan != *p1)
            p1_scan++;

        // 2. If p1_scan reached p1, this is the FIRST time we've seen this char
        if (p1_scan == p1)
        {
            // 3. Scan s2 to see if the char exists there
            p2 = s2;
            while (*p2 && *p2 != *p1)
                p2++;

            // 4. If *p2 isn't null, we found a match
            if (*p2)
                write(1, p1, 1);
        }
        p1++;
    }
    write(1, "\n", 1);
}
*/
