# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/30 14:54:49 by jfleury           #+#    #+#              #
#    Updated: 2019/07/16 19:35:03 by tmaze            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	asm
CC 			= 	gcc
RM 			= 	rm -f
LIB_DIR		=	../libft
INCLUDE 	= 	-I ./include
IN_LIB		= 	-I ../libft/include
CFLAGS		+=	-Wall -Wextra -Werror $(INCLUDE) $(IN_LIB)

SRC_ASM		= 	src_asm/main_asm.c 								\
				src_asm/op.c									\
				src_asm/convert/convert.c						\
				src_asm/convert/conv_instru.c					\
				src_asm/convert/conv_utils.c

SRC_LEXER 	=	src_asm/lexer/src_variable/var_automaton.c		\
				src_asm/lexer/ft_lexer.c						\
				src_asm/lexer/ft_automaton.c					\
				src_asm/lexer/lib_lexer/ft_append_token_label.c	\
				src_asm/lexer/lib_lexer/ft_cut_line.c			\
				src_asm/lexer/lib_lexer/ft_line_strchr.c		\
				src_asm/lexer/lib_lexer/ft_create_string.c		\
				src_asm/lexer/lib_lexer/ft_check_line.c			\
				src_asm/lexer/lib_lexer/ft_append_lst_tk.c		\
				src_asm/lexer/lib_lexer/ft_empty_line.c			\
				src_asm/lexer/lib_lexer/ft_free_list.c			\
				src_asm/lexer/lib_lexer/ft_create_token_label.c

SRC_PARSER 	=	src_asm/parser/ft_parser.c						\
				src_asm/parser/parse_utils.c					\
				src_asm/parser/ft_parse_command.c				\
				src_asm/parser/ft_parse_instruc.c				\
				src_asm/parser/ft_cal_progsize.c

LIB			=	../libft/libft.a

OBJ_ASM 	= $(SRC_ASM:.c=.o)
OBJ_LEXER 	= $(SRC_LEXER:.c=.o)
OBJ_PARSER 	= $(SRC_PARSER:.c=.o)

all: libft $(NAME)

libft :
	make -C $(LIB_DIR) -f Makefile

$(NAME): $(OBJ_ASM) $(OBJ_LEXER) $(OBJ_PARSER)
	make -C $(LIB_DIR) -f Makefile
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ_ASM) $(OBJ_LEXER) $(OBJ_PARSER) $(LIB)

clean:
	make -C $(LIB_DIR) -f Makefile clean
	$(RM) $(OBJ_ASM) $(OBJ_LEXER) $(OBJ_PARSER)

fclean: clean
	make -C $(LIB_DIR) -f Makefile fclean
	$(RM) $(NAME)

re: fclean all

.SILENT: $(OBJ_ASM) $(OBJ_LEXER) $(OBJ_PARSER) $(NAME) all clean fclean re libft
.PHONY: all libft clean fclean re
