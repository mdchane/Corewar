/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_hash2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:20:36 by allefebv          #+#    #+#             */
/*   Updated: 2019/04/02 11:44:04 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_hash_xx_preci(char *str, int i)
{
	char	*tmp;

	tmp = NULL;
	if (i > 1)
	{
		str[i - 2] = '0';
		str[i - 1] = 'X';
	}
	else if (i == 1)
	{
		str[i - 1] = 'X';
		tmp = ft_strextend(ft_strdup("0"), str);
		free(str);
		str = tmp;
	}
	else
	{
		tmp = ft_strextend(ft_strdup("0X"), str);
		free(str);
		str = tmp;
	}
	return (str);
}

char	*ft_hash_xx_zero(char *str, int i)
{
	char	*tmp;

	tmp = NULL;
	if (i > 1)
	{
		str[0] = '0';
		str[1] = 'X';
	}
	else if (i == 1)
	{
		str[1] = 'X';
		tmp = ft_strextend(ft_strdup("0"), str);
		free(str);
		str = tmp;
	}
	else
	{
		tmp = ft_strextend(ft_strdup("0X"), str);
		free(str);
		str = tmp;
	}
	return (str);
}

char	*ft_hash_x_preci(char *str, int i)
{
	char	*tmp;

	tmp = NULL;
	if (i > 1)
	{
		str[i - 2] = '0';
		str[i - 1] = 'x';
	}
	else if (i == 1)
	{
		str[i - 1] = 'x';
		tmp = ft_strextend(ft_strdup("0"), str);
		free(str);
		str = tmp;
	}
	else
	{
		tmp = ft_strextend(ft_strdup("0x"), str);
		free(str);
		str = tmp;
	}
	return (str);
}

char	*ft_hash_x_zero(char *str, int i)
{
	char	*tmp;

	tmp = NULL;
	if (i > 1)
	{
		str[0] = '0';
		str[1] = 'x';
	}
	else if (i == 1)
	{
		str[1] = 'x';
		tmp = ft_strextend(ft_strdup("0"), str);
		free(str);
		str = tmp;
	}
	else
	{
		tmp = ft_strextend(ft_strdup("0x"), str);
		free(str);
		str = tmp;
	}
	return (str);
}
