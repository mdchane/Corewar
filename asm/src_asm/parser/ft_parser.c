/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:48:19 by jfleury           #+#    #+#             */
/*   Updated: 2019/07/16 12:23:55 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_label_pos(t_label *label, char *tk_lab, int size)
{
	while (label)
	{
		if (ft_strequ(label->contents, tk_lab))
		{
			label->place = size;
		}
		label = label->next;
	}
}

void		init_label(t_label *label)
{
	while (label)
	{
		label->contents[ft_strlen(label->contents) - 1] = '\0';
		label = label->next;
	}
}

int			ft_parse_label(t_label *label, t_token *token, unsigned int *size)
{
	ft_label_pos(label, token->contents, *size);
	if (!token->next || token->next->type == COMMENT)
		return (1);
	else if (!ft_parse_instruct(token->next, label, size))
		return (0);
	return (1);
}

int			ft_parser(t_lst_tk *lst, t_label *label, t_header *head)
{
	unsigned int	size;

	init_label(label);
	size = 0;
	if (!parse_header(&lst, head))
		return (0);
	while (lst)
	{
		if (lst->token->type == INSTRUCTION)
		{
			if (!ft_parse_instruct(lst->token, label, &size))
				return (0);
		}
		else if (lst->token->type == LABEL)
		{
			if (!(ft_parse_label(label, lst->token, &size)))
				return (0);
		}
		else if (lst->token->type != COMMENT)
			return (0);
		lst = lst->next;
	}
	if ((head->prog_size = size) == 0)
		return (ft_printf("error: no instruction in the file\n") && 0);
	return (1);
}
