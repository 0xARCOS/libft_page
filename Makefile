# ===========================================================
# =                    VARIABLES SECTION                    =
# ===========================================================
NAME = libft.a # ← Archivo de biblioteca estática			#1
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
AR = ar # ← comando ar, viene de "archiver"					#2
ARFLAGS = rcs # ← reglas, cada letra conlleva una acción.	#3
RM = rm -fr	


# ===========================================================
# =                    SOURCES SECTION                      =
# ===========================================================
SRCS =	ft_isalpha.c /
		ft_isdigit.c /
		ft_isalnum.c /
		ft_isascii.c /
		ft_isprint.c /
		ft_strlen.c /
		ft_memset.c /
		ft_bzero.c /
		



BSRC = ... .c

OBJS = $(SRCS:.c=.o) # ← nos ahorramos el comodín			#4
BOBJS = $(BSRC:.c=.o)

# ===========================================================
# =                    RULES SECTION                        =
# ===========================================================
all: $(NAME)

$(NAME) = $(OBJS)
	@echo "\033[32mCompilando cabeza...\033[0m"
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "\033[32mCabeza compilada: LIBRARY CREATED...\033[0m"

bonus: $(BOBJS)
	@echo "\033[32mCompilando cabeza...\033[0m"
	@$(AR) $(ARFLAGS) $(NAME) $(BOBJS)
	@echo "\033[32mCabeza compilada: BONUS LIBRARY CREATED...\033[0m"

%.o: %.c
	@echo "\033[32mRepilando y Recopilando...\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[32mLimpiando cabeza...\033[0m"
	$(RM) $(OBJS) $(BOBJS)

fclean:
	@echo "\033[32mAcabando con todas las cabezas...\033[0m"
	$(RM) (NAME)

re: fclean all

.PHONY: all clean fclean re bonus

# 1. Un archivo .a es una colección de archivos objetos (.o) empaquetados
# 	en una sola librería que después puede ser lanzada por otros programas.

# 2. La principal función de este comando es agrupar múltiples archivos en
# 	un único archivo, conocido como archivo de biblioteca estática (libft.a).

# 3. Significado de las opciones.
# 	- r : "replace". Si el archivo de la biblioteca ya existe, sustituye los
# 		archivos objeto que se indiquen, o los agrega si no están presentes.
# 	- c : "create" . Crea el archivo de la biblioteca si no existe, sin 
# 		mostrar un mensaje de advertencia.
# 	- s : "index"  . Crea un índice de simbolos en la bilioteca, lo que es esencial
# 		para que el enlazador pueda encontrar rápidamente las funciones durante el
# 		linkeo del programa.

# -------------------------------------------------------------------------------------
# vamos a entender el proceso de compilación en C paso a paso:

# 	1. Procesamiento:
# 		El procesador transforma el código fuente eliminando comentarios, expandiendo
# 		macros y añadiendo las cabezeras (archivos.h). El resultado sigue siendo código 
# 		en lenguaje C, pero preparado para la compilación.
# 	2. Compilación:
# 		El compilador traduce el código C prepocesado a código ensamblador, que es un 
# 		lenguaje simbólico más cercano a la máquina.
# 	3. Ensamblado:
# 		El ensamblador convierte el código ensamblador en código máquina binario, 
# 		pero en formato objeto (.o). Este código máquina aún no es ejecutable directamente, 
# 		porque puede contener referencias externas o en otros archivos.
# 	4. Enlazado:
# 		El enlazador combina uno o más archivos objeto .o, resolviendo referencias externas 
# 		(como llamadas a funciones que están en otros archivos) y a bibliotecas, para 
# 		producir un archivo ejecutable que la máquina puede cargar.
# --------------------------------------------------------------------------------------

# 4. En esta línea estamos diciendo que para llegar a ese objetivo voy a necesitar otro objetivo
# 	que será SRCS que contiene todos los puntos c y además le voy a decir que genere de cada .c 
# 	su .o.

	