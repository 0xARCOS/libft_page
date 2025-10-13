
#include "libft.h"

char    *strjoin(const char *s1, const char *s2)
{
    char    *ptr;
    int     i;
    int     j;

    i = -1;
    j = -1;
    ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!ptr)
        return NULL;
    while (s1[++i])
        ptr[i] = s1[i];
    while (s2[++j])
        ptr[i + j] = s2[j];
    ptr[i + j] = '\0';
    return (ptr);
}
