/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:24:46 by mdchane           #+#    #+#             */
/*   Updated: 2019/07/16 15:35:23 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_parse_name(t_token *tk, t_header *head)
{
	if (!tk || !tk->contents)
		return (ft_printf("error: no champion name in the file\n") && 0);
	if (ft_strlen(tk->contents) > PROG_NAME_LENGTH + 2)
	{
		return (ft_printf("error: Champion name too long (Max length 128)\n")
			&& 0);
	}
	if (tk->next && tk->next->type != COMMENT)
	{
		return (ft_printf("error: syntax: Line %d: "
		"too mush arguments for champion name\n", tk->line) && 0);
	}
	ft_strcpy_1(head->prog_name, tk->contents);
	return (1);
}

int		ft_parse_champ_cmt(t_token *tk, t_header *head)
{
	if (!tk || !tk->contents)
		return (ft_printf("error: no champion comment in the file\n") && 0);
	if (ft_strlen(tk->contents) > COMMENT_LENGTH + 2)
	{
		return (ft_printf("error: Champion comment too long "
		"(Max length 2048)\n")
		&& 0);
	}
	if (tk->next && tk->next->type != COMMENT)
	{
		return (ft_printf("error: syntax: Line %d: "
		"too mush arguments for champion comment\n", tk->line) && 0);
	}
	ft_strcpy_1(head->comment, tk->contents);
	return (1);
}

int		parse_header(t_lst_tk **lst, t_header *head)
{
	while ((*lst) && (*lst)->token && (*lst)->token->type == COMMENT)
		(*lst) = (*lst)->next;
	if ((*lst) && (*lst)->token && (*lst)->token->type == COMMAND
		&& ft_strcmp((*lst)->token->contents, NAME_CMD_STRING) == 0)
	{
		if (!ft_parse_name((*lst)->token->next, head))
			return (0);
	}
	else
		return (ft_printf("error: no name in the file\n") && 0);
	(*lst) = (*lst)->next;
	while ((*lst) && (*lst)->token && (*lst)->token->type == COMMENT)
		(*lst) = (*lst)->next;
	if ((*lst) && (*lst)->token && (*lst)->token->type == COMMAND
		&& ft_strcmp((*lst)->token->contents, COMMENT_CMD_STRING) == 0)
	{
		if (!ft_parse_champ_cmt((*lst)->token->next, head))
			return (0);
	}
	else
		return (ft_printf("error: no champion comment in the file\n") && 0);
	(*lst) = (*lst)->next;
	return (1);
}
