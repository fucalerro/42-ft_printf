#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

void	test_c(void)
{
	printf("\n========== test 1: %%c ==========\n\n");

	int	lc = 0;
	int	ft = 0;

	lc += printf("%c\n", 'c');
	ft += ft_printf("%c\n", 'c');

	printf("\n");

	if (lc != ft)
		printf("\nlen doesn't match!\nlc: %d\nft: %d\n", lc, ft);
}

void	test_d(void)
{
	printf("\n========== test 2: %%d ==========\n\n");

	int	lc = 0;
	int	ft = 0;

	printf("%d\n%d\n\n", lc, ft);

	lc +=    printf("%d\n", 2147483647);
	ft += ft_printf("%d\n", 2147483647);
	lc +=    printf("%d\n", 346340);
	ft += ft_printf("%d\n", 346340);
	lc +=    printf("%d\n", 0);
	ft += ft_printf("%d\n", 0);
	lc +=    printf("%d\n", -1242345);
	ft += ft_printf("%d\n", -1242345);
	lc +=    printf("%d\n", -2147483648);
	ft += ft_printf("%d\n", -2147483648);


	printf("\n");

	if (lc != ft)
		printf("\nlen doesn't match!\nlc: %d\nft: %d\n", lc, ft);
}

void	test_s(void)
{
	printf("\n========== test 3: %%s ==========\n\n");

	int	lc = 0;
	int	ft = 0;

	lc +=    printf("%s\n", "Hello World!");
	ft += ft_printf("%s\n", "Hello World!");
	lc +=    printf("%s\n", "");
	ft += ft_printf("%s\n", "");

	printf("\n");

	if (lc != ft)
		printf("\nlen doesn't match!\nlc: %d\nft: %d\n", lc, ft);
}

void	test_p(void)
{
	printf("\n========== test 4: %%p ==========\n\n");

	int	lc = 0;
	int	ft = 0;
	char *str;

	lc +=    printf("%p\n", NULL);
	ft += ft_printf("%p\n", NULL);
	lc +=    printf("%p\n", &lc);
	ft += ft_printf("%p\n", &lc);
	lc +=    printf("%p\n", str);
	ft += ft_printf("%p\n", str);

	printf("\n");

	if (lc != ft)
		printf("\nlen doesn't match!\nlc: %d\nft: %d\n", lc, ft);
}

void	test_x(void)
{
	printf("\n========== test 5: %%x ==========\n\n");

	int	lc = 0;
	int	ft = 0;

	lc +=    printf("%x\n", 2147483647);
	ft += ft_printf("%x\n", 2147483647);
	lc +=    printf("%x\n", 346340);
	ft += ft_printf("%x\n", 346340);
	lc +=    printf("%x\n", 0);
	ft += ft_printf("%x\n", 0);
	lc +=    printf("%x\n", -1242345);
	ft += ft_printf("%x\n", -1242345);
	lc +=    printf("%x\n", 0x12ef231);
	ft += ft_printf("%x\n", 0x12ef231);
	lc +=    printf("%x\n", -2147483648);
	ft += ft_printf("%x\n", -2147483648);
	lc +=    printf("%x\n", -2147483647);
	ft += ft_printf("%x\n", -2147483647);

	if (lc != ft)
		printf("\nlen doesn't match!\nlc: %d\nft: %d\n", lc, ft);
}

void	test_X(void)
{
	printf("\n========== test 5: %%X ==========\n\n");

	int	lc = 0;
	int	ft = 0;

	lc +=    printf("%X\n", 2147483647);
	ft += ft_printf("%X\n", 2147483647);
	lc +=    printf("%X\n", 346340);
	ft += ft_printf("%X\n", 346340);
	lc +=    printf("%X\n", 0);
	ft += ft_printf("%X\n", 0);
	lc +=    printf("%X\n", -1242345);
	ft += ft_printf("%X\n", -1242345);
	lc +=    printf("%X\n", 0x12ef231);
	ft += ft_printf("%X\n", 0x12ef231);
	lc +=    printf("%X\n", -2147483648);
	ft += ft_printf("%X\n", -2147483648);
	lc +=    printf("%X\n", -2147483647);
	ft += ft_printf("%X\n", -2147483647);

	if (lc != ft)
		printf("\nlen doesn't match!\nlc: %d\nft: %d\n", lc, ft);
}

void	test_per(void)
{
	printf("\n========== test 6: %%%% ==========\n\n");

	int	lc = 0;
	int	ft = 0;

	lc +=    printf("%%\n");
	ft += ft_printf("%%\n");

	lc +=    printf("%%%%%%%%  %% %%%%   %%%% %%\n");
	ft += ft_printf("%%%%%%%%  %% %%%%   %%%% %%\n");



	if (lc != ft)
		printf("\nlen doesn't match!\nlc: %d\nft: %d\n", lc, ft);
}

void	test_u(void)
{
	printf("\n========== test 5: %%u ==========\n\n");

	int	lc = 0;
	int	ft = 0;

	lc +=    printf("%u\n", 2147483647);
	ft += ft_printf("%u\n", 2147483647);
	lc +=    printf("%u\n", 346340);
	ft += ft_printf("%u\n", 346340);
	lc +=    printf("%u\n", 0);
	ft += ft_printf("%u\n", 0);
	lc +=    printf("%u\n", -1242345);
	ft += ft_printf("%u\n", -1242345);
	lc +=    printf("%u\n", 0x12ef231);
	ft += ft_printf("%u\n", 0x12ef231);
	lc +=    printf("%u\n", -2147483648);
	ft += ft_printf("%u\n", -2147483648);
	lc +=    printf("%u\n", -2147483647);
	ft += ft_printf("%u\n", -2147483647);

	if (lc != ft)
		printf("\nlen doesn't match!\nlc: %d\nft: %d\n", lc, ft);
}


int main(void)
{
	test_c();
	test_d();
	test_s();
	test_p();
	test_x();
	test_X();
	test_per();
	test_u();

	printf("\n\n\n");

	unsigned int	nbr = -123;
	printf("%u\n", nbr);


	return 0;
}
