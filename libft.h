#ifndef libft_H
# define libft_H

#include <stdlib.h>

typedef int size_t;

int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);
int ft_strncmp(const char *s1, const char *s2, size_t n);

size_t  ft_strlen(const char *s);
size_t  ft_strlcat(char *dst, const char *src, size_t size)
size_t  ft_strlcpy(char *dst, const char *src, size_t size);

char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
#endif