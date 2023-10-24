/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:18:17 by lferro            #+#    #+#             */
/*   Updated: 2023/10/24 19:52:07 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

size_t	conv_printer_hex(size_t nbr, char const c)
{
	size_t	count;
	char	*hexstr;

	count = 0;
	if (c == 'p')
		hexstr = dectohex_sptr(nbr);
	else if (c == 'x')
		hexstr = dectohex_str(nbr);
	else if (c == 'X')
		hexstr = dectohex_scap(nbr);
	count += print_str(hexstr);
	free(hexstr);
	return (count);
}

// Fn actually printing the characters
// Return:	Number of characters printed
size_t	conv_printer(char const c, va_list args)
{
	size_t	printed_chars;

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
		printed_chars += conv_printer_hex(va_arg(args, size_t), c);
	else if (c == '%')
		printed_chars += print_char('%');
	return (printed_chars);
}

// FT_PRINTF
// The one and only ft_printf
int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			index;
	int			i;
	int			printed_chars;

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
// 	char c2 = '$';
// 	int	nbr = 0x4a2;
// 	int n2 = -1234;
// 	char *str = "semaine";
// 	int	*ptr = NULL;

// 	int lc =    printf("%%%d%%abc%%s%p%d%c%s%%%xabcs%X%%abcs%%%d\n", n2, &ptr, nbr, c2, str, n2, nbr, n2);
// 	int ft = ft_printf("%%%d%%abc%%s%p%d%c%s%%%xabcs%X%%abcs%%%d\n", n2, &ptr, nbr, c2, str, n2, nbr, n2);

// 	printf("libc:	%d\nft:	%d\n", lc, ft);

// 	// ft_putnbr_fd(0x123, 1);

// 	return 0;
// }
