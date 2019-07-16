/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arglen_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:04:25 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/24 13:04:30 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fract_len(const char *f)
{
	const char *t;

	t = f;
	while (*t && *t != '.')
		t++;
	f = t + 1;
	while (*t)
		t++;
	return (t - f);
}

int		ft_arg_db_len(const char *s, int p, double *arg)
{
	int			len;
	uintmax_t	*ptr;

	ptr = (uintmax_t *)arg;
	len = ft_strlen_printf(s);
	if ((p & 1) || (p >> 3 & 1) || (*ptr >> 63))
		len += 1;
	return (len);
}

int		ft_arg_long_db_len(const char *s, int p, long double *arg)
{
	int			len;
	uintmax_t	*ptr;

	ptr = (uintmax_t *)arg;
	len = ft_strlen_printf(s);
	if ((p & 1) || (p >> 3 & 1) || (ptr[1] >> 15) & 1)
		len += 1;
	return (len);
}

int		ft_arg_flen(intmax_t arg, char c, int p, int len)
{
	if ((c == 'i' || c == 'd')
		&& (arg < 0 || (arg >= 0 && (p & 1 || p >> 3 & 1))))
		return (len + 1);
	if ((c == 'x' || c == 'X') && (p >> 2 & 1) && arg)
		return (len + 2);
	else if (c == 'p')
		return (len + 2);
	return (len);
}
