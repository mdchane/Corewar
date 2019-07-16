/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:26:04 by allefebv          #+#    #+#             */
/*   Updated: 2019/05/15 19:49:43 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstadd_end(t_list **alst, t_list *elem)
{
	t_list *end;

	if (elem == NULL)
		return (0);
	if (*alst == NULL)
		ft_lstadd(alst, elem);
	else
	{
		end = *alst;
		while (end->next != NULL)
			end = end->next;
		end->next = elem;
		elem->next = NULL;
	}
	return (1);
}
