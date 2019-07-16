/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:48:50 by jfleury           #+#    #+#             */
/*   Updated: 2019/07/04 12:07:25 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_bin(char *str)
{
	int		j;
	int		bin;
	int		result;

	j = ft_strlen(str) - 1;
	result = 0;
	bin = 1;
	while (j >= 0)
	{
		if (str[j] == '1')
			result = result + bin;
		bin = bin * 2;
		j--;
	}
	return (result);
}
