/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_token_label.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:42:16 by jfleury           #+#    #+#             */
/*   Updated: 2019/07/15 12:56:53 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_append_label(t_label *label, t_label **list_label)
{
	t_label		*tmp_label;

	if (*list_label == NULL)
		*list_label = label;
	else
	{
		tmp_label = *list_label;
		while (tmp_label->next != NULL)
			tmp_label = tmp_label->next;
		tmp_label->next = label;
	}
}

void			ft_append_token_label(t_token *token, t_token **list_token,
								t_label *label, t_label **list_label)
{
	t_token		*tmp_token;

	if (*list_token == NULL)
		*list_token = token;
	else
	{
		tmp_token = *list_token;
		while (tmp_token->next != NULL)
			tmp_token = tmp_token->next;
		tmp_token->next = token;
		tmp_token->line = g_nb_line;
	}
	if (token->type == 1)
		ft_append_label(label, list_label);
	else
		free(label);
}
