/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs_pad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 21:09:48 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/29 21:09:50 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_c(char c, char *b, intmax_t arg, t_param *prm)
{
	char *s;

	if (c == 's')
	{
		if (!arg)
		{
			s = (char *)ft_null();
			ft_printbuf_prc(b, &s, prm->prc);
		}
		else if (prm->p >> 7 & 1)
			ft_printbuf_unicode_prc(b, (wchar_t **)&arg, prm->prc);
		else
			ft_printbuf_prc(b, (char **)&arg, prm->prc);
	}
	else if (c == 'c')
	{
		if (prm->p >> 7 & 1)
			ft_printbuf_wchar_t(b, ft_utf8_encode(arg), ft_wcsize(arg));
		else
			ft_printbuf_char(b, (char)arg);
	}
	else if (c == '%')
		ft_printbuf_char(b, '%');
}

void			ft_print_c_pad(char c, char *b, t_param *prm, intmax_t arg)
{
	int len;

	len = ft_arg_len(arg, c, prm);
	if (prm->prc != -1 && c == 's' && prm->prc < len)
		len = prm->prc;
	if (!(prm->p >> 1 & 1) && (prm->p >> 4 & 1))
		ft_printbuf_pad(b, '0', prm->wdt - len);
	else if (!(prm->p >> 1 & 1))
		ft_printbuf_pad(b, ' ', prm->wdt - len);
	ft_print_c(c, b, arg, prm);
	if (prm->p >> 1 & 1)
		ft_printbuf_pad(b, ' ', prm->wdt - len);
}
