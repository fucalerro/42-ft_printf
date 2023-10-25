/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:18:17 by lferro            #+#    #+#             */
/*   Updated: 2023/10/25 12:09:05 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ull	conv_printer_hex(t_ull nbr, char const c)
{
	t_ull	count;
	char	*hexstr;

	count = 0;
	if (c == 'p')
		hexstr = dectohex_sptr(nbr);
	else if (c == 'x')
		hexstr = dectohex_str(nbr);
	else if (c == 'X')
		hexstr = dectohex_scap(nbr);
	else
		hexstr = 0;
	count += print_str(hexstr);
	free(hexstr);
	return (count);
}

// Fn actually printing the characters
// Return:	Number of characters printed
t_ull	conv_printer(char const c, va_list args)
{
	t_ull	printed_chars;

	printed_chars = 0;
	if (c == 's')
		printed_chars += print_str(va_arg(args, char *));
	else if (c == 'c')
		printed_chars += print_char(va_arg(args, int));
	else if (c == 'i' || c == 'd')
		printed_chars += print_int(va_arg(args, int));
	else if (c == 'u')
		printed_chars += print_uint(va_arg(args, unsigned int));
	else if (c == 'p' || c == 'x' || c == 'X')
		printed_chars += conv_printer_hex(va_arg(args, t_ull), c);
	else if (c == '%')
		printed_chars += print_char('%');
	return (printed_chars);
}

// FT_PRINTF
// The one and only ft_printf
int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		index;
	int		i;
	int		printed_chars;

	index = -1;
	i = 0;
	printed_chars = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			printed_chars += print_char(s[i]);
		else if (s[i] == '%' && index == -1)
			index = i++;
		if (index >= 0 && conv_matcher(s[i]) >= 0)
		{
			printed_chars += conv_printer(s[i], args);
			index = -1;
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}

// int main(void)
// {
// 	char *s = NULL;
// 	printf("%d\n", printf("%s\n", s));
// 	printf("%d\n", ft_printf("%s\n", s));
// 	return 0;
// }

// int main(void)
// {
// 	// char c2 = '$';
// 	int	nbr = 0x4a2;
// 	int n2 = -8757;
// 	char *str = "semaine";
// 	// int	*ptr = Nt_ull;

// 	int lc =    printf("%p  %x %X\n", &str, nbr, n2);
// 	int ft = ft_printf("%p  %x %X\n", &str, nbr, n2);

// 	// int lc =    printf("%%%d%%abc%%s%d%c%s%% %p
//%x   abcs%X%%abcs%%%d\n", n2, nbr, c2, str,&n2,  n2,  nbr, n2);
// 	// int ft = ft_printf("%%%d%%abc%%s%d%c%s%% %p
//%x   abcs%X%%abcs%%%d\n", n2, nbr, c2, str,&n2,  n2,  nbr, n2);

// 	// int lc =    printf("%%%d%%abc%% %x s%p%d%c%s%%
// \n", n2, nbr, &str ,nbr, c2, str);
// 	// int ft = ft_printf("%%%d%%abc%% %x s%p%d%c%s%%
// \n", n2, nbr, &str ,nbr, c2, str);

// 	printf("libc:	%d\nft:	%d\n", lc, ft);

// 	// ft_putnbr_fd(0x123, 1);

// 	return (0);
// }
