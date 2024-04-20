# Note:
`cprintf()` and `cfprintf()` is a macro and will not return anything.       
# Usage:
You can import include/cprintf.h and cprintf.c to your project, and use `cprintf()` and `cfprintf()` just like `printf()` and `fprintf()`.      
# About color format:
These color format will be recognized:      
```
{clear}   :reset the color.
{red}
{blue}
{green}
{yellow}
{cyan}
{black}
{white}
{purple}
{base}    :You need to define it.
{R;G;B}   :RGB color.
```
Note that cprintf() will always clear the color in the end once you call it.