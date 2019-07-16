/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:54:03 by tmaze             #+#    #+#             */
/*   Updated: 2019/07/15 19:02:57 by igarbuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "libft.h"
# include "ft_printf.h"
# include <ncurses.h>

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

/*
** Added MEM_SIZE overflow protection binary mask. MEM_SIZE must be 2^x number.
** MEM_SIZE_M must be MEM_SIZE - 1;
*/
# define MEM_SIZE_M				MEM_SIZE - 1

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

# define T_REG					1
# define T_DIR					2
# define T_IND					4

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

# define AG_VERB				0x0001
# define AG_DUMP32				0x0002
# define AG_DUMP64				0x0004
# define AG_VISUAL				0x0008
# define AG_AFF					0x0010

# define VB_LIVE				0x0001
# define VB_CYCLES				0x0002
# define VB_OPS					0x0004
# define VB_DEATH				0x0008
# define VB_PC					0x0010

# define ART_MAX_SIZE			1023

char					g_buf[BUF_SIZE];

typedef struct			s_player
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
	int					num;
	char				col;
	unsigned int		live_ct;
	unsigned int		lst_live;
	unsigned char		code[CHAMP_MAX_SIZE];
}						t_player;

typedef struct			s_process
{
	size_t				pid;
	unsigned char		op;
	unsigned char		carry;
	char				new;
	unsigned int		wait;
	int					regs[REG_NUMBER + 1];
	int					lst_live;
	unsigned short int	pc;
	struct s_process	*next;
}						t_process;

typedef struct			s_visual
{
	WINDOW				*arena;
	WINDOW				*stat;
	bool				paused;
	int					delay;
}						t_visual;

typedef struct			s_vm
{
	unsigned char		mem[MEM_SIZE];
	unsigned char		col[MEM_SIZE];
	t_player			pls[MAX_PLAYERS];
	int					args;
	int					dump;
	int					verb;
	int					live;
	int					live_ct;
	int					cycles;
	int					ctd_c;
	int					ctd;
	short int			nb_j;
	size_t				p_ct;
	size_t				pid_ct;
	t_process			*tl;
	t_visual			vis;
}						t_vm;

typedef struct			s_ops
{
	unsigned int		wait;
	void				(*func)(t_process*, t_vm*);
}						t_ops;

typedef struct			s_args
{
	char				t;
	short int			i;
}						t_args;

typedef struct			s_pargs
{
	char				*arg;
	void				(*func)(char**, t_vm*, int);
	char				nb_ag;
}						t_pargs;

void					cw_print_usage(void);

void					clear_process(t_vm *vm);
void					init_process(t_vm *vm);
void					del_prcs(t_vm *vm);

void					init_vm(t_vm *vm, int i);
int						load_champ(t_vm *vm);
void					mem_dump(t_vm *vm);

void					arg_dump(char **av, t_vm *vm, int i);
void					arg_verb(char **av, t_vm *vm, int i);
void					arg_visual(char **av, t_vm *vm, int i);
void					arg_aff(char **av, t_vm *vm, int i);
void					fgqarg_aff(char **av, t_vm *vm, int i);

int						cw_parser(int ac, char **av, t_vm *vm);

int						check_file(char *path);

int						read_four(t_vm *vm, size_t index);
short int				read_two(t_vm *vm, size_t index);
unsigned char			read_mem(t_vm *vm, int ind);

void					write_mem(t_vm *vm, unsigned int index, char val
							, unsigned short int pc);
void					write_four(t_vm *vm, unsigned int index, int val
							, unsigned short int pc);

unsigned int			l2b_endian(unsigned int num);
void					cw_move_pc(t_vm *vm, t_process *p, int jp);
void					init_args(t_args *ag, t_process *p, t_vm *vm);
int						check_reg(t_vm *vm, int ind);
int						cw_ocp(char nb_ag, t_args *ag, char size_dir);

void					cw_live(t_process *p, t_vm *vm);
void					cw_ld(t_process *p, t_vm *vm);
void					cw_st(t_process *p, t_vm *vm);
void					cw_add(t_process *p, t_vm *vm);
void					cw_sub(t_process *p, t_vm *vm);
void					cw_and(t_process *p, t_vm *vm);
void					cw_or(t_process *p, t_vm *vm);
void					cw_xor(t_process *p, t_vm *vm);
void					cw_zjump(t_process *p, t_vm *vm);
void					cw_ldi(t_process *p, t_vm *vm);
void					cw_sti(t_process *p, t_vm *vm);
void					cw_fork(t_process *p, t_vm *vm);
void					cw_lld(t_process *p, t_vm *vm);
void					cw_lldi(t_process *p, t_vm *vm);
void					cw_lfork(t_process *p, t_vm *vm);
void					cw_aff(t_process *p, t_vm *vm);

int						err_msg(int err, t_vm *vm);
void					error(t_vm *vm, int err);

/*
** cw_visual.c
*/
void					print_arena(t_vm *vm);
void					print_pc(t_vm *vm, unsigned short int pc, char col);
void					control_delay(t_vm *vm);

/*
** cw_init_ncurs.c
*/
void					init_ncurses(t_vm *vm);
void					destroy_ncurses(t_vm *vm);
void					destroy_ncurses_exit(t_vm *vm);
void					check_user_exit(t_vm *vm, int key);
/*
** cw_visual_win.c
*/
void					visual_winners(t_vm *vm, int i);
void					visual_delay_update(t_vm *vm);
#endif
