/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <alalimov@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/10/14 12:39:58 by alalimov       #+#    #+#                */
/*   Updated: 2025/10/14 12:40:00 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "exam.h"
#define Log(fmt, ...) \
    printf("[%s] [%s] [Line %d]: " fmt "\n", __FILE_NAME__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)

int main(int argc, char** argv)
{
    char str[] = "Hello World\n";
    ft_first_word(str);
    ft_putstr(str);
    ft_rev_print(str);
    ft_rot_13(str);
    ft_rotone(str);
    return 0;
}

/*
int paramsum(char *str)
{
    if (*str >= '0' && *str <= '9')
    {
        int num = 0, sum = 0, final = 0;
        char digit, decimal;
        while (*str)
        {
            num *= 10;
            num += *str - '0';
            str++;
        }
        sum += num;
        final = sum;
        while (sum > 0)
        {
            if (sum / 10 == 0)
                break;
            digit = (sum % 10) + '0';
            decimal = (sum / 10) + '0';
            sum /= 10;
        }
        write(1, &decimal, 1);
        write(1, &digit, 1);
        write(1, "\n", 1);
        return final;
    }
    else
        return 0;
}
 */