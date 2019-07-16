/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:05:37 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/24 13:05:40 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print(const char c, char *b, t_param *prm, va_list valist)
{
	intmax_t	arg;
	double		db;
	long double ldb;

	if (c != '%' && c != 'f')
		arg = ft_arg_cast(valist, prm->p, c);
	else if (c == 'f' && (prm->p >> 9 & 1))
		ldb = va_arg(valist, long double);
	else if (c == 'f')
		db = va_arg(valist, double);
	if (c == 'c' || c == 's' || c == '%')
		ft_print_c_pad(c, b, prm, arg);
	else if ((c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x'
			|| c == 'X' || c == 'p'))
		ft_print_i_pad(c, b, prm, arg);
	else if (c == 'f' && (prm->p >> 9 & 1))
		ft_print_long_db_pad(b, prm, &ldb);
	else if (c == 'f')
		ft_print_db_pad(b, prm, &db);
	else if (c == 'B')
		ft_print_bit_float(b, prm, valist);
}

static void		ft_read_input(va_list valist, char *buf,
								t_param *prm, const char *format)
{
	while (*format)
	{
		ft_init_param(prm);
		ft_printbuf_c(buf, &format, '%');
		if (!*format)
			break ;
		if (*format == '%' && ft_parse(&format, prm))
			ft_print(*format, buf, prm, valist);
		else if (*format)
		{
			ft_print_c_pad('c', buf, prm, *format);
			format++;
			if (*format)
				ft_printbuf_c(buf, &format, '%');
		}
		if (*format && (*format != '%' || *(format - 1) == '%'))
			format++;
	}
}

int				ft_printf(const char *format, ...)
{
	va_list		valist;
	t_param		prm;
	char		buf[BUF_SIZE];

	g_bcn = 0;
	if (format == 0 || *format == '\0')
		return (0);
	va_start(valist, format);
	ft_read_input(valist, buf, &prm, format);
	va_end(valist);
	write(1, buf, g_bcn);
	return (g_bcn);
}
