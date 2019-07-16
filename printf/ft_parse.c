/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:54:23 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/24 23:54:27 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_istype(char c)
{
	return (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
	|| c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f' || c == 'B');
}

static void		ft_parse_prefix(const char **s, t_param *prm)
{
	if (**s == '+')
		prm->p = prm->p | 1;
	else if (**s == '-')
		prm->p = prm->p | 1 << 1;
	else if (**s == '#')
		prm->p = prm->p | 1 << 2;
	else if (**s == ' ')
		prm->p = prm->p | 1 << 3;
	else if (**s == '0')
		prm->p = prm->p | 1 << 4;
}

static void		ft_parse_type(const char **s, t_param *prm)
{
	if (**s == 'h' && *(*s + 1) == 'h')
	{
		prm->p = prm->p | 1 << 5;
		(*s)++;
	}
	else if (**s == 'h')
		prm->p = prm->p | 1 << 6;
	else if (**s == 'l' && *(*s + 1) == 'l')
	{
		prm->p = prm->p | 1 << 8;
		(*s)++;
	}
	else if (**s == 'l')
		prm->p = prm->p | 1 << 7;
	else if (**s == 'L')
		prm->p = prm->p | 1 << 9;
}

static void		ft_parse_wdpr(const char **s, t_param *prm)
{
	if (ft_isdigit_printf(**s))
	{
		prm->wdt = ft_atoi_printf(*s);
		while (ft_isdigit_printf(*(*s + 1)))
			(*s)++;
	}
	else if (**s == '.')
	{
		if (ft_isdigit_printf(*(*s + 1)))
			prm->prc = ft_atoi_printf(*s + 1);
		else
			prm->prc = 0;
		while (ft_isdigit_printf(*(*s + 1)))
			(*s)++;
	}
}

int				ft_parse(const char **s, t_param *prm)
{
	while (**s)
	{
		(*s)++;
		if (**s == '+' || **s == '-' || **s == '#' || **s == ' ' || **s == '0')
			ft_parse_prefix(s, prm);
		else if (**s == 'h' || **s == 'l' || **s == 'L')
			ft_parse_type(s, prm);
		else if (**s == '.' || ft_isdigit_printf(**s))
			ft_parse_wdpr(s, prm);
		else if (ft_istype(**s))
			return (1);
		else
			return (0);
	}
	return (0);
}
