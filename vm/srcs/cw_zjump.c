/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_zjump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:57:44 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/10 15:05:17 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_zjump(t_process *p, t_vm *vm)
{
	int	ind;

	ind = read_two(vm, p->pc + 1);
	if (vm->args & AG_VERB && vm->verb & VB_OPS)
		ft_printf("P %4d | zjmp %d %s\n", p->pid, ind
		, (p->carry) ? "OK" : "FAILED");
	if (p->carry)
		p->pc = ft_mod(p->pc + (read_two(vm, p->pc + 1) % IDX_MOD), MEM_SIZE);
	else
		cw_move_pc(vm, p, 3);
}
