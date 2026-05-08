#include <unistd.h>

int ft_strcmp(char *s1, char *s2)
{
    // Loop forward as long as the characters match AND we haven't hit the end of s1
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }

    // Return the difference between the first non-matching characters.
    // Casting to unsigned char is standard behavior for strcmp.
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/*
int    ft_strcmp(char *s1, char *s2)
{
  while (*s1 && (*s1 == *s2))
    s1++, s2++;
  return *s1 - *s2;
}

// Returns 1 if the two strings are bitwise identical.
// Returns 0 if there is any difference in even a single bit.
int ft_strcmp(char *s1, char *s2)
{
	// Walk through both strings while they are non-null.
	while (*s1 && (*s1 == *s2))
	{
		unsigned char b1 = (unsigned char)*s1;  // Get current byte of s1
		unsigned char b2 = (unsigned char)*s2;  // Get current byte of s2

		// XOR: if bits are the same, result is 0.
		// If they differ, result is non-zero → strings are not identical.
		if (b1 ^ b2)
			return 0;

		s1++;
		s2++;
	}
	// After loop, check whether both strings ended at the same time.
	// If both are '\0', return 1; otherwise return 0.
	return (*s1 - *s2);
}
 */