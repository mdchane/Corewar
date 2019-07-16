/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:05:59 by igarbuz           #+#    #+#             */
/*   Updated: 2019/01/24 13:06:04 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>

/*
** BUF_M is muffer mask; must be a divisible PAGESIZE minus 1;
** exception for BUF_M 0x1, BUF_SIZE must be 0x1;
** BUF_S is a buffer size - must be a divisible PAGESIZE;
** PAGESIZE default 2^12;
** default 0x7ffff is equivalent to 524287 bytes; Examples of values :
** BUF_M : 0x7ffff, 0x3ffff, 0x1ffff, 0x0ffff, 0x7fff, 0x3fff, 0x1fff, 0x0fff;
** BUF_S : 0x80000, 0x40000, 0x20000, 0x10000, 0x8000, 0x4000, 0x2000, 0x1000
*/
# define BUF_M		0x0fff
# define BUF_SIZE	0x1000

/*
** do not modify
*/
# define F_ROUND	6
# define DB_MAX_L	1076
# define DBL_MAX_L	16447

typedef struct		s_param
{
	int		p;
	int		prc;
	int		wdt;
}					t_param;

typedef union		u_value
{
	double			n;
	struct
	{
		uint32_t	lo;
		uint32_t	hi;
	}				u32;
}					t_value;

typedef union		u_value64
{
	long double		n;
	struct
	{
		uint64_t	lo;
		uint64_t	hi;
	}				u64;
}					t_value64;

typedef struct		s_nd
{
	uint32_t		n[128];
	int32_t			lo;
	int32_t			hi;
}					t_nd;

typedef struct		s_nd_long
{
	uint32_t		n[2048];
	int32_t			lo;
	int32_t			hi;
}					t_nd_long;

/*
** buf_cnt.c
*/
extern int			g_bcn;
extern unsigned int	g_pow10[];

/*
** ft_str_null.c
*/
const char			*ft_null(void);

/*
** ft_printf.c
*/
int					ft_printf(const char *format, ...);

/*
** print_num_pad.c
*/
void				ft_print_long_db_pad(char *b, t_param *prm,
											long double *arg);
void				ft_print_db_pad(char *b, t_param *prm, double *arg);
void				ft_print_i_pad(char c, char *b, t_param *prm, intmax_t arg);

/*
** print_cs_pad.c
*/
void				ft_print_c_pad(char c, char *b, t_param *prm, intmax_t arg);

/*
** ft_printf_db.c
*/
char				*ft_printf_db(double *n, int r, char *tbl);

/*
** ft_printf_ldb.c
*/
char				*ft_printf_long_db(long double *n, int r, char *tbl);

/*
** ft_parse.c
*/
int					ft_parse(const char **s, t_param *prm);

/*
** print_buf_prefix.c
*/
void				ft_printbuf_long_fprefix(char *b, int p, long double *arg);
void				ft_printbuf_fprefix(char *b, int p, double *arg);
void				ft_printbuf_xprefix(char *b, char c,
											t_param *prm, intmax_t *arg);
void				ft_printbuf_sprefix(char *b, int p, intmax_t *arg);

/*
** libft_printf.c
*/
int					ft_strlen_printf(const char *s);
int					ft_strlen_unicode(const wchar_t *s);
int					ft_atoi_printf(const char *str);
int					ft_isdigit_printf(char c);

/*
** print_buf.c
*/
void				ft_flush(char *dst);
void				ft_printbuf_char(char *dst, char src);
void				ft_printbuf_pad(char *dst, char c, int len);
void				ft_printbuf_c(char *dst, const char **src, char c);
void				ft_printbuf_prc(char *dst, char **src, int prc);

/*
** print_buf_unicode.c
*/
void				ft_printbuf_wchar_t(char *dst, wchar_t src, int size);
void				ft_printbuf_unicode_prc(char *dst, wchar_t **src, int prc);

/*
** print_buf_num.c
*/
void				ft_printbuf_snum(char *dst, intmax_t n);
void				ft_printbuf_unum(char *dst, uintmax_t n);
void				ft_printbuf_oct(char *dst, uintmax_t o);
void				ft_printbuf_hex(char *dst, uintmax_t x, char c);

/*
** ft_arglen.c
*/
int					ft_arg_len(intmax_t arg, char c, t_param *prm);

/*
** ft_arglen_oct.c
*/
int					ft_arg_len_oct(intmax_t arg, t_param *prm);

/*
** ft_arglen_f.c
*/
int					ft_fract_len(const char *f);
int					ft_arg_db_len(const char *s, int p, double *arg);
int					ft_arg_long_db_len(const char *s, int p, long double *arg);
int					ft_arg_flen(intmax_t arg, char c, int p, int len);

/*
** ft_argcast.c
*/
intmax_t			ft_arg_cast(va_list valist, int p, const char c);

/*
** ft_init_param.c
*/
void				ft_init_param(t_param *prm);
void				ft_init_nd(t_nd *nd);

/*
** ft_exp_dec.c
*/
int					ft_exp_dec(unsigned int value);

/*
** pf_error.c
*/
void				pf_error(int er);

/*
** nd_round.c
*/
void				ft_round(t_nd *nd, int *r);

/*
** ft_buf_print_db.c
*/
char				*ft_buf_print_db(t_nd *nd, int r, char *tbl);

/*
** ft_buf_print_ldb.c
*/
char				*ft_buf_print_ldb(t_nd_long *nd, int r, char *tbl);

/*
** ft_nd_div.c
*/
void				ft_nd_div2p(t_nd *nd, uint32_t p);

/*
** ft_nd_mul.c
*/
void				ft_nd_mul2p(t_nd *nd, uint32_t p, uint32_t carry);

/*
** ft_nd_long_div.c
*/
void				ft_nd_long_div2p(t_nd_long *nd, uint32_t p);

/*
** ft_nd_long_mul.c
*/
void				ft_nd_long_mul2p(t_nd_long *nd, uint32_t p, uint32_t carry);

/*
** ft_nd_long_round.c
*/
void				ft_long_round(t_nd_long *nd, int *r);

/*
** ft_unicode.c
*/
int					ft_wcsize(wchar_t wc);
wchar_t				ft_utf8_encode(unsigned int wchar);

/*
** print_buf_bit_float.c
*/
void				ft_print_buf_bit_float(char *b, float f);
void				ft_print_buf_bit_double(char *b, double db);
void				ft_print_buf_bit_long_double(char *b, long double ldb);
void				ft_print_bit_float(char *b, t_param *prm, va_list valist);

#endif
