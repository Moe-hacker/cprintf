ifeq ($(wildcard config.mk),)
$(error config.mk is missing. Please run gen-config step before building.)
endif
include config.mk
all :
	$(CC) $(CFLAGS) -std=c11 cprintf.c main.c -o cprintf
	$(STRIP) cprintf
format :
	clang-format -i include/cprintf.h cprintf.c test.c main.c
test :
	$(CC) -O0 -Wall -Wextra -Wgnu -std=c11 -pedantic -ggdb -fsanitize=address cprintf.c test.c