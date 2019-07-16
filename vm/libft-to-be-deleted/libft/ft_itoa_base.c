/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:05:04 by allefebv          #+#    #+#             */
/*   Updated: 2019/07/08 17:26:58 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static int	ft_malloc_len(unsigned long long nb, int base)
{
	int		i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(unsigned long long nb, int base)
{
	unsigned long long	result;
	int					i;
	char				*str;
	char				*tab;

	tab = ft_strdup("0123456789abcdef");
	if (base < 2 || base > 16)
		return (NULL);
	i = ft_malloc_len(nb, base);
	if (nb == 0)
		i++;
	if (!(str = (char*)malloc(sizeof(char*) * i + 1)))
		return (NULL);
	str[i] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		i--;
		result = nb % base;
		str[i] = tab[result];
		nb = nb / base;
	}
	free(tab);
	return (str);
}
