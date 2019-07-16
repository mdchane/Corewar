# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igarbuz <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 16:59:10 by igarbuz           #+#    #+#              #
#    Updated: 2018/12/17 15:23:20 by igarbuz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a	

SRC			=	buf_cnt.c \
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
				libft_printf.c \
				pow10.c \
				print_buf_bit_float.c \
				print_buf_num.c \
				print_buf_prefix.c \
				print_buf_unicode.c \
				print_buf.c \
				print_cs_pad.c \
				print_num_pad.c
			
HEAD		= 	ft_printf.h

OBJ			=	$(SRC:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra -O3

CPPFLAGS	=	-I .

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) *.o
	ranlib $(NAME)

%.o : %.c $(HEAD)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

norm:
	norminette $(SRC) $(HEAD) | grep -B1 "Error*"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

debug: CFLAGS += -g
debug: re

re: fclean all

.PHONY: all clean fclean re norm debug
