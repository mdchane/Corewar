/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ldb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:06:44 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/24 13:06:47 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_naninf_ldb(t_value64 *t)
{
	if (t->u64.lo != 0)
		return ("nan");
	else
		return ("inf");
}

static void		ft_fract_to_nd(t_value64 *t, t_nd_long *nd, int32_t *e)
{
	if (t->u64.lo & 0x3FFFFFFFFFFFFFF)
	{
		*e -= 58;
		ft_nd_long_mul2p(nd, 29, (t->u64.lo >> 29) & 0x1FFFFFFF);
		ft_nd_long_mul2p(nd, 29, t->u64.lo & 0x1FFFFFFF);
	}
}

char			*ft_printf_long_db(long double *n, int r, char *tbl)
{
	t_nd_long	nd;
	t_value64	t;
	int32_t		e;

	t.n = *n;
	if ((t.u64.hi << 49) >= 0xfffe000000000000)
		return (ft_naninf_ldb(&t));
	else
	{
		e = (t.u64.hi & 0x7fff);
		nd.n[0] = (t.u64.lo >> 58) & 0x3f;
		e -= 16388;
		ft_fract_to_nd(&t, &nd, &e);
		if (e >= 0)
			ft_nd_long_mul2p(&nd, (uint32_t)e, 0);
		else if (1)
			ft_nd_long_div2p(&nd, (uint32_t)-e);
		if (*n && nd.lo)
			ft_long_round(&nd, &r);
		return (ft_buf_print_ldb(&nd, r, tbl));
	}
}
