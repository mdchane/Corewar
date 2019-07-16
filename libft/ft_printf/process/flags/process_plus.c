/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:55:16 by allefebv          #+#    #+#             */
/*   Updated: 2019/04/02 11:44:10 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_str_c(char *str, char *start, char *end)
{
	ft_strcpy(str, start);
	ft_strcat(str, "+");
	ft_strcat(str, end);
}

char			*ft_process_plus(t_conv_spec conv_spec, char *str)
{
	int		i;
	char	*end;
	char	*start;

	i = 0;
	if (conv_spec.conv_id == 'd' || conv_spec.conv_id == 'i')
	{
		while (!(ft_isdigit(str[i])) && str[i] != '\0')
			i++;
		if (str[i] == '\0' || str[i - 1] == '-')
			return (str);
		else if (i != 0 && str[i - 1] == ' ')
			str[i - 1] = '+';
		else
		{
			start = ft_strsub(str, 0, i);
			end = ft_strsub(str, i, ft_strlen((str + i)));
			free(str);
			str = ft_strnew(ft_strlen(start) + ft_strlen(end) + 1);
			ft_str_c(str, start, end);
			free(end);
			free(start);
		}
	}
	return (str);
}
