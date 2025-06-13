# New in v2.0:
Say hello to `T()` `F()` macro with _Generic() support!      
Usage:
```C
int i = 0;
cprintf("{}\n", T(i)); // Equal to printf("%d\n", i);
cprintf("{}\n", F(i,"06")); // Equal to printf("%06d\n", i);
```
And, now we have `csprintf()`, it supports T() F() but don't support color.      
On linux, cprintf() and cfprintf() will auto disable color when output is not tty.            
# Warning:
cprintf is not more secure than printf(), and, please always use unchangable format string and make sure there's not extra {}!      
For example:
```C
printf("%s%s%s%s","xxxxx"); // Boom!
cprintf("{}{}{}{}","xxxxx"); // Also boom!!!!!!
printf("%s","xxxxx"); // Good!
cprintf("{}","xxxxxx"); // Also good :)
```
# Let's make a colorful world!
# What's this?
We often use ASCII color like `\033[0m` when developing. But it's hard to remember them.          
When writing shell, we can use `CLEAR='\033[0m'`, but for C, I have to write the implementation myself.       
So I use `{color}` for text color and `[color]` for background color, and make them map to print the color, that's this project. Simple, stupid, maybe a bit useless.
I use it to format output in my program.        
# About the binary:
You can just use cprintf as a modified version of "echo -ne" with the color format support. If the color in `{}` or `[]` is not recognized, it will just output the original string.        
# Note:
`cprintf()` and `cfprintf()` is a macro and will not return anything.       
# Cprintf in production:
[ruri](https://github.com/Moe-hacker/ruri)      
# Usage:
You can import include/cprintf.h and cprintf.c to your project, and use `cprintf()` and `cfprintf()` just like `printf()` and `fprintf()`.      
# About color format:
These color format will be recognized:      
```
clear     :reset the color.
underline :underline
highlight :highlight
red
blue
green
yellow
cyan
black
white
purple
base      :You need to define it.
R;G;B     :RGB color.
```
Use `{color}` for foreground color and `[color]` for background color.
Note that cprintf() will always clear the color in the end once you call it, but for background color, you need a `[clear]` before `\n`.      
# Example:
```C
#include "include/cprintf.h"
int main()
{
	cprintf("[91;207;250]                [clear]\n");
	cprintf("[245;170;185]                [clear]\n");
	cprintf("[255;255;255]                [clear]\n");
	cprintf("[245;170;185]                [clear]\n");
	cprintf("[91;207;250]                [clear]\n");
}
```
<p align="center">何もない僕たちに</p>
<p align="center">なぜ夢を見させたか</p>
<p align="center">終わりある人生に</p>
<p align="center">なぜ希望を持たせたか</p>
<p align="center">なぜこの手をすり抜ける</p>
<p align="center">ものばかり与えたか</p>
<p align="center">それでもなおしがみつく</p>
<p align="center">僕らは醜いかい</p>
<p align="center">それとも、きれいかい</p>