# NAME:
```
cprintf(format, ...)
cfprintf(stream, format, ...)
csprintf(string, format, ...)
scprintf(format, ...)
scfprintf(stream, format, ...)
```
# DESCRIPTION:
cprintf is a enhanced version of printf() family of functions. It provides the following additional features:
## a) color formatting with {color} and [color] syntax
cprintf supports inline ANSI color formatting by parsing color tags:      
- {color} sets the foreground color
- [color] sets the background color

Supported colors are:      
```
clear :reset all colors
underline :underline text
highlight :highlight text
red, blue, green, yellow, cyan, black, white, purple
base :user-defined color
R;G;B :RGB color (e.g., 255;0;0 for red)
```
### Example:
```c
cprintf("This is {red}red{clear} and this is [blue]blue[clear].\n");
```
### Note:
This feature is not supported in csprintf().      
## b) generic type formatting
cprintf supports generic type formatting:      
- T(var) Automatically detects the type of `var` and formats it.
- F(var, "format") Formats `var` using the specified format string.

### Example:
```c
int x = 42;
cprintf("Value: {}", T(x)); // Automatically detects type and format x
cprintf("Value: {}", F(x, "08")); // Formats using specified format %08d
```
### Note:
This feature is not supported in scprintf() and scfprintf().      
The generic formatting feature converts every `{}` to `%s`, which disables compile-time format string checking and may lead to undefined behavior if not used carefully.      
# Behavior:
Color output is automatically disabled if the output is not a character device (e.g., redirected to a file).      
This behavior can be overridden by setting the global flag:      
```c
cprintf_print_color_only_tty = false;
```
The output color can be customized by setting the global variable:      
```c
struct CPRINTF_COLOR__ cprintf_color = {
	.base = "254;228;208",
	.black_fg = "\033[30m",
	.red_fg = "\033[31m",
	.green_fg = "\033[32m",
	.yellow_fg = "\033[33m",
	.blue_fg = "\033[34m",
	.purple_fg = "\033[35m",
	.cyan_fg = "\033[36m",
	.white_fg = "\033[37m",
	.black_bg = "\033[40m",
	.red_bg = "\033[41m",
	.green_bg = "\033[42m",
	.yellow_bg = "\033[43m",
	.blue_bg = "\033[44m",
	.purple_bg = "\033[45m",
	.cyan_bg = "\033[46m",
	.white_bg = "\033[47m",
};
```
# Thread Safety:
cprintf is not thread-safe.