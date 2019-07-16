/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:03:16 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/12 12:30:58 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	arg_dump(char **av, t_vm *vm, int i)
{
	if (!(vm->args & AG_VISUAL) && ft_isnumb(av[i + 1])
		&& !ft_atois(av[i + 1], &(vm->dump)))
	{
		if (ft_strequ(av[i], "-dump"))
		{
			vm->args &= ~AG_DUMP64;
			vm->args |= AG_DUMP32;
		}
		else if (ft_strequ(av[i], "-d"))
		{
			vm->args &= ~AG_DUMP32;
			vm->args |= AG_DUMP64;
		}
	}
}

void	arg_verb(char **av, t_vm *vm, int i)
{
	if (!(vm->args & AG_VISUAL) && ft_isnumb(av[i + 1])
		&& !ft_atois(av[i + 1], &(vm->verb)))
		vm->args |= AG_VERB;
}

void	arg_visual(char **av, t_vm *vm, int i)
{
	av = NULL;
	i = 0;
	vm->args &= ~(AG_VERB | AG_DUMP32 | AG_DUMP64 | AG_AFF);
	vm->args |= AG_VISUAL;
}

void	arg_aff(char **av, t_vm *vm, int i)
{
	av = NULL;
	i = 0;
	if (!(vm->args & AG_VISUAL))
		vm->args |= AG_AFF;
}
