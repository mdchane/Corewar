/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:34:08 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/23 15:07:35 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_power(unsigned long long nb, int power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	if (power > 0)
		return (nb * ft_power(nb, power - 1));
	else
		return (0);
}
