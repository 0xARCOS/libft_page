
#include "libft.h"

int ft_isalpha(int c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1;
    return 0;
}

// int main(void)
// {
//     printf("%d\n", ft_isalpha(9));
//     return 0;
// }