#pragma once

#ifdef __cplusplus
extern "C" {
#endif

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

//LEVEL 2
void ft_print_hex(char* str);

//LEVEL 3
char **ft_split(char *str);

#ifdef __cplusplus
}
#endif

