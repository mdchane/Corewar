/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strextend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:15:30 by jfleury           #+#    #+#             */
/*   Updated: 2018/11/21 11:41:42 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strextend(char *s1, char const *s2)
{
	char	*str;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	str = s1;
	if (!(s1 = (char*)malloc(sizeof(s1) * i + 1)))
		return (NULL);
	ft_strcpy(s1, str);
	ft_strcat(s1, s2);
	free(str);
	return (s1);
}
