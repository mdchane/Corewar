/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_init_ncurs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:45:09 by igarbuz           #+#    #+#             */
/*   Updated: 2019/07/13 17:41:48 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		print_logo(t_vm *vm)
{
	int		fd;
	char	buf[ART_MAX_SIZE + 1];
	int		rd;

	fd = open("./art/corewar_3D_logo.txt", O_RDONLY);
	if ((rd = read(fd, &buf, ART_MAX_SIZE)) == -1)
	{
		destroy_ncurses_exit(vm);
		error(vm, 8);
	}
	buf[rd] = '\0';
	wprintw(vm->vis.stat, "%s", &buf);
	close(fd);
	return (0);
}

static void		init_colors(void)
{
	init_color(COLOR_WHITE, 220, 220, 220);
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	init_pair(7, COLOR_BLACK, COLOR_BLUE);
	init_pair(8, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(9, COLOR_BLACK, COLOR_CYAN);
	init_pair(10, COLOR_BLACK, COLOR_RED);
	init_pair(11, COLOR_BLACK, COLOR_GREEN);
	init_pair(12, COLOR_BLACK, COLOR_YELLOW);
	init_pair(13, COLOR_BLACK, COLOR_GREEN);
	init_pair(14, COLOR_GREEN, COLOR_BLACK);
}

void			init_ncurses(t_vm *vm)
{
	if (vm->args & AG_VISUAL)
	{
		initscr();
		noecho();
		cbreak();
		start_color();
		init_colors();
		curs_set(FALSE);
		if ((vm->vis.arena = newwin(66, 195, 0, 0)) == 0)
			error(vm, 7);
		if ((vm->vis.stat = newwin(66, 100, 0, 196)) == 0)
		{
			delwin(vm->vis.arena);
			error(vm, 7);
		}
		keypad(vm->vis.arena, 1);
		print_logo(vm);
		wborder(vm->vis.arena, '|', '|', '-', '-', '+', '+', '+', '+');
		wborder(vm->vis.stat, '|', '|', '-', '-', '+', '+', '+', '+');
	}
}

void			destroy_ncurses_exit(t_vm *vm)
{
	if (vm->args & AG_VISUAL)
	{
		delwin(vm->vis.arena);
		delwin(vm->vis.stat);
		endwin();
	}
}

void			destroy_ncurses(t_vm *vm)
{
	if (vm->args & AG_VISUAL)
	{
		wrefresh(vm->vis.arena);
		wrefresh(vm->vis.stat);
		keypad(vm->vis.arena, 0);
		nodelay(vm->vis.arena, 0);
		wgetch(vm->vis.arena);
		delwin(vm->vis.arena);
		delwin(vm->vis.stat);
		endwin();
	}
}
