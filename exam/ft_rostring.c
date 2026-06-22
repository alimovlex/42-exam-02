/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_rostring.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/22 09:52:42 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/22 09:52:44 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

//char **ft_split(char *str);
char *ft_first_word(char *str);
int ft_is_space(char c);

void ft_rostring(char *str)
{
    char *first_word;
    char *print_ptr;
    int word_printed = 0;

    // 1. Extract the first word using your helper function
    first_word = ft_first_word(str);
    if (!first_word)
        return;

    // 2. Advance the main string pointer PAST the first word
    // First, slide past the leading spaces to match where ft_first_word started
    while (ft_is_space(*str))
        str++;
    // Second, slide past the first word itself
    while (*str && !ft_is_space(*str))
        str++;

    // 3. Process and print all remaining words in the string
    while (*str)
    {
        // Skip spaces between remaining words
        while (ft_is_space(*str))
            str++;

        if (*str == '\0')
            break;

        // Print exactly one space separator before every word (except the first one printed)
        if (word_printed)
            write(1, " ", 1);
        word_printed = 1;

        // Print the current word
        while (*str && !ft_is_space(*str))
        {
            write(1, str, 1);
            str++;
        }
    }

    // 4. Print your saved first word at the very end
    if (word_printed)
        write(1, " ", 1); // Add a space if other words were printed before this

    print_ptr = first_word;
    while (*print_ptr)
        write(1, print_ptr++, 1);

    // 5. Free the memory allocated by ft_strdup to prevent memory leaks
    free(first_word);
}

/*
void ft_rostring(char *s)
{
    char **tab = ft_split(s), **p, *t;

    if (tab && *tab)
    {
        p = tab + 1;
        while (*p)
        {
            t = *p;
            while (*t)
                write(1, t++, 1);
            write(1, " ", 1);
            free(*p++); // Prints and frees the word simultaneously
        }
        t = *tab;
        while (*t)
            write(1, t++, 1);
        free(*tab); // Frees the first word
    }
    if (tab)
        free(tab); // Frees the main container array
    write(1, "\n", 1);
}

void ft_rostring(char *str)
{
    char  **tab;
    char  **ptr;
    char  *tmp;
    char  *p;
    char  **free_ptr; // New pointer strictly for freeing memory
    // 1. THE HACK: Hide the commas from your ft_word_count logic.
    // We iterate through the original string and replace commas with an invisible byte.
    p = str;
    while (*p)
    {
        if (*p == ',')
            *p = 1; // Replace with ASCII 1 (SOH)
        p++;
    }

    // 2. Now your ft_split will parse all words correctly, including the one with the comma.
    tab = ft_split(str);

    // Check if the array exists and has at least one word
    if (tab && *tab)
    {
        ptr = tab + 1; // Jump straight to the SECOND word

        while (*ptr) // Loop until the end of the array (NULL)
        {
            tmp = *ptr;
            while (*tmp)
            {
                // 3. Bring the comma back when printing
                if (*tmp == 1)
                    write(1, ",", 1);
                else
                    write(1, tmp, 1);
                tmp++;
            }
            write(1, " ", 1); // Print a space after each word
            ptr++;
        }

        // Finally, print the FIRST word at the very end
        tmp = *tab;
        while (*tmp)
        {
            if (*tmp == 1)
                write(1, ",", 1);
            else
                write(1, tmp, 1);
            tmp++;
        }
    }

    // 4. FREE THE MEMORY
    if (tab)
    {
        free_ptr = tab; // Point to the start of the array
        while (*free_ptr)
        {
            free(*free_ptr); // Free each individual word
            free_ptr++;      // Move to the next pointer
        }
        free(tab); // Finally, free the main array itself
    }

    write(1, "\n", 1);

}

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
