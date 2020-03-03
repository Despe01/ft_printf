#include "ft_printf.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
	char *test = "retour";

	printf("--------------------------------------\n");
	int return_printf = printf("realprintf : %slol\n", test);
	int return_ft = ft_printf("mon printf : %slol\n", test);
	printf("retour printf : %d\n", return_printf);
	printf("retour ft_printf : %d\n", return_ft);
	printf("--------------------------------------\n");
	return 0;
}
