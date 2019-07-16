/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_struct_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:50:02 by allefebv          #+#    #+#             */
/*   Updated: 2019/04/02 11:44:43 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_store_wc_field_width(t_conv_spec *conv_spec, va_list *ap)
{
	int	tmp;

	tmp = va_arg(*ap, int);
	if (tmp < 0)
	{
		conv_spec->flags[4] = 1;
		tmp = tmp * -1;
	}
	conv_spec->field_width = tmp;
}

void	ft_store_wc_precision(t_conv_spec *conv_spec, va_list *ap)
{
	conv_spec->precision = va_arg(*ap, int);
}

void	ft_store_field_width(t_conv_spec *conv_spec, char *format, int i,
							int len)
{
	while (len > 0)
	{
		if (format[i] >= '1' && format[i] <= '9' && format[i - 1] != '.')
		{
			conv_spec->field_width = 0;
			while (format[i] >= '0' && format[i] <= '9')
			{
				conv_spec->field_width =
				conv_spec->field_width * 10 + (format[i] - 48);
				i++;
				len--;
			}
			return ;
		}
		i++;
		len--;
	}
}

void	ft_store_precision(t_conv_spec *conv_spec, char *format, int i, int len)
{
	while (len > 0)
	{
		if (format[i] == '.')
		{
			conv_spec->precision = 0;
			i++;
			len--;
			while (format[i] >= '0' && format[i] <= '9')
			{
				conv_spec->precision =
				(conv_spec->precision * 10) + (format[i] - 48);
				i++;
				len--;
			}
			return ;
		}
		i++;
		len--;
	}
}
