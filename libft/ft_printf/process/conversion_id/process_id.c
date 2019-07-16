/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:13:32 by allefebv          #+#    #+#             */
/*   Updated: 2019/04/02 11:43:20 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init_table(t_fptr_id *table)
{
	table->conv_id_tab = ft_strdup("cspdiouxXf%bD");
	table->fptr[0] = ft_process_c;
	table->fptr[1] = ft_process_s;
	table->fptr[2] = ft_process_p;
	table->fptr[3] = ft_process_di;
	table->fptr[4] = ft_process_di;
	table->fptr[5] = ft_process_o;
	table->fptr[6] = ft_process_u;
	table->fptr[7] = ft_process_x;
	table->fptr[8] = ft_process_xx;
	table->fptr[9] = ft_process_f;
	table->fptr[10] = ft_process_percent;
	table->fptr[11] = ft_process_b;
	table->fptr[12] = ft_process_dd;
}

char		*ft_process_id(t_conv_spec conv_spec, va_list *ap)
{
	t_fptr_id	*table;
	char		*str;
	int			i;

	i = 0;
	table = ft_memalloc(sizeof(*table));
	ft_init_table(table);
	while (i < CONV_ID_NB)
	{
		if (conv_spec.conv_id == table->conv_id_tab[i])
			str = table->fptr[i](conv_spec, ap);
		i++;
	}
	free(table->conv_id_tab);
	free(table);
	return (str);
}
