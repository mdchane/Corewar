/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 01:52:28 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/30 01:52:31 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_wcsize(wchar_t wc)
{
	if (wc <= 0x007F)
		return (1);
	if (wc <= 0x07FF)
		return (2);
	if (wc <= 0xFFFF)
		return (3);
	if (wc <= 0x10FFFF)
		return (4);
	return (0);
}

static int		ft_wc_to_tbl(unsigned char *s, unsigned int wchar)
{
	int				len;
	unsigned int	rshift;
	unsigned int	mask[2];
	int				i;

	if (!s || !(len = ft_wcsize(wchar)))
		return (0);
	rshift = (len - 1) * 6;
	mask[0] = 0xFF;
	mask[1] = 0xC0;
	if (len > 2)
		mask[1] += (len - 1) * 16;
	i = 0;
	while (i < len)
	{
		s[i++] = (wchar >> rshift & mask[0]) | mask[1];
		mask[0] = 0x3F;
		mask[1] = 0x80;
		rshift -= 6;
	}
	return (len);
}

wchar_t			ft_utf8_encode(unsigned int wchar)
{
	int				len;
	unsigned char	s[4];
	unsigned int	lshift;

	if (!(len = ft_wc_to_tbl(s, wchar)))
		return (0);
	if (!(lshift = (len - 1) * 8))
		return (wchar);
	wchar = 0;
	while (len--)
	{
		wchar |= s[len] << lshift;
		lshift -= 8;
	}
	return (wchar);
}
