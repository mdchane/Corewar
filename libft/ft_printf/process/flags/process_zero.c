/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:16:02 by allefebv          #+#    #+#             */
/*   Updated: 2019/05/15 17:59:20 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_zero_p(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
	{
		str[i] = '0';
		i++;
	}
	if (i > 0)
	{
		str[1] = 'x';
		str[i + 1] = '0';
	}
	return (str);
}

static char	*ft_process_zero_cont(t_conv_spec conv_spec, char *str, int i)
{
	char	*tmp;

	if (conv_spec.conv_id == 'p')
		str = ft_zero_p(str);
	else
	{
		while (str[i] == ' ')
		{
			str[i] = '0';
			i++;
		}
		if (((ft_strchr(str, '+')) || (ft_strchr(str, '-'))) && i != 0)
		{
			tmp = ft_strnew(ft_strlen(str));
			ft_strncpy(tmp, str + i, 1);
			ft_strncat(tmp, str, i);
			ft_strcat(tmp, str + i + 1);
			free(str);
			str = tmp;
		}
	}
	return (str);
}

char		*ft_process_zero(t_conv_spec conv_spec, char *str)
{
	int		i;

	if ((conv_spec.precision > -1 && (conv_spec.conv_id != 'c'
		&& conv_spec.conv_id != 's' && conv_spec.conv_id != '%'))
		|| conv_spec.flags[4] == 1)
		return (str);
	i = 0;
	if (conv_spec.flags[1] == 1 && conv_spec.flags[0] == -1 && str[i] != '-'
		&& (conv_spec.conv_id == 'd' || conv_spec.conv_id == 'i'))
		i++;
	str = ft_process_zero_cont(conv_spec, str, i);
	return (str);
}
