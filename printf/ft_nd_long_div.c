/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nd_long_div.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 20:21:44 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/29 20:21:48 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_nd_div2p_hi(t_nd_long *nd, uint32_t *carry, uint32_t *i)
{
	uint32_t val;

	while (1)
	{
		val = nd->n[*i];
		nd->n[*i] = (val >> 9) + *carry;
		*carry = (val & 0x1ff) * 1953125;
		if (*i == (nd->lo & 2047))
			break ;
		*i = (*i - 1) & 2047;
	}
}

static void		ft_nd_div2p_last(t_nd_long *nd, uint32_t *carry,
									uint32_t *i, uint32_t p)
{
	uint32_t val;
	uint32_t mask;
	uint32_t mul;

	mask = (1U << p) - 1;
	mul = 1000000000 >> p;
	while (1)
	{
		val = nd->n[*i];
		nd->n[*i] = (val >> p) + *carry;
		*carry = (val & mask) * mul;
		if (*i == (nd->lo & 2047))
			break ;
		*i = (*i - 1) & 2047;
	}
}

void			ft_nd_long_div2p(t_nd_long *nd, uint32_t p)
{
	uint32_t carry;
	uint32_t i;

	while (p >= 9)
	{
		carry = 0;
		i = nd->hi & 2047;
		ft_nd_div2p_hi(nd, &carry, &i);
		if (carry)
			nd->n[--(nd->lo) & 2047] = carry;
		p -= 9;
	}
	if (p)
	{
		carry = 0;
		i = nd->hi & 2047;
		ft_nd_div2p_last(nd, &carry, &i, p);
		if (carry)
			nd->n[--(nd->lo) & 2047] = carry;
	}
}
