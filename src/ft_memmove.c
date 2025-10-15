
#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    if (n == 0)
        return (dest);
    const char  *str;
    char        *ptr;

    str = src;
    ptr = dest;

    if (dest < src)
    {
        while (n--)
            *ptr++ = *str++;
    }
    else if (dest > src)
    {
        ptr += n;
        src += n;
        while (n--)
            *--ptr = *--str;
    }
    return ((void *)dest);
}

// #include <stdio.h>
// #include <string.h>

// // Prototipo de tu memmove personalizada
// void    *memmove(void *dest, const void *src, size_t n);

// void    print_buffer(const char *label, const char *buf, size_t n)
// {
//     size_t i = 0;
//     printf("%s: ", label);
//     while (i < n)
//         printf("%c", buf[i++]);
//     printf("\n");
// }

// int main(void)
// {
//     char    buf1[20] = "ABCDEFGHIJKLMN";
//     char    buf2[20] = "ABCDEFGHIJKLMN";
//     char    buf3[20] = "ABCDEFGHIJKLMN";
//     char    buf4[20] = "ABCDEFGHIJKLMN";

//     // Caso 1: Copia normal (no solapada)
//     ft_memmove(buf1 + 5, buf1, 5);
//     ft_memmove(buf2 + 5, buf2, 5); // libc
//     print_buffer("Custom no solap", buf1, 15);
//     print_buffer("Libc   no solap", buf2, 15);

//     // Caso 2: Copia hacia atrás (solapamiento)
//     ft_memmove(buf3, buf3 + 5, 5);
//     ft_memmove(buf4, buf4 + 5, 5); // libc
//     print_buffer("Custom solap  ", buf3, 15);
//     print_buffer("Libc   solap  ", buf4, 15);

//     return (0);
// }
