/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:07:04 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/24 13:07:07 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printbuf_unum(char *dst, uintmax_t n)
{
	if (n / 10)
		ft_printbuf_unum(dst, n / 10);
	ft_printbuf_char(dst, n % 10 + '0');
}

void	ft_printbuf_snum(char *dst, intmax_t n)
{
	if (n < 0)
		ft_printbuf_unum(dst, -n);
	else
		ft_printbuf_unum(dst, n);
}

void	ft_printbuf_oct(char *dst, uintmax_t o)
{
	if (o >> 3)
		ft_printbuf_oct(dst, o >> 3);
	ft_printbuf_char(dst, (o & 7) + '0');
}

void	ft_printbuf_hex(char *dst, uintmax_t x, char c)
{
	if (x >> 4)
		ft_printbuf_hex(dst, x >> 4, c);
	if ((x & 15) > 9)
		ft_printbuf_char(dst, (x & 15) + c);
	else
		ft_printbuf_char(dst, (x & 15) + '0');
}
