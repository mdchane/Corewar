/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_instru.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:56:37 by mdchane           #+#    #+#             */
/*   Updated: 2019/07/16 12:44:33 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_calc_byte(t_token *tk)
{
	char	*str_size;
	int		size;
	char	*complete;

	str_size = ft_strnew(0);
	while (tk)
	{
		if (tk && ft_strcmp(tk->contents, ",") == 0)
			tk = tk->next;
		if (tk->type == DIRECT || tk->type == DIRECT_LABEL)
			str_size = ft_strextend(str_size, "10");
		else if (tk->type == INDIRECT || tk->type == INDIRECT_LABEL)
			str_size = ft_strextend(str_size, "11");
		else if (tk->type == REGISTER)
			str_size = ft_strextend(str_size, "01");
		tk = tk->next;
	}
	complete = ft_strnew_1(8 - ft_strlen(str_size));
	str_size = ft_strextend(str_size, complete);
	size = ft_atoi_bin(str_size);
	ft_strdel(&complete);
	ft_strdel(&str_size);
	return (size);
}

unsigned char	*ft_convert_lab(t_token *tk, int inst,
	int *size_param, t_pos_lab pos_lab)
{
	unsigned char	*param;

	param = NULL;
	if (tk->type == DIRECT_LABEL)
	{
		*size_param = (g_tab[inst].size) ? 2 : 4;
		param = ft_conv_hexa(get_label(tk, pos_lab.lab)->place
			- pos_lab.pos, *size_param);
	}
	else if (tk->type == INDIRECT_LABEL)
	{
		*size_param = 2;
		param = ft_conv_hexa(get_label(tk, pos_lab.lab)->place
			- pos_lab.pos, *size_param);
	}
	return (param);
}

unsigned char	*ft_convert_one(t_token *tk, int inst,
	int *size_param, t_pos_lab pos_lab)
{
	unsigned char	*param;

	*size_param = 0;
	param = NULL;
	if (tk->type == DIRECT)
	{
		*size_param = (g_tab[inst].size) ? 2 : 4;
		param = ft_conv_hexa(ft_atoi(tk->contents + 1), *size_param);
	}
	else if (tk->type == INDIRECT)
	{
		*size_param = 2;
		param = ft_conv_hexa(ft_atoi(tk->contents), *size_param);
	}
	else if (tk->type == REGISTER)
	{
		*size_param = 1;
		param = ft_conv_hexa(ft_atoi(tk->contents + 1), *size_param);
	}
	else
		param = ft_convert_lab(tk, inst, size_param, pos_lab);
	return (param);
}

unsigned char	*ft_str_params(t_token *tk, int inst,
	int *size_params, t_pos_lab pos_lab)
{
	unsigned char	*params;
	unsigned char	*one;
	int				size_one;

	*size_params = 0;
	if (!(params = (unsigned char *)malloc(sizeof(*params))))
		return (NULL);
	while (tk)
	{
		if (tk && ft_strcmp(tk->contents, ",") == 0)
			tk = tk->next;
		else if (tk->type == COMMENT)
			break ;
		one = ft_convert_one(tk, inst, &size_one, pos_lab);
		params = ft_strextend_nm(params, one, *size_params, size_one);
		tk = tk->next;
		*size_params += size_one;
	}
	return (params);
}

unsigned char	*ft_conv_instru(t_token *tk, int *size_instru,
	t_pos_lab pos_lab)
{
	int				inst;
	unsigned char	*instru;
	unsigned char	*params;
	int				size_params;

	inst = is_inst(tk->contents);
	if (!(instru = (unsigned char *)malloc(sizeof(*instru)
		* (1 + g_tab[inst].byte))))
		return (NULL);
	instru[0] = g_tab[inst].op_code;
	params = ft_str_params(tk->next, inst, &size_params, pos_lab);
	if (g_tab[inst].byte)
	{
		instru[1] = ft_calc_byte(tk);
		instru = ft_strextend_nm(instru, params, 2, size_params);
		*size_instru = 2 + size_params;
	}
	else
	{
		instru = ft_strextend_nm(instru, params, 1, size_params);
		*size_instru = 1 + size_params;
	}
	return (instru);
}
