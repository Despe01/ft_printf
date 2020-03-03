#include "ft_printf.h"

int ft_sflag(va_list param)
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
void ft_pflag(va_list param)
{
	void *ptr;
	ptr = (void *) va_arg(param, void * );
}

int ft_flag_identifier(const char *s, va_list param)
{
	int len_flag;
	int i;

	i = 0;
	len_flag = 0;
	if (s[1] == 's')
		return (ft_sflag(param));
	else if (s[1] == 'p')
		ft_pflag(param);
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
