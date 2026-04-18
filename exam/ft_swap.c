#include <unistd.h>

void	ft_swap(int *a, int *b)
{
    if (a != b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

/*
void	ft_swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
 */