/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:53:27 by jfleury           #+#    #+#             */
/*   Updated: 2019/07/09 10:44:50 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_check_line2(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\v')
			return (1);
		i++;
	}
	return (0);
}

char			**ft_cut_line(char **line, int nb_char_token)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = ft_strlen(*line);
	if (len < 1 || len == nb_char_token)
		return (NULL);
	if (!(str = ft_strnew(len - nb_char_token + 1)))
		return (NULL);
	while ((*line)[i + nb_char_token] != 0)
	{
		str[i] = (*line)[nb_char_token + i];
		i++;
	}
	if (!(ft_check_line2(str)))
	{
		free(str);
		return (NULL);
	}
	free(*line);
	*line = str;
	return (line);
}
