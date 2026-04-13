#pragma once

#ifdef __cplusplus
extern "C" {
#endif

char **ft_split(char *str);
void ft_ulstr(char* str);
int ft_strlen(char *str);
void ft_swap(int *a, int *b);
void ft_last_word(char *str);
void ft_putstr(char *str);
void ft_print_hex(char* str);
void ft_repeat_alpha(char* str);
void ft_rev_print(char *str);
void ft_wdmatch(char** argv);
void ft_search_and_replace(int argc, char** argv);
unsigned char reverse_bits(unsigned char octet);

#ifdef __cplusplus
}
#endif

