/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ld_lld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:36:54 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/10 15:08:19 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_ld_common(t_process *p, t_vm *vm, char *name)
{
	int		ag1;
	int		ag2;
	int		jmp;
	t_args	ag[4];

	init_args(ag, p, vm);
	jmp = cw_ocp(2, ag, 4);
	if (ag[0].t == IND_CODE)
		ag1 = read_two(vm, p->pc + 2);
	if (ag[0].t != 0 && ag[0].t != REG_CODE && ag[1].t == REG_CODE
		&& (ag2 = check_reg(vm, p->pc + ag[1].i)))
	{
		if (ag[0].t == DIR_CODE)
			ag1 = read_four(vm, p->pc + 2);
		p->carry = (ag1 == 0) ? 1 : 0;
		if (ag[0].t == IND_CODE)
			ag1 = read_four(vm, p->pc + ((name[1] == 'd') ? (ag1 % IDX_MOD)
				: ag1));
		if (vm->args & AG_VERB && vm->verb & VB_OPS)
			ft_printf("P %4d | %s %d r%d\n", p->pid, name, ag1, ag2);
		p->regs[ag2] = ag1;
	}
	cw_move_pc(vm, p, jmp);
}

void	cw_ld(t_process *p, t_vm *vm)
{
	cw_ld_common(p, vm, "ld");
}

void	cw_lld(t_process *p, t_vm *vm)
{
	cw_ld_common(p, vm, "lld");
}
