/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:36:44 by jfleury           #+#    #+#             */
/*   Updated: 2019/04/02 12:07:30 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_zero(t_conv_spec conv_spec, char *str)
{
	int		i;

	i = 2;
	str = ft_strnew(conv_spec.precision + 2);
	str[0] = '0';
	str[1] = '.';
	while (conv_spec.precision > 0)
	{
		str[i] = '0';
		conv_spec.precision--;
		i++;
	}
	return (str);
}

static char	*ft_place_point(t_conv_spec conv_spec, char *str)
{
	char	*final_str;
	int		i;

	if ((i = ft_strlen(str) - conv_spec.precision) <= 0)
	{
		free(str);
		return (ft_strdup("(error)"));
	}
	final_str = ft_strnew(ft_strlen(str) + 1);
	ft_strncpy(final_str, str, i);
	final_str[i] = '.';
	ft_strcat(final_str, str + i);
	free(str);
	return (final_str);
}

static char	*ft_process(t_conv_spec conv_spec, char *str, int flag,
						long double nb)
{
	long long				result;
	unsigned long long		power;

	if (conv_spec.precision > 16)
		conv_spec.precision = 16;
	power = ft_power(10, conv_spec.precision);
	result = nb * power;
	if (((nb * power * 10) - (result * 10)) > 5)
		result++;
	if (flag == 1)
		result = -result;
	str = ft_itoa(result);
	str = ft_place_point(conv_spec, str);
	return (str);
}

char		*ft_itoa_double(t_conv_spec conv_spec, long double nb)
{
	char					*str;
	int						flag;

	flag = 0;
	str = NULL;
	if (conv_spec.precision == -1)
		conv_spec.precision = 6;
	if (nb < 0)
	{
		flag = 1;
		nb = -nb;
	}
	if (nb == 0)
		str = ft_zero(conv_spec, str);
	else
		str = ft_process(conv_spec, str, flag, nb);
	return (str);
}
