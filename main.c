#include "ft_printf.h"
#include <stdio.h>


int main(int argc, char const *argv[]) {
	//void *testp = NULL;
	//char *test = "retour";
	//char *test2 = NULL;
	//char *test3 = ft_strdup(" ");
	//test3[0] = 0;
	//int testi = 0;
	//char testc = 'a';
	(void) argc;
	(void) argv;
	printf("--------------------------------------\n");
	int return_printf = printf("15chiffre 1 %.s\n", "retour");
	//int return_ft = ft_printf("15chiffre 1 %*d\n", 10, 42);
	printf("--------------------------------------\n");
	printf("retour printf : %d\n", return_printf);
	//printf("retour ft_printf : %d\n", return_ft);

	printf("--------------------------------------\n");
	//printf("retour = 21\t",printf("realprintf : %slol\n", test));
	//printf("retour = 22\t",ft_printf("mon printf : %slol\n", test));
	//printf("test printf : %p\n", &test);
	//ft_printf("test ft_printf : %p\n", &test);
	//printf("%zu\n", ftstrlen(test2));
	//printf("\ntest: :%20p:FIN TEST\n", test);
	//printf("%zu\n", ftstrlen(test));
}
