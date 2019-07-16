/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_read_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:30:46 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/04 23:04:16 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char	read_mem(t_vm *vm, int ind)
{
	return (vm->mem[ft_mod(ind, MEM_SIZE)]);
}

int				read_four(t_vm *vm, size_t index)
{
	int	i;
	int	ret;

	i = -1;
	while (++i < 4)
		ret = ret << 8 | read_mem(vm, index + i);
	return (ret);
}

short int		read_two(t_vm *vm, size_t index)
{
	int			i;
	short int	ret;

	i = -1;
	ret = 0;
	while (++i < 2)
		ret = ret << 8 | read_mem(vm, index + i);
	return (ret);
}
