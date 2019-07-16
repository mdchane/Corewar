/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_print_usage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:30:52 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/16 16:11:24 by tmaze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_print_usage(void)
{
	ft_putstr("Usage: ./corewar [[-dump N|-d N] -v Z -visu] [-n Z] <champion1.c"
		"or> <...>\n    N being a natural number\n    Z being an integer\n#### "
		"TEXT OUTPUT MODE #####################################################"
		"####\n    -a        : Prints output from \"aff\" (Default is to hide i"
		"t)\n    -d N      : Dumps memory after N cycles w/ 64 byes per line\n "
		"   -dump N   : Dumps memory after N cycles w/ 32 bytes per line\n    -"
		"v N      : Verbosity levels, can be added together to enable several\n"
		"                - 0 : Show only essentials\n                - 1 : Show"
		"lives\n                - 2 : Show cycles\n                - 4 : Show o"
		"perations (Params are NOT litteral ...)\n                - 8 : Show de"
		"aths\n                - 16 : Show PC movements (Except for jumps)\n###"
		"# VISUAL OUTPUT MODE #################################################"
		"######\n   -visu     : Activates graphical visualizer\n               "
		"(OVERRIDES ALL TEXT OUTPUT OPTIONS)\n#### CONTROLS\n                - "
		"SPACE     : Pause\n                - KEY_UP    : Increase speed\n     "
		"           - KEY_DOWN  : Decrease speed\n                - q         :"
		" Exit\n");
}
