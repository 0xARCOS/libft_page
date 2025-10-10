
#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    if (n == 0)
        return (dest);
    
    char *ptr;
    const char *str;

    ptr = dest;
    str = src;
    while (n--)
    {
        *ptr++ = *str++;
    }

    return dest;
}

int main(void)
{
    char *src = "hola mundo";
    char dst[20];

    ft_memcpy(dst, src, 5);

    printf("Alojado en destino hay: '%s' correspondientes a %d", dst, 5);

    return 0;
}