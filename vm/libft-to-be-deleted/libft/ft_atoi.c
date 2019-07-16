/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:46:25 by jfleury           #+#    #+#             */
/*   Updated: 2019/03/07 13:38:37 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		number;
	int		c;
	int		signe;

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
