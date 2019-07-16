/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:55:16 by jfleury           #+#    #+#             */
/*   Updated: 2019/03/12 13:55:19 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	**ft_sstrcpy(char **dest, char const **src)
{
	while (*src != 0 && *dest != 0)
	{
		ft_strcpy(*dest, *src);
		src++;
		dest++;
	}
	return (dest);
}
