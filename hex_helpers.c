/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:57:01 by lferro            #+#    #+#             */
/*   Updated: 2023/10/24 19:38:48 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// GET HEX NUMBER LENGH
// Get the nbr of digits of an hex number
// Param:	Decimal number to get the number of digit
// Return:	Number of digits of the number
static int	get_hexnbr_len(size_t n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static char	*max_or_zero(size_t decnbr)
{
	if (decnbr == 0)
		return ("0");
	else
		return (ft_strdup("80000000"));
}

// CONVERT DECIMAL NUMBER TO HEX NUMBER
// Description:	Convert and print a decimal number into an hex and prints it.
// Param:		Decimal number to convert.
// Return:		Return the digits printed, without the \0.
char	*dectohex_str(long long decnbr)
{
	size_t	index;
	size_t	digit;
	char	*nbrstr;

	index = 0;
	if (decnbr == 0 || (long long)decnbr == -2147483648)
		return (max_or_zero(decnbr));
	nbrstr = (char *)malloc((get_hexnbr_len(decnbr) + 1) * sizeof(char));
	if (nbrstr == 0)
		return (0);
	while (decnbr > 0)
	{
		digit = decnbr % 16;
		if (digit < 10)
			nbrstr[index++] = digit + 48;
		else
			nbrstr[index++] = 'a' + digit - 10;
		decnbr /= 16;
	}
	nbrstr[index++] = '\0';
	nbrstr = revtab(nbrstr);
	return (nbrstr);
}

// CONVERT DECIMAL NUMBER TO HEX NUMBER WITHOUT LEADING 0x
// Used to print a ptr address
char	*dectohex_sptr(size_t decnbr)
{
	size_t	index;
	size_t	digit;
	char	*nbrstr;

	index = 0;
	if (decnbr == 0)
		return (ft_strdup("(nil)"));
	nbrstr = (char *)malloc((get_hexnbr_len(decnbr) + 3) * sizeof(char));
	if (nbrstr == 0)
		return (0);
	while (decnbr > 0)
	{
		digit = decnbr % 16;
		if (digit < 10)
			nbrstr[index++] = digit + 48;
		else
			nbrstr[index++] = 'a' + digit - 10;
		decnbr /= 16;
	}
	nbrstr[index++] = 'x';
	nbrstr[index++] = '0';
	nbrstr[index++] = '\0';
	nbrstr = revtab(nbrstr);
	return (nbrstr);
}

// CONVERT DECIMAL NUMBER TO HEX IN CAPITAL LETTERS
char	*dectohex_scap(size_t decnbr)
{
	size_t	index;
	size_t	digit;
	char	*nbrstr;

	index = 0;
	if (decnbr == 0 || (long long)decnbr == -2147483648)
		return (max_or_zero(decnbr));
	nbrstr = (char *)malloc((get_hexnbr_len(decnbr) + 1) * sizeof(char));
	if (nbrstr == 0)
		return (0);
	while (decnbr > 0)
	{
		digit = decnbr % 16;
		if (digit < 10)
			nbrstr[index++] = digit + 48;
		else
			nbrstr[index++] = 'A' + digit - 10;
		decnbr /= 16;
	}
	nbrstr[index++] = '\0';
	nbrstr = revtab(nbrstr);
	return (nbrstr);
}