#include <unistd.h>

void ft_rev_print(char *str)
{
  char newline = '\n';
  char *end = str;

  /* Find the end of the string (point to the null byte) */
  while (*end)
    end++;

  /* `end` now points to '\0'. Move back to the last character. */
  end--; //bring one step back from the null terminator

  /* Print characters backwards */
  while (end >= str)
  {
    write(1, end, 1);
    end--;
  }

  write(1, &newline, 1);
}

//int main(int argc, char **argv)
//{
//  char newline = '\n';
//
//  if (argc != 2) /* exactly one argument expected */
//    write(1, &newline, 1);
//  else
//      while(*++argv)
//    ft_rev_print(*argv);
//
//  return 0;
//}