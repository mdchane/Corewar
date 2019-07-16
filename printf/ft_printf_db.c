/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_db.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:06:20 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/24 13:06:22 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_naninf_db(t_value *t)
{
	if (((t->u32.hi & 0x000fffff) | t->u32.lo) != 0)
		return ("nan");
	else
		return ("inf");
}

static void		ft_fract_to_nd(t_value *t, t_nd *nd, int32_t *e)
{
	if (t->u32.lo)
	{
		*e -= 32;
		nd->n[0] = (nd->n[0] << 3) | (t->u32.lo >> 29);
		ft_nd_mul2p(nd, 29, t->u32.lo & 0x1fffffff);
	}
}

static void		ft_implicit_one(int32_t *e, t_nd *nd)
{
	if (*e == 0)
		(*e)++;
	else
		nd->n[0] |= 0x100000;
}

char			*ft_printf_db(double *n, int r, char *tbl)
{
	t_value		t;
	int32_t		e;
	t_nd		nd;

	t.n = *n;
	ft_init_nd(&nd);
	if ((t.u32.hi << 1) >= 0xffe00000)
		return (ft_naninf_db(&t));
	else
	{
		e = (t.u32.hi >> 20) & 0x7ff;
		nd.n[0] = t.u32.hi & 0xfffff;
		ft_implicit_one(&e, &nd);
		e -= 1043;
		ft_fract_to_nd(&t, &nd, &e);
		if (e >= 0)
			ft_nd_mul2p(&nd, (uint32_t)e, 0);
		else
			ft_nd_div2p(&nd, (uint32_t)-e);
		if (n && nd.lo)
			ft_round(&nd, &r);
		return (ft_buf_print_db(&nd, r, tbl));
	}
	return (0);
}
