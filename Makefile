ifeq ($(wildcard config.mk),)
$(error config.mk is missing. Please run gen-config step before building.)
endif
include config.mk
all :
	$(CC) $(CFLAGS) cprintf.c main.c -o cprintf
	$(STRIP) cprintf
format :
	clang-format -i include/cprintf.h cprintf.c test.c main.c
test :
	$(CC) -O0 -ggdb -fsanitize=address cprintf.c test.c