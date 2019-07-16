/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_print_db.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 20:37:10 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/29 20:37:15 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_sprint(int up, char **p, uint32_t u, int r)
{
	while (up >= r)
	{
		**p = (u / g_pow10[up]) % 10 + 48U;
		(*p)++;
		up--;
	}
}

static void	ft_print_hi(t_nd *nd, char **p)
{
	ft_sprint(ft_exp_dec(nd->n[nd->hi]), p, nd->n[nd->hi & 127], 0);
	while (--(nd->hi) >= 0)
		ft_sprint(8, p, nd->n[nd->hi & 127], 0);
}

static void	ft_print_lo(t_nd *nd, char **p, int r)
{
	int rloc;

	rloc = r % 9;
	while (nd->hi > nd->lo || (!rloc && nd->hi >= nd->lo))
	{
		ft_sprint(8, p, nd->n[nd->hi & 127], 0);
		nd->hi--;
	}
	if (rloc && -nd->lo * 9 >= r)
		ft_sprint(8, p, nd->n[nd->hi & 127], 9 - rloc);
}

char		*ft_buf_print_db(t_nd *nd, int r, char *tbl)
{
	char	*p;

	p = tbl;
	if (nd->hi && !nd->n[nd->hi])
		nd->hi--;
	ft_print_hi(nd, &p);
	*p++ = '.';
	ft_print_lo(nd, &p, r);
	*p = '\0';
	return (tbl);
}
