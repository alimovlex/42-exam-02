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
typedef struct    s_list t_list; //Forward declaration of a linked list
typedef struct  s_point t_point;
// Math Problems & Number Theory
void ft_fizzbuzz();
int is_power_of_2(unsigned int n);
int pgcd(const char *s1, const char *s2);
unsigned int lcm(unsigned int a, unsigned int b);
void tab_mult(char *str);
void ft_add_prime_sum(char *str);
void fprime(char *str);

// Strings Manipulation
void ft_ulstr(char* str);
int ft_strlen(char *str);
void ft_putstr(char *str);
void ft_repeat_alpha(char* str);
void ft_rev_print(char *str);
void ft_rot_13(char* str);
void ft_rotone(char* str);
void ft_first_word(char* str);
char *ft_strcpy(char *s1, char *s2);
void ft_search_and_replace(int argc, char** argv);
void ft_wdmatch(char *s1, char *s2);
char* ft_strrev(char* str);
char* ft_strdup(char* src);
int ft_strcmp(char *s1, char *s2);
void ft_alpha_mirror(char* str);
void ft_inter(char *s1, char *s2);
size_t ft_strcspn(const char *s, const char *reject);
void snake_to_camel(char* str);
void camel_to_snake(char *str);
void ft_union(char* s1, char* s2);
void ft_last_word(char *str);
void rstr_capitalizer(char *str);
void str_capitalizer(char *str);
void hidenp(char *s1, char *s2);
void epur_str(char *str);
void ft_expand_str(char *str);
char **ft_split(char *str);
void ft_rev_wstr(char *str);

// Number Conversions (atoi, itoa)
int ft_atoi(const char* str);
void ft_do_op(int argc, char **argv);
int ft_atoi_base(const char *str, int str_base);
void print_hex(char *str);
char *ft_itoa(int nbr);

// Bit Operations
unsigned char reverse_bits(unsigned char octet);
unsigned char swap_bits(unsigned char octet);
void print_bits(unsigned char octet);

// Linked Lists
int ft_list_size(t_list *begin_list);
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
void ft_list_foreach(t_list *begin_list, void (*f)(void *));
t_list  *sort_list(t_list* lst, int (*cmp)(int, int));

// Array & Parsing
int	max(int* tab, unsigned int len);
void paramsum(int argc, char **argv);
int *ft_rrange(int start, int end);
int *ft_range(int start, int end);
void sort_int_tab(int *tab, unsigned int size);
void ft_rostring(char *str);

// Other / Matrices
void ft_swap(int *a, int *b);
void flood_fill(char **tab, t_point size, t_point begin);

//HELPER FUNCTIONS
int ft_is_space(char c);
int ft_isxdigit(char c);
int ft_strchr(char *s2, char s1);
int ft_strip_twos(int x);
int is_prime(int a);
#ifdef __cplusplus
}
#endif

