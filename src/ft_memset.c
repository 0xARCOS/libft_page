
#include "libft.h"

size_t ft_strlen(const char *s);

void *memset(void *s, int c, size_t n)
{
    unsigned char *str;
    unsigned char ptr;
    size_t i;
    
    str = s;
    ptr = c;
    i = 0;
    while (str[i] && i < n)
    {
        str[i] = ptr;
        i++;
    }
    return s;
}

int main()
{
    char arr[10] = {1, 2, 3, 4, 5, 6, 7};
    int		i = 0;
    size_t	j = ft_strlen(arr);
    memset(arr, 'A', j);
    while (i < j)
    {
	    printf("%c", arr[i]);
	    i++;
    }
    printf("\n");
    return 0;
}