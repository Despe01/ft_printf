#include "../ft_printf.h"

char	*ft_xtype(va_list param, t_flags *flags)
{
	unsigned int i;

	i = (unsigned int)va_arg(param, unsigned int);
	flags->type = 1;
	if (i == 0 && flags->prec_dot == 1)
		return (ft_strdup(""));
	else
		return (ft_itoa_base(i, 16, "0123456789abcdef"));
}
