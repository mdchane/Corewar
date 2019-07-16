/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 17:08:25 by mdchane           #+#    #+#             */
/*   Updated: 2019/07/13 17:14:11 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned char	*ft_strextend_nm(unsigned char *s1,
	char unsigned *s2, int n, int m)
{
	unsigned char	*str;
	int				i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = n + m;
	if (!(str = (unsigned char *)malloc(sizeof(*str) * i + 1)))
		return (NULL);
	ft_strcpy_n(str, s1, 0, n);
	ft_strcpy_n(str, s2, n, m);
	ft_strdel((char **)&s1);
	ft_strdel((char **)&s2);
	return (str);
}

int				ft_tklen(t_token *tk)
{
	int	i;

	i = 0;
	if (!tk)
		return (0);
	while (tk)
	{
		i++;
		tk = tk->next;
	}
	return (i);
}

unsigned char	*ft_strcpy_n(unsigned char *dest,
	const unsigned char *src, int n, int m)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
		i++;
	j = 0;
	while (j < m)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);
}

char			*ft_strnew_1(size_t size)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(str, '0', size);
	str[size] = '\0';
	return (str);
}

char			*ft_strcpy_1(char *dest, const char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
	{
		if (src[j] != '"')
		{
			dest[i] = src[j];
			i++;
		}
		j++;
	}
	return (dest);
}
