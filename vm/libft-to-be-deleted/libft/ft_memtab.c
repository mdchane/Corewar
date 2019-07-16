/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:55:02 by jfleury           #+#    #+#             */
/*   Updated: 2019/03/12 13:55:07 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_memtab(size_t y, size_t x)
{
	char			**tab;
	size_t			i;

	i = 0;
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (y + 1))))
		return (NULL);
	while (i < y)
	{
		if (!(tab[i] = ft_strnew(x)))
		{
			i++;
			while (i > 0)
			{
				free(tab[i - 1]);
				i--;
			}
			free(tab);
			return (NULL);
		}
		i++;
	}
	tab[y] = 0;
	return (tab);
}
