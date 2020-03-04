#include "../ft_printf.h"

void ft_parse(const char *s, va_list param, int *count)
{
	int i;
	//int flag;

	//flag = 0;
	i = 0;
	while(*s)
	{
		if(*s != '%')
		{
			ft_putchar_fd(*s, 1);
			s++;
			i++;
			*count = *count + 1;
		}
		else
		{
			*count = *count + ft_type_identifier(s, param);
			s += 2;
		}
	}
	//*count += i;
}
