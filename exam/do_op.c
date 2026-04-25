#include <stdio.h>
#include <stdlib.h>

void ft_do_op(int argc, char **argv)
{
    /* Check if we have exactly 3 arguments (argc == 4 including program name) */
    if (argc == 4)
    {
        /* Get integers by dereferencing the shifted pointer to the argument strings */
        int n1 = atoi(*(argv + 1));
        int n2 = atoi(*(argv + 3));

        /* Get the operator char:
           *(argv + 2) points to the start of the operator string.
           ** (double dereference) gets the first character of that string. */
        char op = **(argv + 2);

        /* Logic execution using pointer-retrieved values */
        if (op == '+')
            printf("%d", n1 + n2);
        else if (op == '-')
            printf("%d", n1 - n2);
        else if (op == '*')
            printf("%d", n1 * n2);
        else if (op == '/')
            printf("%d", n1 / n2);
        else if (op == '%')
            printf("%d", n1 % n2);
    }
    /* Always a newline */
    printf("\n");
}
