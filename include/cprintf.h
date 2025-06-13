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
void cprintf__(const char *_Nonnull buf);
void cfprintf__(FILE *_Nonnull stream, const char *_Nonnull buf);
// The `base` color.
extern char *cprintf_base_color;
// Do not print color if the stream is a FIFO.
extern bool cprintf_print_color_only_tty;
#define cprintf_get_fmt_(d, f)                              \
	_Generic((d),                                       \
		_Bool: cprintf_get_fmt_bool,                \
		char: cprintf_get_fmt_char,                 \
		signed char: cprintf_get_fmt_schar,         \
		unsigned char: cprintf_get_fmt_uchar,       \
		short: cprintf_get_fmt_short,               \
		unsigned short: cprintf_get_fmt_ushort,     \
		int: cprintf_get_fmt_int,                   \
		unsigned int: cprintf_get_fmt_uint,         \
		long: cprintf_get_fmt_long,                 \
		unsigned long: cprintf_get_fmt_ulong,       \
		long long: cprintf_get_fmt_llong,           \
		unsigned long long: cprintf_get_fmt_ullong, \
		float: cprintf_get_fmt_float,               \
		double: cprintf_get_fmt_double,             \
		long double: cprintf_get_fmt_ldouble,       \
		void *: cprintf_get_fmt_ptr,                \
		default: cprintf_get_fmt_unknown)(f)

#define cprintf_to_char(d, f)                                  \
	_Generic((d),                                          \
		_Bool: cprintf_get_string_bool,                \
		char: cprintf_get_string_char,                 \
		signed char: cprintf_get_string_schar,         \
		unsigned char: cprintf_get_string_uchar,       \
		short: cprintf_get_string_short,               \
		unsigned short: cprintf_get_string_ushort,     \
		int: cprintf_get_string_int,                   \
		unsigned int: cprintf_get_string_uint,         \
		long: cprintf_get_string_long,                 \
		unsigned long: cprintf_get_string_ulong,       \
		long long: cprintf_get_string_llong,           \
		unsigned long long: cprintf_get_string_ullong, \
		float: cprintf_get_string_float,               \
		double: cprintf_get_string_double,             \
		long double: cprintf_get_string_ldouble,       \
		void *: cprintf_get_string_ptr,                \
		default: cprintf_get_string_unknown)(f, d)

#define F(data, format) cprintf_to_char(data, cprintf_get_fmt_(data, format))
#define T(data) F(data, NULL)
#define cprintf_len(format, ...) (snprintf(NULL, 0, cprintf_regen_format(format), __VA_ARGS__) + 8)
#define csprintf(string, format, ...)                             \
	{                                                         \
		if (format == NULL) {                             \
			sprintf(string, "%s", "(null)");          \
		} else {                                          \
			char *fmt = cprintf_regen_format(format); \
			sprintf(string, fmt, __VA_ARGS__);        \
			cprintf_free_buf();                       \
		}                                                 \
	}
#define cprintf(format, ...)                                          \
	{                                                             \
		char *buf = malloc(cprintf_len(format, __VA_ARGS__)); \
		csprintf(buf, format, __VA_ARGS__);                   \
		cprintf__(buf);                                       \
		free(buf);                                            \
	}
#define cfprintf(stream, format, ...)                                 \
	{                                                             \
		char *buf = malloc(cprintf_len(format, __VA_ARGS__)); \
		csprintf(buf, format, __VA_ARGS__);                   \
		cfprintf__(stream, buf);                              \
		free(buf);                                            \
	}
//
char *cprintf_regen_format(const char *f);
void cprintf_free_buf(void);
//
char *cprintf_get_fmt_char(const char *f);
char *cprintf_get_fmt_schar(const char *f);
char *cprintf_get_fmt_uchar(const char *f);
char *cprintf_get_fmt_short(const char *f);
char *cprintf_get_fmt_ushort(const char *f);
char *cprintf_get_fmt_int(const char *f);
char *cprintf_get_fmt_uint(const char *f);
char *cprintf_get_fmt_long(const char *f);
char *cprintf_get_fmt_ulong(const char *f);
char *cprintf_get_fmt_llong(const char *f);
char *cprintf_get_fmt_ullong(const char *f);
char *cprintf_get_fmt_float(const char *f);
char *cprintf_get_fmt_double(const char *f);
char *cprintf_get_fmt_ldouble(const char *f);
char *cprintf_get_fmt_ptr(const char *f);
char *cprintf_get_fmt_unknown(const char *f);
char *cprintf_get_fmt_bool(const char *f);
//
char *cprintf_get_string_bool(char *f, bool d);
char *cprintf_get_string_char(char *f, char d);
char *cprintf_get_string_schar(char *f, signed char d);
char *cprintf_get_string_uchar(char *f, unsigned char d);
char *cprintf_get_string_short(char *f, short d);
char *cprintf_get_string_ushort(char *f, unsigned short d);
char *cprintf_get_string_int(char *f, int d);
char *cprintf_get_string_uint(char *f, unsigned int d);
char *cprintf_get_string_long(char *f, long d);
char *cprintf_get_string_ulong(char *f, unsigned long d);
char *cprintf_get_string_llong(char *f, long long d);
char *cprintf_get_string_ullong(char *f, unsigned long long d);
char *cprintf_get_string_float(char *f, float d);
char *cprintf_get_string_double(char *f, double d);
char *cprintf_get_string_ldouble(char *f, long double d);
char *cprintf_get_string_ptr(char *f, void *d);
char *cprintf_get_string_unknown(char *f, ...);
#define CPRINTF_MAJOR 2
#define CPRINTF_MINOR 0
