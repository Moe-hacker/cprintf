format :
	clang-format -i cprintf.h cprintf.c
test :
	cc -O0 -ggdb -fsanitize=address cprintf.c test.c