#include "../ft_printf.h"

char	*ft_ctype(va_list param, t_flags *flags)
{
	char	*str;
	int		c;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	c = (int)va_arg(param, int);
	if (c == 0)
		flags->czero = 1;
	str[0] = c;
	str[1] = '\0';
	flags->type = 0;
	return (str);
}
