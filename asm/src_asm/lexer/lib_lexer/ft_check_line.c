/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 11:24:43 by jfleury           #+#    #+#             */
/*   Updated: 2019/07/15 18:19:05 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_cal_state(char *line, int state)
{
	int		i;

	i = 0;
	state = 0;
	while (line[i] != 0)
	{
		if (line[i] == '"')
			state = state + 1;
		i++;
	}
	return (state);
}

static char		*ft_error_gnl(char *str, char *line, char *tmp)
{
	ft_strdel(&str);
	ft_strdel(&line);
	ft_strdel(&tmp);
	ft_printf("error: quote `\n");
	return (NULL);
}

char			*ft_check_line(char *line, int fd)
{
	char		*str;
	static char *tmp;
	int			i;
	int			state;

	i = 0;
	state = 0;
	state = ft_cal_state(line, state);
	while (state % 2 == 1)
	{
		if (get_next_line(fd, &str, &tmp) != 1)
			return (ft_error_gnl(str, line, tmp));
		if (!(line = ft_strextend(line, "\n")))
			return (NULL);
		if (!(line = ft_strextend(line, str)))
			return (NULL);
		ft_strdel(&str);
		g_nb_line++;
		g_nb_char = 0;
		state = ft_cal_state(line, state);
	}
	line = ft_strextend(line, "\n");
	return (line);
}
