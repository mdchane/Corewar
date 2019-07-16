/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_token_label.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:03:27 by jfleury           #+#    #+#             */
/*   Updated: 2019/07/15 11:03:20 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_create_token_label(char *str, int type, t_token *token,
								t_label *label)
{
	if (type == 1)
	{
		label->contents = str;
		label->next = NULL;
	}
	token->type = type;
	token->line = g_nb_line;
	token->contents = str;
	token->next = NULL;
}
