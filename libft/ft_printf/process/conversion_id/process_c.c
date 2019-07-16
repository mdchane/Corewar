/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:02:58 by allefebv          #+#    #+#             */
/*   Updated: 2019/04/02 11:43:07 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_process_c(t_conv_spec conv_spec, va_list *ap)
{
	char	c;
	char	*str;

	(void)conv_spec;
	c = va_arg(*ap, int);
	if (c == 0)
		c = -1;
	str = ft_strnew(1);
	str[0] = c;
	return (str);
}
