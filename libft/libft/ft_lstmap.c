/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:20:50 by jfleury           #+#    #+#             */
/*   Updated: 2018/11/15 18:30:30 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*final_lst;
	t_list	*temp_lst;
	t_list	*new;

	if (lst == NULL || f == NULL)
		return (NULL);
	temp_lst = f(lst);
	if (!(new = ft_lstnew(temp_lst->content, temp_lst->content_size)))
		return (NULL);
	final_lst = new;
	lst = lst->next;
	while (lst)
	{
		temp_lst = f(lst);
		if (!(new->next = ft_lstnew(temp_lst->content, temp_lst->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (final_lst);
}
