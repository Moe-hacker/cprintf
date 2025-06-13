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
#include "include/cprintf.h"
#define cprintf_strlen(f) (f == NULL ? 0 : strlen(f))
#define cprintf_avoid_null(f) (f == NULL ? "" : f)
#define cprintf_buf_len(f, d) (f != NULL ? (size_t)snprintf(NULL, 0, f, d) : 0)
static thread_local char **cprintf_buffer = NULL;
static thread_local size_t cprintf_buf_count = 0;
static void cprintf_mark_buf(char *b)
{
	cprintf_buffer = realloc(cprintf_buffer, (cprintf_buf_count + 1) * sizeof(char *));
	cprintf_buffer[cprintf_buf_count] = b;
	cprintf_buf_count++;
}
void cprintf_free_buf(void)
{
	for (size_t i = 0; i < cprintf_buf_count; i++) {
		free(cprintf_buffer[i]);
	}
	free(cprintf_buffer);
	cprintf_buffer = NULL;
	cprintf_buf_count = 0;
}
char *cprintf_regen_format(const char *f)
{
	char *ret = strdup(cprintf_avoid_null(f));
	int j = 0;
	size_t len = cprintf_strlen(f);
	if (len == 0) {
		cprintf_mark_buf(ret);
		return ret;
	}
	for (size_t i = 0; i < len - 1; i++) {
		if (f[i] == '{' && f[i + 1] == '}') {
			ret[j] = '%';
			ret[j + 1] = 's';
			j += 2;
			i++;
		} else {
			ret[j] = f[i];
			j++;
		}
	}
	ret[j] = '\0';
	if (f[len - 1] != '}') {
		ret[j] = f[len - 1];
		ret[j + 1] = '\0';
	}
	cprintf_mark_buf(ret);
	return ret;
}
char *cprintf_get_fmt_unknown(const char *f)
{
	(void)f; // Unused parameter
	return NULL;
}
char *cprintf_get_fmt_bool(const char *f)
{
	(void)f; // Unused parameter
	return NULL;
}
char *cprintf_get_fmt_char(const char *f)
{
	char *b = malloc(cprintf_strlen(f) + 16);
	sprintf(b, "%%%sc", cprintf_avoid_null(f));
	return b;
}
char *cprintf_get_fmt_schar(const char *f)
{
	char *b = malloc(cprintf_strlen(f) + 16);
	sprintf(b, "%%%sd", cprintf_avoid_null(f));
	return b;
}
char *cprintf_get_fmt_uchar(const char *f)
{
	char *b = malloc(cprintf_strlen(f) + 16);
	sprintf(b, "%%%sd", cprintf_avoid_null(f));
	return b;
}
char *cprintf_get_fmt_short(const char *f)
{
	char *b = malloc(cprintf_strlen(f) + 16);
	sprintf(b, "%%%shd", cprintf_avoid_null(f));
	return b;
}
char *cprintf_get_fmt_ushort(const char *f)
{
	char *b = malloc(cprintf_strlen(f) + 16);
	sprintf(b, "%%%shu", cprintf_avoid_null(f));
	return b;
}
char *cprintf_get_fmt_int(const char *f)
{
	char *b = malloc(cprintf_strlen(f) + 16);
	sprintf(b, "%%%sd", cprintf_avoid_null(f));
	return b;
}
char *cprintf_get_fmt_uint(const char *f)
{
	char *b = malloc(cprintf_strlen(f) + 16);
	sprintf(b, "%%%su", cprintf_avoid_null(f));
	return b;
}
char *cprintf_get_fmt_long(const char *f)
{
	char *b = malloc(cprintf_strlen(f) + 16);
	sprintf(b, "%%%sld", cprintf_avoid_null(f));
	return b;
}
char *cprintf_get_fmt_ulong(const char *f)
{
	char *b = malloc(cprintf_strlen(f) + 16);
	sprintf(b, "%%%slu", cprintf_avoid_null(f));
	return b;
}
char *cprintf_get_fmt_llong(const char *f)
{
	char *b = malloc(cprintf_strlen(f) + 16);
	sprintf(b, "%%%slld", cprintf_avoid_null(f));
	return b;
}
char *cprintf_get_fmt_ullong(const char *f)
{
	char *b = malloc(cprintf_strlen(f) + 16);
	sprintf(b, "%%%sllu", cprintf_avoid_null(f));
	return b;
}
char *cprintf_get_fmt_float(const char *f)
{
	char *b = malloc(cprintf_strlen(f) + 16);
	sprintf(b, "%%%sf", cprintf_avoid_null(f));
	return b;
}
char *cprintf_get_fmt_double(const char *f)
{
	char *b = malloc(cprintf_strlen(f) + 16);
	sprintf(b, "%%%sf", cprintf_avoid_null(f));
	return b;
}
char *cprintf_get_fmt_ldouble(const char *f)
{
	char *b = malloc(cprintf_strlen(f) + 16);
	sprintf(b, "%%%sLf", cprintf_avoid_null(f));
	return b;
}
char *cprintf_get_fmt_ptr(const char *f)
{
	char *b = malloc(cprintf_strlen(f) + 16);
	sprintf(b, "%%%sp", cprintf_avoid_null(f));
	return b;
}

