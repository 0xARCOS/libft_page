
#include "libft.h"

int	ft_isascii(int c)
{
    return (c >= 0 && c <= 127);
}

// int main(void)
// {
//     printf("Test con 'A': %d\n", ft_isascii('A'));   // esperado: 1
//     printf("Test con '9': %d\n", ft_isascii('9'));   // esperado: 1
//     printf("Test con 'ñ': %d\n", ft_isascii('ñ'));   // esperado: 0
//     printf("Test con 127: %d\n", ft_isascii(127));   // esperado: 1
//     printf("Test con 128: %d\n", ft_isascii(128));   // esperado: 0
//     printf("Test con -5: %d\n", ft_isascii(-5));     // esperado: 0
//     return 0;
// }