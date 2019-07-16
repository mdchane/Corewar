/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buf_unicode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 01:50:29 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/30 01:50:34 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printbuf_wchar_t(char *dst, wchar_t src, int size)
{
	int shift;

	if (!size)
		return ;
	if ((g_bcn & BUF_M) > BUF_M - size)
		ft_flush(dst);
	shift = 0;
	while (--size >= 0)
	{
		dst[g_bcn & BUF_M] = src >> shift & 0xFF;
		g_bcn++;
		shift += 8;
	}
}

void		ft_printbuf_unicode_prc(char *dst, wchar_t **src, int prc)
{
	while (**src && prc)
	{
		ft_printbuf_wchar_t(dst, ft_utf8_encode(**src), ft_wcsize(**src));
		(*src)++;
		prc--;
	}
}
