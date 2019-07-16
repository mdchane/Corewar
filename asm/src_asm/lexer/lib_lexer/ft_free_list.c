/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:04:41 by jfleury           #+#    #+#             */
/*   Updated: 2019/07/13 15:11:14 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_free_token(t_token *token)
{
	t_token		*tmp;

	tmp = NULL;
	while (token != NULL)
	{
		tmp = token->next;
		ft_strdel(&token->contents);
		free(token);
		token = tmp;
	}
}

static void		ft_free_label(t_label *label)
{
	t_label		*tmp;

	tmp = NULL;
	while (label != NULL)
	{
		tmp = label->next;
		free(label);
		label = tmp;
	}
}

void			ft_free_list(t_lst_tk *list, t_label *label)
{
	t_lst_tk	*tmp;

	tmp = NULL;
	while (list != NULL)
	{
		tmp = list->next;
		ft_free_token(list->token);
		free(list);
		list = tmp;
	}
	ft_free_label(label);
}

void			ft_free_all(t_lst_tk *list, t_label *label, t_header *head)
{
	if (head)
		free(head);
	ft_free_list(list, label);
}
