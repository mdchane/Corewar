/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal_progsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:20:20 by jfleury           #+#    #+#             */
/*   Updated: 2019/07/13 15:26:28 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static unsigned char		*ft_resize(unsigned char *str, int size)
{
	int				len;
	int				i;
	int				j;
	unsigned char	*str2;

	i = 0;
	j = 0;
	len = ft_strlen((char*)str);
	if (!(str2 = malloc(sizeof(char) * (size * 2))))
		return (NULL);
	while (i < size * 2 - len)
	{
		str2[i] = '0';
		i++;
	}
	while (i < size * 2)
	{
		str2[i] = str[j];
		i++;
		j++;
	}
	free(str);
	return (str2);
}

static unsigned char		ft_atoi_hex(unsigned char *str)
{
	unsigned char		nb;

	if (str[0] >= '0' && str[0] <= '9')
		str[0] = str[0] - 48;
	if (str[1] >= '0' && str[1] <= '9')
		str[1] = str[1] - 48;
	if (str[0] >= 'a' && str[0] <= 'f')
		str[0] = str[0] - 87;
	if (str[1] >= 'a' && str[1] <= 'f')
		str[1] = str[1] - 87;
	if (str[0] != 0)
		nb = (str[0] * 16) + str[1];
	else
		nb = str[1];
	return (nb);
}

unsigned char				*ft_conv_hexa(int nbr, int size)
{
	unsigned char	*str;
	unsigned char	*final_str;
	int				len;

	if (!(final_str = (unsigned char*)ft_strnew(size)))
		return (NULL);
	if (size == 2)
		str = (unsigned char *)ft_itoa_base_short(nbr, 16);
	else
		str = (unsigned char *)ft_itoa_base_int(nbr, 16);
	len = ft_strlen((char*)str);
	if (len < size * 2)
		str = ft_resize(str, size);
	while (size * 2 > 0)
	{
		final_str[size - 1] = ft_atoi_hex(str + ((size * 2) - 2));
		size--;
	}
	ft_strdel((char **)&str);
	return (final_str);
}
