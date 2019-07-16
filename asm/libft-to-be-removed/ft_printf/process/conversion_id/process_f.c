/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:30:04 by jfleury           #+#    #+#             */
/*   Updated: 2019/04/02 11:43:17 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_process_f(t_conv_spec conv_spec, va_list *ap)
{
	if (conv_spec.modifier[3] == 1)
		return (ft_itoa_double(conv_spec, va_arg(*ap, double)));
	if (conv_spec.modifier[4] == 1)
		return (ft_itoa_double(conv_spec, va_arg(*ap, long double)));
	return (ft_itoa_double(conv_spec, va_arg(*ap, double)));
}
