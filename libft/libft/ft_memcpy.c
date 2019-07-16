/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:11:11 by jfleury           #+#    #+#             */
/*   Updated: 2018/11/13 18:25:47 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
		i++;
		n--;
	}
	return (dest);
}
