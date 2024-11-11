# Let's make a colorful world!
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