#include <unistd.h>

void ft_print_range(char *start, char *end)
{
  // Only print while the start pointer hasn't passed the end pointer
  while (start < end)
  {
    write(1, start, 1);
    start++;
  }
}

void ft_last_word(char *str)
{
  char *end = str;

  // 1. Move end to the actual \0
  while (*end)
    end++;

  // 2. Back up past trailing spaces/tabs
  while (end > str && (*(end - 1) == ' ' || *(end - 1) == '\t'))
    end--;

  // 3. Back up until we hit a space or the start of the string
  char *start = end;
  while (start > str && (*(start - 1) != ' ' && *(start - 1) != '\t'))
    start--;

  // 4. Print only the range we found
  ft_print_range(start, end);
}

//int main(int argc, char **argv)
//{
//  // Usually, these exercises only care about the FIRST argument passed
//  if (argc == 2)
//    ft_last_word(*++argv);
//  write(1, "\n", 1);
//  return 0;
//}