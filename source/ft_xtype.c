#include "../ft_printf.h"

char *ft_xtype(va_list param, FlagStruct *flags)
{
	//(void)param;
	unsigned int i;
	//long test;
	char *res;

	i = (unsigned int) va_arg(param, unsigned int);
	//printf("printf : %ld\n", (long)ptr);
	//test = (long) ptr;
	//printf("testptype : %ld", test);
	res = ft_itoa_base(i, 16, "0123456789abcdef");
	flags->type = 0;
  return (res);
	//printf("res : 0x%s", res);
}
