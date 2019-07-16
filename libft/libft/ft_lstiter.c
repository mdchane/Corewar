/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:11:41 by jfleury           #+#    #+#             */
/*   Updated: 2018/11/16 14:37:53 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*temp_lst;
	t_list	*temp_next;

	temp_lst = lst;
	while (temp_lst)
	{
		temp_next = temp_lst->next;
		f(temp_lst);
		temp_lst = temp_next;
	}
}
