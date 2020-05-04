#include "../ft_printf.h"

char *ft_xtype(va_list param, FlagStruct *flags)
{
	unsigned int i;

	i = (unsigned int) va_arg(param, unsigned int);
	flags->type = 1;
	if (i == 0 && flags->prec_dot == 1)
		return (ft_strdup(""));
	else
		return (ft_itoa_base(i, 16, "0123456789abcdef"));
	//printf("res : 0x%s", res);
}
