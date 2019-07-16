/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ops_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:54:26 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/15 23:52:08 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	l2b_endian(unsigned int num)
{
	uint32_t b0;
	uint32_t b1;
	uint32_t b2;
	uint32_t b3;
	uint32_t res;

	b0 = (num & 0x000000ff) << 24u;
	b1 = (num & 0x0000ff00) << 8u;
	b2 = (num & 0x00ff0000) >> 8u;
	b3 = (num & 0xff000000) >> 24u;
	res = b0 | b1 | b2 | b3;
	return (res);
}

void			init_args(t_args *ag, t_process *p, t_vm *vm)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		ag[i].t = 0;
		ag[i].i = 0;
	}
	ag[3].t = read_mem(vm, p->pc + 1);
}

int				check_reg(t_vm *vm, int ind)
{
	int	reg;

	reg = read_mem(vm, ind);
	return ((reg > 0 && reg <= REG_NUMBER) ? reg : 0);
}

void			cw_move_pc(t_vm *vm, t_process *p, int jp)
{
	if (vm->verb != -1 && vm->verb & VB_PC)
		ft_printf("ADV %d (0x%04x -> 0x%04x)", jp, p->pc, p->pc + jp);
	p->pc = (p->pc + jp) % MEM_SIZE;
	while (jp && vm->verb != -1 && vm->verb & VB_PC)
		ft_printf(" %02x", vm->mem[((unsigned)(p->pc - jp--)) % MEM_SIZE]);
	if (vm->verb != -1 && vm->verb & VB_PC)
		ft_printf(" \n");
}

int				cw_ocp(char nb_ag, t_args *ag, char size_dir)
{
	int	res;
	int	i;

	res = 2;
	i = -1;
	while (++i < nb_ag)
	{
		ag[i].i = res;
		if (((ag[3].t & (0xC0 >> (2 * i))) >> (2 * (3 - i))) == IND_CODE)
		{
			res += 2;
			ag[i].t = IND_CODE;
		}
		else if (((ag[3].t & (0xC0 >> (2 * i))) >> (2 * (3 - i))) == REG_CODE)
		{
			res += 1;
			ag[i].t = REG_CODE;
		}
		else if (((ag[3].t & (0xC0 >> (2 * i))) >> (2 * (3 - i))) == DIR_CODE)
		{
			res += size_dir;
			ag[i].t = DIR_CODE;
		}
	}
	return (res);
}
