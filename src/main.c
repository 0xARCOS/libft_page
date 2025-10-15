// main.c — test harness para ft_split con casos límite y reporte claro
// Compila con: 
//   cc -Wall -Wextra -Werror -fsanitize=address -g main.c ft_split.c -o split_tester
// Ejecuta: 
//   ./split_tester
// Nota: usa fork() para aislar tests que hacen SEGFAULT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

// Prototipo de tu función (incluye tu libft.h si lo prefieres):
char **ft_split(char const *s, char c);

// Utilidad: libera el array devuelto por ft_split
static void free_split(char **v) {
    if (!v) return;
    for (int i = 0; v[i]; i++) free(v[i]);
    free(v);
}

// Cuenta elementos en array NULL-terminado
static int arrlen(char **v) {
    if (!v) return -1;
    int n = 0; 
    while (v[n]) n++;
    return n;
}

// Compara resultado con esperado; si expected == NULL, sólo imprime resultado
static int compare_tokens(char **res, const char **expected, int expected_n) {
    int ok = 1;
    int n = arrlen(res);
    if (expected) {
        if (n != expected_n) {
            ok = 0;
        } else {
            for (int i = 0; i < expected_n; i++) {
                if (!res[i] || strcmp(res[i], expected[i]) != 0) {
                    ok = 0;
                    break;
                }
            }
        }
    }
    // Reporte
    printf("  -> tokens (%d):\n", n);
    for (int i = 0; i < n; i++) {
        // mostrar también longitudes
        printf("     [%d] \"%s\" (len=%zu)\n", i, res[i], strlen(res[i]));
    }
    if (expected) {
        printf("  -> esperado (%d):\n", expected_n);
        for (int i = 0; i < expected_n; i++) {
            printf("     [%d] \"%s\"\n", i, expected[i]);
        }
        printf("  => %s\n", ok ? "OK" : "MISMATCH ❌");
    }
    return ok ? 0 : 1;
}

// Estructura de test
typedef struct s_test {
    const char *name;
    const char *input;      // puede ser NULL
    char delim;
    const char **expected;  // NULL si no comparamos
    int expected_n;         // -1 si no comparamos
} t_test;

// Helpers para expected arrays
#define EXP_ARR(...) (const char*[]){__VA_ARGS__}
#define NO_EXPECT    NULL, -1

// Define casos límite y representativos
static t_test TESTS[] = {
    { "NULL input", NULL, ',', NO_EXPECT },                              // debería no crashear; tu código ahora crashea
    { "Empty string", "", ',', EXP_ARR(), 0 },
    { "Only delimiter", ",,,,,", ',', EXP_ARR(), 0 },
    { "No delimiter present", "abcdef", ',', EXP_ARR("abcdef"), 1 },
    { "Single char", "a", ',', EXP_ARR("a"), 1 },
    { "Delimiter at start", ",start", ',', EXP_ARR("start"), 1 },
    { "Delimiter at end", "end,", ',', EXP_ARR("end"), 1 },
    { "Consecutive delimiters", "a,,b,,,c", ',', EXP_ARR("a","b","c"), 3 },
    { "All spaces", "     ", ' ', EXP_ARR(), 0 },
    { "Leading/trailing spaces", "  hi  there  ", ' ', EXP_ARR("hi","there"), 2 },
    { "Multiple spaces mid", "hi   there   you", ' ', EXP_ARR("hi","there","you"), 3 },
    { "Tabs mixed with spaces (delim=' ')", "a\t b \t c", ' ', EXP_ARR("a\t","b","\t","c"), 4 },
    { "Tab delimiter", "a\tb\t\tc", '\t', EXP_ARR("a","b","c"), 3 },
    { "Newline delimiter", "line1\nline2\n\nline4", '\n', EXP_ARR("line1","line2","line4"), 3 },
    { "NULL char delimiter -> whole string", "abc,def", '\0', EXP_ARR("abc,def"), 1 },
    { "NULL char delimiter with empty", "", '\0', EXP_ARR(), 0 },
    { "Non-alnum delimiter", "x--y--z", '-', EXP_ARR("x","","y","","z"), 5 }, // ojo: ¿quieres ignorar vacíos? tu split los IGNORA → este test muestra diseño
    { "Path-like", "/usr//local/bin/", '/', EXP_ARR("usr","local","bin"), 3 },
    { "Emoji / UTF-8 bytes (delim=' ')", "hola ☕ mundo", ' ', EXP_ARR("hola","☕","mundo"), 3 },
    { "Long run of delimiters", "a,,,,,,,,,,b", ',', EXP_ARR("a","b"), 2 },
};

static void print_header(const t_test *t) {
    printf("=== TEST: %s ===\n", t->name);
    if (t->input) {
        // imprime el input mostrando escapes visibles
        printf("input: \"%s\"\n", t->input);
    } else {
        printf("input: (NULL)\n");
    }
    if (t->delim == '\0') printf("delim: '\\0'\n");
    else if (t->delim == '\n') printf("delim: '\\n'\n");
    else if (t->delim == '\t') printf("delim: '\\t'\n");
    else printf("delim: '%c'\n", t->delim);
}

// Ejecuta un test en un proceso hijo para capturar señales
static int run_one_isolated(const t_test *t) {
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 2; }
    if (pid == 0) {
        // Proceso hijo: corre el test
        print_header(t);
        char **res = ft_split(t->input, t->delim);
        int rc = compare_tokens(res, t->expected, t->expected_n);
        free_split(res);
        exit(rc);
    } else {
        // Proceso padre: espera y analiza estado
        int status = 0;
        waitpid(pid, &status, 0);
        if (WIFSIGNALED(status)) {
            int sig = WTERMSIG(status);
            const char *sn =
                (sig == SIGSEGV) ? "SIGSEGV" :
                (sig == SIGABRT) ? "SIGABRT" :
                (sig == SIGBUS)  ? "SIGBUS"  :
                (sig == SIGFPE)  ? "SIGFPE"  :
                (sig == SIGILL)  ? "SIGILL"  : "SIGNAL";
            printf("  !! Proceso del test terminó por señal: %s (%d)\n", sn, sig);
            return 100 + sig; // marca como fallo por señal
        } else if (WIFEXITED(status)) {
            int code = WEXITSTATUS(status);
            if (code == 0) printf("  => OK ✅\n");
            else printf("  => FALLÓ (code=%d) ❌\n", code);
            return code;
        } else {
            printf("  !! Terminación anómala\n");
            return 3;
        }
    }
}

int main(void) {
    int ntests = (int)(sizeof(TESTS)/sizeof(TESTS[0]));
    int fails = 0, signals = 0;

    printf("== ft_split test harness ==\n");
    for (int i = 0; i < ntests; i++) {
        int rc = run_one_isolated(&TESTS[i]);
        if (rc != 0) {
            fails++;
            if (rc >= 100) signals++;
        }
        printf("\n");
    }
    printf("Resumen: %d tests, %d fallos (%d por señal)\n", ntests, fails, signals);
    printf("NOTA: Si 'NULL input' da SIGSEGV, corrige tu ft_split para chequear 's' antes de usarlo.\n");
    return (fails != 0);
}
