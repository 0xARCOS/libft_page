
#include <stddef.h>
#include <stdio.h>

size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

// int main(void)
// {
//     char *s = "mamahuevo";
//     printf("%s = %ld\n", s, ft_strlen(s));
//     return 0;
// }