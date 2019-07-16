/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atois.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:58:44 by tmaze             #+#    #+#             */
/*   Updated: 2019/06/19 15:23:42 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atois(const char *str, int *nb)
{
	int	num;

	num = 0;
	while (ft_iswhitespace(str[num]))
		num++;
	if (str[num] == '+' || str[num] == '-')
		num++;
	if (ft_strlen(&(str[num])) < 10 || (num > 0 && str[num - 1] == '-'
		&& ft_strcmp("2147483648", &(str[num])) >= 0)
		|| ft_strcmp("2147483647", &(str[num])) >= 0)
	{
		*nb = ft_atoi(str);
		return (0);
	}
	return (1);
}
