/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:09:19 by jfleury           #+#    #+#             */
/*   Updated: 2018/11/13 18:00:31 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*temp_dest;
	char	*temp_src;
	int		i;

	temp_dest = (char*)dest;
	temp_src = (char*)src;
	i = 0;
	while (n > 0)
	{
		temp_dest[i] = temp_src[i];
		if (temp_src[i] == (char)c)
			return (dest + i + 1);
		i++;
		n--;
	}
	return (NULL);
}
