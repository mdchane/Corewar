/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:50:20 by jfleury           #+#    #+#             */
/*   Updated: 2019/07/01 15:23:57 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_read(char *tmp, char **line, int fd, int *check_end)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		i;

	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		i = 0;
		buf[ret] = '\0';
		while (buf[i] != '\0' && buf[i] != '\n')
			i++;
		if (buf[i] == '\n')
		{
			if (!(*line = ft_strnextend(*line, buf, i)))
				return (NULL);
			ft_strcpy(tmp, buf + i + 1);
			return (tmp);
		}
		if (!(*line = ft_strextend(*line, buf)))
			return (NULL);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (!ret && **line == '\0')
		*check_end = 1;
	return (tmp);
}

char	*ft_checktmp(char *tmp, char **line, int *check_n)
{
	int			i;
	int			j;

	i = 0;
	if (tmp == NULL)
	{
		if (!(tmp = ft_strnew(BUFF_SIZE)))
			return (NULL);
	}
	while (tmp[i] != '\0' && tmp[i] != '\n')
	{
		line[0][i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		*check_n = 1;
	j = 0;
	while (tmp[i + j] != '\0')
		j++;
	ft_memmove(tmp, tmp + i + 1, j);
	ft_bzero(tmp + j, i + 1);
	return (tmp);
}

int		get_next_line(const int fd, char **line, char **tmp)
{
	char		buf[1];
	int			check_n;
	int			check_end;

	if (line == NULL || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (!(*line = ft_strnew(BUFF_SIZE)))
		*line = NULL;
	check_n = 0;
	check_end = 0;
	if (!(*tmp = ft_checktmp(*tmp, line, &check_n)))
		return (-1);
	if (check_n == 1)
		return (1);
	if (!(*tmp = ft_read(*tmp, line, fd, &check_end)))
		return (-1);
	if (check_end == 0)
		return (1);
	return (0);
}
