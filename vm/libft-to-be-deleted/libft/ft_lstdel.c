/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:54:50 by jfleury           #+#    #+#             */
/*   Updated: 2018/11/15 18:31:58 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*temp_alst;
	t_list	*temp_next;

	temp_alst = *alst;
	while (temp_alst)
	{
		temp_next = temp_alst->next;
		del(temp_alst->content, temp_alst->content_size);
		free(temp_alst);
		temp_alst = temp_next;
	}
	*alst = NULL;
}
