
#include "libft.h"

size_t ft_strlen(const char *str)
{
    size_t i = 0;
    while (*str++)
        i++;
    return i;
}

size_t strlcat(char *dst, const char *src, size_t size)
{
    size_t  i = 0;
    size_t  j;
    size_t  l = 0;

    while (dst[l] != '\0' && l < size)
        l++;

    j = l;
    while (src[i] != '\0')
        i++;
    if (size == 0 || l >= size)
        return (l + i);
    while (j < (size - 1) && src[j - l] != '\0')
    {
        dst[j] = src[j - l];
        j++;
    }
    dst[j] = '\0';
    return (j + l);
}
