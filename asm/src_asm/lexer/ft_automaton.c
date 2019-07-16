/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_automaton.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:48:26 by jfleury           #+#    #+#             */
/*   Updated: 2019/07/16 14:30:23 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_cal_i_string(int i_matrice, char *line, int *nb_char_token)
{
	int		i_string;

	i_string = 0;
	if (line[*nb_char_token] == 0
		|| (i_matrice == 21 && line[*nb_char_token] != '\n'))
		i_string = 16;
	else
		while (!(ft_line_strchr(g_string_automaton[i_string],
			line[*nb_char_token])) && i_string < 15)
			i_string++;
	return (i_string);
}

static int		ft_end_error(int *nb_char_token, char *line)
{
	g_nb_char = g_nb_char + *nb_char_token;
	ft_printf("error: syntax %d:%d char: %c\n",
		g_nb_line, g_nb_char + 1, line[*nb_char_token]);
	return (0);
}

int				ft_automaton(char *line, t_token *token, t_label *label,
				int *nb_char_token)
{
	int		i_matrice;
	int		i_string;
	int		type;

	i_matrice = 0;
	while (1)
	{
		type = i_matrice;
		i_string = ft_cal_i_string(i_matrice, line, nb_char_token);
		i_matrice = g_matrice_automaton[i_matrice][i_string];
		if (i_matrice == -2 || i_matrice == -3)
		{
			if (i_matrice == -3)
				*nb_char_token = *nb_char_token - 1;
			g_nb_char = g_nb_char + *nb_char_token;
			ft_create_token_label(ft_create_string(line, *nb_char_token),
													type, token, label);
			return (1);
		}
		else if (i_matrice == -1)
			return (ft_end_error(nb_char_token, line));
		else
			*nb_char_token = *nb_char_token + 1;
	}
}
