/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:54:57 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/16 17:44:18 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void					cw_intro(t_vm *vm)
{
	short int	i;

	ft_printf("Introducing contestants...\n");
	i = 0;
	while (i < vm->nb_j)
	{
		ft_printf("* Player %hd, weighing %d bytes, \"%s\" (\"%s\") !\n"
			, i + 1, vm->pls[i].prog_size, vm->pls[i].prog_name
			, vm->pls[i].comment);
		i++;
	}
}

static void				corewar_run(t_vm *vm, t_process *it)
{
	static t_ops	ops[16] = {{10, &cw_live}, {5, &cw_ld}, {5, &cw_st}
					, {10, &cw_add}, {10, &cw_sub}, {6, &cw_and}, {6, &cw_or}
					, {6, &cw_xor}, {20, &cw_zjump}, {25, &cw_ldi}
					, {25, &cw_sti}, {800, &cw_fork}, {10, &cw_lld}
					, {50, &cw_lldi}, {1000, &cw_lfork}, {2, &cw_aff}};

	while (it)
	{
		print_pc(vm, it->pc, vm->col[it->pc]);
		if (it->wait)
		{
			it->wait--;
			if (it->wait == 0)
				ops[it->op - 1].func(it, vm);
		}
		else if (vm->mem[it->pc] > 0 && vm->mem[it->pc] < 17)
		{
			it->op = vm->mem[it->pc];
			it->wait = ops[it->op - 1].wait - 1;
		}
		else
			it->pc = (it->pc + 1) % MEM_SIZE;
		if (it)
			it = it->next;
	}
}

static void				corewar(t_vm *vm)
{
	init_ncurses(vm);
	while (vm->tl && (!(vm->args & (AG_DUMP32 | AG_DUMP64))
						|| vm->cycles < vm->dump))
	{
		print_arena(vm);
		vm->cycles++;
		vm->ctd_c++;
		if (vm->args & AG_VERB && vm->verb & VB_CYCLES)
			ft_printf("It is now cycle %d\n", vm->cycles);
		corewar_run(vm, vm->tl);
		wrefresh(vm->vis.arena);
		if (vm->ctd_c == vm->ctd || vm->ctd <= 0)
			del_prcs(vm);
		control_delay(vm);
	}
	if (!vm->tl)
		vm->args &= ~(AG_DUMP32 & AG_DUMP64);
}

static void				cw_print_win(t_vm *vm, int i)
{
	if (vm->args & AG_VISUAL)
		visual_winners(vm, i);
	else if (vm->args & AG_VERB)
		ft_printf("Contestant %lu, \"%s\", has won !\n", i + 1
			, vm->pls[i].prog_name);
	else
		ft_printf("le joueur %d(%s) a gagne\n", vm->pls[i].num
			, vm->pls[i].prog_name);
}

int						main(int ac, char **av)
{
	t_vm		vm;
	short int	i;

	init_vm(&vm, 0);
	if (cw_parser(ac, av, &vm))
		return (1);
	init_process(&vm);
	load_champ(&vm);
	if (vm.args & AG_VERB)
		cw_intro(&vm);
	corewar(&vm);
	if (vm.args & AG_DUMP32 || vm.args & AG_DUMP64)
		mem_dump(&vm);
	else
	{
		i = 0;
		while (i < vm.nb_j && vm.pls[i].num != vm.live)
			i++;
		cw_print_win(&vm, i);
	}
	destroy_ncurses(&vm);
	clear_process(&vm);
	return (0);
}
