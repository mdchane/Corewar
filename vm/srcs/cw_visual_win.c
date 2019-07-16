/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_visual_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 21:15:56 by igarbuz           #+#    #+#             */
/*   Updated: 2019/07/16 19:09:19 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			print_logo_win(t_vm *vm, int i)
{
	int	j;

	wmove(vm->vis.stat, 0, 0);
	j = 0;
	while (++j < 9)
		mvwchgat(vm->vis.stat, j, 1, 93, A_BLINK, vm->pls[i].col, NULL);
}

void				visual_delay_update(t_vm *vm)
{
	wmove(vm->vis.stat, (vm->nb_j - 1) * 3 + 29, 15);
	wattron(vm->vis.stat, COLOR_PAIR(14));
	wprintw(vm->vis.stat, "%8dμs   ", vm->vis.delay & 0x3FFFFF);
	wattroff(vm->vis.stat, COLOR_PAIR(14));
	wrefresh(vm->vis.stat);
}

void				check_user_exit(t_vm *vm, int key)
{
	if (key == 'q')
	{
		destroy_ncurses_exit(vm);
		error(vm, 9);
	}
}

void				visual_winners(t_vm *vm, int i)
{
	int k;

	wmove(vm->vis.stat, 40, 5);
	wclrtobot(vm->vis.stat);
	wattron(vm->vis.stat, COLOR_PAIR(14));
	k = -1;
	while (++k < 90)
		waddch(vm->vis.stat, '*');
	wprintw(vm->vis.stat, "\n\n     Contestant %lu, \"%s\", has won !\n", \
							i + 1, vm->pls[i].prog_name);
	wprintw(vm->vis.stat, "\n\n     Press any key to exit\n");
	wattroff(vm->vis.stat, COLOR_PAIR(14));
	print_logo_win(vm, i);
	wborder(vm->vis.stat, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(vm->vis.stat);
}
