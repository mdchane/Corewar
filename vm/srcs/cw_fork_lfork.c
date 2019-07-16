/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_fork_lfork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:53:45 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/10 17:57:49 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_prcs_cpy(t_vm *vm, int *arg, t_process *p, t_process *new)
{
	new->op = 0;
	new->pid = vm->pid_ct++;
	new->new = 1;
	new->carry = p->carry;
	new->wait = 0;
	arg[2] = -1;
	while (++arg[2] <= REG_NUMBER)
		new->regs[arg[2]] = p->regs[arg[2]];
	new->pc = arg[1];
	new->lst_live = p->lst_live;
}

void	cw_fork_common(t_vm *vm, t_process *p, char *name)
{
	t_process	*new;
	int			arg[3];

	if ((new = (t_process*)ft_memalloc(sizeof(t_process))) == NULL)
	{
		ft_printf("Error at process init: %s\n", strerror(errno));
		destroy_ncurses(vm);
		clear_process(vm);
		exit(0);
	}
	arg[0] = read_two(vm, p->pc + 1);
	arg[1] = p->pc + ((name[0] == 'l') ? arg[0] : (arg[0] % IDX_MOD));
	if (vm->args & AG_VERB && vm->verb & VB_OPS)
		ft_printf("P %4d | %s %d (%d)\n", p->pid, name, arg[0], arg[1]);
	arg[1] = ft_mod(arg[1], MEM_SIZE);
	cw_prcs_cpy(vm, arg, p, new);
	new->next = vm->tl;
	vm->tl = new;
	vm->p_ct++;
	cw_move_pc(vm, p, 3);
}

void	cw_fork(t_process *p, t_vm *vm)
{
	cw_fork_common(vm, p, "fork");
}

void	cw_lfork(t_process *p, t_vm *vm)
{
	cw_fork_common(vm, p, "lfork");
}
