/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bit_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:51:17 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/02 18:44:46 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_buf_bit_float(char *b, float f)
{
	int				size;
	int				sztmp;
	unsigned char	*ptr;
	int				j;

	if (!f)
		return ;
	size = sizeof(float) - 1;
	sztmp = size;
	ptr = (unsigned char *)&f;
	while (size >= 0)
	{
		j = 8;
		while (--j >= 0)
		{
			if ((size == sztmp || size == (sztmp - 1)) && j == 6)
				ft_printbuf_char(b, ' ');
			ft_printbuf_char(b, (ptr[size] >> j & 1) + '0');
		}
		size--;
	}
}

void		ft_print_buf_bit_double(char *b, double db)
{
	int				size;
	int				sztmp;
	unsigned char	*ptr;
	int				j;

	if (!db)
		return ;
	size = sizeof(double) - 1;
	sztmp = size;
	ptr = (unsigned char *)&db;
	while (size >= 0)
	{
		j = 8;
		while (--j >= 0)
		{
			if (size == sztmp && j == 6)
				ft_printbuf_char(b, ' ');
			else if (size == (sztmp - 1) && j == 3)
				ft_printbuf_char(b, ' ');
			ft_printbuf_char(b, (ptr[size] >> j & 1) + '0');
		}
		size--;
	}
}

void		ft_print_buf_bit_long_double(char *b, long double ldb)
{
	int				size;
	int				sztmp;
	unsigned char	*ptr;
	int				j;

	if (!ldb)
		return ;
	size = sizeof(long double) - 7;
	sztmp = size;
	ptr = (unsigned char *)&ldb;
	while (size >= 0)
	{
		j = 8;
		while (--j >= 0)
		{
			if (size == sztmp && j == 6)
				ft_printbuf_char(b, ' ');
			else if (size == (sztmp - 2) && j == 7)
				ft_printbuf_char(b, ' ');
			ft_printbuf_char(b, (ptr[size] >> j & 1) + '0');
		}
		size--;
	}
}

void		ft_print_bit_float(char *b, t_param *prm, va_list valist)
{
	double		db;
	long double ldb;

	if (prm->p >> 9 & 1)
		ldb = va_arg(valist, long double);
	else
		db = va_arg(valist, double);
	if (prm->p >> 9 & 1)
		ft_print_buf_bit_long_double(b, ldb);
	else if ((prm->p >> 7 & 1) || (prm->p >> 8 & 1))
		ft_print_buf_bit_double(b, db);
	else
		ft_print_buf_bit_float(b, (float)db);
}
