#include "ft_printf.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
	char *test = "retour";

	(void) argc;
	(void) argv;
	printf("--------------------------------------\n");
	int return_printf = printf("realprintf : %slol\n", test);
	int return_ft = ft_printf("mon printf : %slol\n", test);
	printf("retour printf : %d\n", return_printf);
	printf("retour ft_printf : %d\n", return_ft);

	printf("--------------------------------------\n");
	//printf("retour = 21\t",printf("realprintf : %slol\n", test));
	//printf("retour = 22\t",ft_printf("mon printf : %slol\n", test));
	printf("test : %s", ft_itoa_base(2147483647, 16, "0123456789ABCDEF"));

	return 0;
}
