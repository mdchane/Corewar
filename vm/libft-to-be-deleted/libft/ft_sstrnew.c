/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:51:04 by jfleury           #+#    #+#             */
/*   Updated: 2019/03/12 13:51:06 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sstrnew(size_t y, size_t x)
{
	char	**str;
	size_t	i;

	i = 0;
	if (!(str = (char**)ft_memalloc(y + 1)))
		return (NULL);
	while (i < y)
	{
		str[i] = ft_strnew(x);
		i++;
	}
	str[y] = 0;
	return (str);
}
