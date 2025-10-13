
#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    while (1)
    {
        if (*s == (char)c)
            return ((char *)s);
        if (!*s)
            return NULL;
    }
    return (NULL);
}
