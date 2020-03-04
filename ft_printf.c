#include "ft_printf.h"

int ft_stype(va_list param)
{
	char *str;
	str = (char *) va_arg(param, const char * );
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
	/*while(*str)
	{
		buffer++ = str++;
	}*/
}

void ft_ptype(va_list param)
{
	(void) param;
	//void *ptr;
	//ptr = (void *) va_arg(param, void * );
}

int ft_type_identifier(const char *s, va_list param)
{
	//int len_type;
	//int i;

	//i = 0;
	//len_type = 0;
	if (s[1] == 's')
		return (ft_stype(param));
	else if (s[1] == 'p')
		ft_ptype(param);
	return 0;
}

int ft_printf(const char *s, ...)
{
	int count;
	va_list param;

	count = 0;
	va_start(param, s);
	ft_parse(s, param, &count);
	va_end(param);
	return count;
}
