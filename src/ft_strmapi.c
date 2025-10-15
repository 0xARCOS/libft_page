
#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    int     s_len = ft_strlen(s);
    char    *str = (char *)malloc((s_len + 1) * sizeof(char));
    if (!str)
        return NULL;

    int i = 0;
    while (i < s_len)
    {
        str[i] = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}