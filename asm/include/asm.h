/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:43:12 by jfleury           #+#    #+#             */
/*   Updated: 2019/07/16 11:40:38 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define LABEL 1
# define INSTRUCTION 2
# define DIRECT 3
# define DIRECT_LABEL 4
# define INDIRECT 5
# define INDIRECT_LABEL 6
# define REGISTER 7
# define STRING 8
# define SEPERATOR 9
# define COMMENT 10
# define COMMAND 11

# include "libft.h"
# include "ft_printf.h"
# include "op.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
** Struct
*/

typedef struct		s_token
{
	int				type;
	char			*contents;
	int				line;
	struct s_token	*next;
}					t_token;

typedef struct		s_label
{
	char			*contents;
	int				place;
	struct s_label	*next;
}					t_label;

typedef struct		s_lst_tk
{
	t_token			*token;
	struct s_lst_tk	*next;
}					t_lst_tk;

typedef struct		s_pos_lab
{
	t_label			*lab;
	int				pos;
}					t_pos_lab;

typedef struct		s_inst
{
	char			*name;
	int				nb_params;
	char			poss[3];
}					t_inst;

/*
** Global
*/

extern int			g_matrice_automaton[30][17];
extern char			*g_string_automaton[16];
extern int			g_nb_line;
extern int			g_nb_char;
extern int			g_nb_token;
extern int			g_place;
extern t_op			g_tab[17];

/*
** ASM
*/

t_label				*get_label(t_token *tk, t_label *label);
void				ft_convert(t_lst_tk *lst, t_header *head, char **argv,
								t_label *list_lab);
void				ft_free_all(t_lst_tk *list, t_label *label, t_header *head);
unsigned char		*ft_conv_instru(t_token *tk, int *size_instru,
									t_pos_lab pos_lab);
unsigned char		*ft_strextend_nm(unsigned char *s1, char unsigned *s2,
										int n, int m);

/*
** Lexer
*/

t_token				*ft_lexer_token(char **line, t_label **list_label);
int					ft_lexer(t_lst_tk **lst_tk, t_label **list_label,
								char **argv);
int					ft_automaton(char *line, t_token *token, t_label *label,
								int *nb_char_token);
int					ft_line_strchr(char *str, char c);
int					ft_empty_line(char *line);
int					ft_append_lst_tk(t_token *list_token, t_lst_tk **list);
char				**ft_cut_line(char **line, int nb_char_token);
char				*ft_create_string(char *line, int nb_char_token);
char				*ft_check_line(char *line, int fd);
void				ft_append_token_label(t_token *token, t_token **list_token,
										t_label *label, t_label **list_label);
void				ft_create_token_label(char *str, int type, t_token *token,
											t_label *label);
void				ft_free_list(t_lst_tk *list, t_label *label);

/*
** Parser
*/

int					ft_tklen(t_token *tk);
int					ft_parse_instruct(t_token *tk, t_label *label,
										unsigned int *size);
int					parse_header(t_lst_tk **lst, t_header *head);
int					ft_parser(t_lst_tk *lst, t_label *label, t_header *head);
int					is_inst(char *name);
char				*ft_error(char *msg);
char				*ft_parse_command(t_token *tk);
char				*ft_parse_command2(t_token *tk, t_header *head);
char				*ft_strnew_1(size_t size);
char				*ft_strcpy_1(char *dest, const char *src);
unsigned char		*ft_strcpy_n(unsigned char *dest, const unsigned char *src,
									int n, int m);
unsigned char		*ft_conv_hexa(int nbr, int size);

#endif
