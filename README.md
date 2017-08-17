# Project Name : ft_printf

# Info:
The goal of this project is to recode the printf function from stdio library.
* There is no buffer management in the printf function.
* Conversions: sSpdDioOuUxXcC.
* The %% is supported.
* The following flags are supported: #0-+* and space.
* Minimum field-width.
* Precision.
* Flags hh, h, l, ll, j, z.

# Allowed functions:
* write
* malloc
* free
* exit
* The functions of man 3 stdarg

# Usage:
```
$> make
```
compile with libprintf.a 
```
#include <ft_printf.h>

int main (void)
{
  ft_print("%d %s", 100, "it's 1 hundred")
  return (0);
}
```
