/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ldi_lldi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:43:31 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/16 14:20:24 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_ldi(t_process *p, char *name, int *arg)
{
	ft_printf("P %4d | %s %d %d r%d\n", \
				p->pid, name, arg[0], arg[1], arg[2]);
	if (name[1] == 'd')
		ft_printf("%7c| -> load from %d + %d = %d (with pc and mod %d)\n"
			, ' ', arg[0], arg[1], arg[4], arg[5]);
	else
		ft_printf("%7c| -> load from %d + %d = %d (with pc %d)\n"
			, ' ', arg[0], arg[1], arg[4], arg[5]);
}

int		cw_ldi_args(t_process *p, t_vm *vm, t_args *ag, int *arg)
{
	return (((ag[0].t == REG_CODE && (arg[0] = check_reg(vm, p->pc + 2)))
				|| (ag[0].t != 0 && ag[0].t != REG_CODE))
			&& ((ag[1].t == REG_CODE
				&& (arg[1] = check_reg(vm, p->pc + ag[1].i)))
				|| ag[1].t == DIR_CODE) && ag[2].t == REG_CODE
			&& (arg[2] = check_reg(vm, p->pc + ag[2].i)));
}

void	cw_ldi_common(t_process *p, t_vm *vm, char *n)
{
	t_args	ag[4];
	int		arg[6];

	init_args(ag, p, vm);
	arg[3] = cw_ocp(3, ag, 2);
	if (cw_ldi_args(p, vm, ag, arg))
	{
		if (ag[0].t == DIR_CODE)
			arg[0] = read_two(vm, p->pc + 2);
		else if (ag[0].t == IND_CODE)
			arg[0] = read_four(vm, p->pc + (read_two(vm, p->pc + 2) % IDX_MOD));
		else
			arg[0] = p->regs[arg[0]];
		if (ag[1].t == DIR_CODE)
			arg[1] = read_two(vm, p->pc + ag[1].i);
		else
			arg[1] = p->regs[arg[1]];
		arg[4] = arg[0] + arg[1];
		arg[5] = (n[1] != 'd') ? (p->pc + arg[4]) % MEM_SIZE
			: (p->pc + (arg[4] % IDX_MOD)) % MEM_SIZE;
		if (vm->args & AG_VERB && vm->verb & VB_OPS)
			print_ldi(p, n, arg);
		p->regs[arg[2]] = read_four(vm, arg[5]);
	}
	cw_move_pc(vm, p, arg[3]);
}

void	cw_ldi(t_process *p, t_vm *vm)
{
	cw_ldi_common(p, vm, "ldi");
}

void	cw_lldi(t_process *p, t_vm *vm)
{
	cw_ldi_common(p, vm, "lldi");
}
