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
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
void __cprintf(const char *buf);
void __cfprintf(FILE *stream, const char *buf);
size_t cprintf_get_bufsize(const char *format, ...);
// The `base` color.
#define CPRINTF_BASE_COLOR "\033[1;38;2;254;228;208m"
/*
 * cprintf() is a macro,
 * first, we get the size of the string to print,
 * we use sprintf() to write it to buf[],
 * so that we only need to parse the string in buf[].
 */
#define cprintf(format, ...)                                                 \
	{                                                                    \
		char *buf = NULL;                                            \
		size_t bufsize = cprintf_get_bufsize(format, ##__VA_ARGS__); \
		buf = malloc(bufsize);                                       \
		sprintf(buf, format, ##__VA_ARGS__);                         \
		__cprintf(buf);                                              \
		free(buf);                                                   \
	}
#define cfprintf(stream, format, ...)                                        \
	{                                                                    \
		char *buf = NULL;                                            \
		size_t bufsize = cprintf_get_bufsize(format, ##__VA_ARGS__); \
		buf = malloc(bufsize);                                       \
		sprintf(buf, format, ##__VA_ARGS__);                         \
		__cfprintf(stream, buf);                                     \
		free(buf);                                                   \
	}
#define CPRINTF_MAJOR 1
#define CPRINTF_MINOR 0
