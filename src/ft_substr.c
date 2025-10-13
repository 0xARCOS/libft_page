
#include "libft.h"

/*
 - Descripción: Reserva memoria usando malloc y devuelve una
    subcadena de la string. La subcadena empieza en el
    índice start y tiene una longitud máxima len.
 - Valor Devuelto: La subcadena resultante, o NULL si
    la reserva de memoria falla.
*/

char    *ft_substr(const char *s, unsigned int start, size_t len)
{
    unsigned int s_len = ft_strlen(s);
    char *str = (char *)malloc((len + 1) * sizeof(char));
    int i = 0;
    
    if (start >= s_len || !*s)
        return NULL;
    if (len > s_len - start)
        len = s_len - start;
    if (!str)
        return NULL;
    while (i < len && s[start + 1])
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
