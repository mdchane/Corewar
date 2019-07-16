/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:04:55 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/24 13:04:59 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_exp_dec(unsigned int value)
{
	int exponent;

	exponent = 0;
	if (value >= 10000 && (value /= 10000))
		exponent += 4;
	if (value >= 1000 && (value /= 1000))
		exponent += 3;
	if (value >= 100 && (value /= 100))
		exponent += 2;
	if (value >= 10 && (value /= 10))
		exponent += 1;
	return (exponent);
}
