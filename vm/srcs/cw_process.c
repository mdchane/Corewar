/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:46:19 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/16 17:30:57 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	clear_process(t_vm *vm)
{
	t_process	*tmp;

	while (vm->tl)
	{
		tmp = vm->tl;
		vm->tl = tmp->next;
		ft_memdel((void**)&tmp);
	}
}

void	init_process(t_vm *vm)
{
	t_process	*new;
	short int	i;

	i = -1;
	while (++i < vm->nb_j)
	{
		if ((new = (t_process*)ft_memalloc(sizeof(t_process))) == NULL)
		{
			ft_printf("Error at process init: %s\n", strerror(errno));
			clear_process(vm);
			exit(2);
		}
		new->op = 0;
		new->pid = vm->pid_ct++;
		new->new = 1;
		new->carry = 0;
		new->wait = 0;
		ft_bzero(new->regs, (REG_NUMBER + 1) * REG_SIZE);
		new->pc = (MEM_SIZE / vm->nb_j) * i;
		new->regs[1] = vm->pls[i].num;
		new->lst_live = 0;
		new->next = vm->tl;
		vm->tl = new;
		vm->p_ct++;
	}
}

void	del_prcs_start(t_vm *vm)
{
	t_process	*tmp;

	while (vm->tl && (vm->cycles - vm->tl->lst_live) >= vm->ctd)
	{
		if (vm->verb != -1 && vm->verb & VB_DEATH)
			ft_printf("Process %d hasn't lived for %lu cycles (CTD %d)\n",
				vm->tl->pid, vm->cycles - vm->tl->lst_live, vm->ctd);
		tmp = vm->tl;
		vm->tl = vm->tl->next;
		ft_memdel((void**)&tmp);
		vm->p_ct--;
	}
}

void	del_prcs_mid(t_vm *vm)
{
	t_process	*it;
	t_process	*tmp;

	it = vm->tl;
	while (it && it->next)
	{
		if ((vm->cycles - it->next->lst_live) >= vm->ctd)
		{
			if (vm->verb != -1 && vm->verb & VB_DEATH)
				ft_printf("Process %d hasn't lived for %lu cycles (CTD %d)\n",
					it->next->pid, vm->cycles - it->next->lst_live, vm->ctd);
			tmp = it->next;
			it->next = it->next->next;
			ft_memdel((void**)&tmp);
			vm->p_ct--;
		}
		else
			it = it->next;
	}
}

void	del_prcs(t_vm *vm)
{
	static int	nb_checks = 0;
	int			i;

	del_prcs_start(vm);
	del_prcs_mid(vm);
	nb_checks++;
	vm->ctd_c = 0;
	if (vm->live_ct >= NBR_LIVE || nb_checks == MAX_CHECKS - 1)
	{
		vm->ctd -= CYCLE_DELTA;
		nb_checks = 0;
		if (vm->verb != -1 && vm->verb & VB_CYCLES)
			ft_printf("Cycle to die is now %d\n", vm->ctd);
	}
	vm->live_ct = 0;
	i = -1;
	while (++i < vm->nb_j)
		vm->pls[i].live_ct = 0;
}
