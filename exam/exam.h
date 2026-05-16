/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   exam.h                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:14:48 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:20:20 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>
//LEVEL 0
void ft_fizzbuzz();
void ft_ulstr(char* str);
int ft_strlen(char *str);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
void ft_repeat_alpha(char* str);
void ft_rev_print(char *str);
void ft_rot_13(char* str);
void ft_rotone(char* str);
void ft_first_word(char* str);
char *ft_strcpy(char *s1, char *s2);
void ft_search_and_replace(int argc, char** argv);

//LEVEL 1
unsigned char reverse_bits(unsigned char octet);
unsigned char swap_bits(unsigned char octet);
void print_bits(unsigned char octet);
void ft_wdmatch(char *s1, char *s2);
int	max(int* tab, unsigned int len);
char* ft_strrev(char* str);
char* ft_strdup(char* src);
int ft_strcmp(char *s1, char *s2);
void ft_alpha_mirror(char* str);
int ft_atoi(const char* str);
int is_power_of_2(unsigned int n);
void ft_inter(char *s1, char *s2);
size_t ft_strcspn(const char *s, const char *reject);
void ft_do_op(int argc, char **argv);
void snake_to_camel(char* str);
void camel_to_snake(char *str);
void ft_union(char* s1, char* s2);
void ft_last_word(char *str);

//LEVEL 2
int ft_atoi_base(const char *str, int str_base);
void rstr_capitalizer(char *str);
void str_capitalizer(char *str);
void print_hex(char *str);
int pgcd(const char *s1, const char *s2);
void hidenp(char *s1, char *s2);
unsigned int lcm(unsigned int a, unsigned int b);
void paramsum(int argc, char **argv);
void epur_str(char *str);
int *ft_rrange(int start, int end);
int *ft_range(int start, int end);
void tab_mult(char *str);
void ft_expand_str(char *str);
void ft_add_prime_sum(char *str);
typedef struct    s_list t_list;
int ft_list_size(t_list *begin_list);

//LEVEL 3
char **ft_split(char *str);

#ifdef __cplusplus
}
#endif

