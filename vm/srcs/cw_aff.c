/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:58:20 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/10 17:23:37 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_aff(t_process *p, t_vm *vm)
{
	t_args	ag[4];
	int		jmp;
	int		val;
	char	c;

	init_args(ag, p, vm);
	jmp = cw_ocp(1, ag, 4);
	if (ag[0].t == REG_CODE && check_reg(vm, p->pc + 2))
	{
		val = p->regs[read_mem(vm, p->pc + 2)];
		if (vm->args & AG_VERB && vm->verb & VB_OPS)
			ft_printf("P %4d | aff %d\n", p->pid, val);
		c = val % 256;
		p->carry = (!c) ? 1 : 0;
		if (vm->args & AG_AFF)
			ft_printf("Aff: %c\n", c);
	}
	cw_move_pc(vm, p, jmp);
}
