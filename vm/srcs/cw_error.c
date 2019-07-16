/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:54:36 by igarbuz           #+#    #+#             */
/*   Updated: 2019/07/13 17:21:07 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		err_msg(int err, t_vm *vm)
{
	if (err == 1)
		ft_printf("Error champ %d: %s\n", vm->nb_j, strerror(errno));
	else if (err == 2)
		ft_printf("Error champ %d: Wrong magic number\n", vm->nb_j);
	else if (err == 3)
		ft_printf("Error champ %d: Champ too large (%d > %d)\n"
			, vm->nb_j, vm->pls[vm->nb_j].prog_size, CHAMP_MAX_SIZE);
	else if (err == 4)
		ft_printf("Error champ no.%d: File is not .cor\n", vm->nb_j);
	else if (err == 5)
		ft_printf("Error champ no.%d: Number %d already in use\n", vm->nb_j
			, vm->pls[vm->nb_j].num);
	else if (err == 6)
	{
		ft_printf("Error dump: Missing or Invalid number\n");
		return (-1);
	}
	else if (err == 7)
		ft_printf("Error: ncurses new window initialization\n");
	else if (err == 8)
		ft_printf("Error: cannot open file with logo\n");
	else if (err == 9)
		ft_printf("Program ended by user\n");
	return (1);
}

void	error(t_vm *vm, int err)
{
	clear_process(vm);
	err_msg(err, vm);
	exit(EXIT_FAILURE);
}
