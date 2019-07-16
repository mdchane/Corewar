/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:06:12 by jfleury           #+#    #+#             */
/*   Updated: 2018/11/13 18:48:02 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_isneg(int n)
{
	if (n >= 0)
		return (0);
	else
		return (1);
}

static int		ft_nbrlen(int n)
{
	int		i;

	i = 0;
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb = n;
	len = ft_nbrlen(n) + ft_isneg(n);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		n = -n;
	while (len > ft_isneg(nb))
	{
		len--;
		str[len] = (n % 10) + 48;
		n = n / 10;
	}
	if (ft_isneg(nb) == 1)
		str[0] = '-';
	return (str);
}
