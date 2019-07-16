/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_and_or_xor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:52:19 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/10 15:09:34 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	cw_logic_check_args(t_vm *vm, t_process *p, t_args *ag)
{
	return (((ag[0].t != 0 && ag[0].t != REG_CODE)
			|| (ag[0].t == REG_CODE && check_reg(vm, p->pc + 2)))
		&& ((ag[1].t != 0 && ag[1].t != REG_CODE)
			|| (ag[1].t == REG_CODE && check_reg(vm, p->pc + ag[1].i)))
		&& ag[1].t != 0 && ag[2].t == REG_CODE
		&& check_reg(vm, p->pc + ag[2].i));
}

char	cw_logic_common(t_vm *vm, t_process *p, t_args *ag, int *res)
{
	init_args(ag, p, vm);
	res[3] = cw_ocp(3, ag, 4);
	if (cw_logic_check_args(vm, p, ag))
	{
		if (ag[0].t == IND_CODE)
			res[0] = read_four(vm, p->pc + (read_two(vm, p->pc + 2) % IDX_MOD));
		else if (ag[0].t == DIR_CODE)
			res[0] = read_four(vm, p->pc + 2);
		else
			res[0] = p->regs[read_mem(vm, p->pc + 2)];
		if (ag[1].t == IND_CODE)
			res[1] = read_four(vm, p->pc + (read_two(vm, p->pc + ag[1].i)
				% IDX_MOD));
		else if (ag[1].t == DIR_CODE)
			res[1] = read_four(vm, p->pc + ag[1].i);
		else
			res[1] = p->regs[read_mem(vm, p->pc + ag[1].i)];
		res[2] = read_mem(vm, p->pc + ag[2].i);
		return (1);
	}
	return (0);
}

void	cw_and(t_process *p, t_vm *vm)
{
	t_args	ag[4];
	int		res[4];

	if (cw_logic_common(vm, p, ag, res))
	{
		if (vm->args & AG_VERB && vm->verb & VB_OPS)
			ft_printf("P %4d | and %d %d r%d\n", p->pid, res[0], res[1]
				, res[2]);
		p->regs[res[2]] = res[0] & res[1];
		p->carry = (!p->regs[res[2]]) ? 1 : 0;
	}
	cw_move_pc(vm, p, res[3]);
}

void	cw_or(t_process *p, t_vm *vm)
{
	t_args	ag[4];
	int		res[4];

	if (cw_logic_common(vm, p, ag, res))
	{
		if (vm->args & AG_VERB && vm->verb & VB_OPS)
			ft_printf("P %4d | or %d %d r%d\n", p->pid, res[0], res[1]
				, res[2]);
		p->regs[res[2]] = res[0] | res[1];
		p->carry = (!p->regs[res[2]]) ? 1 : 0;
	}
	cw_move_pc(vm, p, res[3]);
}

void	cw_xor(t_process *p, t_vm *vm)
{
	t_args	ag[4];
	int		res[4];

	if (cw_logic_common(vm, p, ag, res))
	{
		if (vm->args & AG_VERB && vm->verb & VB_OPS)
			ft_printf("P %4d | xor %d %d r%d\n", p->pid, res[0], res[1]
				, res[2]);
		p->regs[res[2]] = res[0] ^ res[1];
		p->carry = (!p->regs[res[2]]) ? 1 : 0;
	}
	cw_move_pc(vm, p, res[3]);
}
