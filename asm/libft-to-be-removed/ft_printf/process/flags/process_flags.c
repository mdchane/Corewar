/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:02:32 by allefebv          #+#    #+#             */
/*   Updated: 2019/04/02 11:43:58 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init_table(t_fptr_flag *table)
{
	int		i;

	i = 0;
	table->flags = ft_memalloc(sizeof(int) * FLAGS_NB);
	while (i < FLAGS_NB)
	{
		table->flags[i] = 1;
		i++;
	}
	table->fptr[0] = &ft_process_plus;
	table->fptr[1] = &ft_process_space;
	table->fptr[2] = &ft_process_zero;
	table->fptr[3] = &ft_process_hash;
	table->fptr[4] = &ft_process_minus;
}

char		*ft_process_flags(t_conv_spec conv_spec, char *str)
{
	t_fptr_flag		*table;
	int				i;

	i = 0;
	table = ft_memalloc(sizeof(*table));
	ft_init_table(table);
	while (i < FLAGS_NB)
	{
		if (conv_spec.flags[i] == table->flags[i])
			str = table->fptr[i](conv_spec, str);
		i++;
	}
	free(table->flags);
	free(table);
	return (str);
}
