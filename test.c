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
int main()
{
	cprintf("%s %s %d %s %d\n", "{black}ehi{114;5;14}bfwvjbkuiew{red}fgLCUEUIGvli{white}uEGFVLI{green}ILWR{yellow}Hvbi{blue}HVIBU{purple}WBHC{cyan}wvlrjvkjnvkjdcbvljb{clear}cjbskdjlvbjasf", "xxxxxxxxxxxxxxxxxxx[underline]xxxxxxxxx[clear]xx{cyan}xxxxx[highlight]xx{cyan}xxxx{base}xxxxxxxxxxxxx", 114514, "efbwevohaerhgkvfewugfagawhlgfigriywgjvwejhciwgihegjyvwrisavclhhahscvhvahwhjvbewvcjhkcvheqivchkvkhcbiqhbcjkqbkhbqhbhlecbqlehvhqwbvkhbkhlbvkbvljahbkhcvbklvbkbabehkavbkahbvkhavbakhebekjabhhgvcuiweryiagvhgweyhgviyacwhgvlyiwgviywgy{base}ihlwgiyywhgviywgyiwgcjtycujgcjuttugggggggukkuyu{clear}tyktfytgfyyfuktggfllyryhgwygyiwryrwyiyirliaiirwyayiwg{}iy{rryiirr{yhiho}ijoviho{11;45;14}iwhow{1919810}e{191;9;810}oweh{clear}", 514);
	cfprintf(stderr, "%s %s %d %s %d\n", "{black}ehi{114;5;14}bfwvjbkuiew{red}fgLCUEUIGvli{white}uEGFVLI{green}ILWR{yellow}Hvbi{blue}HVIBU{purple}WBHC{cyan}wvlrjvkjnvkjdcbvljb{clear}cjbskdjlvbjasf", "xxxxxxxxxxxxxxxx[underline]xxxxxxxxx[clear]xxx{cyan}xxx[highlight]xxx[base]xxxxxxxx{cyan}xxxxxxxxxxxx", 114514, "efbwevohaerhgkvfewugfagawhlgfigriywgjvwejhciwgihegjyvwrisavclhhahscvhvahwhjvbewvcjhkcvheqivchkvkhcbiqhbcjkqbkhbqhbhlecbqlehvhqwbvkhbkhlbvkbvljahbkhcvbklvbkbabehkavbkahbvkhavbakhebekjabhhgvcuiweryiagvhgweyhgviyacwhgvlyiwgviywgy{base}ihlwgiyywhgviywgyiwgcjtycujgcjuttugggggggukkuyu{clear}tyktfytgfyyfuktggfllyryhgwygyiwryrwyiyirliaiirwyayiwg{}iy{rryiirr{yhiho}ijoviho{11;45;14}iwhow{1919810}e{191;9;810}oweh{clear}", 514);
	cprintf("%s %s %d %s %d\n", "[black]ehi[114;5;14]bfwvjbkuiew[red]fgLCUEUIGvli[white]uEGFVLI[green]ILWR[yellow]Hvbi[blue]HVIBU[purple]WBHC[cyan]wvlrjvkjnvkjdcbvljb[clear]cjbskdjlvbjasf", "xxxxxxxxxxxxxxxxxxxxxxxxxxx[underline]xxxxxxx[clear]xx{cyan}xxxx[highlight]xxx[base]xxxxx{cyan}xxxxxx", 114514, "efbwevohaerhgkvfewugfagawhlgfigriywgjvwejhciwgihegjyvwrisavclhhahscvhvahwhjvbewvcjhkcvheqivchkvkhcbiqhbcjkqbkhbqhbhlecbqlehvhqwbvkhbkhlbvkbvljahbkhcvbklvbkbabehkavbkahbvkhavbakhebekjabhhgvcuiweryiagvhgweyhgviyacwhgvlyiwgviywgy[base]ihlwgiyywhgviywgyiwgcjtycujgcjuttugggggggukkuyu[clear]tyktfytgfyyfuktggfllyryhgwygyiwryrwyiyirliaiirwyayiwg[]iy[rryiirr[yhiho]ijoviho[11;45;14]iwhow[1919810]e[191;9;810]oweh[clear]", 514);
	cfprintf(stderr, "%s %s %d %s %d\n", "[black]ehi[114;5;14]bfwvjbkuiew[red]fgLCUEUIGvli[white]uEGFVLI[green]ILWR[yellow]Hvbi[blue]HVIBU[purple]WBHC[cyan]wvlrjvkjnvkjdcbvljb[clear]cjbskdjlvbjasf", "xxxxxxxxxxxxxxxxxx[underline]xxxxxxx[clear]xxx{cyan}xxx[highlight]xxxx[base]xxx{cyan}xxxxxxxxxxxxxxxx", 114514, "efbwevohaerhgkvfewugfagawhlgfigriywgjvwejhciwgihegjyvwrisavclhhahscvhvahwhjvbewvcjhkcvheqivchkvkhcbiqhbcjkqbkhbqhbhlecbqlehvhqwbvkhbkhlbvkbvljahbkhcvbklvbkbabehkavbkahbvkhavbakhebekjabhhgvcuiweryiagvhgweyhgviyacwhgvlyiwgviywgy[base]ihlwgiyywhgviywgyiwgcjtycujgcjuttugggggggukkuyu[clear]tyktfytgfyyfuktggfllyryhgwygyiwryrwyiyirliaiirwyayiwg[]iy[rryiirr[yhiho]ijoviho[11;45;14]iwhow[1919810]e[191;9;810]oweh[clear]", 514);
}