char *cprintf_get_string_bool(char *f, bool d)
{
	char *buf = malloc(32);
	sprintf(buf, "%s", d ? "true" : "false");
	free(f);
	cprintf_mark_buf(buf);
	return buf;
}
char *cprintf_get_string_char(char *f, char d)
{
	char *buf = malloc(cprintf_buf_len(f, d) + 32);
	sprintf(buf, f, d);
	free(f);
	cprintf_mark_buf(buf);
	return buf;
}
char *cprintf_get_string_schar(char *f, signed char d)
{
	char *buf = malloc(cprintf_buf_len(f, d) + 32);
	sprintf(buf, f, d);
	free(f);
	cprintf_mark_buf(buf);
	return buf;
}
char *cprintf_get_string_uchar(char *f, unsigned char d)
{
	char *buf = malloc(cprintf_buf_len(f, d) + 32);
	sprintf(buf, f, d);
	free(f);
	cprintf_mark_buf(buf);
	return buf;
}
char *cprintf_get_string_short(char *f, short d)
{
	char *buf = malloc(cprintf_buf_len(f, d) + 32);
	sprintf(buf, f, d);
	free(f);
	cprintf_mark_buf(buf);
	return buf;
}
char *cprintf_get_string_ushort(char *f, unsigned short d)
{
	char *buf = malloc(cprintf_buf_len(f, d) + 32);
	sprintf(buf, f, d);
	free(f);
	cprintf_mark_buf(buf);
	return buf;
}
char *cprintf_get_string_int(char *f, int d)
{
	char *buf = malloc(cprintf_buf_len(f, d) + 32);
	sprintf(buf, f, d);
	free(f);
	cprintf_mark_buf(buf);
	return buf;
}
char *cprintf_get_string_uint(char *f, unsigned int d)
{
	char *buf = malloc(cprintf_buf_len(f, d) + 32);
	sprintf(buf, f, d);
	free(f);
	cprintf_mark_buf(buf);
	return buf;
}
char *cprintf_get_string_long(char *f, long d)
{
	char *buf = malloc(cprintf_buf_len(f, d) + 32);
	sprintf(buf, f, d);
	free(f);
	cprintf_mark_buf(buf);
	return buf;
}
char *cprintf_get_string_ulong(char *f, unsigned long d)
{
	char *buf = malloc(cprintf_buf_len(f, d) + 32);
	sprintf(buf, f, d);
	free(f);
	cprintf_mark_buf(buf);
	return buf;
}
char *cprintf_get_string_llong(char *f, long long d)
{
	char *buf = malloc(cprintf_buf_len(f, d) + 32);
	sprintf(buf, f, d);
	free(f);
	cprintf_mark_buf(buf);
	return buf;
}
char *cprintf_get_string_ullong(char *f, unsigned long long d)
{
	char *buf = malloc(cprintf_buf_len(f, d) + 32);
	sprintf(buf, f, d);
	free(f);
	cprintf_mark_buf(buf);
	return buf;
}
char *cprintf_get_string_float(char *f, float d)
{
	char *buf = malloc(cprintf_buf_len(f, d) + 32);
	sprintf(buf, f, d);
	free(f);
	cprintf_mark_buf(buf);
	return buf;
}
char *cprintf_get_string_double(char *f, double d)
{
	char *buf = malloc(cprintf_buf_len(f, d) + 32);
	sprintf(buf, f, d);
	free(f);
	cprintf_mark_buf(buf);
	return buf;
}
char *cprintf_get_string_ldouble(char *f, long double d)
{
	char *buf = malloc(cprintf_buf_len(f, d) + 32);
	sprintf(buf, f, d);
	free(f);
	cprintf_mark_buf(buf);
	return buf;
}
char *cprintf_get_string_ptr(char *f, void *d)
{
	char *buf = malloc(cprintf_buf_len(f, d) + 32);
	sprintf(buf, f, d);
	free(f);
	cprintf_mark_buf(buf);
	return buf;
}
char *cprintf_get_string_unknown(char *f, ...)
{
	char *buf = malloc(32);
	sprintf(buf, "%s", "{unknown type}");
	free(f);
	cprintf_mark_buf(buf);
	return buf;
}
char *cprintf_base_color = "254;228;208";
bool cprintf_print_color_only_tty = true;
#ifdef _GNU_SOURCE
#define fprintf_only_tty(stream, ...)                                                               \
	{                                                                                           \
		if (!cprintf_print_color_only_tty) {                                                \
			fprintf(stream, __VA_ARGS__);                                               \
		} else {                                                                            \
			struct stat _stat_buf;                                                      \
			if (fstat(fileno(stream), &_stat_buf) == 0 && S_ISCHR(_stat_buf.st_mode)) { \
				fprintf(stream, __VA_ARGS__);                                       \
			}                                                                           \
		}                                                                                   \
	}
