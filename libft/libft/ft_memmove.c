/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:55:12 by jfleury           #+#    #+#             */
/*   Updated: 2018/11/13 18:45:16 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			i;

	temp_dest = (unsigned char*)dest;
	temp_src = (unsigned char*)src;
	i = n;
	if (temp_dest > temp_src)
		while (n)
		{
			temp_dest[n - 1] = temp_src[n - 1];
			n--;
		}
	else
		ft_memcpy(temp_dest, temp_src, i);
	return (dest);
}
