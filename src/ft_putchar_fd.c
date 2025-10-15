
#include "libft.h"

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

/*
CONCEPTOS FUNDAMENTALES

Para escribir esta función, solo necesitamos entender dos
cosas:

 1. Que es un File Descriptor(int fd)
 2. Cómo funciona la llamada al sistema write.

 1. File Descriptor (Descriptor de Archivos)
 Piensa en un file descriptor como un número de identifi-
 cación que el sistema operativo le asigna a cualquier
 canal de entrada o salida que tu programa pueda usar.
 No es solo para "archivos" en el disco.

 Por defecto, todo programa en un entorno tipo UNIX tiene 
 tres descriptores estándar abiertos:
 -> 0 : Entrada estándar (stdin): Generalmente es el teclado.
  Es de donde el programa "lee".
 -> 1 : Salida estándar (stdout): Generalmente es la pantalla
  (la terminal). Es donde el programa "escribe" su salida normal.
 -> 2 : Salida de error estándar (stderr) : También suele
  ser la pantalla. Es donde envían los mensajes de error.

 Nuestro parámetro int fd recibirá uno de estos números 
   (o el número de un archivo que hayas abierto explícitamente).
   Tu función debe ser capaz de escribir en cualquiera de ellos.

2. La función write
    Esta es la única función que tenemos permitida y es la
    clave de todo. Write es una "llamada al sistema" (system call),
    lo que significa que es la forma en en que el programa
    pide directamente al sistema operativo (como Linux) que
    realice una operación a bajo nivel.

 Su prototipo es: ssize_t write(int fd, const void *buf, size_t count);

 Vamos a analizar sus parámetros:

 -> int fd: El destino. Aquí le pasas el file descriptor
  al que quieres escribir. Coincide exactamente con el fd
  que recibe la función.
 -> const void *buf: Los datos a escribir. Este es el punto
  más importante. Write no acepta un carácter directamente (char).
  Pide un puntero (*buf), que es la dirección de memoria 
  donde están los datos que se van a escribir. Como tú tienes un
  solo carácter (char c), necesitas pasarle su dirección de memoria.
  Esto se hace con el operador &, así &c.
 -> size_t count: La cantidad de byte a escribir. Como un char
 ocupa exactamente 1 byte, este valor siempre será 1 en tu función.
 



*/