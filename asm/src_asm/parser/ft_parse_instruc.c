/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_instruc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:17:56 by mdchane           #+#    #+#             */
/*   Updated: 2019/07/16 15:36:42 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_inst(char *name)
{
	int		i;

	if (!name)
		return (-1);
	i = 0;
	while (i < 16 && ft_strcmp(name, g_tab[i].name) != 0)
		i++;
	if (i == 16)
		return (-1);
	else
		return (i);
}

int		ft_verif_param(t_token *tk, int inst, int num_param, t_label *label)
{
	int		type;

	if (tk->type == INDIRECT
		|| (tk->type == INDIRECT_LABEL && get_label(tk, label)))
		type = T_IND;
	else if (tk->type == DIRECT
		|| (tk->type == DIRECT_LABEL && get_label(tk, label)))
		type = T_DIR;
	else if (tk->type == REGISTER && ft_atoi(tk->contents + 1) < 100)
		type = T_REG;
	else
		type = 0;
	if (g_tab[inst].poss[num_param] & type)
		return (1);
	else
	{
		ft_printf("error: l%d : Invalid parameter %d for instruction %s\n",
			tk->line, num_param, g_tab[inst].name);
		return (0);
	}
}

int		ft_correct_instru(t_token *tk, int i, t_label *label, int line)
{
	int		num_param;

	num_param = 0;
	while (tk && num_param < g_tab[i].nb_param)
	{
		if (ft_verif_param(tk, i, num_param, label))
		{
			tk = tk->next;
			if (!tk && num_param == g_tab[i].nb_param - 1)
				return (1);
			else if (tk && tk->type == COMMENT
				&& !tk->next && num_param == g_tab[i].nb_param - 1)
				return (1);
			else if (tk && ft_strcmp(tk->contents, ",") == 0)
				num_param++;
			else
				return (ft_printf("error: l%d: bad param %d for instru %s\n",
					line, num_param + 1, g_tab[i].name) && 0);
		}
		else
			return (0);
		tk = tk->next;
	}
	return (ft_printf("error: l%d: bad params for instru %s\n",
		line, g_tab[i].name) && 0);
}

int		ft_calc_size(t_token *tk, int inst)
{
	int		size;

	size = 1 + g_tab[inst].byte;
	while (tk)
	{
		if (tk->type == INDIRECT || tk->type == INDIRECT_LABEL)
			size += 2;
		else if (tk->type == DIRECT || tk->type == DIRECT_LABEL)
			size += (g_tab[inst].size) ? 2 : 4;
		else if (tk->type == REGISTER)
			size += 1;
		tk = tk->next;
	}
	return (size);
}

int		ft_parse_instruct(t_token *tk, t_label *label, unsigned int *size)
{
	int		inst;

	inst = is_inst(tk->contents);
	if (inst < 0)
	{
		return (ft_printf("error: l%d: invalid instruction '%s'\n",
			tk->line, tk->contents) && 0);
	}
	if (!tk->next)
	{
		return (ft_printf("error: l%d: no params for instru %s\n",
			tk->line, tk->contents) && 0);
	}
	if (ft_correct_instru(tk->next, inst, label, tk->line))
	{
		*size += ft_calc_size(tk->next, inst);
		return (1);
	}
	else
	{
		return (0);
	}
}
