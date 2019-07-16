/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 20:40:42 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/29 20:40:44 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strlen_unicode(const wchar_t *s)
{
	const wchar_t	*tmp;

	if (!s)
		return (6);
	tmp = s;
	while (*s)
		s++;
	return (s - tmp);
}

int			ft_strlen_printf(const char *s)
{
	size_t			len;
	unsigned int	*x;

	if (!s)
		return (6);
	len = 0;
	while (1)
	{
		x = (unsigned int *)s;
		if ((*x & 0xFF) == 0)
			return (len);
		if ((*x & 0xFF00) == 0)
			return (len + 1);
		if ((*x & 0xFF0000) == 0)
			return (len + 2);
		if ((*x & 0xFF000000) == 0)
			return (len + 3);
		s += 4;
		len += 4;
	}
}

int			ft_atoi_printf(const char *str)
{
	int			d;
	int			integer;

	d = 1;
	integer = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' && (d = -1))
		str++;
	else if (*str == '+')
		str++;
	str--;
	while (++str && (*str >= 48 && *str <= 57))
		integer = integer * 10 + *str - 48;
	if (d == -1)
		return (integer * d);
	return (integer);
}

int			ft_isdigit_printf(char c)
{
	return (c >= '0' && c <= '9');
}
