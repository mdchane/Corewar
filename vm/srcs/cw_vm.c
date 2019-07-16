/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:52:51 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/16 14:22:34 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		init_vm_vars(t_vm *vm)
{
	g_bcn = 0;
	g_buf[g_bcn] = '\0';
	vm->args = 0;
	vm->pid_ct = 1;
	vm->cycles = 0;
	vm->ctd = CYCLE_TO_DIE;
	vm->ctd_c = 0;
	vm->nb_j = 0;
	vm->tl = NULL;
	vm->live = 0;
	vm->live_ct = 0;
	vm->dump = -1;
	vm->verb = -1;
	vm->p_ct = 0;
	vm->vis.delay = 10000;
	vm->vis.paused = TRUE;
	vm->vis.arena = NULL;
	vm->vis.stat = NULL;
}

void			init_vm(t_vm *vm, int i)
{
	ft_bzero(vm->mem, MEM_SIZE);
	ft_bzero(vm->col, MEM_SIZE);
	init_vm_vars(vm);
	i = -1;
	while (++i < MAX_PLAYERS)
	{
		vm->pls[i].magic = 0;
		ft_bzero(vm->pls[i].prog_name, PROG_NAME_LENGTH + 1);
		vm->pls[i].prog_size = 0;
		ft_bzero(vm->pls[i].comment, COMMENT_LENGTH + 1);
		vm->pls[i].num = 0;
		ft_bzero(vm->pls[i].code, CHAMP_MAX_SIZE);
		vm->pls[i].col = 0;
		vm->pls[i].live_ct = 0;
		vm->pls[i].lst_live = 0;
	}
}

int				load_champ(t_vm *vm)
{
	short int	i;
	int			inc;

	inc = 0;
	i = 0;
	while (i < vm->nb_j)
	{
		ft_memmove(&(vm->mem[inc]), vm->pls[i].code, vm->pls[i].prog_size);
		ft_memset(&(vm->col[inc]), i + 1, vm->pls[i].prog_size);
		vm->pls[i].col = i + 1;
		inc += (MEM_SIZE / vm->nb_j);
		i++;
	}
	return (0);
}

void			mem_dump(t_vm *vm)
{
	int	i;
	int	nb;

	i = 0;
	nb = (vm->args & AG_DUMP64) ? 64 : 32;
	while (i < MEM_SIZE)
	{
		if (i % nb == 0)
			ft_printf("0x%04x : ", i);
		ft_printf("%02x ", vm->mem[i]);
		if ((i + 1) % nb == 0)
			ft_printf("\n");
		i++;
	}
}
