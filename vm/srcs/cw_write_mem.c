/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_write_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:31:10 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/13 17:17:08 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_mem(t_vm *vm, unsigned int index, char val, unsigned short int pc)
{
	vm->mem[ft_mod(index, MEM_SIZE)] = val;
	vm->col[index & MEM_SIZE_M] = vm->col[pc & MEM_SIZE_M];
}

void	write_four(t_vm *vm, unsigned int index, int val, unsigned short int pc)
{
	int	mask;
	int	i;

	mask = 0x000000FF;
	i = 0;
	while (i < 4)
	{
		write_mem(vm, (index + (3 - i)), (val & mask) >> (8 * i), pc);
		mask = mask << 8;
		i++;
	}
}
