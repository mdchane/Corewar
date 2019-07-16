/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:09:29 by jfleury           #+#    #+#             */
/*   Updated: 2018/11/13 18:00:43 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp_s;
	unsigned char	temp_c;
	int				i;

	temp_s = (unsigned char*)s;
	temp_c = (unsigned char)c;
	i = 0;
	while (n > 0)
	{
		if (temp_s[i] == temp_c)
			return (temp_s + i);
		i++;
		n--;
	}
	return (NULL);
}
