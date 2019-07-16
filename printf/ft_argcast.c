/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argcast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:03:50 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/24 13:03:56 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t		ft_arg_cast_c(va_list valist)
{
	return (va_arg(valist, int));
}

static intmax_t		ft_arg_cast_s(va_list valist)
{
	return (va_arg(valist, intptr_t));
}

static intmax_t		ft_arg_cast_i(va_list valist, int p)
{
	if (p >> 8 & 1)
		return (va_arg(valist, long long int));
	else if (p >> 7 & 1)
		return (va_arg(valist, long int));
	else if (p >> 6 & 1)
		return ((short int)va_arg(valist, int));
	else if (p >> 5 & 1)
		return ((signed char)va_arg(valist, int));
	else
		return (va_arg(valist, int));
}

static intmax_t		ft_arg_cast_u(va_list valist, int p)
{
	if (p >> 8 & 1)
		return (va_arg(valist, unsigned long long int));
	else if (p >> 7 & 1)
		return (va_arg(valist, unsigned long int));
	else if (p >> 6 & 1)
		return ((unsigned short int)va_arg(valist, int));
	else if (p >> 5 & 1)
		return ((unsigned char)va_arg(valist, int));
	else
		return (va_arg(valist, unsigned int));
}

intmax_t			ft_arg_cast(va_list valist, int p, const char c)
{
	if (c == 'c')
		return (ft_arg_cast_c(valist));
	else if (c == 's')
		return (ft_arg_cast_s(valist));
	else if (c == 'd' || c == 'i')
		return (ft_arg_cast_i(valist, p));
	else if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (ft_arg_cast_u(valist, p));
	else if (c == 'p')
		return (ft_arg_cast_u(valist, 0x100));
	return (0);
}
