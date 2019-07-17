/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 21:34:43 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/29 21:34:47 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flush(char *dst)
{
	write(1, dst, BUF_SIZE);
	g_bcn++;
}

void		ft_printbuf_char(char *dst, char src)
{
	if ((g_bcn & BUF_M) < BUF_M)
		dst[g_bcn & BUF_M] = src;
	else if ((g_bcn & BUF_M) == BUF_M)
	{
		ft_flush(dst);
		dst[g_bcn & BUF_M] = src;
	}
	g_bcn++;
}

void		ft_printbuf_prc(char *dst, char **src, int prc)
{
	if (!dst || !src)
		pf_error(-1);
	while (**src && prc)
	{
		if ((g_bcn & BUF_M) == BUF_M)
			ft_flush(dst);
		dst[g_bcn & BUF_M] = **src;
		g_bcn++;
		(*src)++;
		prc--;
	}
}

void		ft_printbuf_c(char *dst, const char **src, char c)
{
	while (**src && **src != c)
	{
		if ((g_bcn & BUF_M) == BUF_M)
			ft_flush(dst);
		dst[g_bcn & BUF_M] = **src;
		g_bcn++;
		(*src)++;
	}
}

void		ft_printbuf_pad(char *dst, char c, int len)
{
	while (len > 0)
	{
		if ((g_bcn & BUF_M) == BUF_M)
			ft_flush(dst);
		dst[g_bcn & BUF_M] = c;
		g_bcn++;
		len--;
	}
}
