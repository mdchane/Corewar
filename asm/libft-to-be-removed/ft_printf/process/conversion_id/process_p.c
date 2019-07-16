/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:10:52 by jfleury           #+#    #+#             */
/*   Updated: 2019/04/02 11:43:28 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_process_p(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;
	char	*str2;

	(void)conv_spec;
	str = ft_itoa_base(va_arg(*ap, long long), 16);
	str2 = ft_strdup("0x");
	str2 = ft_strextend(str2, str);
	free(str);
	return (str2);
}
