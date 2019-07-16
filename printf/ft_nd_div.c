/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nd_div.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 20:15:58 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/29 20:16:02 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** carry is a (value / 2^9) * 10^10 / 2^9, where
** value is divided by 512 and multiplied by 1953125, whick is the maximal
** decimal 9-digit decimal times 512;
*/

static void		ft_nd_div2p_hi(t_nd *nd, uint32_t *carry, uint32_t *i)
{
	uint32_t val;

	while (1)
	{
		val = nd->n[*i];
		nd->n[*i] = (val >> 9) + *carry;
		*carry = (val & 0x1ff) * 1953125;
		if (*i == (nd->lo & 127))
			break ;
		*i = (*i - 1) & 127;
	}
}

static void		ft_nd_div2p_last(t_nd *nd, uint32_t *carry,
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
		if (*i == (nd->lo & 127))
			break ;
		*i = (*i - 1) & 127;
	}
}

void			ft_nd_div2p(t_nd *nd, uint32_t p)
{
	uint32_t carry;
	uint32_t i;

	while (p >= 9)
	{
		carry = 0;
		i = nd->hi & 127;
		ft_nd_div2p_hi(nd, &carry, &i);
		if (carry)
			nd->n[--(nd->lo) & 127] = carry;
		p -= 9;
	}
	if (p)
	{
		carry = 0;
		i = nd->hi & 127;
		ft_nd_div2p_last(nd, &carry, &i, p);
		if (carry)
			nd->n[--(nd->lo) & 127] = carry;
	}
}
