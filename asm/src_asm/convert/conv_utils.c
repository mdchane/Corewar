/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:17:14 by mdchane           #+#    #+#             */
/*   Updated: 2019/07/11 13:28:14 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label		*get_label(t_token *tk, t_label *label)
{
	char	*name;

	if (tk->type == INDIRECT_LABEL)
		name = ft_strdup(tk->contents + 1);
	else if (tk->type == DIRECT_LABEL)
		name = ft_strdup(tk->contents + 2);
	else
		return (NULL);
	while (label)
	{
		if (ft_strequ(label->contents, name))
		{
			ft_strdel(&name);
			return (label);
		}
		label = label->next;
	}
	ft_strdel(&name);
	return (NULL);
}
