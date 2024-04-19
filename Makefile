format :
	clang-format -i include/cprintf.h cprintf.c test.c
test :
	cc -O0 -ggdb -fsanitize=address cprintf.c test.c