# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 20:22:58 by jfleury           #+#    #+#              #
#    Updated: 2019/07/09 15:26:41 by jfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
AR = ar rc
CC = gcc
RL = ranlib
RM = rm -f
INCLUDE = -I ./include
CFLAGS = -Wall -Werror -Wextra -c $(INCLUDE)

SRC_LIBFT =		libft/ft_memset.c		\
				libft/ft_bzero.c		\
				libft/ft_memcpy.c		\
				libft/ft_memccpy.c		\
				libft/ft_memmove.c		\
				libft/ft_memchr.c		\
				libft/ft_memcmp.c		\
				libft/ft_strlen.c		\
				libft/ft_strcmp.c 		\
				libft/ft_strdup.c		\
				libft/ft_strcpy.c		\
				libft/ft_strncpy.c		\
				libft/ft_strcat.c		\
				libft/ft_strncat.c		\
				libft/ft_strlcat.c		\
				libft/ft_strchr.c		\
				libft/ft_strrchr.c		\
				libft/ft_atoi.c			\
				libft/ft_atoi_bin.c		\
				libft/ft_atoi_long.c	\
				libft/ft_isalpha.c		\
				libft/ft_isdigit.c		\
				libft/ft_isalnum.c		\
				libft/ft_strstr.c 		\
				libft/ft_strnstr.c 		\
				libft/ft_strncmp.c 		\
				libft/ft_strnequ.c 		\
				libft/ft_isascii.c		\
				libft/ft_isprint.c		\
				libft/ft_toupper.c		\
				libft/ft_tolower.c		\
				libft/ft_memalloc.c		\
				libft/ft_memdel.c		\
				libft/ft_strnew.c		\
				libft/ft_strdel.c		\
				libft/ft_strclr.c		\
				libft/ft_striter.c		\
				libft/ft_striteri.c		\
				libft/ft_strmap.c		\
				libft/ft_strmapi.c		\
				libft/ft_strequ.c		\
				libft/ft_strsub.c		\
				libft/ft_strtrim.c		\
				libft/ft_strsplit.c		\
				libft/ft_itoa.c			\
				libft/ft_strjoin.c		\
				libft/ft_putchar.c		\
				libft/ft_putstr.c		\
				libft/ft_putendl.c		\
				libft/ft_putnbr.c		\
				libft/ft_putchar_fd.c	\
				libft/ft_putstr_fd.c	\
				libft/ft_putendl_fd.c	\
				libft/ft_putnbr_fd.c	\
				libft/ft_lstnew.c		\
				libft/ft_lstdelone.c	\
				libft/ft_lstdel.c		\
				libft/ft_lstadd.c		\
				libft/ft_lstadd_end.c	\
				libft/ft_lstiter.c		\
				libft/ft_lstprint_str.c	\
				libft/ft_lstmap.c		\
				libft/ft_strextend.c	\
				libft/ft_strnextend.c	\
				libft/ft_sstrnew.c		\
				libft/ft_sstrcpy.c		\
				libft/ft_sstrdel.c		\
				libft/get_next_line.c	\
				libft/ft_memtab.c		\
				libft/ft_memint_tab.c	\
				libft/ft_sstrprint.c	\
				libft/ft_bubble_sort.c	\
				libft/ft_char_replace.c	\
				libft/ft_itoa_base.c 	\
				libft/ft_itoa_double.c 	\
				libft/ft_strnchr.c 		\
				libft/ft_strrnchr.c 	\
				libft/ft_strupcase.c 	\
				libft/ft_strndup.c 		\
				libft/ft_power.c 		\
				libft/ft_itoa_base_int.c 	\
				libft/ft_itoa_base_short.c 	\
				libft/ft_strrev.c

SRC_PRINTF =	ft_printf/ft_printf.c 									\
				ft_printf/store/ft_store_struct.c						\
				ft_printf/store/ft_store_struct_2.c						\
				ft_printf/store/ft_struct_init_del.c					\
				ft_printf/process/conversion_id/process_c.c				\
				ft_printf/process/conversion_id/process_p.c				\
				ft_printf/process/conversion_id/process_s.c				\
				ft_printf/process/conversion_id/process_di.c			\
				ft_printf/process/conversion_id/process_id.c			\
				ft_printf/process/conversion_id/process_o.c				\
				ft_printf/process/conversion_id/process_u.c				\
				ft_printf/process/conversion_id/process_x.c				\
				ft_printf/process/conversion_id/process_xx.c			\
				ft_printf/process/conversion_id/process_f.c				\
				ft_printf/process/conversion_id/process_b.c				\
				ft_printf/process/conversion_id/process_dd.c			\
				ft_printf/process/conversion_id/process_percent.c		\
				ft_printf/process/flags/process_flags.c					\
				ft_printf/process/flags/process_space.c					\
				ft_printf/process/flags/process_plus.c					\
				ft_printf/process/flags/process_zero.c					\
				ft_printf/process/flags/process_minus.c					\
				ft_printf/process/flags/process_hash.c					\
				ft_printf/process/flags/process_hash2.c					\
				ft_printf/process/min_width/process_min_width.c			\
				ft_printf/process/precision/process_preci_diouxx.c		\
				ft_printf/process/precision/process_preci_s.c			\
				ft_printf/process/precision/process_preci_p.c			\
				ft_printf/process/precision/process_preci_table.c		\
				ft_printf/data/ft_data.c

OBJ_LIBFT = $(SRC_LIBFT:.c=.o)
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_LIBFT) $(OBJ_PRINTF)
	$(AR) $(NAME) $(OBJ_LIBFT) $(OBJ_PRINTF)
	$(RL) $(NAME)
	echo "Make libft"

clean:
	$(RM) $(OBJ_LIBFT) $(OBJ_PRINTF)
	echo "Clean libft"

fclean: clean
	$(RM) $(NAME)
	echo "Fclean libft"

re: fclean all

.SILENT: $(OBJ_LIBFT) $(OBJ_PRINTF) $(NAME) all clean fclean re
