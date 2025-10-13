
#include "libft.h"

void *memchr(const void *s, int c, size_t n)
{
    size_t  i;
    const unsigned char  *ptr;
    unsigned char cc;

    cc = (unsigned char)c;
    ptr = (const unsigned char *)s;
    i = 0;
    while (i < n)
    {
        if (ptr[i] == cc)
            return ((void *)&ptr[i]);
        i++;
    }
    return (NULL);
}
