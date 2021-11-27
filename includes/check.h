#ifndef CHECK_H
# define CHECK_H

# include <stdio.h>
# include <assert.h>
# include <float.h>
# include <limits.h>
# include <stddef.h>
# include <unistd.h>

# define OK "\033[32m[OK]\033[39m\n\n"
# define KO "\033[31m[KO]\033[39m\n\n"
# define check(b) printf( b ? OK : KO )

# define title(str) printf("\033[34m ================= \n     %s \n ================= \033[39m\n", str);
# define case_title(text) printf("\033[07m %%%s \033[0m\n", text);
# define BASIC printf("=====   Basic   =====\n")
# define WIDTH printf("=====   Width   =====\n")
# define PRECI printf("===== Precision =====\n")

#endif