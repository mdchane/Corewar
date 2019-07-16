#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaze <tmaze@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 18:38:00 by tmaze             #+#    #+#              #
#    Updated: 2019/07/16 19:36:58 by tmaze            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	corewar

#	Make options
MAKEFLAGS	+=	--no-print-directory

#	Output
UNAME	:=	$(shell uname)
ifeq ($(UNAME), Darwin)
ECHO	=	@echo
endif

ifeq ($(UNAME), Linux)
ECHO	=	@echo -e
endif

#	Compilator
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
NCURS	=	-lncurses

#	Folders
LIBDIR	=	../libft
PRTDIR	=	printf
SRCDIR  =	srcs
OBJDIR	=	objs
INCDIR	=	includes ../libft/include

#	Source files

SRC		=	cw_parser.c		\
			cw_read_mem.c	\
			cw_write_mem.c	\
			cw_process.c	\
			cw_vm.c			\
			cw_live.c		\
			cw_add_sub.c	\
			cw_aff.c		\
			cw_and_or_xor.c	\
			cw_fork_lfork.c	\
			cw_ld_lld.c		\
			cw_ldi_lldi.c	\
			cw_st.c			\
			cw_sti.c		\
			cw_zjump.c		\
			check_args.c	\
			main.c			\
			cw_visual.c		\
			cw_init_ncurs.c \
			cw_error.c		\
			cw_print_usage.c\
			cw_ops_tools.c	\
			cw_args.c		\
			cw_visual_win.c

SRC_PRT	=	buf_cnt.c \
			ft_argcast.c \
			ft_arglen_f.c \
			ft_arglen_oct.c \
			ft_arglen.c \
			ft_buf_print_db.c \
			ft_buf_print_ldb.c \
			ft_error.c \
			ft_exp_dec.c \
			ft_init_param.c \
			ft_nd_div.c \
			ft_nd_long_div.c \
			ft_nd_long_mul.c \
			ft_nd_long_round.c \
			ft_nd_mul.c \
			ft_nd_round.c \
			ft_null.c \
			ft_parse.c \
			ft_printf_db.c \
			ft_printf_ldb.c \
			ft_printf.c \
			ft_unicode.c \
			ft_strcat.c \
			libft_printf.c \
			pow10.c \
			print_buf_bit_float.c \
			print_buf_num.c \
			print_buf_prefix.c \
			print_buf_unicode.c \
			print_buf.c \
			print_cs_pad.c \
			print_num_pad.c

OBJ		=	$(SRC:.c=.o)
OBJ		=	$(SRC_PRT:.c=.o)

LIB		=	ft
LIBFILE	=	libft.a

#	Prefixes
OBJP		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o)) 
OBJP_PRT	=	$(addprefix $(OBJDIR)/, $(SRC_PRT:.c=.o))

INCP		=	$(foreach dir, $(INCDIR), -I$(dir))

#	Default Rule
DRULE	=	all

#	Main rules
default	:
		@$(ECHO) -e "$(PUR)===> $(GRE)$(NAME) : $(PUR) START RULE : $(DRULE) <===$(DEF)"
		@make $(DRULE)
		@$(ECHO) -e "$(PUR)===> $(GRE)$(NAME) : $(PUR) END RULE : $(DRULE) <===$(DEF)"

all		:	$(NAME)

#	Compilation rules
$(OBJDIR)/%.o	:	$(SRCDIR)/%.c includes/corewar.h
		@mkdir -p $(OBJDIR)
		$(CC) $(FLAGS) -c -o $@ $< $(INCP)

$(OBJDIR)/%.o	:	$(PRTDIR)/%.c includes/ft_printf.h
		@mkdir -p $(OBJDIR)
		$(CC) $(FLAGS) -c -o $@ $< $(INCP)


$(LIBDIR)/$(LIBFILE)	:
		@$(ECHO) "$(YEL)===> $(GRE)$(NAME) : $(YEL) Librairy Compilation <===$(DEF)"
		$(MAKE) -C $(LIBDIR) all

$(NAME)	:	$(OBJP) $(OBJP_PRT) $(LIBDIR)/$(LIBFILE) # $(PRTDIR)/$(PRTFILE)
		@$(ECHO) "$(YEL)===> $(GRE)$(NAME) : $(YEL) Binary Compilation <===$(DEF)"
		$(CC) $(FLAGS) -o $@ $^ $(INCP) -L$(LIBDIR) -l$(LIB) $(NCURS)

#	Cleaner rules
clean	:
		@$(ECHO) "$(RED)===> $(GRE)$(NAME) : $(RED) Delete Object Files <===$(DEF)"
		@$(RM) -rf $(OBJDIR)
		@$(MAKE) -C $(LIBDIR) clean
#		@$(MAKE) -C $(PRTDIR) clean

fclean	:	clean
		@$(ECHO) "$(RED)===> $(GRE)$(NAME) : $(RED) Delete Binary File <===$(DEF)"
		@$(RM) -f $(NAME) $(NAME2)
		@$(RM) -rf *.dSYM
		@$(MAKE) -C $(LIBDIR) fclean

re		:	fclean default

#	Debug rules
debug	:	FLAGS += -g
debug	:	fclean all


#	Phony
.PHONY	=	default all re clean fclean

#	Color
DEF		=	\033[0m
BLA		=	\033[30m
BLI		=	\033[5m
BLU		=	\033[34m
CYA		=	\033[36m
GRA		=	\033[1m
GRE		=	\033[32m
PUR		=	\033[35m
RED		=	\033[31m
SOU		=	\033[4m
WHI		=	\033[37m
YEL		=	\033[33m
