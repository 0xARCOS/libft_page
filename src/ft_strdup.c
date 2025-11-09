
#include "libft.h"

char	*ft_strdup(const char *s)
{
    char *str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
    if (!str)
        return NULL;
    int i = 0;
    while (i < ft_strlen(s) && str[i] && s[i])
        str[i++] = s[i++];
    str[i] = '\0';
    return (str);
}

// Optimizado 
/*
char *ft_strdup(const char *s)
{
    char *str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
    if (!str)
        return NULL;
    int i = 0;
    while ((str[i] = s[i]) != '\0')
        i++;
    return (str);
}
*/
