#include "ft_printf.h"
#include <stdio.h>

size_t	ftstrlen(const char *s)
{
	size_t i;

	i = 0;
	if (s != NULL)
	{
	while (s[i])
		i++;
	}
	return (i);
}

int main(int argc, char const *argv[]) {
	char *test = "retour";
	char *test2 = NULL;
	int testi = 10;
	(void) argc;
	(void) argv;
	printf("--------------------------------------\n");
	int return_printf = printf("realprintf : %-.3slol\n", test);
	int return_ft = ft_printf("mon printf : %-.3slol\n", test);
	printf("retour printf : %d\n", return_printf);
	printf("retour ft_printf : %d\n", return_ft);

	printf("--------------------------------------\n");
	//printf("retour = 21\t",printf("realprintf : %slol\n", test));
	//printf("retour = 22\t",ft_printf("mon printf : %slol\n", test));
	//printf("test printf : %p\n", &test);
	//ft_printf("test ft_printf : %p\n", &test);
	printf("%zu\n", ftstrlen(test2));
	printf("\ntest: :%.05d:FIN TEST\n", testi);

	return 0;
}
