ifeq ($(wildcard config.mk),)
$(error config.mk is missing. Please run gen-config step before building.)
endif
include config.mk
all :
	$(CC) $(CFLAGS) -std=gnu11 cprintf.c main.c -o cprintf
	$(STRIP) cprintf
format :
	clang-format -i include/cprintf.h cprintf.c test.c main.c
test :
	$(CC) -O0 -Wall -Wno-format-extra-args -Wextra -Wno-format-security -std=gnu11 -Wno-gnu-zero-variadic-macro-arguments -Wno-gnu-statement-expression-from-macro-expansion -pedantic -ggdb -fsanitize=address cprintf.c test.c