#else
#define fprintf_if_not_fifo(stream, ...) fprintf(stream, __VA_ARGS__)
#endif
static void fprint_rgb_fg_color(FILE *_Nonnull stream, const char *_Nonnull color)
{
	/*
	 * print \033[1;38;2;R;G;Bm format color.
	 */
	char buf[17];
	for (size_t i = 1; i < strlen(color) - 1; i++) {
		buf[i - 1] = color[i];
		buf[i] = 0;
	}
	fprintf_only_tty(stream, "\033[38;2;%sm", buf);
}
static void fprint_rgb_bg_color(FILE *_Nonnull stream, const char *_Nonnull color)
{
	/*
	 * print \033[1;38;2;R;G;Bm format color.
	 */
	char buf[17];
	for (size_t i = 1; i < strlen(color) - 1; i++) {
		buf[i - 1] = color[i];
		buf[i] = 0;
	}
	fprintf_only_tty(stream, "\033[48;2;%sm", buf);
}
static bool is_rgb_color(const char *_Nonnull color)
{
	/*
	 * Check if color is an R;G;B format color.
	 */
	int sem = 0;
	// If R > 255, it's not a color.
	if (atoi(color) > 255) {
		return false;
	}
	for (size_t i = 1; i < strlen(color) - 1; i++) {
		if (color[i] == ';') {
			sem++;
			// If G or B > 255, it's not a color.
			if (atoi(&color[i + 1]) > 255) {
				return false;
			}
		}
		// If there are more than 2 `;`, the format is not correct.
		if (sem > 2) {
			return false;
		}
		// If the color include other charactor, the format is not correct.
		if (!isdigit(color[i]) && color[i] != ';') {
			return false;
		}
	}
	// If there are not 2 `;`, the format is not correct.
	if (sem != 2) {
		return false;
	}
	return true;
}
static const char *cfprintf_print_fg_color(FILE *_Nonnull stream, const char *_Nonnull buf)
{
	/*
	 * Only valid {color} will be recognized,
	 * and for other '{' without 'color}', we print a '{'.
	 * we return the pointer to the last character that is
	 * not recognized as color.
	 */
	const char *ret = buf;
	char color[17] = { '\0' };
	for (int i = 0; i < 16; i++) {
		if (buf[i] == '}') {
			color[i] = buf[i];
			color[i + 1] = 0;
			ret = &(buf[i]);
			break;
		}
		color[i] = buf[i];
		color[i + 1] = 0;
	}
	if (strcmp(color, "{clear}") == 0) {
		fprintf_only_tty(stream, "\033[0m");
	} else if (strcmp(color, "{black}") == 0) {
		fprintf_only_tty(stream, "\033[30m");
	} else if (strcmp(color, "{red}") == 0) {
		fprintf_only_tty(stream, "\033[31m");
	} else if (strcmp(color, "{green}") == 0) {
		fprintf_only_tty(stream, "\033[32m");
	} else if (strcmp(color, "{yellow}") == 0) {
		fprintf_only_tty(stream, "\033[33m");
	} else if (strcmp(color, "{blue}") == 0) {
		fprintf_only_tty(stream, "\033[34m");
	} else if (strcmp(color, "{purple}") == 0) {
		fprintf_only_tty(stream, "\033[35m");
	} else if (strcmp(color, "{cyan}") == 0) {
		fprintf_only_tty(stream, "\033[36m");
	} else if (strcmp(color, "{white}") == 0) {
		fprintf_only_tty(stream, "\033[37m");
	} else if (strcmp(color, "{base}") == 0) {
		fprintf_only_tty(stream, "\033[1;38;2;%sm", cprintf_base_color);
	} else if (strcmp(color, "{underline}") == 0) {
		fprintf_only_tty(stream, "\033[4m");
	} else if (strcmp(color, "{highlight}") == 0) {
		fprintf_only_tty(stream, "\033[1m");
	} else if (is_rgb_color(color)) {
		fprint_rgb_fg_color(stream, color);
	} else {
		ret = buf;
		fprintf(stream, "{");
	}
	return ret;
}
static const char *cfprintf_print_bg_color(FILE *_Nonnull stream, const char *_Nonnull buf)
{
	/*
	 * Only valid [color] will be recognized,
	 * and for other '[' without 'color[', we print a '['.
	 * we return the pointer to the last character that is
	 * not recognized as color.
	 */
	const char *ret = buf;
	char color[17] = { '\0' };
	for (int i = 0; i < 16; i++) {
		if (buf[i] == ']') {
			color[i] = buf[i];
			color[i + 1] = 0;
			ret = &(buf[i]);
			break;
		}
		color[i] = buf[i];
		color[i + 1] = 0;
	}
	if (strcmp(color, "[clear]") == 0) {
		fprintf_only_tty(stream, "\033[0m");
	} else if (strcmp(color, "[black]") == 0) {
		fprintf_only_tty(stream, "\033[40m");
	} else if (strcmp(color, "[red]") == 0) {
		fprintf_only_tty(stream, "\033[41m");
	} else if (strcmp(color, "[green]") == 0) {
		fprintf_only_tty(stream, "\033[42m");
	} else if (strcmp(color, "[yellow]") == 0) {
		fprintf_only_tty(stream, "\033[43m");
	} else if (strcmp(color, "[blue]") == 0) {
		fprintf_only_tty(stream, "\033[44m");
	} else if (strcmp(color, "[purple]") == 0) {
		fprintf_only_tty(stream, "\033[45m");
	} else if (strcmp(color, "[cyan]") == 0) {
		fprintf_only_tty(stream, "\033[46m");
	} else if (strcmp(color, "[white]") == 0) {
		fprintf_only_tty(stream, "\033[47m");
	} else if (strcmp(color, "[base]") == 0) {
		fprintf_only_tty(stream, "\033[1;48;2;%sm", cprintf_base_color);
	} else if (strcmp(color, "[underline]") == 0) {
		fprintf_only_tty(stream, "\033[4m");
	} else if (strcmp(color, "[highlight]") == 0) {
		fprintf_only_tty(stream, "\033[1m");
	} else if (is_rgb_color(color)) {
		fprint_rgb_bg_color(stream, color);
	} else {
		ret = buf;
		fprintf(stream, "[");
	}
	return ret;
}
void cprintf__(const char *_Nonnull buf)
{
	const char *p = NULL;
	p = buf;
	for (size_t i = 0; i < strlen(buf); i++) {
		// Search for '{'.
		if (*p == '{') {
			// *p will be moved because we need to skip the {color} string.
			p = cfprintf_print_fg_color(stdout, p);
		} else if (*p == '[') {
			// *p will be moved because we need to skip the [color] string.
			p = cfprintf_print_bg_color(stdout, p);
		} else {
			printf("%c", *p);
		}
		// Recompute the value of i.
		i = (size_t)(p - buf);
		// Goto the next charactor.
		p = &(p[1]);
	}
	// We will always reset the color in the end.
	fprintf_only_tty(stdout, "\033[0m");
	fflush(stdout);
}
void cfprintf__(FILE *_Nonnull stream, const char *_Nonnull buf)
{
	const char *p = NULL;
	p = buf;
	for (size_t i = 0; i < strlen(buf); i++) {
		// Search for '{' or '['.
		if (*p == '{') {
			// *p will be moved because we need to skip the {color} string.
			p = cfprintf_print_fg_color(stream, p);
		} else if (*p == '[') {
			// *p will be moved because we need to skip the {color} string.
			p = cfprintf_print_bg_color(stream, p);
		} else {
			fprintf(stream, "%c", *p);
		}
		// Recompute the value of i.
		i = (size_t)(p - buf);
		// Goto the next charactor.
		p = &(p[1]);
	}
	// We will always reset the color in the end.
	fprintf_only_tty(stream, "\033[0m");
	fflush(stream);
}
