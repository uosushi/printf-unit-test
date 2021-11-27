PFT_TEST   = variety f
PRINTF_DIR = ..

GCC					= gcc
CFLAGS			= -Wall -Wextra -Werror

$(PFT_TEST): %: check
	@make -C $(PRINTF_DIR)
	@$(GCC) -I ./includes main.c pft/$*.c $(PRINTF_DIR)/libftprintf.a -o test 2>&1 | grep error
	@rm -rf *.o

check:

.PHONY: $(PFT_TEST)