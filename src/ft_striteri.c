
#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int    i;
    unsigned int    len;

    len = ft_strlen(s);
    i = 0;
    while (i < len)
    {
        f(i, &s[i]);
        i++;
    }
    
}
