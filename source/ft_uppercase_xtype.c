#include "../ft_printf.h"

char *ft_uppercase_xtype(va_list param, FlagStruct *flags)
{
	unsigned int i;
	char *res;

	i = (unsigned int) va_arg(param, unsigned int);
	res = ft_itoa_base(i, 16, "0123456789ABCDEF");
	flags->type = 0;
  return (res);
}
