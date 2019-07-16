/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:48:23 by jfleury           #+#    #+#             */
/*   Updated: 2019/07/16 16:20:57 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_free_line(char **line, char **tmp)
{
	free(*line);
	free(*tmp);
	return (0);
}

static void		ft_free_error(t_token *token, t_label *label,
								t_token *list_token)
{
	t_token		*tmp;

	free(token);
	free(label);
	if (list_token != NULL)
	{
		while (list_token != NULL)
		{
			tmp = list_token->next;
			free(list_token->contents);
			free(list_token);
			list_token = tmp;
		}
	}
}

t_token			*ft_lexer_token(char **line, t_label **list_label)
{
	t_token		*token;
	t_label		*label;
	t_token		*list_token;
	int			nb_char_token;

	list_token = NULL;
	while ((*line)[0] != '\n' && (*line)[0] != 0)
	{
		if (!(token = malloc(sizeof(t_token))))
			return (NULL);
		if (!(label = malloc(sizeof(t_label))))
			return (NULL);
		nb_char_token = 0;
		if (!(ft_automaton(*line, token, label, &nb_char_token)))
		{
			ft_free_error(token, label, list_token);
			return (NULL);
		}
		ft_append_token_label(token, &list_token, label, list_label);
		if (!(line = ft_cut_line(line, nb_char_token)))
			break ;
	}
	return (list_token);
}

int				ft_lexer(t_lst_tk **list, t_label **list_label, char **argv)
{
	char		*line;
	int			fd;
	static char *tmp;

	fd = open(argv[1], O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line, &tmp) == 1)
	{
		g_nb_char = 0;
		g_nb_line++;
		if (!(line = ft_check_line(line, fd)))
			return (ft_free_line(&line, &tmp));
		if (!(ft_empty_line(line)))
		{
			free(line);
			continue ;
		}
		if (!(ft_append_lst_tk(ft_lexer_token(&line, list_label), list)))
			return (ft_free_line(&line, &tmp));
		free(line);
	}
	if (line != NULL)
		free(line);
	free(tmp);
	return (1);
}
