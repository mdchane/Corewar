/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:51:43 by jfleury           #+#    #+#             */
/*   Updated: 2019/03/05 19:48:52 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long		ft_atoi_long(const char *str)
{
	long long		number;
	long long		c;
	long long		signe;

	number = 0;
	c = 0;
	signe = 0;
	while (str[c] != '\0' && (str[c] == '\t' || str[c] == '\n'
	|| str[c] == '\v' || str[c] == '\f' || str[c] == '\r' || str[c] == ' '))
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			signe = 1;
		c++;
	}
	while (str[c] != '\0' && (str[c] >= '0' && str[c] <= '9'))
	{
		number = ((number * 10) + (str[c] - 48));
		c++;
	}
	if (signe == 1)
		number = -number;
	return (number);
}
