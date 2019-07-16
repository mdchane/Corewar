/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_add_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:48:20 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/10 15:12:46 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	cw_math_common(t_vm *vm, t_process *p, t_args *ag, int *res)
{
	init_args(ag, p, vm);
	res[3] = cw_ocp(3, ag, 4);
	if (ag[0].t == REG_CODE && check_reg(vm, p->pc + 2)
		&& ag[1].t == REG_CODE && check_reg(vm, p->pc + 3)
		&& ag[2].t == REG_CODE && check_reg(vm, p->pc + 4))
	{
		res[0] = read_mem(vm, p->pc + 2);
		res[1] = read_mem(vm, p->pc + 3);
		res[2] = read_mem(vm, p->pc + 4);
		return (1);
	}
	return (0);
}

void	cw_add(t_process *p, t_vm *vm)
{
	t_args	ag[4];
	int		res[4];

	if (cw_math_common(vm, p, ag, res))
	{
		if (vm->args & AG_VERB && vm->verb & VB_OPS)
			ft_printf("P %4d | add r%d r%d r%d\n", p->pid, res[0], res[1]
				, res[2]);
		p->regs[res[2]] = p->regs[res[0]] + p->regs[res[1]];
		p->carry = (!p->regs[res[2]]) ? 1 : 0;
	}
	cw_move_pc(vm, p, res[3]);
}

void	cw_sub(t_process *p, t_vm *vm)
{
	t_args	ag[4];
	int		res[4];

	if (cw_math_common(vm, p, ag, res))
	{
		if (vm->args & AG_VERB && vm->verb & VB_OPS)
			ft_printf("P %4d | sub r%d r%d r%d\n", p->pid, res[0], res[1]
				, res[2]);
		p->regs[res[2]] = p->regs[res[0]] - p->regs[res[1]];
		p->carry = (!p->regs[res[2]]) ? 1 : 0;
	}
	cw_move_pc(vm, p, res[3]);
}
