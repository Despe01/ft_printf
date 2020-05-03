#include "../ft_printf.h"

char	*ft_ctype(va_list param, FlagStruct *flags, int *count)
{
	char	*str;
  int c;
	//int *test = count;

  if (!(str = (char *)malloc(sizeof(char) * 2)))
    return (NULL);
	//printf("%d\n", *test);
	c = (int)va_arg(param, int);
	//*count = *count + ftstrlen(str);
	if (c == 0)
		*count = *count + 1;
  str[0] = c;
  str[1] = '\0';
	flags->type = 0;
	return (str);
}
