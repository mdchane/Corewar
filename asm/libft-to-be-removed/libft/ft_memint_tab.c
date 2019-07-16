/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memint_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:54:49 by jfleury           #+#    #+#             */
/*   Updated: 2019/03/12 13:54:54 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		**ft_memint_tab(size_t y, size_t x)
{
	int				**tab;
	size_t			i;

	i = 0;
	if (!(tab = (int**)ft_memalloc(sizeof(int*) * (y))))
		return (NULL);
	while (i < y)
	{
		if (!(tab[i] = (int*)ft_memalloc(sizeof(int) * x)))
		{
			i++;
			while (i > 0)
			{
				free(tab[i - 2]);
				i--;
			}
			free(tab);
			return (NULL);
		}
		i++;
	}
	return (tab);
}
