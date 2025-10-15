
#include "libft.h"

/*
    Aquí la idea es parecida a ft_putchar_fd, pero en lugar
    de escribir un solo carácter, escribes una cadena completa
    y luego un salto de línea.
*/

void    ft_putendl_fd(char *s, int fd)
{
    int     i;

    if (!s)
        return NULL;
    while (s[i])
        write(fd, &s[i++], 1);
    write(fd, "\n", 1);
}
