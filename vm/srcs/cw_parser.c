/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:20:48 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/13 17:22:28 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int			p_parser(char *p, t_player *pl)
{
	int	fd;

	if ((fd = open(p, O_RDONLY)) == -1 || read(fd, &(pl->magic), 4) == -1)
		return (1);
	pl->magic = l2b_endian(pl->magic);
	if (pl->magic != COREWAR_EXEC_MAGIC)
		return (2);
	if (read(fd, &(pl->prog_name), PROG_NAME_LENGTH) < 1
		|| lseek(fd, 136, SEEK_SET) == -1
		|| read(fd, &(pl->prog_size), 4) < 1)
		return (1);
	pl->prog_size = l2b_endian(pl->prog_size);
	if (pl->prog_size > CHAMP_MAX_SIZE)
		return (3);
	if (read(fd, &(pl->comment), COMMENT_LENGTH) < 1
		|| lseek(fd, 2192, SEEK_SET) == -1
		|| read(fd, &(pl->code), pl->prog_size) != pl->prog_size
		|| close(fd) == -1)
		return (1);
	return (0);
}

static int			get_num(t_vm *vm, int ac, char **av, int *i)
{
	static int	pl_i = -1;
	short int	j;

	if (ft_strequ(av[*i], "-n") && (*i + 2 < ac) && ft_isnumb(av[*i + 1])
		&& (j = -1) && !ft_atois(av[(*i) + 1], &(vm->pls[vm->nb_j].num)))
	{
		while (++j < vm->nb_j)
		{
			if (vm->pls[j].num == vm->pls[vm->nb_j].num)
				return (1);
		}
		*i += 2;
	}
	else if (!ft_strequ(av[*i], "-n") && (j = -1))
	{
		while (++j < vm->nb_j)
			if (pl_i == vm->pls[j].num && (j = -1))
				pl_i--;
		vm->pls[vm->nb_j].num = pl_i--;
	}
	else
		return (1);
	return (0);
}

static int			cw_get_args(int ac, char **av, t_vm *vm)
{
	int				i;
	int				j;
	static t_pargs	args[5] = {{"-dump", &arg_dump, 2}, {"-d", &arg_dump, 2}
								, {"-v", &arg_verb, 2}, {"-a", &arg_aff, 1}
								, {"-visu", &arg_visual, 1}};

	i = 1;
	while (i < ac && av[i][0] == '-' && !ft_strequ("-n", av[i]) && !(j = 0))
	{
		while (j < 5 && !ft_strequ(args[j].arg, av[i]))
			j++;
		if (j < 5 && i + args[j].nb_ag < ac)
		{
			args[j].func(av, vm, i);
			i += args[j].nb_ag;
		}
		else
		{
			cw_print_usage();
			exit(1);
		}
	}
	return (i);
}

int					cw_parser(int ac, char **av, t_vm *vm)
{
	int	i;
	int	err;

	i = cw_get_args(ac, av, vm);
	if (i >= ac)
	{
		cw_print_usage();
		return (1);
	}
	while (i < ac && vm->nb_j < 4)
	{
		if (get_num(vm, ac, av, &i))
			return (err_msg(5, vm));
		if (!check_file(av[i]))
			return (err_msg(4, vm));
		if ((err = p_parser(av[i], &(vm->pls[vm->nb_j]))))
			return (err_msg(err, vm));
		vm->live = vm->pls[vm->nb_j].num;
		vm->nb_j++;
		i++;
	}
	return (0);
}
