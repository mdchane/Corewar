/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:33:47 by allefebv          #+#    #+#             */
/*   Updated: 2019/04/02 12:09:00 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*strcpy;

	if (ft_strlen(s) > len)
	{
		if (!(strcpy = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ft_strncpy(strcpy, s, len);
	}
	else
	{
		if (!(strcpy = ft_strdup(s)))
			return (NULL);
	}
	return (strcpy);
}
