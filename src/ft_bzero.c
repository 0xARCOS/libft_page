
#include "libft.h"

void ft_bzero(void *d, size_t len)
{
    unsigned char   *str;
    size_t          i;
    
    str = d;
    i = 0;
    while (i < len)
    {
        str[i] = 0;
        i++;
    }
}

size_t ft_strlen(const char *s)
{
    size_t  i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

int main(void)
{
    char *str = "hola que tal";
    size_t  len = ft_strlen(str);
    ft_bzero((void *)str, len);
    printf("%s\n", str);
    return 0;
}