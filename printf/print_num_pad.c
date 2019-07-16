/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_pad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 21:05:47 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/29 21:05:50 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_float_default_prc(t_param *prm)
{
	if (prm->prc == -1)
		prm->prc = F_ROUND;
}

static void	ft_print_i(char c, char *dst, intmax_t arg, t_param *prm)
{
	if (!arg && !prm->prc)
		return ;
	else if (c == 'd' || c == 'i')
		ft_printbuf_snum(dst, arg);
	else if (c == 'u')
		ft_printbuf_unum(dst, (uintmax_t)arg);
	else if (c == 'o')
		ft_printbuf_oct(dst, (uintmax_t)arg);
	else if (c == 'x' || c == 'p')
		ft_printbuf_hex(dst, (uintmax_t)arg, 87);
	else if (c == 'X')
		ft_printbuf_hex(dst, (uintmax_t)arg, 55);
}

/*
** if arg == 0 and a precision is specified : empty is preanted
** ft_arg_len() : real length rlen without format prefixes
** ft_arg_flen() : full length len
*/

void		ft_print_i_pad(char c, char *b, t_param *prm, intmax_t arg)
{
	int flen;
	int	rlen;

	rlen = ft_arg_len(arg, c, prm);
	flen = rlen;
	if (prm->prc > rlen)
		flen = prm->prc;
	flen = ft_arg_flen(arg, c, prm->p, flen);
	if (!(prm->p >> 1 & 1) && (!(prm->p >> 4 & 1) || prm->prc != -1))
		ft_printbuf_pad(b, ' ', prm->wdt - flen);
	if (c == 'i' || c == 'd')
		ft_printbuf_sprefix(b, prm->p, &arg);
	else if (c == 'x' || c == 'X' || c == 'o' || c == 'p')
		ft_printbuf_xprefix(b, c, prm, &arg);
	if (!(prm->p >> 1 & 1) && (prm->p >> 4 & 1) && prm->prc == -1)
		ft_printbuf_pad(b, '0', prm->wdt - flen);
	ft_printbuf_pad(b, '0', prm->prc - rlen);
	ft_print_i(c, b, arg, prm);
	if ((prm->p >> 1 & 1))
		ft_printbuf_pad(b, ' ', prm->wdt - flen);
}

/*
** ft_printf_db_pad return a string of a max length nor more than decimal LSB
*/

void		ft_print_db_pad(char *b, t_param *prm, double *arg)
{
	const char	*f;
	int			len;
	int			frc;
	char		tbl[DB_MAX_L];

	ft_float_default_prc(prm);
	if ((f = ft_printf_db(arg, prm->prc, tbl)))
	{
		len = ft_arg_db_len(f, prm->p, arg);
		if ((frc = ft_fract_len(f)) >= 0 && prm->prc > frc)
			len += (prm->prc - frc);
		if (!(prm->p >> 1 & 1) && (!(prm->p >> 4 & 1)))
			ft_printbuf_pad(b, ' ', prm->wdt - len);
		ft_printbuf_fprefix(b, prm->p, arg);
		if (!(prm->p >> 1 & 1) && (prm->p >> 4 & 1))
			ft_printbuf_pad(b, '0', prm->wdt - len);
		if (!frc && !(prm->p >> 2 & 1) && prm->prc == 0)
			ft_printbuf_c(b, &f, '.');
		else
			ft_printbuf_c(b, &f, '\0');
		if (frc != -1)
			ft_printbuf_pad(b, '0', prm->prc - frc);
		if ((prm->p >> 1 & 1))
			ft_printbuf_pad(b, ' ', prm->wdt - len);
	}
}

/*
** ft_printf_ldb return a string of a max length nor more than
** lond double LSB in decimal; Equivalent to ft_print_db_pad
*/

void		ft_print_long_db_pad(char *b, t_param *prm, long double *arg)
{
	const char	*f;
	int			len;
	int			frc;
	char		tbl[DBL_MAX_L];

	ft_float_default_prc(prm);
	if ((f = ft_printf_long_db(arg, prm->prc, tbl)))
	{
		len = ft_arg_long_db_len(f, prm->p, arg);
		if ((frc = ft_fract_len(f)) >= 0 && prm->prc > frc)
			len += (prm->prc - frc);
		if (!(prm->p >> 1 & 1) && (!(prm->p >> 4 & 1)))
			ft_printbuf_pad(b, ' ', prm->wdt - len);
		ft_printbuf_long_fprefix(b, prm->p, arg);
		if (!(prm->p >> 1 & 1) && (prm->p >> 4 & 1))
			ft_printbuf_pad(b, '0', prm->wdt - len);
		if (!frc && !(prm->p >> 2 & 1) && prm->prc == 0)
			ft_printbuf_c(b, &f, '.');
		else
			ft_printbuf_c(b, &f, '\0');
		if (frc != -1)
			ft_printbuf_pad(b, '0', prm->prc - frc);
		if ((prm->p >> 1 & 1))
			ft_printbuf_pad(b, ' ', prm->wdt - len);
	}
}
