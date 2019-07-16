/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buf_prefix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 20:59:34 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/29 20:59:36 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printbuf_sprefix(char *b, int p, intmax_t *arg)
{
	if (*arg < 0)
		ft_printbuf_char(b, '-');
	else if (*arg >= 0 && (p & 1))
		ft_printbuf_char(b, '+');
	else if (*arg >= 0 && (p >> 3 & 1))
		ft_printbuf_char(b, ' ');
}

/*
** c must be 55 (65 - 10) for HEX upper case;
** 87 (97 - 10) for hex lower case;
*/

void		ft_printbuf_xprefix(char *b, char c, t_param *prm, intmax_t *arg)
{
	if ((c == 'x' || c == 'X') && (prm->p >> 2 & 1) && *arg)
	{
		ft_printbuf_char(b, '0');
		ft_printbuf_char(b, c);
	}
	else if (c == 'p')
	{
		ft_printbuf_char(b, '0');
		ft_printbuf_char(b, 'x');
	}
	else if (c == 'o' && (prm->p >> 2 & 1) && (*arg || !prm->prc))
		ft_printbuf_char(b, '0');
}

void		ft_printbuf_fprefix(char *b, int p, double *arg)
{
	uintmax_t *ptr;

	ptr = (uintmax_t *)arg;
	if (!(*ptr >> 63) && (p & 1))
		ft_printbuf_char(b, '+');
	else if (!(*ptr >> 63) && (p >> 3 & 1))
		ft_printbuf_char(b, ' ');
	else if (*ptr >> 63)
		ft_printbuf_char(b, '-');
}

void		ft_printbuf_long_fprefix(char *b, int p, long double *arg)
{
	uintmax_t *ptr;

	ptr = (uintmax_t *)arg;
	if (!((ptr[1] >> 15) & 1) && (p & 1))
		ft_printbuf_char(b, '+');
	else if (!((ptr[1] >> 15) & 1) && (p >> 3 & 1))
		ft_printbuf_char(b, ' ');
	else if ((ptr[1] >> 15) & 1)
		ft_printbuf_char(b, '-');
}
