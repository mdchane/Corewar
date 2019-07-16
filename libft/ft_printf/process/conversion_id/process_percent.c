/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:54:51 by allefebv          #+#    #+#             */
/*   Updated: 2019/04/02 11:43:32 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_process_percent(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;

	(void)conv_spec;
	(void)ap;
	str = ft_strdup("%");
	return (str);
}
