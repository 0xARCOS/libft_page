# ===========================================================
# =                    VARIABLES SECTION                    =
# ===========================================================
NAME    = libft.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g
AR      = ar
ARFLAGS = rcs
RM      = rm -f

# ===========================================================
# =                    SOURCES SECTION                      =
# ===========================================================
SRCS =  ft_isalpha.c \
        ft_isdigit.c \
        ft_isalnum.c \
        ft_isascii.c \
        ft_isprint.c \
        ft_strlen.c \
        ft_memset.c \
        ft_bzero.c \
        ft_memcpy.c \
        ft_memmove.c \
        ft_strlcpy.c \
        ft_strlcat.c \
        ft_toupper.c \
        ft_tolower.c \
        ft_strchr.c \
        ft_strncmp.c \
        ft_memchr.c \
        ft_memcmp.c \
        ft_strnstr.c \
        ft_atoi.c \
        ft_calloc.c \
        ft_strjoin.c \
        ft_strtrim.c \
        ft_substr.c \
        ft_split.c
        #ft_strdup.c \

# Si tienes bonus, ponlos aquí (o déjalo vacío)
BONUS_SRCS =
# BONUS_SRCS = ...

OBJS      = $(SRCS:.c=.o)
BONUS_OBJS= $(BONUS_SRCS:.c=.o)

# ===========================================================
# =                    RULES SECTION                        =
# ===========================================================
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[32mCompilando librería...\033[0m"
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "\033[32mOK: $(NAME) creada\033[0m"

bonus: $(OBJS) $(BONUS_OBJS)
	@echo "\033[32mCompilando librería (bonus)...\033[0m"
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "\033[32mOK: $(NAME) con bonus\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[33mLimpiando objetos...\033[0m"
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@echo "\033[31mEliminando librería...\033[0m"
	@$(RM) $(NAME)

re: fclean all

# === Targets de prueba opcionales (para tu main.c del split) ===
TEST = split_tester
TEST_SRCS = main.c
test: $(TEST)
	@./$(TEST)

$(TEST): $(NAME) $(TEST_SRCS)
	@$(CC) $(CFLAGS) $(TEST_SRCS) -L. -lft -fsanitize=address -o $(TEST)
	@echo "\033[32mOK: $(TEST) listo\033[0m"

.PHONY: all clean fclean re bonus test


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

	