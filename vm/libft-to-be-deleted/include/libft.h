/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:35:42 by jfleury           #+#    #+#             */
/*   Updated: 2019/07/15 19:15:18 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define BUFF_SIZE 32
# define CONV_ID_NB 13
# define FLAGS_NB 5
# define PRECI_GROUPS 3
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"
# define STRONG "\033[1m"

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_conv_spec
{
	char			conv_id;
	int				*flags;
	int				*modifier;
	int				field_width;
	int				precision;
	char			*converted;
}					t_conv_spec;

typedef struct		s_fptr_id
{
	char			*conv_id_tab;
	char			*(*fptr[CONV_ID_NB])(t_conv_spec c_s, va_list *list);
}					t_fptr_id;

typedef struct		s_fptr_flag
{
	int				*flags;
	char			*(*fptr[FLAGS_NB])(t_conv_spec c_s, char *str);
}					t_fptr_flag;

typedef struct		s_fptr_preci
{
	char			**preci_group;
	char			*(*fptr[PRECI_GROUPS])(t_conv_spec c_s, char *str);
}					t_fptr_preci;

int					ft_atoi(const char *str);
int					ft_atoi_bin(char *str);
long long			ft_atoi_long(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
char				*ft_itoa_base_int(unsigned int nb, int base);
char				*ft_itoa_base_short(unsigned short nb, int base);
int					ft_toupper(int c);
char				*ft_strextend(char *s1, char const *s2);
char				*ft_strnextend(char *s1, char const *s2, size_t len);
char				**ft_sstrnew(size_t row, size_t col);
char				**ft_sstrcpy(char **dest, char const **src);
char				**ft_memtab(size_t y, size_t x);
int					**ft_memint_tab(size_t y, size_t x);
void				ft_sstrprint(char **str);
int					*ft_bubble_sort(int *tab, int size);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
int					ft_lstadd_end(t_list **alst, t_list *elem);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstprint_str(t_list *lst);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_sstrdel(char **str, int size);
int					get_next_line(const int fd, char **line, char **tmp);
unsigned long long	ft_power(unsigned long long nb, unsigned long long power);
char				*ft_char_replace(char *str, char c, char r);
char				*ft_strupcase(char *str);
char				*ft_strnchr(const char *s, int c, int n);
char				*ft_strrnchr(const char *s, int c, int n);
char				*ft_strndup(const char *src, size_t n);
char				*ft_itoa_base(unsigned long long n, int base);
char				*ft_itoa_double(t_conv_spec conv_spec, long double nb);
char				*ft_strrev(char *str);
char				*ft_data_conv_id(void);
int					ft_store_conv_id(t_conv_spec *c_s, char *format, int i);
void				ft_store_modifier(t_conv_spec *c_s, char *f, int i, int l);
void				ft_store_flag(t_conv_spec *c_s, char *format, int i, int l);
void				ft_store_wc_field_width(t_conv_spec *c_s, va_list *ap);
void				ft_store_wc_precision(t_conv_spec *c_s, va_list *ap);
void				ft_store_field_width
					(t_conv_spec *c_s, char *format, int i, int len);
void				ft_store_precision(t_conv_spec *c_s, char *f, int i, int l);
void				ft_struct_init(t_conv_spec *c_s);
void				ft_struct_del(t_conv_spec *c_s);
char				*ft_data_conv_ids(void);
char				*ft_process_c(t_conv_spec c_s, va_list *ap);
char				*ft_process_s(t_conv_spec c_s, va_list *ap);
char				*ft_process_p(t_conv_spec c_s, va_list *ap);
char				*ft_process_di(t_conv_spec c_s, va_list *ap);
char				*ft_process_o(t_conv_spec c_s, va_list *ap);
char				*ft_process_u(t_conv_spec c_s, va_list *ap);
char				*ft_process_x(t_conv_spec c_s, va_list *ap);
char				*ft_process_xx(t_conv_spec c_s, va_list *ap);
char				*ft_process_f(t_conv_spec c_s, va_list *ap);
char				*ft_process_b(t_conv_spec c_s, va_list *ap);
char				*ft_process_dd(t_conv_spec c_s, va_list *ap);
char				*ft_process_percent(t_conv_spec c_s, va_list *ap);
char				*ft_process_id(t_conv_spec c_s, va_list *ap);
char				*ft_process_flags(t_conv_spec c_s, char *str);
char				*ft_process_hash(t_conv_spec c_s, char *str);
char				*ft_hash_xx_preci(char *str, int i);
char				*ft_hash_xx_zero(char *str, int i);
char				*ft_hash_x_preci(char *str, int i);
char				*ft_hash_x_zero(char *str, int i);
char				*ft_process_plus(t_conv_spec c_s, char *str);
char				*ft_process_zero(t_conv_spec c_s, char *str);
char				*ft_process_minus(t_conv_spec c_s, char *str);
char				*ft_process_space(t_conv_spec c_s, char *str);
char				*ft_process_min_width(t_conv_spec c_s, char *str);
char				*ft_precision_diouxx(t_conv_spec c_s, char *str);
char				*ft_precision_s(t_conv_spec c_s, char *str);
char				*ft_precision_p(t_conv_spec c_s, char *str);
char				*ft_process_preci(t_conv_spec c_s, char *str);

int					ft_atois(const char *str, int *nb);
int					ft_isnumb(char *str);
int					ft_mod(unsigned int val, unsigned int div);
int					ft_iswhitespace(char c);

#endif
