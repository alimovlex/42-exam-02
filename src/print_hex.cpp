#include <unistd.h>
#include <stdio.h>

void ft_print_digit(char* str, int iterator)
{
  int digit = 0, decimal = 0, number = 0;
    while(iterator--)
      number = *str - '0' * 10;
  //digit = number % 10;
  //decimal = number / 10;
  printf("digit = %d\n", *str - '0');
  
}

void ft_print_hex(char* str)
{
  //int digits = 0, decimals = 0;
  int i = 0;
  while(*str)
  {
    //ft_print_digit(str);
    str++;
  }

}

//int main(int argc, char** argv)
//{
//  char newline = '\n';
//  if (argc < 2)
//    write(1, &newline, 1);
//  else
//    while(*++argv)
//      ft_print_hex(*argv);
//  return 0;
//}