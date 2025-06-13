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
#pragma once
#ifdef __linux__
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <sys/stat.h>
#include <threads.h>
#ifndef _Nullable
#define _Nullable
#endif
#ifndef _Nonnull
#define _Nonnull
#endif
#if __STDC_VERSION__ < 202000L
#define bool _Bool
#define true ((_Bool) + 1u)
#define false ((_Bool) + 0u)
#endif
#define CPRINTF_MAJOR 2
#define CPRINTF_MINOR 0
int cprintf__(const char *_Nonnull buf);
int cfprintf__(FILE *_Nonnull stream, const char *_Nonnull buf);
// The `base` color.
extern char *cprintf_base_color;
// Do not print color if the stream is a FIFO.
extern bool cprintf_print_color_only_tty;

// Generic support.
#define cprintf_strlen(f) (f == NULL ? 0 : strlen(f))
#define cprintf_avoid_null(f) (f == NULL ? "" : f)
#define cprintf_buf_len(f, d) (f != NULL ? (size_t)snprintf(NULL, 0, f, d) : 0)
#define cprintf_get_fmt_(d, f)                            \
	({                                                \
		char *b = malloc(cprintf_strlen(f) + 16); \
		sprintf(b,                                \
			_Generic((d),                     \
			_Bool: (d ? "true" : "false"),    \
			char: "%%%sc",                    \
			signed char: "%%%sd",             \
			unsigned char: "%%%sd",           \
			short: "%%%shd",                  \
			unsigned short: "%%%shu",         \
			int: "%%%sd",                     \
			unsigned int: "%%%su",            \
			long: "%%%sld",                   \
			unsigned long: "%%%slu",          \
			long long: "%%%slld",             \
			unsigned long long: "%%%sllu",    \
			float: "%%%sf",                   \
			double: "%%%sf",                  \
			long double: "%%%sLf",            \
			void *: "%%%sp",                  \
			default: "{unknown}"),            \
			cprintf_avoid_null(f));           \
		cprintf_mark_buf(b);                      \
		b;                                        \
	})

#define cprintf_to_char(d, f)                                   \
	({                                                      \
		char *buf = malloc(cprintf_buf_len(f, d) + 32); \
		sprintf(buf, f, d);                             \
		cprintf_mark_buf(buf);                          \
		buf;                                            \
	})

#define F(data, format) cprintf_to_char(data, cprintf_get_fmt_(data, format))
#define T(data) F(data, NULL)
#define cprintf_len(format, ...) (snprintf(NULL, 0, cprintf_regen_format(format), ##__VA_ARGS__) + 8)
#define csprintf(string, format, ...)                              \
	({                                                         \
		int ret = 0;                                       \
		if (format == NULL) {                              \
			ret = sprintf(string, "%s", "(null)");     \
		} else {                                           \
			char *fmt = cprintf_regen_format(format);  \
			ret = sprintf(string, fmt, ##__VA_ARGS__); \
			cprintf_free_buf();                        \
		}                                                  \
		ret;                                               \
	})
#define cprintf(format, ...)                                            \
	({                                                              \
		int ret = 0;                                            \
		char *buf = malloc(cprintf_len(format, ##__VA_ARGS__)); \
		csprintf(buf, format, ##__VA_ARGS__);                   \
		ret = cprintf__(buf);                                   \
		free(buf);                                              \
		ret;                                                    \
	})
#define cfprintf(stream, format, ...)                                   \
	({                                                              \
		int ret = 0;                                            \
		char *buf = malloc(cprintf_len(format, ##__VA_ARGS__)); \
		csprintf(buf, format, ##__VA_ARGS__);                   \
		ret = cfprintf__(stream, buf);                          \
		free(buf);                                              \
		ret;                                                    \
	})
// For generic support.
char *cprintf_regen_format(const char *f);
void cprintf_free_buf(void);
void cprintf_mark_buf(char *b);
