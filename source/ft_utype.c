#include "../ft_printf.h"

char	*ft_utype(va_list param, FlagStruct *flags)
{
	unsigned int i;
  char *res;

	i = (unsigned int)va_arg(param, unsigned int);
  flags->type = 1;
  res = ft_itoa_base(i, 10, "0123456789");
	return res;
}
