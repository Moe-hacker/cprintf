// SPDX-License-Identifier: MIT
/*
 *
 * This file is part of cprintf, with ABSOLUTELY NO WARRANTY.
 *
 * MIT License
 *
 * Copyright (c) 2024 Moe-hacker
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *
 */
#include "cprintf.h"
const char *cprintf_print_color(const char *buf)
{
	const char *ret = buf;
	char color[17] = { '\0' };
	for (int i = 0; i < 16; i++) {
		if (buf[i] == '}') {
			color[i] = buf[i];
			color[i + 1] = 0;
			ret = &buf[i];
			break;
		} else {
			color[i] = buf[i];
			color[i + 1] = 0;
		}
	}
	if (strcmp(color, "{clear}") == 0) {
		printf("\033[0m");
	} else if (strcmp(color, "{black}") == 0) {
		printf("\033[30m");
	} else if (strcmp(color, "{red}") == 0) {
		printf("\033[31m");
	} else if (strcmp(color, "{green}") == 0) {
		printf("\033[32m");
	} else if (strcmp(color, "{yellow}") == 0) {
		printf("\033[33m");
	} else if (strcmp(color, "{blue}") == 0) {
		printf("\033[34m");
	} else if (strcmp(color, "{purple}") == 0) {
		printf("\033[35m");
	} else if (strcmp(color, "{cyan}") == 0) {
		printf("\033[36m");
	} else if (strcmp(color, "{white}") == 0) {
		printf("\033[37m");
	} else {
  ret = buf;
  printf("{");
        }
	return ret;
}
void __cprintf(const char *buf)
{
	const char *p;
	p = buf;
	for (size_t i = 0; i < strlen(buf); i++) {
		if (*p == '{') {
			p = cprintf_print_color(p);
		} else {
			printf("%c", *p);
		}
		i = p - buf;
		p = &p[1];
	}
}
size_t cprintf_get_bufsize(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	size_t ret = 0;
	char *buf = NULL;
	ret += strlen(format);
	for (size_t i = 0; i < strlen(format); i++) {
		if (format[i] == '%') {
			i++;
			buf = va_arg(ap, char *);
			switch (format[i]) {
			case 's': {
				ret += strlen(buf);
			}
			default: {
				ret += 114;
			}
			}
		}
	}
	return ret + 1919;
}