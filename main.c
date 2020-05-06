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
	/*printf("--------------------------------------\n");
	int return_printf = printf(":%017.*u%d%sRSMjj%.2s%%\n", -10, 2147483647, 42, "lol", test);
	int return_ft = ft_printf(":%017.*u%d%sRSMjj%.2s%%\n", -10, 2147483647, 42, "lol", test);
	printf("--------------------------------------\n");
	printf("retour printf : %d\n", return_printf);
	printf("retour ft_printf : %d\n", return_ft);
	printf("--------------------------------------\n");*/
ft_printf("hello ca%----4c %1c%10c%-c ??\n", '\0', '\n', (char)56, 0);
printf("hello ca%----4c %1c%10c%-c ??\n", '\0', '\n', (char)56, 0);
//ft_printf(NULL, 0);
		//ft_printf(":%017.*u%d%sRSMjj%.2s%%\n", -10, 2147483647, 42, "lol", "lel");
		//printf("%0-10.5d\n", 42);
	//ft_printf("%d\n", 10);
	//getchar();
	//printf("retour = 21\t",printf("realprintf : %slol\n", test));
	//printf("retour = 22\t",ft_printf("mon printf : %slol\n", test));
	//printf("test printf : %p\n", &test);
	//ft_printf("test ft_printf : %p\n", &test);
	//printf("%zu\n", ftstrlen(test2));
	//printf("\ntest: :%20p:FIN TEST\n", test);
	//printf("%zu\n", ftstrlen(test));
}
