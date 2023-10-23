/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:18:17 by lferro            #+#    #+#             */
/*   Updated: 2023/10/23 20:18:26 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"


// size_t	logicator(char c, va_list args)
// {
// 	int	index;
// 	int	printed_chars;

// 	index = 0;
// 	printed_chars = 0;
// 	if (c != '%')
// 	{
// 		printed_chars += print_char(c);
// 		index == 0;
// 	}
// 	else if (c == '%' && index == 0)
// 	{
// 		index = 1;
// 	}
// 	else if (index == 1 && conv_matcher(c) >= 0)
// 	{
// 		printed_chars += conv_printer(c, args);
// 		index = 0;
// 	}
// }



size_t	conv_printer(char const c, va_list args)
{
	size_t	printed_chars;

	printed_chars = 0;
	if (c == 's')
		printed_chars += print_str(va_arg(args, char *));
	else if (c  == 'c')
		printed_chars += print_char(va_arg(args, int));
	else if (c  == 'i' || c  == 'd')
		printed_chars += print_int(va_arg(args, int));
	else if (c == 'u')
		printed_chars += print_uint(va_arg(args, unsigned int));
	else if (c  == 'p')
		printed_chars += print_str(dectohex_sptr((size_t)va_arg(args, size_t)));
	else if (c  == 'x')
		printed_chars += print_str(dectohex_str(va_arg(args, size_t)));
	else if (c  == 'X')
		printed_chars += print_str(dectohex_scap(va_arg(args, size_t)));
	else if (c == '%')
		printed_chars += print_char('%');
	return (printed_chars);
}


// int	ft_printf(const char *s, ...)
// {
// 	va_list		args;
// 	va_list		args_copy;
// 	int			index;
// 	int			i;
// 	int			printed_chars;

// 	index = 0;
// 	i = 0;
// 	printed_chars = 0;
// 	va_start(args, s);
// 	va_copy(args_copy, args);

// 	while (s[i])
// 	{
// 		logicator(s[i], args_copy);
// 		i++;
// 	}
// 	va_end(args);
// 	va_end(args_copy);
// 	return (printed_chars);
// }





int	ft_printf(const char *s, ...)
{
	va_list		args;
	va_list		args_copy;
	int			index;
	int			i;
	int			printed_chars;

	index = 0;
	i = 0;
	printed_chars = 0;
	va_start(args, s);
	va_copy(args_copy, args);

	while (s[i])
	{
		if (s[i] != '%')
		{
			printed_chars += print_char(s[i]);
			index == 0;
		}
		else if (s[i] == '%' && index == 0)
		{
			i++;
			index = 1;
		}
		if (index == 1 && conv_matcher(s[i]) >= 0)
		{
			printed_chars += conv_printer(s[i], args_copy);
			index = 0;
		}
		i++;
	}
	va_end(args);
	va_end(args_copy);
	return (printed_chars);
}

int main(void)
{
	char c = '@';
	char *s = "abcd";
	char c2 = '$';
	int	nbr = 0x4a2;
	int n2 = 345434;
	unsigned int	nbr2 = 42;

	char	*ptr = "abcd";

	char *str = "semaine";
	char *s2 = "pain";

	int lc =    printf("abc%%s%p%d%c%s%%%xabcs%X%%abcs\n", &nbr, nbr, c2, str, n2, nbr);
	int ft = ft_printf("abc%%s%p%d%c%s%%%xabcs%X%%abcs\n", &nbr, nbr, c2, str, n2, nbr);

	printf("libc:	%d\nft:	%d\n", lc, ft);

	// ft_putnbr_fd(0x123, 1);

	//    printf("  %%%%%c    %s%%%c  %c%%%%%d %%%%%d %%%%%%\n", c, s, c2, c, nbr, nbr2);
	// ft_printf("  %%%%%c    %s%%%c  %c%%%%%d %%%%%d %%%%%%\n", c, s, c2, c, nbr, nbr2);

	return 0;
}
