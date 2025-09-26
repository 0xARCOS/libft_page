#ifndef LIBFT_H
# define LIBFT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

// typedef struct libft
// {
//     /* data */
// };

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
size_t  ft_strlen(const char *s);
void    *memset(void *s, int c, size_t n);
void    ft_bzero(void *d, size_t len);

#endif