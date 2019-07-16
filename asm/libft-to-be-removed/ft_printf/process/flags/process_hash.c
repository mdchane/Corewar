/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:20:36 by allefebv          #+#    #+#             */
/*   Updated: 2019/05/15 18:02:46 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_o_preci(char *str, int i)
{
	char	*tmp;

	tmp = NULL;
	if (str[i] == '0')
		return (str);
	else if (i > 1)
		str[i - 1] = '0';
	else
	{
		tmp = ft_strextend(ft_strdup("0"), str);
		free(str);
		str = tmp;
	}
	return (str);
}

static char	*ft_o_zero(char *str, int i)
{
	char	*tmp;

	tmp = NULL;
	if (str[0] == '0')
		return (str);
	else if (i > 1)
		str[i - 1] = '0';
	else
	{
		tmp = ft_strextend(ft_strdup("0"), str);
		free(str);
		str = tmp;
	}
	return (str);
}

static char	*ft_hash_zero(char *str, int i, t_conv_spec conv_spec)
{
	while (str[i] == '0')
		i++;
	if (str[i] == '\0' && conv_spec.conv_id != 'o')
		return (str);
	if (conv_spec.conv_id == 'x')
		str = ft_hash_x_zero(str, i);
	else if (conv_spec.conv_id == 'X')
		str = ft_hash_xx_zero(str, i);
	else if (conv_spec.conv_id == 'o')
		str = ft_o_zero(str, i);
	return (str);
}

static char	*ft_hash_preci(char *str, int i, t_conv_spec conv_spec)
{
	while (str[i] == ' ')
		i++;
	if (conv_spec.conv_id != 'o' && (str[i] == '\0'
			|| (str[i] == '0' && str[i + 1] == '\0')))
		return (str);
	if (conv_spec.conv_id == 'x')
		str = ft_hash_x_preci(str, i);
	else if (conv_spec.conv_id == 'X')
		str = ft_hash_xx_preci(str, i);
	else if (conv_spec.conv_id == 'o')
		str = ft_o_preci(str, i);
	return (str);
}

char		*ft_process_hash(t_conv_spec conv_spec, char *str)
{
	int	i;

	i = 0;
	if (conv_spec.precision != -1 || (conv_spec.precision == -1
			&& ((conv_spec.flags[2] == -1) || conv_spec.flags[4] == 1)))
		str = ft_hash_preci(str, i, conv_spec);
	else
		str = ft_hash_zero(str, i, conv_spec);
	return (str);
}
