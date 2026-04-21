#include <unistd.h>

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

