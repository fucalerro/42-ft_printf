#include "ft_printf.h"

void	test_c(void)
{
	int	lc;
	int	ft;

	printf("\n========== test 1: %%c ==========\n\n");
	lc = 0;
	ft = 0;
	lc += printf("%c\n", 'c');
	ft += ft_printf("%c\n", 'c');
	printf("\n");
	if (lc != ft)
		printf("\nlen doesn't match!\nlc: %d\nft: %d\n", lc, ft);
}

void	test_d(void)
{
	int	lc;
	int	ft;

	printf("\n========== test 2: %%d ==========\n\n");
	lc = 0;
	ft = 0;
	printf("%d\n%d\n\n", lc, ft);
	lc += printf("%d\n", (int)2147483647);
	ft += ft_printf("%d\n", (int)2147483647);
	lc += printf("%d\n", (int)346340);
	ft += ft_printf("%d\n", (int)346340);
	lc += printf("%d\n", (int)0);
	ft += ft_printf("%d\n", (int)0);
	lc += printf("%d\n", (int)-1242345);
	ft += ft_printf("%d\n", (int)-1242345);
	lc += printf("%d\n", (int)-2147483648);
	ft += ft_printf("%d\n", (int)-2147483648);
	printf("\n");
	if (lc != ft)
		printf("\nlen doesn't match!\nlc: %d\nft: %d\n", lc, ft);
}

void	test_s(void)
{
	int	lc;
	int	ft;

	printf("\n========== test 3: %%s ==========\n\n");
	lc = 0;
	ft = 0;
	lc += printf("%s\n", "Hello World!");
	ft += ft_printf("%s\n", "Hello World!");
	lc += printf("%s\n", "");
	ft += ft_printf("%s\n", "");
	printf("\n");
	if (lc != ft)
		printf("\nlen doesn't match!\nlc: %d\nft: %d\n", lc, ft);
}

void	test_p(void)
{
	int		lc;
	int		ft;
	char	*str;
	char	*ptrnu;

	printf("\n========== test 4: %%p ==========\n\n");
	lc = 0;
	ft = 0;
	str = "123";
	ptrnu = NULL;
	lc += printf("%p\n", ptrnu);
	ft += ft_printf("%p\n", ptrnu);
	lc += printf("%p\n", &lc);
	ft += ft_printf("%p\n", &lc);
	lc += printf("%p\n", str);
	ft += ft_printf("%p\n", str);
	printf("\n");
	if (lc != ft)
		printf("\nlen doesn't match!\nlc: %d\nft: %d\n", lc, ft);
}

void	test_x(void)
{
	int	lc;
	int	ft;

	printf("\n========== test 5: %%x ==========\n\n");
	lc = 0;
	ft = 0;
	lc += printf("%x\n", (int)2147483647);
	ft += ft_printf("%x\n", (int)2147483647);
	lc += printf("%x\n", (int)346340);
	ft += ft_printf("%x\n", (int)346340);
	lc += printf("%x\n", (int)0);
	ft += ft_printf("%x\n", (int)0);
	lc += printf("%x\n", (int)-1242345);
	ft += ft_printf("%x\n", (int)-1242345);
	lc += printf("%x\n", (int)0x12ef231);
	ft += ft_printf("%x\n", (int)0x12ef231);
	lc += printf("%x\n", (int)-2147483648);
	ft += ft_printf("%x\n", (int)-2147483648);
	lc += printf("%x\n", (int)-2147483647);
	ft += ft_printf("%x\n", (int)-2147483647);
	if (lc != ft)
		printf("\nlen doesn't match!\nlc: %d\nft: %d\n", lc, ft);
}

void	test_X(void)
{
	int	lc;
	int	ft;

	printf("\n========== test 5: %%X ==========\n\n");
	lc = 0;
	ft = 0;
	lc += printf("%X\n", (int)2147483647);
	ft += ft_printf("%X\n", (int)2147483647);
	lc += printf("%X\n", (int)346340);
	ft += ft_printf("%X\n", (int)346340);
	lc += printf("%X\n", (int)0);
	ft += ft_printf("%X\n", (int)0);
	lc += printf("%X\n", (int)-1242345);
	ft += ft_printf("%X\n", (int)-1242345);
	lc += printf("%X\n", (int)0x12ef231);
	ft += ft_printf("%X\n", (int)0x12ef231);
	lc += printf("%X\n", (int)-2147483648);
	ft += ft_printf("%X\n", (int)-2147483648);
	lc += printf("%X\n", (int)-2147483647);
	ft += ft_printf("%X\n", (int)-2147483647);
	if (lc != ft)
		printf("\nlen doesn't match!\nlc: %d\nft: %d\n", lc, ft);
}

void	test_per(void)
{
	int	lc;
	int	ft;

	printf("\n========== test 6: %%%% ==========\n\n");
	lc = 0;
	ft = 0;
	lc += printf("%%\n");
	ft += ft_printf("%%\n");
	lc += printf("%%%%%%%%  %% %%%%   %%%% %%\n");
	ft += ft_printf("%%%%%%%%  %% %%%%   %%%% %%\n");
	if (lc != ft)
		printf("\nlen doesn't match!\nlc: %d\nft: %d\n", lc, ft);
}

void	test_u(void)
{
	int	lc;
	int	ft;

	printf("\n========== test 5: %%u ==========\n\n");
	lc = 0;
	ft = 0;
	lc += printf("%u\n", (int)2147483647);
	ft += ft_printf("%u\n", (int)2147483647);
	lc += printf("%u\n", (int)346340);
	ft += ft_printf("%u\n", (int)346340);
	lc += printf("%u\n", (int)0);
	ft += ft_printf("%u\n", (int)0);
	lc += printf("%u\n", (int)-1242345);
	ft += ft_printf("%u\n", (int)-1242345);
	lc += printf("%u\n", (int)0x12ef231);
	ft += ft_printf("%u\n", (int)0x12ef231);
	lc += printf("%u\n", (int)-2147483648);
	ft += ft_printf("%u\n", (int)-2147483648);
	lc += printf("%u\n", (int)-2147483647);
	ft += ft_printf("%u\n", (int)-2147483647);
	if (lc != ft)
		printf("\nlen doesn't match!\nlc: %d\nft: %d\n", lc, ft);
}

int	main(void)
{
	unsigned int	nbr;

	test_c();
	test_d();
	test_s();
	test_p();
	test_x();
	test_X();
	test_per();
	test_u();
	printf("\n\n\n");
	nbr = -123;
	printf("%u\n", nbr);
	return (0);
}
