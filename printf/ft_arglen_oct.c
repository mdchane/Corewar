/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arglen_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:52:21 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/29 19:52:25 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_octlen(uintmax_t o)
{
	int i;

	i = 1;
	while (o > 7)
	{
		o = (o >> 3);
		i++;
	}
	return (i);
}

int				ft_arg_len_oct(intmax_t arg, t_param *prm)
{
	if (arg && prm->prc)
		return (ft_octlen((uintmax_t)arg) + (prm->p >> 2 & 1));
	else if (!arg && !prm->prc && !(prm->p >> 2 & 1))
		return (0);
	return (ft_octlen((uintmax_t)arg));
}
