// SPDX-License-Identifier: MIT
/*
 *
 * This file is part of cprintf, with ABSOLUTELY NO WARRANTY.
 *
 * MIT License
 *
 * Copyright (c) 2025 Moe-hacker
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
#include "include/cprintf.h"
static char *cprintf_parse__(const char *_Nonnull buf)
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
static void do_cprintf__(const char *_Nonnull buf)
{
	char *__buf = cprintf_parse__(buf);
	cprintf("%s", __buf);
	free(__buf);
}
int main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++) {
		do_cprintf__(argv[i]);
		if (i < argc - 1) {
			printf(" ");
		}
	}
}