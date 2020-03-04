#ifndef ft_printf
#define FT_PRINTF

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"

int ft_printf(const char *s, ...);
void ft_parse(const char *s, va_list param, int *count);
int ft_type_identifier(const char *s, va_list param);
void ft_ptype(va_list param);
int ft_stype(va_list param);

#endif
