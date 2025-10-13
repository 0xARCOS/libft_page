
#include "libft.h"

size_t ft_strlen(const char *s)
{
    size_t  i = 0;
    while (*s++)
        i++;
    return i;
}

char    *ft_strrchr(const char *s, int c)
{
    int i = ft_strlen((const char *)s);
    
    while(i >= 0)
    {
        if(s[i] == c)
            return((char *)s + i);
        i--;
    }
    return NULL;
}
int main() {
	char 	*str = "Finis Mundi";
	char	ch = 'n';
	char	*result;
	
	result = ft_strrchr(str, ch);
	
	if(result)
		printf("El carácter '%c' se encontró en la posición %ld\n", ch, result - str);
	else
		printf("No se encontró rey");
		
	return (0);
}
