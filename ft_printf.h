/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lferro <lferro@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:18:30 by lferro            #+#    #+#             */
/*   Updated: 2023/10/24 19:29:32 by lferro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# include <stdio.h>

// Helper functions
void	ft_putnbr(long long n);
char	*dectohex_str(long long decnbr);
char	*dectohex_sptr(size_t decnbr);
char	*dectohex_scap(size_t decnbr);
int		print_n_size(char *str);
size_t	nbr_count_digit(long long n);
size_t	print_int(int nbr);
size_t	print_str(char *str);
size_t	print_char(char c);
size_t	print_uint(unsigned int nbr);
int		conv_matcher(char c);
size_t	conv_printer(char const c, va_list args);
void	ft_putnbr_uint(size_t n);
char	*revtab(char *tab);


// Printf
int		ft_printf(const char *, ...);

#endif

