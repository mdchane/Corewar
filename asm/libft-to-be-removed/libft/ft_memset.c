/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:17:24 by jfleury           #+#    #+#             */
/*   Updated: 2018/11/13 18:25:45 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;
	int				i;

	i = 0;
	temp = (unsigned char*)s;
	while (n > 0)
	{
		temp[i] = c;
		i++;
		n--;
	}
	return (s);
}
