/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arglen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:04:12 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/24 13:04:16 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_unbrlen(uintmax_t n)
{
	int i;

	i = 1;
	while (n && n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int		ft_snbrlen(intmax_t n)
{
	if (n < 0)
		return (ft_unbrlen(-n));
	return (ft_unbrlen(n));
}

static int		ft_hexlen(uintmax_t x)
{
	int i;

	i = 1;
	while (x > 15)
	{
		x = (x >> 4);
		i++;
	}
	return (i);
}

/*
** For string length, if an argument is an integer Zero, "(null)" is printed
** that corresponds to below returned precision of 6;
*/

int				ft_arg_len(intmax_t arg, char c, t_param *prm)
{
	if (c == 'c' || c == '%')
		return (1);
	else if (!arg && !prm->prc && c != 'o')
		return (0);
	else if (c == 'd' || c == 'i')
		return (ft_snbrlen((intmax_t)arg));
	else if (c == 'u')
		return (ft_unbrlen((uintmax_t)arg));
	else if (c == 'o')
		return (ft_arg_len_oct(arg, prm));
	else if (c == 'x' || c == 'X')
		return (ft_hexlen((uintmax_t)arg));
	else if (c == 'p')
		return (ft_hexlen((uintmax_t)arg));
	else if (c == 's' && prm->p >> 7 & 1)
		return (ft_strlen_unicode((wchar_t *)arg));
	else if (c == 's')
		return (ft_strlen_printf((char *)arg));
	return (0);
}
