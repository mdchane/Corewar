/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:38:01 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/14 14:10:52 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	cw_print_live(t_vm *vm, int j)
{
	if (vm->args & AG_VERB && vm->verb & VB_LIVE)
		ft_printf("Player %d (%s) is said to be alive\n", j + 1
			, vm->pls[j].prog_name);
	else if (!(vm->args & AG_VERB) && !(vm->args & AG_VISUAL))
		ft_printf("un processus dit que le joueur %d(%s) est en vie\n"
			, vm->pls[j].num, vm->pls[j].prog_name);
}

void		cw_live(t_process *p, t_vm *vm)
{
	int					pl;
	short int			j;
	unsigned short int	i;

	i = 0;
	pl = read_four(vm, p->pc + 1);
	j = 0;
	if (vm->args & AG_VERB && vm->verb & VB_OPS)
		ft_printf("P %4d | live %d\n", p->pid, pl);
	vm->live_ct++;
	p->lst_live = vm->cycles;
	while (j < vm->nb_j)
	{
		if (pl == vm->pls[j].num)
		{
			cw_print_live(vm, j);
			vm->pls[j].live_ct++;
			vm->pls[j].lst_live = vm->cycles;
			vm->live = pl;
			break ;
		}
		j++;
	}
	cw_move_pc(vm, p, 5);
}
