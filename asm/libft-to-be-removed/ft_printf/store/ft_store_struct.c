/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:06:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/04/02 11:44:46 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_store_conv_id(t_conv_spec *conv_spec, char *format, int i)
{
	char	*conv_id;
	int		j;
	int		tmp;
	int		len;

	conv_id = ft_data_conv_id();
	tmp = ft_strlen(conv_id) - 1;
	len = i;
	while (format[i] != '\0')
	{
		j = tmp;
		i++;
		while (j >= 0)
		{
			if (conv_id[j] == format[i])
			{
				conv_spec->conv_id = conv_id[j];
				free(conv_id);
				return (i - len);
			}
			j--;
		}
	}
	free(conv_id);
	return (0);
}

void	ft_store_modifier(t_conv_spec *conv_spec, char *format, int i, int len)
{
	conv_spec->modifier = (int *)ft_memalloc(sizeof(int) * 5);
	conv_spec->modifier[0] = 0;
	conv_spec->modifier[1] = 0;
	conv_spec->modifier[2] = 0;
	conv_spec->modifier[3] = 0;
	conv_spec->modifier[4] = 0;
	while (len > 0)
	{
		if (format[i] == 'h' && format[i + 1] == 'h')
			conv_spec->modifier[0] = 1;
		if (format[i] == 'h' && format[i + 1] != 'h' && format[i - 1] != 'h')
			conv_spec->modifier[1] = 1;
		if (format[i] == 'l' && format[i + 1] != 'l' && format[i - 1] != 'l')
			conv_spec->modifier[2] = 1;
		if (format[i] == 'l' && format[i + 1] == 'l')
			conv_spec->modifier[3] = 1;
		if (format[i] == 'L')
			conv_spec->modifier[4] = 1;
		i++;
		len--;
	}
}

void	ft_store_flag(t_conv_spec *conv_spec, char *format, int i, int len)
{
	int		j;
	int		x;

	j = 0;
	conv_spec->flags = (int *)ft_memalloc(sizeof(int) * FLAGS_NB);
	while (j < FLAGS_NB)
	{
		conv_spec->flags[j] = -1;
		j++;
	}
	j = i;
	x = j + len;
	if ((ft_strnchr(format + i, '+', len)) != NULL)
		conv_spec->flags[0] = 1;
	if ((ft_strnchr(format + i, ' ', len)) != NULL)
		conv_spec->flags[1] = 1;
	while (!(ft_isdigit(format[j])) && j < x)
		j++;
	if (format[j] == '0')
		conv_spec->flags[2] = 1;
	if ((ft_strnchr(format + i, '#', len)) != NULL)
		conv_spec->flags[3] = 1;
	if ((ft_strnchr(format + i, '-', len)) != NULL)
		conv_spec->flags[4] = 1;
}
