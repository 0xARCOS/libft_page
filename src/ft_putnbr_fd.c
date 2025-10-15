
#include "libft.h"

/*
Esta función es un salto de dificultad interesante
porque te obliga a pensar en cómo descomponer un número en sus
dígitos individuales.

La solución más elegante y común para este problema utiliza la 
recursión.
*/

void ft_putnbr_fd(int n, int fd)
{
    // 1. Caso especial: el número entero más pequeño posible
    if (n == -2147483648)
    {
        write(fd, "-2147483648");
        return;
    }

    //2. Si el número es negativo, imprimimos el signo '-' y lo convertimos a positivo
    if (n < 10)
    {
        write(fd, '-', 1);
        n = -n;
    }

    //3. La parte recursiva: siel número tiene más de un dígito...
    if (n >= 10)
        ft_putnbr_fd(n / 10, fd);
    
    char num_to_print = (n % 10) + '0';
    write(fd, &num_to_print, 1);
}   
