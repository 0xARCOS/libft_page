
#include <stdio.h>

int ft_isprint(int c)
{
    if ( c >= 32 && c <= 126)
        return 1;
    return 0;
}

int main(void)
{
    char *str = "hola \nque tal";
    int i = 0;
    while (str[i])
    {
        if (ft_isprint(str[i]))
            printf("'%c' %d es imprimible\n", str[i], str[i]);
        else
            printf("'%c' (%d) NO es imprimible\n", str[i], (unsigned char)str[i]);
        i++;
    }
    return 0;
}