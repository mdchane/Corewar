/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_preci_diouxx.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:49:48 by jfleury           #+#    #+#             */
/*   Updated: 2019/04/02 11:44:27 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_minus(char *str, char *tmp, int *flag)
{
	if (*flag == 1)
	{
		tmp = ft_strdup("-");
		tmp = ft_strextend(tmp, str);
		free(str);
		str = tmp;
	}
	if (str[0] == '-' && *flag == 0)
	{
		*flag = 1;
		tmp = ft_strdup(str + 1);
		free(str);
		str = tmp;
	}
	return (str);
}

char		*ft_precision_diouxx(t_conv_spec conv_spec, char *str)
{
	int		i;
	int		j;
	int		flag;
	char	*tmp;

	flag = 0;
	tmp = NULL;
	str = ft_minus(str, tmp, &flag);
	i = ft_strlen(str);
	if (conv_spec.precision == 0 && str[0] == '0')
	{
		free(str);
		str = ft_strdup("");
	}
	else if (i < conv_spec.precision)
	{
		j = conv_spec.precision - i;
		tmp = ft_strnew(j);
		ft_memset(tmp, '0', j);
		tmp = ft_strextend(tmp, str);
		free(str);
		str = tmp;
	}
	str = ft_minus(str, tmp, &flag);
	return (str);
}
