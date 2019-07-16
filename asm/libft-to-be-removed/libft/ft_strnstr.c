/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:44:35 by jfleury           #+#    #+#             */
/*   Updated: 2018/11/15 17:19:56 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s1[i] == s2[j] && s2[j] != 0 && s1[i] != 0 && i < n)
		{
			i++;
			j++;
		}
		if (s2[j] == 0)
			return ((char*)s1 + i - j);
		if (j == 0)
			i++;
		else
			i = i - j + 1;
	}
	return (NULL);
}
