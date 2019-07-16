/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:36:54 by allefebv          #+#    #+#             */
/*   Updated: 2019/04/02 11:44:08 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_process_minus(t_conv_spec conv_spec, char *str)
{
	int		size_space;
	int		size_num;

	size_space = 0;
	while (str[size_space] == ' ')
		size_space++;
	if (size_space != 0 && conv_spec.flags[1] == 1 && conv_spec.flags[0] == -1)
		size_space--;
	size_num = ft_strlen(str + size_space);
	ft_memmove(str, str + size_space, size_num);
	ft_memset(str + size_num, ' ', size_space);
	return (str);
}
