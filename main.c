#include "include/cprintf.h"
static char *__cprintf_parse(const char *_Nonnull buf)
{
	char *ret = malloc(strlen(buf) + 114);
	ret[0] = '\0';
	for (size_t i = 0; i < strlen(buf); i++) {
		if (buf[i] == '\\' && i < strlen(buf) - 1) {
			if (buf[i + 1] == 'n') {
				strncat(ret, "\n", 2);
				i++;
			} else if (buf[i + 1] == 't') {
				strncat(ret, "\t", 2);
				i++;
			} else if (buf[i + 1] == 'r') {
				strncat(ret, "\r", 2);
				i++;
			} else if (buf[i + 1] == '0') {
				if (i < strlen(buf) - 3 && buf[i + 2] == '3' && buf[i + 3] == '3') {
					strncat(ret, "\033", 2);
					i += 3;
				} else {
					strncat(ret, "\0", 2);
					i++;
				}
			} else if (buf[i + 1] == 'a') {
				strncat(ret, "\a", 2);
				i++;
			} else if (buf[i + 1] == 'b') {
				strncat(ret, "\b", 2);
				i++;
			} else if (buf[i + 1] == 'f') {
				strncat(ret, "\f", 2);
				i++;
			} else if (buf[i + 1] == 'e') {
				strncat(ret, "\e", 2);
				i++;
			} else {
				strncat(ret, &buf[i], 1);
                strncat(ret, "\0", 1);
			}
		} else {
			strncat(ret, &buf[i], 1);
            strncat(ret, "\0", 1);
		}
	}
	return ret;
}
static void __cprintf__(const char *_Nonnull buf)
{
	char *__buf = __cprintf_parse(buf);
	cprintf("%s", __buf);
    free(__buf);
}
int main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++) {
		__cprintf__(argv[i]);
		if (i < argc - 1) {
			printf(" ");
		}
	}
}