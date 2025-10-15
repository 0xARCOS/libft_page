
#include "libft.h"

static int word_count(const char *str, char c)
{
    int     i = 0;
    int     count = 0;

    while (str[i] != '\0')
    {
        if (str[i] != c)
        {
            count++;
            while(str[i] != c && str[i] != '\0')
                i++;
        }
        else
            i++;
    }
    return (count);
}

static int word_len(const char *str, char c, int i)
{
    int j;

    j = i;
    while (str[j] != c && str[j] != '\0')
        j++;
    return (j);
}

static void *free_all(char **str, int k)
{
    while (k >= 0)
    {
        free(str[k]);
        k--;
    }
    free(str);
    return NULL;
}

char    **ft_split(char const *s, char c)
{

    char    **str;
    int     num_words = word_count(s, c);
    if (!s)
        return NULL;

    str = (char **)malloc((num_words + 1) * sizeof(char *));
    if (!str)
        return (NULL);
    
    int i = 0;
    int k = 0; // índice donde termina la palabra en "s"
    int l = 0; // índice de la palabra actual en el array "str"
    int m = 0; // índice de carácter dentro de la palabra "str[l]"
    while (s[i] != '\0')
    {
        while (s[i] == c)
            i++;
        if (s[i] != '\0')
        {
            k = word_len(s, c, i);
            int len = k - i;
            str[l] = (char *)malloc((len + 1) * sizeof(char)); // Línea A
            if (!str[l])
                return (free_all(str, l)); // Línea B
            m = 0;
            while (i < k)
                str[l][m++] = s[i++];
            str[l++][m] = '\0'; // Línea C
        }
    }
    str[l] = NULL;
    return (str);
}
