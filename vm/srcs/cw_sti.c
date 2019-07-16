/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:46:59 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/15 23:59:22 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	cw_check_sti(t_process *p, t_vm *vm, t_args *ag, int *arg)
{
	return (ag[0].t == REG_CODE && (arg[0] = check_reg(vm, p->pc + 2))
		&& ((ag[1].t == REG_CODE && (arg[1] = check_reg(vm, p->pc + ag[1].i)))
			|| (ag[1].t != 0 && ag[1].t != REG_CODE))
		&& ((ag[2].t == REG_CODE && (arg[2] = check_reg(vm, p->pc + ag[2].i)))
			|| ag[2].t == DIR_CODE));
}

static void	cw_print_sti(t_process *p, int *arg)
{
	ft_printf("P %4d | sti r%d %d %d\n", p->pid, arg[0], arg[1], arg[2]);
	ft_printf("%7c| -> store to %d + %d = %d (with pc and mod %d)\n", ' '
		, arg[1], arg[2], arg[4], arg[5]);
}

void		cw_sti(t_process *p, t_vm *vm)
{
	t_args	ag[4];
	int		arg[6];

	init_args(ag, p, vm);
	arg[3] = cw_ocp(3, ag, 2);
	if (cw_check_sti(p, vm, ag, arg))
	{
		if (ag[1].t == REG_CODE)
			arg[1] = p->regs[arg[1]];
		else if (ag[1].t == IND_CODE)
			arg[1] = read_four(vm, p->pc + (read_two(vm, p->pc + 3) % IDX_MOD));
		else
			arg[1] = read_two(vm, p->pc + 3);
		if (ag[2].t == DIR_CODE)
			arg[2] = read_two(vm, p->pc + ag[2].i);
		else
			arg[2] = p->regs[arg[2]];
		arg[4] = arg[1] + arg[2];
		arg[5] = p->pc + (arg[4] % IDX_MOD);
		if (vm->args & AG_VERB && vm->verb & VB_OPS)
			cw_print_sti(p, arg);
		write_four(vm, ft_mod(arg[5], MEM_SIZE), p->regs[arg[0]], p->pc);
	}
	cw_move_pc(vm, p, arg[3]);
}
