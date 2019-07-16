/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_preci_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:06:14 by jfleury           #+#    #+#             */
/*   Updated: 2019/04/02 11:44:35 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_precision_s(t_conv_spec conv_spec, char *str)
{
	char	*str2;

	if (conv_spec.precision < 0)
		return (str);
	str2 = ft_strnew(conv_spec.precision);
	ft_strncat(str2, str, conv_spec.precision);
	free(str);
	return (str2);
}
