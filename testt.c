#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
  int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
  char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
  printf("%-.i, %-d, %-d, %-d, %-d, %-d, %-d, %-d\n", i, j, k, l, m, c, e, d);
  ft_printf("%-.i, %-d, %-d, %-d, %-d, %-d, %-d, %-d\n", i, j, k, l, m, c, e, d);


//return 0;
}
