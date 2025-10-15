
#include "libft.h"

int in_set(char c, const char *set)
{
    while (*set)
    {
        if (c == *set)
            return (1);
        set++;
    }
    return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    const char        *first;
    const char        *last;
    size_t      len_s1;
    char        *trimmed_str;

    if (!s1 || !set)
        return NULL;
    len_s1 = ft_strlen(s1);
    first = s1;
    last = s1 + len_s1 - 1;
    while (first <= last && in_set(*first, set))
        first++;
    while (last >= first && in_set(*last, set))
        last--;
    
    trimmed_str = ft_substr(first, 0, last - first + 1);

    return (trimmed_str);
}

int main(void)
{
    const char  *s1 = ".-trim-me-.";
    const char  *set = ".-";
    printf("%s", ft_strtrim(s1, set));
    return 0;
}
