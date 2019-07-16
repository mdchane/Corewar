/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:40:53 by tmaze             #+#    #+#             */
/*   Updated: 2019/06/27 11:07:38 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	cw_st_check_args(t_vm *vm, t_process *p, t_args *ag, int *arg)
{
	return (ag[0].t == REG_CODE && (arg[0] = check_reg(vm, p->pc + 2))
		&& ((ag[1].t == REG_CODE && (arg[1] = check_reg(vm, p->pc + 3)))
			|| ag[1].t == IND_CODE));
}

void	cw_st(t_process *p, t_vm *vm)
{
	int			arg[3];
	t_args		ag[4];

	init_args(ag, p, vm);
	arg[2] = cw_ocp(2, ag, 4);
	arg[0] = 0;
	if (cw_st_check_args(vm, p, ag, arg))
	{
		if (ag[1].t == IND_CODE)
			arg[1] = read_two(vm, p->pc + 3);
		if (vm->verb != -1 && vm->verb & VB_OPS)
			ft_printf("P %4d | st r%d %d\n", p->pid, arg[0], arg[1]);
		if (ag[1].t == REG_CODE)
			p->regs[arg[1]] = p->regs[arg[0]];
		else
			write_four(vm, p->pc + (arg[1] % IDX_MOD), p->regs[arg[0]], p->pc);
	}
	cw_move_pc(vm, p, arg[2]);
}
