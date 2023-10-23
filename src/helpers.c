/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:11:02 by lferro            #+#    #+#             */
/*   Updated: 2023/10/23 19:54:19 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

// CONVERSION MATCHER
// Search in the conversion array if it finds the character C
// Param 1:	Character to find matching
// Param 2:	Conversion array
// Return:	Return the index of the Conversion Character matched.
//			Return -1 in case it doesn't match
int	conv_matcher(char c)
{
	int	i;
	char *conv_array;

	i = 0;
	conv_array = "diuxXscp%";
	while (conv_array[i])
		{
			if (c == conv_array[i])
				return ((int)c);
			i++;
		}
	return (-1);
}

// PUT NUMBER
void	ft_putnbr(size_t n)
{
	size_t	nbr;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", 1);
	if (n == -2147483648)
		return ;
	else if (n < 0 && n > -2147483648)
	{
		n = -n;
		ft_putchar_fd('-', 1);
	}
	else if (n == 0)
	{
		ft_putchar_fd(0 + 48, 1);
		return ;
	}
	if (n > 9)
	{
		nbr = n % 10;
		n = n / 10;
		ft_putnbr(n);
		ft_putchar_fd(nbr + 48, 1);
	}
	else if (n < 10)
		ft_putchar_fd(n + 48, 1);
}

// NUMBER COUNT DIGIT
size_t	nbr_count_digit(size_t n)
{
	size_t	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}