/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nd_long_mul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 20:23:07 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/29 20:23:09 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_nd_mul2p_main(t_nd_long *nd, uint32_t *carry, uint32_t *i)
{
	uint64_t val;

	while (++(*i) <= (uint32_t)nd->hi)
	{
		val = ((uint64_t)nd->n[*i] << 29) | *carry;
		*carry = (uint32_t)(val / 1000000000);
		nd->n[*i] = (uint32_t)val - *carry * 1000000000;
	}
}

static void		ft_nd_mul2p_last(t_nd_long *nd, uint32_t *carry,
									uint32_t *i, uint32_t p)
{
	uint64_t val;

	while (++(*i) <= (uint32_t)nd->hi)
	{
		val = ((uint64_t)nd->n[*i] << p) | *carry;
		*carry = (uint32_t)(val / 1000000000);
		nd->n[*i] = (uint32_t)val - *carry * 1000000000;
	}
}

void			ft_nd_long_mul2p(t_nd_long *nd, uint32_t p, uint32_t carry)
{
	uint32_t i;

	while (p >= 29)
	{
		i = -1;
		ft_nd_mul2p_main(nd, &carry, &i);
		if (carry)
		{
			nd->n[++(nd->hi)] = carry;
			carry = 0;
		}
		p -= 29;
	}
	if (p)
	{
		i = -1;
		ft_nd_mul2p_last(nd, &carry, &i, p);
		if (carry)
			nd->n[++(nd->hi)] = carry;
	}
}
