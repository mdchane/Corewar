/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:02:37 by allefebv          #+#    #+#             */
/*   Updated: 2019/04/02 11:43:14 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_process_di(t_conv_spec conv_spec, va_list *ap)
{
	if (conv_spec.modifier[0] == 1)
		return (ft_itoa((char)va_arg(*ap, int)));
	if (conv_spec.modifier[1] == 1)
		return (ft_itoa((short)va_arg(*ap, int)));
	if (conv_spec.modifier[2] == 1)
		return (ft_itoa(va_arg(*ap, long)));
	if (conv_spec.modifier[3] == 1)
		return (ft_itoa(va_arg(*ap, long long)));
	return (ft_itoa(va_arg(*ap, int)));
}
