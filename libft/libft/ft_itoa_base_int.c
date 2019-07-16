/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:05:04 by allefebv          #+#    #+#             */
/*   Updated: 2019/07/12 17:24:38 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static int			ft_malloc_len(unsigned int nb, int base)
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

unsigned char		*ft_itoa_base_int(unsigned int nb, int base)
{
	unsigned int		result;
	int					i;
	unsigned char		*str;
	char				*tab;

	tab = ft_strdup("0123456789abcdef");
	if (base < 2 || base > 16)
		return (NULL);
	i = ft_malloc_len(nb, base);
	if (nb == 0)
		i++;
	if (!(str = malloc(sizeof(unsigned char*) * i + 1)))
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
