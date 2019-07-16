/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnextend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:16:19 by jfleury           #+#    #+#             */
/*   Updated: 2018/11/21 11:42:05 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnextend(char *s1, char const *s2, size_t len)
{
	char	*tmp;
	int		i;

	if (!(s1) || !(s2))
		return (NULL);
	if (len < ft_strlen(s2))
		i = ft_strlen(s1) + len;
	else
		i = ft_strlen(s1) + ft_strlen(s2);
	tmp = s1;
	if (!(s1 = (char*)malloc(sizeof(s1) * (i + 1))))
		return (NULL);
	ft_strcpy(s1, tmp);
	ft_strncat(s1, s2, len);
	free(tmp);
	return (s1);
}
