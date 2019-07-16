/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_lst_tk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 11:38:38 by jfleury           #+#    #+#             */
/*   Updated: 2019/07/01 11:22:10 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_lst_tk	*ft_create_lst_tk(t_token *token)
{
	t_lst_tk	*new;

	if (token == NULL)
		return (NULL);
	if (!(new = (t_lst_tk*)malloc(sizeof(t_lst_tk))))
		return (NULL);
	new->token = token;
	new->next = NULL;
	return (new);
}

int			ft_append_lst_tk(t_token *token, t_lst_tk **list)
{
	t_lst_tk		*begin;

	begin = *list;
	if (token == NULL)
		return (0);
	if (*list == NULL)
	{
		if (!(*list = ft_create_lst_tk(token)))
			return (1);
	}
	else
	{
		while ((*list)->next != NULL)
			*list = (*list)->next;
		if (!((*list)->next = ft_create_lst_tk(token)))
			return (1);
		*list = begin;
	}
	return (1);
}
