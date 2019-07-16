/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nd_long_round.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 20:25:42 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/29 20:25:45 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_round_up(uint32_t *nd, int ndlo)
{
	while (nd[ndlo & 2047] >= 1000000000)
	{
		ndlo++;
		nd[ndlo & 2047] += 1;
	}
}

static void		ft_round_ndlo(int r, int rloc, int *ndlo)
{
	if (!r)
		*ndlo = 0;
	else if (!rloc && -*ndlo * 9 >= r)
		*ndlo = -r / 9;
	else if (rloc && -*ndlo * 9 >= r)
		*ndlo = -r / 9 - 1;
}

static int		ft_round_last(int ndlo, int r, uint32_t *nd)
{
	int	rloc;
	int tlo;

	tlo = ndlo;
	rloc = (r % 9);
	ft_round_ndlo(r, rloc, &ndlo);
	if (((r / 9) + 1) == -tlo && !(nd[tlo & 2047] % g_pow10[8 - rloc]))
	{
		if (rloc && (nd[ndlo & 2047] / g_pow10[9 - rloc] % 10) & 1
			&& (nd[ndlo & 2047] / g_pow10[8 - rloc]) % 10 == 5)
			nd[ndlo & 2047] += g_pow10[9 - rloc];
		else if (!rloc && (tlo <= ndlo - 1) && (nd[ndlo & 2047] % 10) & 1
			&& nd[(ndlo - 1) & 2047] / g_pow10[8] == 5)
			nd[ndlo & 2047] += 1;
	}
	else
	{
		if (rloc && (nd[ndlo & 2047] / g_pow10[8 - rloc]) % 10 >= 5)
			nd[ndlo & 2047] += g_pow10[9 - rloc];
		else if (!rloc && (tlo <= ndlo - 1)
			&& nd[(ndlo - 1) & 2047] / g_pow10[8] >= 5)
			nd[ndlo & 2047] += 1;
	}
	return (ndlo);
}

void			ft_long_round(t_nd_long *nd, int *r)
{
	if (*r > -nd->lo * 9)
		*r = -nd->lo * 9;
	nd->lo = ft_round_last(nd->lo, *r, nd->n);
	ft_round_up(nd->n, nd->lo);
}
