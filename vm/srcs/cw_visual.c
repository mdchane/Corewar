/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:12:51 by igarbuz           #+#    #+#             */
/*   Updated: 2019/07/13 19:14:56 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		print_lives(t_player *pl, WINDOW *stat)
{
	int i;
	int	cycles;

	if (pl->live_ct < 560)
		cycles = pl->live_ct / 10;
	else
		cycles = 56;
	wattron(stat, COLOR_PAIR(pl->col));
	wprintw(stat, "\n\n   Lives for: ");
	wprintw(stat, "%s", pl->prog_name);
	wprintw(stat, " => %-5d  \n", pl->live_ct);
	waddstr(stat, "		|");
	i = -1;
	while (++i < cycles)
		waddch(stat, ACS_HLINE | A_REVERSE);
	while (i++ < 56)
		waddch(stat, ACS_HLINE);
	waddch(stat, '|');
	wattroff(stat, COLOR_PAIR(pl->col));
}

static void		print_stats(t_vm *vm, WINDOW *stat)
{
	short int i;

	wmove(stat, 10, 1);
	wclrtobot(stat);
	i = -1;
	while (++i < vm->nb_j)
		print_lives(&vm->pls[i], stat);
	wattron(stat, COLOR_PAIR(14));
	wprintw(stat, "\n\n	Cycle: %-10lld\n\n \
	Processes: %-10u\n\n \
	Total Number of lives: %3d/%-10d\n\n \
	Players number: %hd/%d\n\n \
	Decrease cycle to die with: %d\n\n \
	Cycles to die: %d/%d\n\n",
	vm->cycles, vm->p_ct, vm->live_ct, NBR_LIVE, \
	vm->nb_j, MAX_PLAYERS, CYCLE_DELTA, vm->ctd_c, vm->ctd);
	wprintw(stat, "\n\n	Delay: %8dμs   ", vm->vis.delay & 0x3FFFFF);
	wattroff(stat, COLOR_PAIR(14));
	wborder(stat, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(stat);
}

void			control_delay(t_vm *vm)
{
	int	key;

	while (vm->args & AG_VISUAL)
	{
		key = wgetch(vm->vis.arena);
		if (key == ' ' && vm->vis.paused == 0)
		{
			nodelay(vm->vis.arena, 0);
			vm->vis.paused = 1;
		}
		else if (key == ' ' && vm->vis.paused == 1)
		{
			nodelay(vm->vis.arena, 1);
			vm->vis.paused = 0;
		}
		else if (key == KEY_DOWN && vm->vis.delay < 100000)
			vm->vis.delay = (vm->vis.delay + 1) * 1.1;
		else if (key == KEY_UP)
			vm->vis.delay = (vm->vis.delay * 0.9);
		check_user_exit(vm, key);
		if (vm->vis.paused == 1)
			visual_delay_update(vm);
		if (vm->vis.paused == 0)
			break ;
	}
}

void			print_arena(t_vm *vm)
{
	int i;

	if (vm->args & AG_VISUAL)
	{
		i = 0;
		werase(vm->vis.arena);
		while (i < MEM_SIZE)
		{
			if ((i & 0x3F) == 0)
				wprintw(vm->vis.arena, "\n ");
			wattron(vm->vis.arena, COLOR_PAIR(vm->col[i]));
			wprintw(vm->vis.arena, " %02x", 0xFF & vm->mem[i]);
			wattroff(vm->vis.arena, COLOR_PAIR(vm->col[i]));
			wattroff(vm->vis.arena, COLOR_PAIR(1));
			i++;
		}
		wborder(vm->vis.arena, '|', '|', '-', '-', '+', '+', '+', '+');
		print_stats(vm, vm->vis.stat);
	}
}

void			print_pc(t_vm *vm, unsigned short int pc, char col)
{
	if (vm->args & AG_VISUAL)
	{
		mvwchgat(vm->vis.arena, 1 + pc / 64, 2 + 3 * (pc & 63),\
				2, A_REVERSE, col, NULL);
		usleep(vm->vis.delay);
	}
}
