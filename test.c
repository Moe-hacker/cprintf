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
int main(void)
{
	cprintf("%s %s %d %s %d{clear}\n\n\n",
		"{black}ehi{114;5;14}bfwvjbkuiew{red}fgLCUEUIGvli{white}uEGFVLI{green}ILWR{yellow}Hvbi{blue}HVIBU{purple}WBHC{cyan}wvlrjvkjnvkjdcbvljb{clear}cjbskdjlvbjasf",
		"xxxxxxxxxxxxxxxxxxx[underline]xxxxxxxxx[clear]xx{cyan}xxxxx[highlight]xx{cyan}xxxx{base}xxxxxxxxxxxxx",
		114514,
		"efbwevohaerhgkvfewugfagawhlgfigriywgjvwejhciwgihegjyvwrisavclhhahscvhvahwhjvbewvcjhkcvheqivchkvkhcbiqhbcjkqbkhbqhbhlecbqlehvhqwbvkhbkhlbvkbvljahbkhcvbklvbkbabehkavbkahbvkhavbakhebekjabhhgvcuiweryiagvhgweyhgviyacwhgvlyiwgviywgy{base}ihlwgiyywhgviywgyiwgcjtycujgcjuttugggggggukkuyu{clear}tyktfytgfyyfuktggfllyryhgwygyiwryrwyiyirliaiirwyayiwg{}iy{rryiirr{yhiho}ijoviho{11;45;14}iwhow{1919810}e{191;9;810}oweh{clear}",
		514);
	cfprintf(
		stderr, "%s %s %d %s %d{clear}\n\n\n",
		"{black}ehi{114;5;14}bfwvjbkuiew{red}fgLCUEUIGvli{white}uEGFVLI{green}ILWR{yellow}Hvbi{blue}HVIBU{purple}WBHC{cyan}wvlrjvkjnvkjdcbvljb{clear}cjbskdjlvbjasf",
		"xxxxxxxxxxxxxxxx[underline]xxxxxxxxx[clear]xxx{cyan}xxx[highlight]xxx[base]xxxxxxxx{cyan}xxxxxxxxxxxx",
		114514,
		"efbwevohaerhgkvfewugfagawhlgfigriywgjvwejhciwgihegjyvwrisavclhhahscvhvahwhjvbewvcjhkcvheqivchkvkhcbiqhbcjkqbkhbqhbhlecbqlehvhqwbvkhbkhlbvkbvljahbkhcvbklvbkbabehkavbkahbvkhavbakhebekjabhhgvcuiweryiagvhgweyhgviyacwhgvlyiwgviywgy{base}ihlwgiyywhgviywgyiwgcjtycujgcjuttugggggggukkuyu{clear}tyktfytgfyyfuktggfllyryhgwygyiwryrwyiyirliaiirwyayiwg{}iy{rryiirr{yhiho}ijoviho{11;45;14}iwhow{1919810}e{191;9;810}oweh{clear}",
		514);
	cprintf("%s %s %d %s %d{clear}\n",
		"[black]ehi[114;5;14]bfwvjbkuiew[red]fgLCUEUIGvli[white]uEGFVLI[green]ILWR[yellow]Hvbi[blue]HVIBU[purple]WBHC[cyan]wvlrjvkjnvkjdcbvljb[clear]cjbskdjlvbjasf",
		"xxxxxxxxxxxxxxxxxxxxxxxxxxx[underline]xxxxxxx[clear]xx{cyan}xxxx[highlight]xxx[base]xxxxx{cyan}xxxxxx",
		114514,
		"efbwevohaerhgkvfewugfagawhlgfigriywgjvwejhciwgihegjyvwrisavclhhahscvhvahwhjvbewvcjhkcvheqivchkvkhcbiqhbcjkqbkhbqhbhlecbqlehvhqwbvkhbkhlbvkbvljahbkhcvbklvbkbabehkavbkahbvkhavbakhebekjabhhgvcuiweryiagvhgweyhgviyacwhgvlyiwgviywgy[base]ihlwgiyywhgviywgyiwgcjtycujgcjuttugggggggukkuyu[clear]tyktfytgfyyfuktggfllyryhgwygyiwryrwyiyirliaiirwyayiwg[]iy[rryiirr[yhiho]ijoviho[11;45;14]iwhow[1919810]e[191;9;810]oweh[clear]",
		514);
	cfprintf(
		stderr, "%s %s %d %s %d{clear}\n\n\n",
		"[black]ehi[114;5;14]bfwvjbkuiew[red]fgLCUEUIGvli[white]uEGFVLI[green]ILWR[yellow]Hvbi[blue]HVIBU[purple]WBHC[cyan]wvlrjvkjnvkjdcbvljb[clear]cjbskdjlvbjasf",
		"xxxxxxxxxxxxxxxxxx[underline]xxxxxxx[clear]xxx{cyan}xxx[highlight]xxxx[base]xxx{cyan}xxxxxxxxxxxxxxxx",
		114514,
		"efbwevohaerhgkvfewugfagawhlgfigriywgjvwejhciwgihegjyvwrisavclhhahscvhvahwhjvbewvcjhkcvheqivchkvkhcbiqhbcjkqbkhbqhbhlecbqlehvhqwbvkhbkhlbvkbvljahbkhcvbklvbkbabehkavbkahbvkhavbakhebekjabhhgvcuiweryiagvhgweyhgviyacwhgvlyiwgviywgy[base]ihlwgiyywhgviywgyiwgcjtycujgcjuttugggggggukkuyu[clear]tyktfytgfyyfuktggfllyryhgwygyiwryrwyiyirliaiirwyayiwg[]iy[rryiirr[yhiho]ijoviho[11;45;14]iwhow[1919810]e[191;9;810]oweh[clear]",
		514);
	struct {
		int t;
	} d = {
		.t = 0,
	};
	cprintf("cprintf: %s\n", "d");
	cprintf("got: {} {} {} {}  {} {} {} {} {} {} {} {} {} {} {} {}\n", T(d), T(d), T(d), T(d), T(d), T(d),
		T(d), T(d), T(d), T(d), T(d), T(d), T(d), T(d), T(d), T(d));
	cprintf("cprintf: %s\n", "(_Bool)1");
	cprintf("got: {}\n", T((_Bool)1));
	cprintf("cprintf: %s\n", "(char)'A'");
	cprintf("got: {}\n", T((char)'A'));
	cprintf("cprintf: %s\n", "(signed char)-8");
	cprintf("got: {}\n", T((signed char)-8));
	cprintf("cprintf: %s\n", "(unsigned char)200");
	cprintf("got: {}\n", T((unsigned char)200));
	cprintf("cprintf: %s\n", "(short)-123");
	cprintf("got: {}\n", T((short)-123));
	cprintf("cprintf: %s\n", "(unsigned short)456");
	cprintf("got: {}\n", T((unsigned short)456));
	cprintf("cprintf: %s\n", "(int)114");
	cprintf("got: {}\n", T((int)114));
	cprintf("cprintf: %s\n", "(unsigned int)514");
	cprintf("got: {}\n", T((unsigned int)514));
	cprintf("cprintf: %s\n", "(long)123456L");
	cprintf("got: {}\n", T((long)123456L));
	cprintf("cprintf: %s\n", "(unsigned long)654321UL");
	cprintf("got: {}\n", T((unsigned long)654321UL));
	cprintf("cprintf: %s\n", "(long long)-123456789LL");
	cprintf("got: {}\n", T((long long)-123456789LL));
	cprintf("cprintf: %s\n", "(unsigned long long)987654321ULL");
	cprintf("got: {}\n", T((unsigned long long)987654321ULL));
	cprintf("cprintf: %s\n", "(float)3.14f");
	cprintf("got: {}\n", T((float)3.14f));
	cprintf("cprintf: %s\n", "(double)2.71828");
	cprintf("got: {}\n", T((double)2.71828));
	cprintf("cprintf: %s\n", "(long double)1.6180339887L");
	cprintf("got: {}\n", T((long double)1.6180339887L));
	cprintf("cprintf: %s\n", "(size_t)1024");
	cprintf("got: {}\n", T((size_t)1024));
	cprintf("cprintf: %s\n", "(void *)0x1234");
	cprintf("got: {}\n", T((void *)0x1234));
	cprintf(NULL, NULL);
	cprintf("\n", NULL);

	cprintf("{} {}\n", T(1), F(2, "08"));

	int i = 0;
	cprintf("{}\n", T(i));
}
