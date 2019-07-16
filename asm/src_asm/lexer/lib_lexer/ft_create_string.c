/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:57:44 by jfleury           #+#    #+#             */
/*   Updated: 2019/07/09 10:44:33 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*ft_cut_string(char *str)
{
	char	*str2;
	int		i;
	int		j;

	i = ft_strlen(str);
	j = 0;
	while (str[i - 1] == ' ' || str[i - 1] == '\t'
		|| str[i - 1] == '\v' || str[i - 1] == '\n')
		i--;
	if (!(str2 = ft_strnew(i + 1)))
		return (NULL);
	while (j < i)
	{
		str2[j] = str[j];
		j++;
	}
	free(str);
	str = str2;
	return (str);
}

char			*ft_create_string(char *line, int nb_char_token)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v')
		i++;
	if (!(str = ft_strnew(nb_char_token - i)))
		return (NULL);
	while (j <= nb_char_token - i - 1)
	{
		str[j] = line[j + i];
		j++;
	}
	str = ft_cut_string(str);
	return (str);
}
